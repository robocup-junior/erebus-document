import starlight from '@astrojs/starlight';
import { defineConfig } from 'astro/config';
import { satteri } from '@astrojs/markdown-satteri';
import { readFileSync } from 'node:fs';
import starlightLinksValidator from 'starlight-links-validator';
import { headingIds } from './src/i18n/heading-ids.mjs';
import { languageRedirectScript } from './src/i18n/language-redirect.mjs';
import { locales } from './src/i18n/locales.mjs';

// The UI strings of each language, by BCP-47 tag. Starlight reads them too, from the i18n collection.
const strings = Object.fromEntries(
	locales.map(({ lang }) => [lang, JSON.parse(readFileSync(new URL(`./src/content/i18n/${lang}.json`, import.meta.url), 'utf8'))]),
);

// A sidebar label in English, with its translations. Missing translations fall back to English.
function label(key) {
	if (!strings.en[key]) throw new Error(`No English string for "${key}" in src/content/i18n/en.json`);
	const translations = Object.fromEntries(
		locales.filter(({ lang }) => lang !== 'en' && strings[lang][key]).map(({ lang }) => [lang, strings[lang][key]]),
	);
	return { label: strings.en[key], translations };
}

// Old URLs. The Erebus client and older documents link to some of them.
const redirects = {
	'/search': '/docs/',
	'/docs/events': '/docs/events/upcoming-events/',
	'/docs/reference': '/docs/reference/parameters/',
	'/docs/tutorials': '/docs/programming/',
	'/docs/contribution-guidelines': '/docs/contributing/',
	'/docs/reference/function-reference': '/docs/reference/messages/',
	'/docs/reference/parameter-reference': '/docs/reference/parameters/',
	'/docs/tutorials/emitter-and-receiver': '/docs/programming/communication/',
	'/docs/tutorials/emitter-and-receiver/map-bonus': '/docs/programming/map-bonus/',
	'/docs/tutorials/getting-started': '/docs/getting-started/',
	'/docs/tutorials/map-creator': '/docs/tools/world-editor/',
	'/docs/tutorials/movement': '/docs/programming/movement/',
	'/docs/tutorials/navigate-the-maze': '/docs/programming/navigate-the-maze/',
	'/docs/tutorials/remotecontroller': '/docs/competition/remote-controller/',
	'/docs/tutorials/remotecontroller/linux': '/docs/competition/remote-controller/linux/',
	'/docs/tutorials/remotecontroller/mac': '/docs/competition/remote-controller/mac/',
	'/docs/tutorials/remotecontroller/windows': '/docs/competition/remote-controller/windows/',
	'/docs/tutorials/sensors': '/docs/programming/sensors/',
	'/docs/tutorials/sensors/distance-sensor': '/docs/programming/sensors/distance-sensor/',
	'/docs/tutorials/sensors/lidar': '/docs/programming/sensors/lidar/',
	'/docs/tutorials/sensors/location-sensor': '/docs/programming/sensors/location-sensor/',
	'/docs/tutorials/sensors/rgb-camera': '/docs/programming/sensors/rgb-camera/',
	'/docs/tutorials/the-robot': '/docs/robot/',
	'/docs/tutorials/wall-tokens': '/docs/programming/wall-tokens/',
};

// Cloudflare Pages builds every branch, and tells the build its name. A release/vNN
// branch is the site of an old version, published at vNN.erebus.rcj.cloud.
const branch = process.env.CF_PAGES_BRANCH ?? '';
const archivedVersion = process.env.PUBLIC_ARCHIVED_VERSION ?? branch.match(/^release\/(v\d+)$/)?.[1] ?? '';
const archived = Boolean(archivedVersion);
const site = archived ? `https://${archivedVersion}.erebus.rcj.cloud` : 'https://erebus.rcj.cloud';

// Writes the redirects as a _redirects file too, so that Cloudflare Pages answers with a real 301.
const redirectsFile = {
	name: 'redirects-file',
	hooks: {
		'astro:build:done': async ({ dir }) => {
			const { writeFile } = await import('node:fs/promises');
			const lines = Object.entries(redirects).flatMap(([from, to]) => [`${from} ${to} 301`, `${from}/ ${to} 301`]);
			await writeFile(new URL('_redirects', dir), lines.join('\n') + '\n');
		},
	},
};

export default defineConfig({
	site,
	trailingSlash: 'ignore',
	redirects,
	markdown: { processor: satteri({ mdastPlugins: [headingIds()] }) },
	vite: {
		// Keep downloadable files, like the example programs, as real files.
		build: { assetsInlineLimit: 0 },
		// Lets the pages know if this is the site of an old version.
		define: { 'import.meta.env.PUBLIC_ARCHIVED_VERSION': JSON.stringify(archivedVersion) },
	},
	integrations: [
		redirectsFile,
		starlight({
			title: 'Erebus',
			// English is the root locale, at /. The other languages are at /<code>/, such as /ja/docs/.
			locales: Object.fromEntries(locales.map(({ code, lang, label }) => [code, { label, lang }])),
			description:
				'A rescue simulation competition environment designed for intermediate to highly experienced programmers.',
			logo: { src: './src/assets/logo.svg' },
			favicon: '/favicon.svg',
			head: [
				// Opens the reader's language on their first visit. See src/i18n/language-redirect.mjs.
				{ tag: 'script', content: languageRedirectScript() },
				{ tag: 'link', attrs: { rel: 'icon', href: '/favicon.ico', sizes: '32x32' } },
				{ tag: 'link', attrs: { rel: 'apple-touch-icon', href: '/apple-touch-icon.png' } },
				{ tag: 'meta', attrs: { name: 'theme-color', content: '#0b1a22' } },
				{ tag: 'meta', attrs: { property: 'og:image', content: `${site}/og.png` } },
				{ tag: 'meta', attrs: { property: 'og:image:width', content: '1200' } },
				{ tag: 'meta', attrs: { property: 'og:image:height', content: '630' } },
				{ tag: 'meta', attrs: { property: 'og:image:alt', content: 'Erebus: send your robot into the maze' } },
				{ tag: 'meta', attrs: { name: 'twitter:image', content: `${site}/og.png` } },
				// Old versions should not compete with the latest one in search results.
				...(archived ? [{ tag: 'meta', attrs: { name: 'robots', content: 'noindex' } }] : []),
			],
			customCss: ['./src/styles/theme.css'],
			components: {
				Banner: './src/components/Banner.astro',
				Footer: './src/components/Footer.astro',
				LanguageSelect: './src/components/LanguageSelect.astro',
				SiteTitle: './src/components/SiteTitle.astro',
				ThemeSelect: './src/components/ThemeSelect.astro',
			},
			plugins: [starlightLinksValidator({ errorOnLocalLinks: false })],
			social: [
				{ icon: 'github', label: 'GitHub', href: 'https://github.com/robocup-junior/erebus' },
				{ icon: 'discord', label: 'Discord', href: 'https://discord.com/invite/6FJxZxk' },
			],
			editLink: {
				baseUrl: 'https://github.com/robocup-junior/erebus-document/edit/master/',
			},
			lastUpdated: true,
			// Every page must be listed here, in learning order. The build fails if a slug does not exist.
			// The labels are "sidebar.*" strings in src/content/i18n/.
			sidebar: [
				{
					...label('sidebar.startHere'),
					items: [
						{ ...label('sidebar.overview'), slug: 'docs' },
						{ ...label('sidebar.whatIsErebus'), slug: 'docs/introduction' },
						{
							...label('sidebar.installation'),
							collapsed: true,
							items: [
								{ ...label('sidebar.requirements'), slug: 'docs/installation' },
								'docs/installation/windows',
								'docs/installation/mac',
								{ ...label('sidebar.linux'), slug: 'docs/installation/linux' },
							],
						},
					],
				},
				{
					...label('sidebar.theGame'),
					items: [{ ...label('sidebar.rulesSummary'), slug: 'docs/rules' }],
				},
				{
					...label('sidebar.yourRobot'),
					items: [
						{ ...label('sidebar.getYourRobot'), slug: 'docs/robot' },
						{ ...label('sidebar.buildYourRobot'), slug: 'docs/robot/build' },
					],
				},
				{
					...label('sidebar.firstRun'),
					items: [{ ...label('sidebar.yourFirstRun'), slug: 'docs/getting-started' }],
				},
				{
					...label('sidebar.programmingBasics'),
					items: [
						{ ...label('sidebar.overview'), slug: 'docs/programming' },
						{ ...label('sidebar.yourFirstProgram'), slug: 'docs/programming/first-program' },
						{ ...label('sidebar.movement'), slug: 'docs/programming/movement' },
						{
							...label('sidebar.sensors'),
							items: [
								{ ...label('sidebar.overview'), slug: 'docs/programming/sensors' },
								{ ...label('sidebar.distanceSensor'), slug: 'docs/programming/sensors/distance-sensor' },
								{ ...label('sidebar.locationSensor'), slug: 'docs/programming/sensors/location-sensor' },
								{ ...label('sidebar.colourSensor'), slug: 'docs/programming/sensors/colour-sensor' },
								{ ...label('sidebar.rgbCamera'), slug: 'docs/programming/sensors/rgb-camera' },
								{ ...label('sidebar.lidar'), slug: 'docs/programming/sensors/lidar' },
								{ ...label('sidebar.imu'), slug: 'docs/programming/sensors/imu' },
							],
						},
					],
				},
				{
					...label('sidebar.playTheGame'),
					items: [
						{ ...label('sidebar.navigateTheMaze'), slug: 'docs/programming/navigate-the-maze' },
						{ ...label('sidebar.communication'), slug: 'docs/programming/communication' },
						{ ...label('sidebar.wallTokens'), slug: 'docs/programming/wall-tokens' },
						{ ...label('sidebar.exploring'), slug: 'docs/programming/exploring' },
						{ ...label('sidebar.mappingRules'), slug: 'docs/rules/mapping' },
						{ ...label('sidebar.mapBonus'), slug: 'docs/programming/map-bonus' },
					],
				},
				{
					...label('sidebar.compete'),
					items: [
						{ ...label('sidebar.preparing'), slug: 'docs/competition' },
						{
							...label('sidebar.remoteController'),
							collapsed: true,
							items: [
								{ ...label('sidebar.overview'), slug: 'docs/competition/remote-controller' },
								'docs/competition/remote-controller/windows',
								'docs/competition/remote-controller/mac',
								{ ...label('sidebar.linux'), slug: 'docs/competition/remote-controller/linux' },
							],
						},
						{ ...label('sidebar.upcomingEvents'), slug: 'docs/events/upcoming-events' },
						{ ...label('sidebar.pastEvents'), slug: 'docs/events/past-events' },
					],
				},
				{
					...label('sidebar.goingFurther'),
					items: [
						{ ...label('sidebar.customizerReference'), slug: 'docs/robot/customizer' },
						{ ...label('sidebar.worldEditor'), slug: 'docs/tools/world-editor' },
						{ ...label('sidebar.cpp'), slug: 'docs/programming/cpp' },
						{ ...label('sidebar.whatsNew'), slug: 'docs/whats-new' },
					],
				},
				{
					...label('sidebar.help'),
					items: [
						{ ...label('sidebar.troubleshooting'), slug: 'docs/troubleshooting' },
						{ ...label('sidebar.faq'), slug: 'docs/faq' },
					],
				},
				{
					...label('sidebar.reference'),
					items: [
						{ ...label('sidebar.parameters'), slug: 'docs/reference/parameters' },
						{ ...label('sidebar.messages'), slug: 'docs/reference/messages' },
						{ ...label('sidebar.glossary'), slug: 'docs/reference/glossary' },
						{ ...label('sidebar.versions'), slug: 'docs/reference/versions' },
					],
				},
				{
					...label('sidebar.about'),
					items: [
						{ ...label('sidebar.contributing'), slug: 'docs/contributing' },
						{ ...label('sidebar.community'), slug: 'community' },
						{ ...label('sidebar.privacy'), slug: 'docs/privacy' },
						{ label: 'RoboCupJunior Rescue', link: 'https://junior.robocup.org/rescue/', attrs: { target: '_blank' } },
						{ label: 'RCJ Rescue Community', link: 'https://rescue.rcj.cloud', attrs: { target: '_blank' } },
					],
				},
			],
		}),
	],
});
