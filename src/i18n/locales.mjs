// The languages of the site, in the order of the language menu.
//
//   code   the first segment of the URL, such as /ja/docs/. English is the root locale, without one.
//   lang   the BCP-47 tag. The UI strings of a language are in src/content/i18n/<lang>.json.
//   flag   the country code of the flag in the language menu, from the flag-icons package.
//
// Pages that are not translated yet are shown in English. See README.md to add a translation.
export const locales = [
	{ code: 'id', lang: 'id', label: 'Bahasa Indonesia', flag: 'id' },
	{ code: 'de', lang: 'de', label: 'Deutsch', flag: 'de' },
	{ code: 'root', lang: 'en', label: 'English', flag: 'gb' },
	{ code: 'es', lang: 'es', label: 'Español', flag: 'es' },
	{ code: 'fr', lang: 'fr', label: 'Français', flag: 'fr' },
	{ code: 'pt-br', lang: 'pt-BR', label: 'Português (Brasil)', flag: 'br' },
	{ code: 'tr', lang: 'tr', label: 'Türkçe', flag: 'tr' },
	{ code: 'th', lang: 'th', label: 'ไทย', flag: 'th' },
	{ code: 'zh-cn', lang: 'zh-CN', label: '中文（简体）', flag: 'cn' },
	{ code: 'zh-hant', lang: 'zh-Hant', label: '中文（繁體）', flag: 'tw' },
	{ code: 'ja', lang: 'ja', label: '日本語', flag: 'jp' },
	{ code: 'ko', lang: 'ko', label: '한국어', flag: 'kr' },
];

/** The URL segments of the translated locales, such as "ja". */
export const localeCodes = locales.map((locale) => locale.code).filter((code) => code !== 'root');
