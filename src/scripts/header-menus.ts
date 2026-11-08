// Closes the header menus when clicking elsewhere or pressing Escape. Imported by the menus, so it
// runs once per page.
const menus = () => document.querySelectorAll<HTMLDetailsElement>('details.header-menu');

document.addEventListener('click', (event) => {
	for (const menu of menus()) if (!menu.contains(event.target as Node)) menu.open = false;
});

document.addEventListener('keydown', (event) => {
	if (event.key === 'Escape') for (const menu of menus()) menu.open = false;
});
