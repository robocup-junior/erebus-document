// Documentation versions, newest first. We support the latest two years, so keep at most two.
// Used by the menu in the header and by the Versions page.
export const latestSite = 'https://erebus.rcj.cloud';

// Set by the deployment on release/* branches, such as "v26". Empty on the latest site.
export const archivedVersion: string | undefined = import.meta.env.PUBLIC_ARCHIVED_VERSION;

export const versions = [
	{ name: 'v26', rules: '2026', webots: 'R2023b', url: latestSite, current: true },
];
