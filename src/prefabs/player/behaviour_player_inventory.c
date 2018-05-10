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
	static sfVector2i offset = {0, 0};
	sfVector2i m_pos = sfMouse_getPositionRenderWindow(inv->engine->window);
	sfIntRect move_box = {inv->screen_pos.x, inv->screen_pos.y, 32, 32};

	if (!sfMouse_isButtonPressed(sfMouseLeft)) {
		is_hold = false;
		return;
	}
	if (m_pos.x >= move_box.left && m_pos.y >= move_box.top && \
m_pos.x <= move_box.left + move_box.width && \
m_pos.y <= move_box.top + move_box.height && !is_hold) {
		offset.x = move_box.left - m_pos.x;
		offset.y = move_box.top - m_pos.y;
		is_hold = true;
	}
	if (is_hold) {
		inv->screen_pos.x = m_pos.x + offset.x;
		inv->screen_pos.y = m_pos.y + offset.y;
	}
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