/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Rpg enemy component
*/

#include <stdlib.h>
#include "my.h"
#include "my_sfml.h"
#include "rpg.h"
#include "utils.h"

static void destroy_player_comp(sf_player_t *comp)
{
	if (comp == NULL)
		return;
	free(comp);
}

void destroy_player(sf_engine_t *engine, gameobject_t *go)
{
	sf_player_t *player = get_component(go, FPLAYER);
	sf_loadbar_t *loadbar = NULL;

	if (player == NULL)
		return;
	loadbar = get_component(player->life_bar_go, LOADBAR);
	if (loadbar == NULL)
		return;
	engine->destroy_gameobject(engine, loadbar->back_go);
	engine->destroy_gameobject(engine, player->life_bar_go);
	engine->destroy_gameobject(engine, go);
}

int update_player(void *datas, UNUSED int delta_time)
{
	gameobject_t *go = (gameobject_t *)datas;
	sf_player_t *player = get_component(go, FPLAYER);
	sf_loadbar_t *life_bar = NULL;
	sf_text_t *mana_text = NULL;
	char *mana_content = "";

	if (player == NULL)
		return (84);
	life_bar = get_component(player->life_bar_go, LOADBAR);
	mana_text = get_component(player->mana_text_go, TEXT);
	if (life_bar == NULL || mana_text == NULL)
		return (84);
	life_bar->current_value = player->datas->life;
	mana_content = my_int_to_str(player->datas->mana);
	my_strdupcat(&mana_content, "/");
	my_strdupcat(&mana_content, my_int_to_str(player->datas->max_mana));
	sfText_setString(mana_text->text, mana_content);
	return (0);
}

sf_player_t *create_player_comp(gameobject_t *parent)
{
	sf_player_t *player = malloc(sizeof(*player));

	if (player == NULL)
		return (NULL);
	player->parent = parent;
	player->destroy = &destroy_player_comp;
	player->fight = NULL;
	player->datas = NULL;
	player->life_bar_go = NULL;
	player->mana_text_go = NULL;
	return (player);
}