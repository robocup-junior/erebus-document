// Lets a heading keep a fixed id: "## Règles {#rules}" gets the id "rules" instead of "regles".
// Translated pages keep the ids of the English headings, so links to #anchors work in every
// language. In MDX, braces start an expression, so write "\{#rules\}" there.
const marker = /\s*\{#([\w-]+)\}\s*$/;

export function headingIds() {
	return {
		name: 'heading-ids',
		heading(node) {
			const last = node.children.at(-1);
			const match = last?.type === 'text' ? last.value.match(marker) : null;
			if (!match) return;
			const text = last.value.slice(0, match.index);
			const children = [...node.children.slice(0, -1), ...(text ? [{ ...last, value: text }] : [])];
			return { ...node, children, data: { ...node.data, hProperties: { ...node.data?.hProperties, id: match[1] } } };
		},
	};
}
