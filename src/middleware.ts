// Keeps readers in their language. Pages, components and untranslated (English) content link to
// /docs/... and /community/; on a translated page, such as /ja/docs/, these links get the
// locale too, so they lead to /ja/docs/... Pages that are not translated yet are shown in English
// at those addresses. Links with a hreflang, like the ones of the language menu, are kept.
import { defineMiddleware } from 'astro:middleware';
import { localeCodes } from './i18n/locales.mjs';

const localizable = /(\shref=")\/(?=(?:docs|community)(?:[/?#"])|["?#])/;

export const onRequest = defineMiddleware(async (context, next) => {
	const response = await next();
	const locale = context.url.pathname.split('/')[1];
	if (!localeCodes.includes(locale) || !response.headers.get('content-type')?.startsWith('text/html')) {
		return response;
	}
	const html = await response.text();
	const localized = html.replace(/<a\s[^>]*>/g, (tag) =>
		/\shreflang=/.test(tag) ? tag : tag.replace(localizable, `$1/${locale}/`),
	);
	const headers = new Headers(response.headers);
	headers.delete('content-length');
	return new Response(localized, { status: response.status, statusText: response.statusText, headers });
});
