/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Pause scene
*/

/* File created the 26/04/2018 at 14:15:02 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "rpg.h"

void calc_go_to_old_camera(sf_engine_t *engine, gameobject_t *go)
{
	sf_transform_t *tr = get_component(go, TRANSFORM);
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);
	sfVector2f curr_pos = {0, 0};
	sfVector2f center = engine->pause.scene_before_pause->camera->position;
	sfVector2f size = engine->pause.scene_before_pause->camera->view_size;

	if (tr != NULL) {
		curr_pos = (sfVector2f){tr->position.x, tr->position.y};
		tr->position.x = center.x - size.x / 2 + curr_pos.x;
		tr->position.y = center.y - size.y / 2 + curr_pos.y;
	}
	if (anim != NULL) {
		curr_pos = sfSprite_getPosition(anim->sprite);
		curr_pos.x += center.x - size.x / 2;
		curr_pos.y += center.y - size.y / 2;
		sfSprite_setPosition(anim->sprite, curr_pos);
	}
}

int load_pause_scene(sf_engine_t *engine, UNUSED void *data)
{
	gameobject_t *border = NULL;

	if (engine == NULL)
		return (84);
	border = create_prefab_image(engine, SPRITE_BORDER, 0);
	calc_go_to_old_camera(engine, border);
	return (0);
}

int loop_pause_scene(sf_engine_t *engine, UNUSED void *data)
{
	sfEvent evt;

	if (engine == NULL)
		return (84);
	while (sfRenderWindow_pollEvent(engine->window, &evt)) {
		if (evt.type == sfEvtClosed)
			sfRenderWindow_close(engine->window);
		if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyEscape)
			quit_pause(engine);
	}
	return (0);
}

int unload_pause_scene(sf_engine_t *engine, UNUSED void *data)
{
	if (engine == NULL)
		return (84);
	reset_scene(engine->current_scene);
	return (0);
}

sf_scene_t *create_pause_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = create_scene("pause");

	if (new_scene == NULL || engine == NULL)
		return (NULL);
	new_scene->load = &load_pause_scene;
	new_scene->loop = &loop_pause_scene;
	new_scene->unload = &unload_pause_scene;
	engine->add_scene(engine, new_scene);
	return (new_scene);
}