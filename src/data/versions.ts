// Documentation versions, newest first. We support the latest two years, so keep at most two.
// Used by the menu in the header and by the Versions page.
export const latestSite = 'https://erebus.rcj.cloud';

// Set when building a release/vNN branch, such as "v26". Empty on the latest site.
// See astro.config.mjs.
export const archivedVersion: string = import.meta.env.PUBLIC_ARCHIVED_VERSION;

export const versions = [
	{ name: 'v27', rules: '2027', webots: 'R2025a', url: latestSite, current: true },
	{ name: 'v26', rules: '2026', webots: 'R2023b', url: 'https://v26.erebus.rcj.cloud', current: false },
];
