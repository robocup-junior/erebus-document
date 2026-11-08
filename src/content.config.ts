import { defineCollection } from 'astro:content';
import { z } from 'astro/zod';
import { docsLoader, i18nLoader } from '@astrojs/starlight/loaders';
import { docsSchema, i18nSchema } from '@astrojs/starlight/schema';
import en from './content/i18n/en.json';

// Our own UI strings: every key of en.json, optional in the other languages.
type Key = keyof typeof en;
const ownStrings = Object.fromEntries(Object.keys(en).map((key) => [key, z.string().optional()])) as Record<
	Key,
	z.ZodOptional<z.ZodString>
>;

export const collections = {
	docs: defineCollection({ loader: docsLoader(), schema: docsSchema() }),
	// UI strings: Starlight's own, and those of our components and home page. See src/i18n/locales.mjs.
	i18n: defineCollection({ loader: i18nLoader(), schema: i18nSchema({ extend: z.object(ownStrings) }) }),
};
