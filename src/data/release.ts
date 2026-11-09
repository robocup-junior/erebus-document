// The latest Erebus release of the version this documentation is for, such as v27.0.0 for v27.
// It is read from GitHub when the site is built, and DownloadErebus.astro checks it again in the
// browser, so that download links follow new releases without a new build of the site.
import { versions } from './versions';

export const repository = 'robocup-junior/erebus';

/** The version series of this documentation, such as "v27". */
export const series = versions.find((version) => version.current)?.name ?? 'v27';

// Used when GitHub cannot be reached during the build. Update it from time to time.
const knownVersion = '27.0.0';

async function fetchLatestVersion(): Promise<string> {
	try {
		const response = await fetch(`https://api.github.com/repos/${repository}/releases?per_page=30`, {
			headers: { accept: 'application/vnd.github+json' },
		});
		if (!response.ok) throw new Error(`GitHub answered ${response.status}`);
		const releases: { tag_name: string; draft: boolean; prerelease: boolean }[] = await response.json();
		const release = releases.find(
			(release) => !release.draft && !release.prerelease && release.tag_name.startsWith(`${series}.`),
		);
		if (!release) throw new Error(`no ${series}.x release`);
		return release.tag_name.replace(/^v/, '');
	} catch (error) {
		console.warn(`[release] Using Erebus ${knownVersion}: could not read the latest release (${error})`);
		return knownVersion;
	}
}

/** The latest version, without "v", such as "27.0.0". */
export const latestVersion = await fetchLatestVersion();

/** The source code zip of a version. */
export const downloadUrl = (version: string) => `https://github.com/${repository}/archive/refs/tags/v${version}.zip`;
