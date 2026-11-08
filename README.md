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

Each version of the site is a separate [Cloudflare Worker](https://developers.cloudflare.com/workers/static-assets/) with static assets, deployed by GitHub Actions with Wrangler (`.github/workflows/deploy.yml`). Cloudflare's own automatic builds are not used, because of the restrictions of the GitHub organization:

| Branch | Worker | Address |
|---|---|---|
| `master` | `erebus-document` | `erebus.rcj.cloud` |
| `release/vNN` | `erebus-docs-vNN` | `vNN.erebus.rcj.cloud` |

The repository needs the secrets `CLOUDFLARE_API_TOKEN`, with the Edit Cloudflare Workers permission, and `CLOUDFLARE_ACCOUNT_ID`. Until the repository variable `BIND_DOMAINS` is `true`, sites are only published at their `workers.dev` address and the custom domains are left alone.

v25 and earlier use Hugo. Their sites are frozen: they are not deployed from this workflow, and pushing to their branches does nothing.

## Where things are

| Path | Contents |
|---|---|
| `src/content/docs/docs/` | The pages. The URL follows the folder: `tutorials/movement/index.mdx` is `/docs/tutorials/movement/`. |
| `src/pages/index.astro` | The home page. Its media is in `public/home/`, and the hero clips are listed in `heroClips`. |
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

## The starter robot and the examples

Every example runs on the starter robot, `public/downloads/starter-robot.json`, which is built step by step in [Build your robot](src/content/docs/docs/robot/build/index.mdx). If you change the robot, change that page and the examples too.

Before a release, run each example on the starter robot in Erebus: load the robot, load the program, and check that it does what its page says. The C/C++ examples can be run with the Remote Controller after compiling them, as explained in [C++ controllers](src/content/docs/docs/programming/cpp/index.md).

## Updating for a new Erebus version

1. Before changing anything, create `release/vNN` from `master` for the version that is about to be replaced. Pushing it publishes the old version at `vNN.erebus.rcj.cloud`, with a notice that links to the latest version.
1. Update `version` and `rulesYear` at the top of `src/pages/index.astro`.
1. In `src/data/versions.ts`, add the new version with `current: true`, and change the previous one to `current: false` with its `vNN.erebus.rcj.cloud` address.
1. We support the latest two years, so remove older versions from `src/data/versions.ts`.
1. Search `src/content/docs` for the old version numbers, and for the Webots version if it has changed.
1. Update the rules summary from the new rules PDF. Links to the PDF are in `rules/index.md` and `tutorials/map-creator/index.md`.
1. Check the example matrices in `rules/mapping/index.md`. If the worlds have changed, they must be generated again from the new version.
