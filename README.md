[![Netlify Status](https://api.netlify.com/api/v1/badges/f78f57f2-a53d-4f78-8e08-14fb57abe01b/deploy-status)](https://app.netlify.com/sites/erebus/deploys)

## Cloning the Project

The following will give you a project that is set up and ready to use (don't forget to use `--recurse-submodules` or you won't pull down some of the code you need to generate a working site). The `hugo server` command builds and serves the site. If you just want to build the site, run `hugo` instead.

```bash
git clone --recurse-submodules --depth 1 https://github.com/robocup-junior/erebus-document.git
cd erebus-document
hugo server
```

The theme is included as a Git submodule:

```bash
▶ git submodule
 a053131a4ebf6a59e4e8834a42368e248d98c01d themes/docsy (heads/master)
```

If you want to do SCSS edits and want to publish these, you need to install `PostCSS` (not needed for `hugo server`):

```bash
npm install -g postcss-cli
```

## Running the website locally

Once you've cloned the site repo, from the repo root folder, run:

```
hugo server
```

## How to add a document
Please refer to the files in `content/en/docs`, edit or add to them as needed.
