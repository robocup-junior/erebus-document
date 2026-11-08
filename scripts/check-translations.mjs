// Checks that translated pages still match the structure of their English page:
// the same heading ids, link and image targets, imports, components and code blocks.
//
//   node scripts/check-translations.mjs        all languages
//   node scripts/check-translations.mjs ja     one language
//
// Also lists English pages that have no translation yet, and translations whose English page
// changed after them (by the date of the last commit), which may need updating.
import { execFileSync } from 'node:child_process';
import { existsSync, readFileSync, readdirSync } from 'node:fs';
import { join, posix, resolve, dirname } from 'node:path';
import { localeCodes } from '../src/i18n/locales.mjs';

const docs = 'src/content/docs';
const languages = process.argv[2] ? [process.argv[2]] : localeCodes;

function pages(dir) {
	return readdirSync(dir, { withFileTypes: true }).flatMap((entry) => {
		const path = posix.join(dir, entry.name);
		if (entry.isDirectory()) return dir === docs && localeCodes.includes(entry.name) ? [] : pages(path);
		return /\.mdx?$/.test(entry.name) ? [path] : [];
	});
}

/** The parts of a page that must not change in a translation. */
function structure(file) {
	const text = readFileSync(file, 'utf8');
	const code = [...text.matchAll(/^([ \t]*)(```|~~~)[^\n]*\n[\s\S]*?^\1\2[ \t]*$/gm)].map((match) => match[0].trim());
	const prose = text.replace(/^([ \t]*)(```|~~~)[^\n]*\n[\s\S]*?^\1\2[ \t]*$/gm, '');
	// Resolve relative targets, so that ./x.png in English and ../../docs/x.png in a translation match.
	const target = (path) => (/^\.\.?\//.test(path) ? resolve(dirname(file), path) : path);
	return {
		'heading ids': [...prose.matchAll(/^#{2,6} .*?\\?\{#([\w-]+)\\?\}\s*$/gm)].map((match) => match[1]),
		headings: [...prose.matchAll(/^(#{2,6}) /gm)].map((match) => match[1]),
		links: [...prose.matchAll(/\]\(([^)\s]+)/g)].map((match) => target(match[1].split('#')[0]) + (match[1].includes('#') ? '#' + match[1].split('#')[1] : '')),
		imports: [...prose.matchAll(/^import .* from ['"]([^'"]+)['"]/gm)].map((match) => target(match[1])),
		components: [...prose.matchAll(/<\/?([A-Z]\w*)/g)].map((match) => match[1]),
		'code blocks': code,
	};
}

let problems = 0;
const report = (message) => {
	problems++;
	console.log(message);
};

for (const locale of languages) {
	for (const english of pages(docs)) {
		const translated = join(docs, locale, english.slice(docs.length + 1));
		if (!existsSync(translated)) {
			console.log(`untranslated  ${translated}`);
			continue;
		}
		const expected = structure(english);
		const actual = structure(translated);
		for (const [part, values] of Object.entries(expected)) {
			if (part === 'heading ids') continue; // English pages have no explicit ids.
			// A translation may put the links of a sentence in another order.
			const same = part === 'links' ? JSON.stringify([...values].sort()) === JSON.stringify([...actual[part]].sort()) : JSON.stringify(values) === JSON.stringify(actual[part]);
			if (!same) {
				const missing = values.filter((value) => !actual[part].includes(value));
				const extra = actual[part].filter((value) => !values.includes(value));
				report(`${translated}: ${part} differ${missing.length ? `\n  missing: ${missing.join(', ').slice(0, 300)}` : ''}${extra.length ? `\n  extra: ${extra.join(', ').slice(0, 300)}` : ''}`);
			}
		}
		if (actual['heading ids'].length !== actual.headings.length) {
			report(`${translated}: ${actual.headings.length - actual['heading ids'].length} headings without {#id}`);
		}
		const lastCommit = (file) => Number(execFileSync('git', ['log', '-1', '--format=%ct', '--', file], { encoding: 'utf8' }).trim() || 0);
		const englishDate = lastCommit(english);
		const translatedDate = lastCommit(translated);
		if (englishDate && translatedDate && englishDate > translatedDate) {
			console.log(`outdated      ${translated} (the English page changed after it)`);
		}
	}
}

if (problems) {
	console.log(`\n${problems} problem(s)`);
	process.exit(1);
}
console.log('Translations match their English pages.');
