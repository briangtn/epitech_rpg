/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Menu scene
*/

/* File created the 25/04/2018 at 11:50:57 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "rpg.h"

void setup_buttons(sf_engine_t *engine)
{
	gameobject_t *button_start = NULL;
	gameobject_t *button_help = NULL;
	gameobject_t *button_quit = NULL;

	create_prefab_image(engine, BACKGROUND_WORLDMAP, -1);
	button_start = create_prefab_button(engine, "start button", BUTTON_GAME\
, (sfIntRect){WINDOW_SIZE_X - 350, WINDOW_SIZE_Y / 2 - 225, 300, 150});
	((sf_button_t *)get_component(button_start, BUTTON))->on_clicked = \
&launch_game;
	button_help = create_prefab_button(engine, "help button", BUTTON_HELP\
, (sfIntRect){WINDOW_SIZE_X - 350, WINDOW_SIZE_Y / 2 - 75, 300, 150});
	((sf_button_t *)get_component(button_help, BUTTON))->on_clicked = \
&launch_help;
	button_quit = create_prefab_button(engine, "quit button", BUTTON_QUIT, \
(sfIntRect){WINDOW_SIZE_X - 350, WINDOW_SIZE_Y / 2 + 75, 300, 150});
	((sf_button_t *)get_component(button_quit, BUTTON))->on_clicked = \
&quit_app;
}

int load_menu_scene(sf_engine_t *engine, parser_to_game_t *data)
{
	if (engine == NULL)
		return (84);
	setup_buttons(engine);
	data->player_start_pos = (sf_vector_3d_t){736, 352, 0};
	return (0);
}

int loop_menu_scene(sf_engine_t *engine, UNUSED void *data)
{
	sfEvent event;

	if (engine == NULL)
		return (84);
	while (sfRenderWindow_pollEvent(engine->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(engine->window);
	}
	return (0);
}

int unload_menu_scene(sf_engine_t *engine, UNUSED void *data)
{
	reset_scene(engine->current_scene);
	return (0);
}

sf_scene_t *create_menu_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = create_scene("menu");

	if (new_scene == NULL || engine == NULL)
		return (NULL);
	new_scene->load = &load_menu_scene;
	new_scene->loop = &loop_menu_scene;
	new_scene->unload = &unload_menu_scene;
	engine->add_scene(engine, new_scene);
	return (new_scene);
}