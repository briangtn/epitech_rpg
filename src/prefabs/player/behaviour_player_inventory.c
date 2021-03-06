/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** inventory test
*/

#include "my_sfml.h"
#include "my.h"
#include "prefabs.h"
#include "rpg.h"
#include "ui.h"

void move_window_mouse(sf_inventory_t *inv)
{
	static bool is_hold = false;
	static sfVector2i off = {0, 0};
	static sfVector2i last = {0, 0};
	sfVector2i pos = sfMouse_getPositionRenderWindow(inv->engine->window);
	sfIntRect box = {inv->screen_pos.x, inv->screen_pos.y, 32, 32};

	if (!sfMouse_isButtonPressed(sfMouseLeft)) {
		if (box.left >= WINDOW_SIZE_X || box.top >= WINDOW_SIZE_Y || \
box.left < 0 || box.top < 0)
			inv->screen_pos = last;
		is_hold = false;
		return;
	}
	if (pos.x >= box.left && pos.y >= box.top && pos.x <= box.left + \
box.width && pos.y <= box.top + box.height && !is_hold) {
		last = (sfVector2i){box.left, box.top};
		off = (sfVector2i){box.left - pos.x, box.top - pos.y};
		is_hold = true;
	}
	if (is_hold)
		inv->screen_pos = (sfVector2i){pos.x + off.x, pos.y + off.y};
}

static void mouse_item_select(sf_inventory_t *inv)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(inv->engine->window);
	sfIntRect box = {inv->screen_pos.x, inv->screen_pos.y, 60, 60};

	if (!sfMouse_isButtonPressed(sfMouseLeft))
		return;
	for (int i = 0; i < INV_SIZE; i++) {
		box.left = inv->screen_pos.x + 55 + (96 * (i % 5));
		box.top = inv->screen_pos.y + 60 + (90 * (i / 5));
		if (inv->backpack[i].use == NULL)
			continue;
		if (box.left <= pos.x && pos.x <= box.left + box.width && \
box.top <= pos.y && pos.y <= box.top + box.height) {
			inv->backpack[i].use(&(inv->backpack[i]), inv);
			return;
		}
	}
}

static void render_items(sf_inventory_t *self)
{
	sfVector2i pos = self->screen_pos;

	for (int i = 0; i < INV_SIZE; i++) {
		pos.x = self->screen_pos.x + 55 + (96 * (i % 5));
		pos.y = self->screen_pos.y + 60 + (90 * (i / 5));
		if (self->bp_sprite[i])
			sfSprite_setPosition(self->bp_sprite[i], \
sfRenderWindow_mapPixelToCoords(self->engine->window, pos, \
sfRenderWindow_getView(self->engine->window)));
	}
}

static void render_skills(sf_inventory_t *self)
{
	move_loadbar(self->prgbar_atk, \
sfRenderWindow_mapPixelToCoords(self->engine->window, \
(sfVector2i){self->screen_pos.x + 180, self->screen_pos.y + 275}, \
sfRenderWindow_getView(self->engine->window)));
	move_loadbar(self->prgbar_def, \
sfRenderWindow_mapPixelToCoords(self->engine->window, \
(sfVector2i){self->screen_pos.x + 180, self->screen_pos.y + 350}, \
sfRenderWindow_getView(self->engine->window)));
	move_loadbar(self->prgbar_dex, \
sfRenderWindow_mapPixelToCoords(self->engine->window, \
(sfVector2i){self->screen_pos.x + 400, self->screen_pos.y + 275}, \
sfRenderWindow_getView(self->engine->window)));
	move_loadbar(self->prgbar_int, \
sfRenderWindow_mapPixelToCoords(self->engine->window, \
(sfVector2i){self->screen_pos.x + 400, self->screen_pos.y + 350}, \
sfRenderWindow_getView(self->engine->window)));
	move_loadbar(self->prgbar_exp, \
sfRenderWindow_mapPixelToCoords(self->engine->window, \
(sfVector2i){self->screen_pos.x + 50, self->screen_pos.y + 400}, \
sfRenderWindow_getView(self->engine->window)));
}

int player_inventory(gameobject_t *player, UNUSED int delta_time)
{
	static bool was_pressed = false;
	sf_inventory_t *inv = get_component(player, INVENTORY);

	if (player == NULL || inv == NULL) {
		my_puterror("Error in player inventory, component not found\n");
		return (84);
	}
	if (was_pressed && !sfKeyboard_isKeyPressed(sfKeyI))
		inv->toggle(inv);
	was_pressed = sfKeyboard_isKeyPressed(sfKeyI);
	if (inv->is_opened) {
		move_window_mouse(inv);
		mouse_item_select(inv);
		sfSprite_setPosition(inv->sprite, \
sfRenderWindow_mapPixelToCoords(inv->engine->window, inv->screen_pos, \
sfRenderWindow_getView(inv->engine->window)));
		render_items(inv);
		render_skills(inv);
	}
	return (0);
}