/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Load bar prefab
*/

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

static int setup_components(sf_engine_t *engine, gameobject_t *go, \
float max, sfFloatRect rect)
{
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);
	sf_loadbar_t *loadbar = get_component(go, LOADBAR);

	if (anim == NULL || loadbar == NULL)
		return (84);
	anim->set_sprite(anim, engine->get_sprite(engine, WHITE_SPRITE));
	sfSprite_setPosition(anim->sprite, (sfVector2f){rect.left, rect.top});
	loadbar->max_value = max;
	loadbar->current_value = max;
	loadbar->sizes = (sf_vector_2d_t){rect.width, rect.height};
	loadbar->back_go = create_prefab_loadbar_back(engine, rect, \
loadbar->back_color);
	loadbar->engine = engine;
	register_animation(engine, anim, UI_IMAGE);
	return (0);
}

static int add_components(gameobject_t *enemy)
{
	if (enemy->add_component(enemy, ANIMATION_2D) == NULL) {
		my_puterror("[ERROR]enemy: Could not add animation!\n");
		return (84);
	}
	if (add_custom_component(enemy, (void *(*)(gameobject_t *))\
&create_loadbar_comp, LOADBAR) == NULL)
		return (84);
	return (0);
}

gameobject_t *create_prefab_loadbar(sf_engine_t *engine, sfFloatRect rect, \
float max)
{
	gameobject_t *new_go = create_gameobject("loadbar");

	if (engine == NULL || new_go == NULL)
		return (NULL);
	if (add_components(new_go) == 84) {
		new_go->destroy(new_go);
	}
	if (setup_components(engine, new_go, max, rect) == 84) {
		new_go->destroy(new_go);
		return (NULL);
	}
	engine->add_update(engine, new_go, &loadbar_update);
	return (new_go);
}