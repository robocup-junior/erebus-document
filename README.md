# Erebus documentation

The documentation site of [Erebus](https://github.com/robocup-junior/erebus), built with [Astro](https://astro.build/) and [Starlight](https://starlight.astro.build/).

## Running locally

You need the Node.js version in `.nvmrc`.

```bash
npm install
npm run dev
```

The site is served at <http://localhost:4321>. `npm run build` makes a production build in `dist/`, and fails if an internal link, an image or a code sample is missing. Pull requests run the same check.

## Deployment

The site is on [Cloudflare Pages](https://pages.cloudflare.com/), which builds every push with these settings:

| Setting | Value |
|---|---|
| Build command | `npm run build` |
| Build output directory | `dist` |
| Environment variable | `NODE_VERSION` = `24` |

Each version of the site is a branch:

| Branch | Address |
|---|---|
| `master` | `erebus.rcj.cloud` |
| `release/vNN` | `vNN.erebus.rcj.cloud`, with a notice that links to the latest version |

The build recognizes `release/vNN` branches by itself. For a new old version, point `vNN.erebus.rcj.cloud` to the branch in the Pages project. v25 and earlier are Hugo sites, and are not built from this repository.

## Where things are

| Path | Contents |
|---|---|
| `src/content/docs/docs/` | The pages. The URL follows the folder: `tutorials/movement/index.mdx` is `/docs/tutorials/movement/`. |
| `src/pages/[...locale]/index.astro` | The home page, in every language. Its media is in `public/home/`, and the hero clips are listed in `heroClips`. |
| `src/i18n/locales.mjs` | The languages, with their flags in the language menu |
| `src/content/i18n/` | The UI strings of each language: menus, sidebar labels and the home page |
| `src/content/docs/<code>/` | The translated pages, such as `src/content/docs/ja/docs/` |
| `scripts/` | Tools to prepare and check translations |
| `astro.config.mjs` | The sidebar, the redirects from old URLs and the site settings |
| `src/styles/theme.css` | Colours and fonts |
| `src/data/versions.ts` | The versions in the header menu and on the Versions page |
| `src/components/` | Code tabs and the version menu |
| `public/` | Files served as they are, like the downloadable sample programs |

## Editing pages

Pages are Markdown (`.md`), or MDX (`.mdx`) when they use a component. Put images next to the page and link them with `![Description](./image.png)`.

**To add a page:** create `<folder>/index.md` with a `title` in the frontmatter, and add it to `sidebar` in `astro.config.mjs`.

**To move or rename a page:** add a redirect from the old URL in `astro.config.mjs`, since other sites and the Erebus client link to us.

**To add a code sample:** write a complete program that runs on the starter robot, and put `example.py` and/or `example.c` next to the page. Then write this in an `.mdx` page:

```mdx
import CodeTabs from '@/components/CodeTabs.astro';

<CodeTabs file="example" />
```

To show only part of a program, mark it with `# region name` and `# endregion` (`// region name` in C/C++), and use `<CodeTabs file="example" region="name" />`. The markers are hidden when the whole program is shown. The [Navigate the maze](src/content/docs/docs/programming/navigate-the-maze/index.mdx) tutorial works like this, so its steps always match the complete program.

**For notes and warnings,** use Starlight [asides](https://starlight.astro.build/guides/authoring-content/#asides), and see its [guide](https://starlight.astro.build/guides/authoring-content/) for everything else.

## Translations

The site is in English, Bahasa Indonesia, Deutsch, Español, Français, Português (Brasil), Türkçe, ไทย, 中文（简体）, 中文（繁體）, 日本語 and 한국어. English is at `/`, and the other languages at `/<code>/`, such as `/ja/docs/`. Pages and strings that are not translated yet are shown in English.

On their first visit, readers get the language of their browser, if the site has it. Once they choose a language in the menu, the site keeps their choice. See `src/i18n/language-redirect.mjs`.

**To translate a page:** run `npm run build`, then `node scripts/prepare-translation.mjs <code> [pages]`, such as `node scripts/prepare-translation.mjs ja docs/rules/index.md`. It copies the English page to the language folder, such as `src/content/docs/ja/docs/rules/index.md`, with paths that point to the English images and code samples. Translate the copy, and keep:

- the `{#id}` at the end of each heading (`\{#id\}` in MDX). Headings keep the ids of the English ones, so links to `#anchors` work in every language.
- link targets, image paths, imports, components and code blocks.

**When an English page changes,** change its translations too, or prepare them again. `node scripts/check-translations.mjs` lists the translations whose structure no longer matches their English page, the ones older than their English page, and the pages that are not translated yet.

**To translate the UI:** the strings are in `src/content/i18n/<lang>.json`, with the keys of `en.json`. Sidebar labels are the `sidebar.*` keys, and the home page the `home.*` keys. Starlight translates its own UI.

**Links:** write links to `/docs/...` as usual. On a translated page they lead to the same language, because `src/middleware.ts` adds the language to them.

## The starter robot and the examples

Every example runs on the starter robot, `public/downloads/starter-robot.json`, which is built step by step in [Build your robot](src/content/docs/docs/robot/build/index.mdx). If you change the robot, change that page and the examples too.

Before a release, run each example on the starter robot in Erebus: load the robot, load the program, and check that it does what its page says. The C/C++ examples can be run with the Remote Controller after compiling them, as explained in [C++ controllers](src/content/docs/docs/programming/cpp/index.md).

## Updating for a new Erebus version

1. Before changing anything, create `release/vNN` from `master` for the version that is about to be replaced, and push it. Then point `vNN.erebus.rcj.cloud` to that branch in the Cloudflare Pages project.
1. Update `rulesYear` at the top of `src/pages/[...locale]/index.astro`, and `knownVersion` in `src/data/release.ts`. Download links follow the latest release of the documented version by themselves (`v26.x` for v26): the site reads it from GitHub when it is built, and again in the browser.
1. In `src/data/versions.ts`, add the new version with `current: true`, and change the previous one to `current: false` with its `vNN.erebus.rcj.cloud` address.
1. We support the latest two years, so remove older versions from `src/data/versions.ts`.
1. Search `src/content/docs` for the old version numbers, and for the Webots version if it has changed.
1. Update the rules summary from the new rules PDF. Links to the PDF are in `rules/index.md` and `tools/world-editor/index.md`.
1. Check the example matrices in `rules/mapping/index.md`. If the worlds have changed, they must be generated again from the new version.
1. Give the new version its own accent colour, so that readers can tell the versions apart: change the `--sl-color-accent*` and `--erebus-highlight*` variables at the top of `src/styles/theme.css`.
1. Retake the screenshots and the home page clips (`public/home/`) with the new version.
