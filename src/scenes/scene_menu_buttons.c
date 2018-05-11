/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Button on menu
*/

/* File created the 25/04/2018 at 11:52:50 by julian.frabel@epitech.eu */

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"
#include "utils.h"

void launch_game(sf_button_t *button)
{
	sf_engine_t *engine = button->engine;
	parser_to_game_t *ptg = engine->data;

	if (ptg == NULL)
		return;
	ptg->active_scene = 1;
	engine->change_scene(engine, "intro", ptg);
}

void launch_fight(sf_button_t *button)
{
	sf_engine_t *engine = button->engine;

	run_fight(1, engine, NULL);
}

void quit_app(sf_button_t *button)
{
	sfRenderWindow_close(button->engine->window);
}

void goto_menu(sf_button_t *button)
{
	sf_engine_t *engine = button->engine;

	quit_pause(engine);
	engine->change_scene(engine, "menu", engine->data);
}

void end_menu(sf_button_t *button)
{
	sf_engine_t *engine = button->engine;

	engine->change_scene(engine, "menu", engine->data);
}