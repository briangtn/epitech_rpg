/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Player creation and destruction
*/

/* File created the 04/04/2018 at 14:10:22 by julian.frabel@epitech.eu */

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

gameobject_t *create_prefab_player(UNUSED sf_engine_t *engine)
{
	gameobject_t *new_player = create_gameobject("player");

	if (new_player == NULL)
		return (NULL);
	new_player->destroy = &destroy_prefab_player;
	return (new_player);
}

void destroy_prefab_player(gameobject_t *player)
{
	destroy_gameobject(player);
}