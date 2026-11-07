import starlight from '@astrojs/starlight';
import { defineConfig } from 'astro/config';
import starlightLinksValidator from 'starlight-links-validator';

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
	'/docs/tutorials/movement': '/docs/robot/movement/',
	'/docs/tutorials/navigate-the-maze': '/docs/programming/navigate-the-maze/',
	'/docs/tutorials/remotecontroller': '/docs/competition/remote-controller/',
	'/docs/tutorials/remotecontroller/linux': '/docs/competition/remote-controller/linux/',
	'/docs/tutorials/remotecontroller/mac': '/docs/competition/remote-controller/mac/',
	'/docs/tutorials/remotecontroller/windows': '/docs/competition/remote-controller/windows/',
	'/docs/tutorials/sensors': '/docs/robot/sensors/',
	'/docs/tutorials/sensors/distance-sensor': '/docs/robot/sensors/distance-sensor/',
	'/docs/tutorials/sensors/lidar': '/docs/robot/sensors/lidar/',
	'/docs/tutorials/sensors/location-sensor': '/docs/robot/sensors/location-sensor/',
	'/docs/tutorials/sensors/rgb-camera': '/docs/robot/sensors/rgb-camera/',
	'/docs/tutorials/the-robot': '/docs/robot/',
	'/docs/tutorials/wall-tokens': '/docs/programming/wall-tokens/',
};

export default defineConfig({
	// The deployment sets SITE_URL for the sites of old versions.
	site: process.env.SITE_URL ?? 'https://erebus.rcj.cloud',
	trailingSlash: 'ignore',
	redirects,
	integrations: [
		starlight({
			title: 'Erebus',
			description:
				'A rescue simulation competition environment designed for intermediate to highly experienced programmers.',
			logo: { src: './src/assets/logo.svg' },
			favicon: '/favicon.ico',
			customCss: ['./src/styles/theme.css'],
			components: {
				Banner: './src/components/Banner.astro',
				SiteTitle: './src/components/SiteTitle.astro',
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
			// Every page must be listed here. The build fails if a slug does not exist.
			sidebar: [
				{
					label: 'Get started',
					items: [
						{ label: 'Overview', slug: 'docs' },
						{ label: 'What is Erebus?', slug: 'docs/introduction' },
						{ label: "What's new in v26", slug: 'docs/whats-new' },
						{
							label: 'Installation',
							collapsed: true,
							items: [
								{ label: 'Requirements', slug: 'docs/installation' },
								'docs/installation/windows',
								'docs/installation/mac',
								'docs/installation/linux',
							],
						},
						{ label: 'Your first run', slug: 'docs/getting-started' },
						'docs/troubleshooting',
						'docs/faq',
					],
				},
				{
					label: 'Competition',
					items: [
						{ label: 'Rules summary', slug: 'docs/rules' },
						{ label: 'Mapping rules', slug: 'docs/rules/mapping' },
						{ label: 'Preparing for a competition', slug: 'docs/competition' },
						{
							label: 'Remote Controller',
							collapsed: true,
							items: [
								{ label: 'Overview', slug: 'docs/competition/remote-controller' },
								'docs/competition/remote-controller/windows',
								'docs/competition/remote-controller/mac',
								'docs/competition/remote-controller/linux',
							],
						},
						{ label: 'Upcoming events', slug: 'docs/events/upcoming-events' },
						{ label: 'Past events', slug: 'docs/events/past-events' },
					],
				},
				{
					label: 'Build your robot',
					items: [
						{ label: 'The robot', slug: 'docs/robot' },
						'docs/robot/movement',
						{
							label: 'Sensors',
							collapsed: true,
							items: [
								{ label: 'Overview', slug: 'docs/robot/sensors' },
								'docs/robot/sensors/distance-sensor',
								'docs/robot/sensors/location-sensor',
								'docs/robot/sensors/colour-sensor',
								'docs/robot/sensors/rgb-camera',
								'docs/robot/sensors/lidar',
								'docs/robot/sensors/imu',
							],
						},
					],
				},
				{
					label: 'Program your robot',
					items: [
						{ label: 'Overview', slug: 'docs/programming' },
						'docs/programming/navigate-the-maze',
						'docs/programming/communication',
						'docs/programming/wall-tokens',
						'docs/programming/exploring',
						'docs/programming/map-bonus',
						'docs/programming/cpp',
					],
				},
				{
					label: 'Tools',
					items: [
						'docs/tools/world-editor',
						'docs/tools/robot-customizer',
					],
				},
				{
					label: 'Reference',
					items: [
						'docs/reference/parameters',
						'docs/reference/messages',
						'docs/reference/glossary',
						'docs/reference/versions',
					],
				},
				{
					label: 'About',
					items: ['docs/contributing', 'community', 'docs/privacy'],
				},
			],
		}),
	],
});
