/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Fight callback
*/

/* File created the 11/05/2018 at 10:37:34 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "rpg.h"

void give_xp(sf_engine_t *engine, float amount)
{
	gameobject_t *player = engine->get_gameobject(engine, "player");
	sf_inventory_t *inv = get_component(player, INVENTORY);
	int level_up = 0;
	sf_speak_t *speak = NULL;

	if (inv != NULL)
		level_up = inv->add_exp(inv, amount * inv->s_int);
	if (level_up) {
		speak = create_speak_component(NULL);
		if (speak != NULL) {
			speak->set_info(speak, LEVEL_UP_MESSAGE, FACE_HERO);
			speak->set_font(speak, FONT_SPEAK);
			speak->show(speak, engine);
		}
	}
}

int end_fight_win(sf_engine_t *engine, gameobject_t *enemy, fight_t *fight)
{
	engine->destroy_gameobject(engine, enemy);
	give_xp(engine, fight->xp_given);
	return (0);
}

int end_fight_lose(sf_engine_t *engine, UNUSED gameobject_t *enemy, \
parser_to_game_t *ptg, UNUSED fight_t *fight)
{
	sf_speak_t *dead = create_speak_component(NULL);

	ptg->active_scene = 1;
	ptg->player_start_pos = (sf_vector_3d_t){23 * TILE_SIZE, \
11 * TILE_SIZE, 0};
	engine->change_scene(engine, "game", ptg);
	update_selected_scene(engine);
	engine->current_scene->camera->update(engine->current_scene->camera, 0);
	dead->set_info(dead, DEATH_MESSAGE, FACE_HERO);
	dead->set_font(dead, FONT_SPEAK);
	dead->show(dead, engine);
	return (0);
}

int end_callback_fight(fight_t *fight, void *datas,\
bool win, sf_engine_t *engine)
{
	parser_to_game_t *ptg = engine->data;

	if (datas == NULL || ptg == NULL)
		return (84);
	ptg->come_from_fight = true;
	engine->change_scene(engine, "game", ptg);
	update_selected_scene(engine);
	if (win) {
		end_fight_win(engine, datas, fight);
	} else {
		end_fight_lose(engine, datas, ptg, fight);
	}
	return (0);
}