// Picks the language of the reader's browser on their first visit. Added to the <head> of every
// page by astro.config.mjs, so that it runs before the page is drawn.
//
// On an English page, if the reader has never chosen a language in the language menu, it moves
// them to the same page in the first language of their browser that the site has. Once they
// choose a language in the menu (English too), LanguageSelect.astro saves it in localStorage
// under this key, and this script follows that choice instead.
import { locales } from './locales.mjs';

export const languageKey = 'erebus-language';

/** The locale code for each browser language. Chinese is matched by script and region. */
function matcher() {
	const codes = Object.fromEntries(locales.map(({ code, lang }) => [lang.toLowerCase(), code === 'root' ? '' : code]));
	return `function (tag) {
		var codes = ${JSON.stringify(codes)};
		tag = tag.toLowerCase();
		if (tag.indexOf('zh') === 0) return /hant|-tw|-hk|-mo/.test(tag) ? codes['zh-hant'] : codes['zh-cn'];
		if (tag in codes) return codes[tag];
		var base = tag.split('-')[0];
		if (base === 'pt') return codes['pt-br'];
		return base in codes ? codes[base] : undefined;
	}`;
}

export function languageRedirectScript() {
	const translated = locales.map(({ code }) => code).filter((code) => code !== 'root');
	return `(function () {
	try {
		var segment = location.pathname.split('/')[1];
		if (${JSON.stringify(translated)}.indexOf(segment) !== -1) return;
		var saved = localStorage.getItem(${JSON.stringify(languageKey)});
		var match = ${matcher()};
		var translated = ${JSON.stringify(translated)};
		var code = saved === '' || translated.indexOf(saved) !== -1 ? saved : undefined;
		if (code === undefined) {
			var languages = navigator.languages && navigator.languages.length ? navigator.languages : [navigator.language || ''];
			for (var i = 0; i < languages.length && code === undefined; i++) code = match(languages[i]);
		}
		if (code) location.replace('/' + code + location.pathname + location.search + location.hash);
	} catch (error) {}
})();`;
}
