// Copies English pages to a language folder, ready to be translated:
//
//   node scripts/prepare-translation.mjs ja                      every page that has no translation yet
//   node scripts/prepare-translation.mjs ja docs/rules/index.md  only these pages (overwrites them)
//
// In the copies, each heading keeps the id of its English heading ({#id}), so that links to
// anchors work in every language, and relative paths to images and code point to the English
// folder. Run `npm run build` first: the ids are read from the built English pages in dist/.
import { existsSync, mkdirSync, readFileSync, readdirSync, writeFileSync } from 'node:fs';
import { dirname, join, posix, relative } from 'node:path';
import { localeCodes } from '../src/i18n/locales.mjs';

const docs = 'src/content/docs';
const [locale, ...only] = process.argv.slice(2);
if (!localeCodes.includes(locale)) throw new Error(`Usage: prepare-translation.mjs <${localeCodes.join('|')}> [pages]`);

/** English pages, relative to src/content/docs, such as docs/rules/index.md. */
function englishPages(dir = '') {
	return readdirSync(join(docs, dir), { withFileTypes: true }).flatMap((entry) => {
		const path = posix.join(dir, entry.name);
		if (entry.isDirectory()) return dir === '' && localeCodes.includes(entry.name) ? [] : englishPages(path);
		return /\.mdx?$/.test(entry.name) ? [path] : [];
	});
}

/** The ids of the headings of a built English page, in order. */
function headingIds(page) {
	const route = page.replace(/(\/?index)?\.mdx?$/, '');
	const html = readFileSync(join('dist', route, 'index.html'), 'utf8');
	const content = html.slice(html.indexOf('sl-markdown-content'));
	return [...content.matchAll(/<h[2-6] id="([^"]+)"/g)].map((match) => match[1]);
}

function prepare(page) {
	const mdx = page.endsWith('.mdx');
	const target = join(docs, locale, page);
	const toEnglish = relative(dirname(target), dirname(join(docs, page))).split('\\').join('/');
	const ids = headingIds(page);
	let fenced = false;
	let heading = 0;
	const lines = readFileSync(join(docs, page), 'utf8').split('\n').map((line) => {
		if (/^\s*(```|~~~)/.test(line)) fenced = !fenced;
		if (fenced) return line;
		if (/^#{2,6} /.test(line)) {
			const id = ids[heading++];
			return mdx ? `${line} \\{#${id}\\}` : `${line} {#${id}}`;
		}
		// Relative links, images and imports: ./x.png, ../x/y.png, './maze.py?url'.
		return line.replace(/(\]\(|from ['"]|src=["'])(\.\.?\/)/g, (_, before, start) => `${before}${toEnglish}/${start === './' ? '' : '../'}`);
	});
	if (heading !== ids.length) throw new Error(`${page}: ${heading} headings in the source, ${ids.length} in dist/`);
	mkdirSync(dirname(target), { recursive: true });
	writeFileSync(target, lines.join('\n'));
	return target;
}

const pages = only.length ? only : englishPages().filter((page) => !existsSync(join(docs, locale, page)));
for (const page of pages) console.log(prepare(page));
