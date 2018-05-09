/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** intro scene
*/

/* File created the 09/05/2018 at 21:30:22 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "rpg.h"

int load_intro_scene(sf_engine_t *engine, UNUSED void *data)
{
	if (engine == NULL)
		return (84);
	create_prefab_image(engine, BACKGROUND_INTRO, 0);
	return (0);
}

int space_pressed(sf_engine_t *engine, void *data)
{
	gameobject_t *background = engine->get_gameobject(engine, "image");
	sf_animation_2d_t *anim = get_component(background, ANIMATION_2D);
	sfVector2f pos = sfSprite_getPosition(anim->sprite);

	if (background == NULL || pos.x <= -1600 * 3)
		return (engine->change_scene(engine, "game", data));
	else {
		pos.x -= 1600;
		sfSprite_setPosition(anim->sprite, pos);
		return (0);
	}
}

int loop_intro_scene(sf_engine_t *engine, void *data)
{
	sfEvent evt;

	if (engine == NULL)
		return (84);
	while (sfRenderWindow_pollEvent(engine->window, &evt)) {
		if (evt.type == sfEvtClosed) {
			sfRenderWindow_close(engine->window);
			return (0);
		}
		if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeySpace)
			return (space_pressed(engine, data));
	}
	return (0);
}

int unload_intro_scene(sf_engine_t *engine, UNUSED void *data)
{
	if (engine == NULL)
		return (84);
	reset_scene(engine->current_scene);
	return (0);
}

sf_scene_t *create_intro_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = create_scene("intro");

	if (new_scene == NULL || engine == NULL)
		return (NULL);
	new_scene->load = &load_intro_scene;
	new_scene->loop = &loop_intro_scene;
	new_scene->unload = &unload_intro_scene;
	engine->add_scene(engine, new_scene);
	return (new_scene);
}