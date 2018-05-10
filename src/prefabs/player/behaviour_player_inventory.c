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

int player_inventory(gameobject_t *player, UNUSED int delta_time)
{
	sf_inventory_t *inv = get_component(player, INVENTORY);
	sfVector2i screen_pos = {200, 350};

	if (player == NULL || inv == NULL) {
		my_puterror("Error in player inventory, component not found\n");
		return (84);
	}
	if (sfKeyboard_isKeyPressed(sfKeyI))
		inv->toggle(inv);
	if (inv->is_opened)
		sfSprite_setPosition(inv->sprite, \
sfRenderWindow_mapPixelToCoords(inv->engine->window, screen_pos, \
sfRenderWindow_getView(inv->engine->window)));
	return (0);
}