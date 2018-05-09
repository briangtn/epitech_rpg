/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** end scene
*/

/* File created the 26/04/2018 at 14:15:02 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "rpg.h"

int load_end_scene(sf_engine_t *engine, UNUSED void *data)
{
	gameobject_t *menu = NULL;
	gameobject_t *quit = NULL;

	if (engine == NULL)
		return (84);
	create_prefab_image(engine, BACKGROUND_END, 0);
	menu = create_prefab_button(engine, "menu button", \
BUTTON_MENU, (sfIntRect){WINDOW_SIZE_X - 200, WINDOW_SIZE_Y - 100, 200, 100});
	((sf_button_t *)get_component(menu, BUTTON))->on_clicked = &end_menu;
	quit = create_prefab_button(engine, "quit button", \
BUTTON_QUIT, (sfIntRect){WINDOW_SIZE_X - 400, WINDOW_SIZE_Y - 100, 200, 100});
	((sf_button_t *)get_component(quit, BUTTON))->on_clicked = &quit_app;
	return (0);
}

int loop_end_scene(sf_engine_t *engine, UNUSED void *data)
{
	sfEvent evt;

	if (engine == NULL)
		return (84);
	while (sfRenderWindow_pollEvent(engine->window, &evt)) {
		if (evt.type == sfEvtClosed) {
			sfRenderWindow_close(engine->window);
			return (0);
		}
		if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyEscape)
			return (engine->change_scene(engine, "menu", \
engine->data));
	}
	return (0);
}

int unload_end_scene(sf_engine_t *engine, UNUSED void *data)
{
	if (engine == NULL)
		return (84);
	reset_scene(engine->current_scene);
	return (0);
}

sf_scene_t *create_end_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = create_scene("end");

	if (new_scene == NULL || engine == NULL)
		return (NULL);
	new_scene->load = &load_end_scene;
	new_scene->loop = &loop_end_scene;
	new_scene->unload = &unload_end_scene;
	engine->add_scene(engine, new_scene);
	return (new_scene);
}