// Draws the diagrams of the documentation as SVG files, next to the pages that use them:
//
//   node scripts/diagrams.mjs
//
// The diagrams use numbers and symbols rather than words, so that every language can show
// the same file.
import { writeFileSync } from 'node:fs';
import { join } from 'node:path';

const docs = 'src/content/docs/docs';
const ink = '#1d2327';
const muted = '#6b7780';
const accent = '#1f8ba3';
const font = `font-family="Inter, system-ui, sans-serif"`;

function svg(width, height, body) {
	return `<svg xmlns="http://www.w3.org/2000/svg" width="${width}" height="${height}" viewBox="0 0 ${width} ${height}">
<rect width="${width}" height="${height}" fill="#ffffff"/>
${body}
</svg>
`;
}

function save(path, content) {
	writeFileSync(join(docs, path), content);
	console.log(join(docs, path));
}

const arrowHead = (id, color) =>
	`<marker id="${id}" viewBox="0 0 10 10" refX="8" refY="5" markerWidth="7" markerHeight="7" orient="auto-start-reverse"><path d="M0 0 L10 5 L0 10 z" fill="${color}"/></marker>`;

/** A robot seen from above: a round body, two wheels and an arrow to its front. */
function robot(cx, cy, r, { left = 0, right = 0 } = {}) {
	const wheel = (x, speed) => {
		const w = r * 0.28;
		const h = r * 0.9;
		let arrow = '';
		if (speed) {
			const len = 0.55 * r * Math.abs(speed);
			const y1 = cy + (speed > 0 ? len : -len);
			const y2 = cy - (speed > 0 ? len : -len);
			const ax = x + (x < cx ? -w * 1.6 : w * 1.6);
			arrow = `<line x1="${ax}" y1="${y1}" x2="${ax}" y2="${y2}" stroke="${accent}" stroke-width="3" marker-end="url(#a)"/>`;
		}
		return `<rect x="${x - w / 2}" y="${cy - h / 2}" width="${w}" height="${h}" rx="3" fill="${ink}"/>${arrow}`;
	};
	return `<circle cx="${cx}" cy="${cy}" r="${r}" fill="#eef3f5" stroke="${ink}" stroke-width="2"/>
<path d="M${cx} ${cy - r * 0.75} L${cx - r * 0.18} ${cy - r * 0.45} L${cx + r * 0.18} ${cy - r * 0.45} z" fill="#3aa655"/>
${wheel(cx - r, left)}${wheel(cx + r, right)}`;
}

// Movement: how the two wheel speeds move the robot.
{
	const cases = [
		{ left: 1, right: 1, path: 'forward' },
		{ left: -1, right: -1, path: 'backward' },
		{ left: -1, right: 1, path: 'spinLeft' },
		{ left: 1, right: -1, path: 'spinRight' },
		{ left: 1, right: 0.4, path: 'curveRight' },
	];
	const cell = 170;
	let body = `<defs>${arrowHead('a', accent)}${arrowHead('m', muted)}</defs>`;
	cases.forEach((c, i) => {
		const cx = cell * i + cell / 2;
		const cy = 110;
		body += robot(cx, cy, 34, c);
		// The movement of the robot, in grey.
		const p = {
			forward: `<line x1="${cx}" y1="${cy - 50}" x2="${cx}" y2="${cy - 85}" stroke="${muted}" stroke-width="3" marker-end="url(#m)"/>`,
			backward: `<line x1="${cx}" y1="${cy + 50}" x2="${cx}" y2="${cy + 85}" stroke="${muted}" stroke-width="3" marker-end="url(#m)"/>`,
			spinLeft: `<path d="M${cx + 30} ${cy - 50} A58 58 0 0 0 ${cx - 30} ${cy - 50}" fill="none" stroke="${muted}" stroke-width="3" marker-end="url(#m)"/>`,
			spinRight: `<path d="M${cx - 30} ${cy - 50} A58 58 0 0 1 ${cx + 30} ${cy - 50}" fill="none" stroke="${muted}" stroke-width="3" marker-end="url(#m)"/>`,
			curveRight: `<path d="M${cx} ${cy - 50} Q${cx} ${cy - 85} ${cx + 40} ${cy - 88}" fill="none" stroke="${muted}" stroke-width="3" marker-end="url(#m)"/>`,
		}[c.path];
		body += p;
	});
	save('programming/movement/wheel-speeds.svg', svg(cell * cases.length, 220, body));
}

// LIDAR: the order of the 512 points of a layer, clockwise from the front.
{
	const cx = 200;
	const cy = 200;
	let body = `<defs>${arrowHead('a', accent)}</defs>`;
	for (let i = 0; i < 64; i++) {
		const angle = (i / 64) * 2 * Math.PI;
		const x = cx + Math.sin(angle) * 150;
		const y = cy - Math.cos(angle) * 150;
		body += `<line x1="${cx + Math.sin(angle) * 55}" y1="${cy - Math.cos(angle) * 55}" x2="${x}" y2="${y}" stroke="#c9dde3" stroke-width="1.5"/>`;
	}
	const labels = [
		[0, '0'],
		[0.25, '128'],
		[0.5, '256'],
		[0.75, '384'],
	];
	for (const [t, text] of labels) {
		const angle = t * 2 * Math.PI;
		const x = cx + Math.sin(angle) * 150;
		const y = cy - Math.cos(angle) * 150;
		body += `<line x1="${cx + Math.sin(angle) * 55}" y1="${cy - Math.cos(angle) * 55}" x2="${x}" y2="${y}" stroke="${accent}" stroke-width="3"/>`;
		body += `<circle cx="${x}" cy="${y}" r="5" fill="${accent}"/>`;
		body += `<text x="${cx + Math.sin(angle) * 178}" y="${cy - Math.cos(angle) * 178 + 7}" text-anchor="middle" font-size="20" font-weight="600" fill="${ink}" ${font}>${text}</text>`;
	}
	body += `<path d="M${cx + Math.sin(0.4) * 115} ${cy - Math.cos(0.4) * 115} A115 115 0 0 1 ${cx + Math.sin(1.2) * 115} ${cy - Math.cos(1.2) * 115}" fill="none" stroke="${accent}" stroke-width="3" marker-end="url(#a)"/>`;
	body += robot(cx, cy, 40);
	save('programming/sensors/lidar/lidar-order.svg', svg(400, 400, body));
}

// Gyro: the turning speed is positive when the robot turns to the left, negative to the right.
{
	let body = `<defs>${arrowHead('a', accent)}${arrowHead('m', muted)}</defs>`;
	const turn = (cx, sign) => {
		const cy = 160;
		const left = sign > 0;
		const colour = left ? accent : muted;
		body += robot(cx, cy, 50);
		body += left
			? `<path d="M${cx + 60} ${cy - 55} A82 82 0 0 0 ${cx - 60} ${cy - 55}" fill="none" stroke="${colour}" stroke-width="4" marker-end="url(#a)"/>`
			: `<path d="M${cx - 60} ${cy - 55} A82 82 0 0 1 ${cx + 60} ${cy - 55}" fill="none" stroke="${colour}" stroke-width="4" marker-end="url(#m)"/>`;
		body += `<text x="${cx}" y="${cy - 102}" text-anchor="middle" font-size="30" font-weight="700" fill="${colour}" ${font}>${left ? '+' : '−'}</text>`;
	};
	turn(150, 1);
	turn(410, -1);
	save('programming/sensors/imu/gyro-sign.svg', svg(560, 250, body));
}

// Exploring: where the elements of the tile in row r and column c go in the map matrix.
{
	const size = 64;
	const x0 = 110;
	const y0 = 70;
	const labels = ['4r', '4r+1', '4r+2', '4r+3', '4r+4'];
	const colLabels = ['4c', '4c+1', '4c+2', '4c+3', '4c+4'];
	let body = '';
	for (let row = 0; row < 5; row++) {
		for (let col = 0; col < 5; col++) {
			const north = row === 0;
			const west = col === 0;
			const floor = (row === 1 || row === 3) && (col === 1 || col === 3);
			const fill = north || west ? '#d9ecf1' : floor ? '#f6e7b8' : '#ffffff';
			body += `<rect x="${x0 + col * size}" y="${y0 + row * size}" width="${size}" height="${size}" fill="${fill}" stroke="#b8c4ca" stroke-width="1.5"/>`;
			const text = north || west ? '1' : floor ? '4' : '';
			if (text) body += `<text x="${x0 + col * size + size / 2}" y="${y0 + row * size + size / 2 + 8}" text-anchor="middle" font-size="22" font-family="JetBrains Mono, monospace" fill="${ink}">${text}</text>`;
		}
		body += `<text x="${x0 - 12}" y="${y0 + row * size + size / 2 + 6}" text-anchor="end" font-size="16" font-family="JetBrains Mono, monospace" fill="${muted}">${labels[row]}</text>`;
	}
	colLabels.forEach((text, col) => {
		body += `<text x="${x0 + col * size + size / 2}" y="${y0 - 14}" text-anchor="middle" font-size="16" font-family="JetBrains Mono, monospace" fill="${muted}">${text}</text>`;
	});
	// The tile itself, from its north-west corner to the next one.
	body += `<rect x="${x0}" y="${y0}" width="${size * 5}" height="${size * 5}" fill="none" stroke="${accent}" stroke-width="3"/>`;
	save('programming/exploring/tile-to-matrix.svg', svg(x0 + size * 5 + 40, y0 + size * 5 + 40, body));
}

// Wall tokens: the five parts of a cognitive target and the points where to read their colours.
{
	const cx = 210;
	const cy = 200;
	const R = 150;
	// Yellow, Blue, Red, Black and Green from the centre outwards, as in the rules.
	const colours = ['#f2d230', '#2f6fd6', '#d63a2f', '#1d1d1d', '#35a853'];
	let body = '';
	for (let i = 4; i >= 0; i--) body += `<circle cx="${cx}" cy="${cy}" r="${(R * (i + 1)) / 5}" fill="${colours[i]}"/>`;
	body += `<line x1="${cx}" y1="${cy}" x2="${cx + R}" y2="${cy}" stroke="#ffffff" stroke-width="2" stroke-dasharray="4 4"/>`;
	for (const t of [0, 0.3, 0.5, 0.7, 0.9]) {
		const x = cx + R * t;
		body += `<circle cx="${x}" cy="${cy}" r="7" fill="#ffffff" stroke="${ink}" stroke-width="2.5"/>`;
		body += `<line x1="${x}" y1="${cy + 12}" x2="${x}" y2="${cy + R + 22}" stroke="${muted}" stroke-width="1" stroke-dasharray="3 3"/>`;
		body += `<text x="${x}" y="${cy + R + 42}" text-anchor="middle" font-size="17" fill="${ink}" ${font}>${t}</text>`;
	}
	body += `<text x="${cx + R + 12}" y="${cy + R + 42}" font-size="17" font-style="italic" fill="${muted}" ${font}>× R</text>`;
	save('programming/wall-tokens/cognitive-target-sampling.svg', svg(440, 410, body));
}

console.log('done');
