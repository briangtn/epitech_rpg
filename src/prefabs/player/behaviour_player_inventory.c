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

void move_window_mouse(sf_inventory_t *inv)
{
	static bool is_hold = false;
	static sfVector2i off = {0, 0};
	static sfVector2i last = {0, 0};
	sfVector2i pos = sfMouse_getPositionRenderWindow(inv->engine->window);
	sfIntRect box = {inv->screen_pos.x, inv->screen_pos.y, 32, 32};

	if (!sfMouse_isButtonPressed(sfMouseLeft)) {
		if (box.left >= WINDOW_SIZE_X || box.top >= WINDOW_SIZE_Y)
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

int player_inventory(gameobject_t *player, UNUSED int delta_time)
{
	sf_inventory_t *inv = get_component(player, INVENTORY);

	if (player == NULL || inv == NULL) {
		my_puterror("Error in player inventory, component not found\n");
		return (84);
	}
	if (sfKeyboard_isKeyPressed(sfKeyI))
		inv->toggle(inv);
	if (inv->is_opened) {
		move_window_mouse(inv);
		sfSprite_setPosition(inv->sprite, \
sfRenderWindow_mapPixelToCoords(inv->engine->window, inv->screen_pos, \
sfRenderWindow_getView(inv->engine->window)));
	}
	return (0);
}