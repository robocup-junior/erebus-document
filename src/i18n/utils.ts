import { localeCodes } from './locales.mjs';

type Translate = App.Locals['t'];

/** The path without its locale segment: /ja/docs/ becomes /docs/. */
export function stripLocale(pathname: string): string {
	const [, first, ...rest] = pathname.split('/');
	return localeCodes.includes(first) ? `/${rest.join('/')}` : pathname;
}

/** The path for a locale: /docs/ becomes /ja/docs/. The root locale is "root" or undefined. */
export function localePath(locale: string | undefined, pathname: string): string {
	return !locale || locale === 'root' ? pathname : `/${locale}${pathname}`;
}

/**
 * Splits a string around its {{link}} placeholder, so that a link can be put between the parts
 * in the word order of each language.
 */
export function splitAroundLink(t: Translate, key: 'rcj.partOf' | 'rcj.community'): [string, string] {
	const mark = '\u0000';
	const [before = '', after = ''] = t(key, { link: mark, interpolation: { escapeValue: false } }).split(mark);
	return [before, after];
}
