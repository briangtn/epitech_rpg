/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Fighting backgound creation and destruction
*/

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

static int fenemy_animation_update(sf_animation_2d_t *anim,\
UNUSED int elapsed_milliseconds)
{
	sf_transform_t *transform = get_component(anim->parent, TRANSFORM);

	if (anim == NULL || transform == NULL)
		return (84);
	sfSprite_setPosition(anim->sprite,\
(sfVector2f){transform->position.x, transform->position.y});
	return (0);
}

static int setup_components(sf_engine_t *engine, gameobject_t *enemy,\
fight_enemy_t *fenemy, fight_t *fight)
{
	sf_animation_2d_t *anim = get_component(enemy, ANIMATION_2D);
	sf_transform_t *transform = get_component(enemy, TRANSFORM);
	sf_enemy_t *enemy_comp = get_component(enemy, FENEMY);

	if (anim == NULL || transform == NULL || enemy_comp == NULL)
		return (84);
	anim->update = fenemy_animation_update;
	anim->set_sprite(anim, engine->get_sprite(engine,\
fenemy->sprite_path));
	register_animation(engine, anim, GAME);
	enemy_comp->datas = fenemy;
	enemy_comp->fight = fight;
	return (0);
}

static int add_components(gameobject_t *enemy)
{
	if (enemy->add_component(enemy, ANIMATION_2D) == NULL) {
		my_puterror("[ERROR]enemy: Could not add animation!\n");
		return (84);
	}
	if (enemy->add_component(enemy, TRANSFORM) == NULL) {
		my_puterror("[ERROR]enemy: Could not add tranform\n");
		return (84);
	}
	if (add_custom_component(enemy, (void *(*)(gameobject_t *))\
&create_enemy_comp, FENEMY) == NULL)
		return (84);
	return (0);
}

static void after_init(gameobject_t *go, sf_engine_t *engine,\
fight_enemy_t *enemy, int pos_x)
{
	const int offset = (100 - FIGHT_ELEMENT_SIZE) / 2;
	sf_transform_t *tr = NULL;
	sf_enemy_t *enemy_comp = NULL;
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);
	sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(anim->sprite);
	sfFloatRect rect = {0, 0, 0, 0};

	tr = get_component(go, TRANSFORM);
	enemy_comp = get_component(go, FENEMY);
	if (tr == NULL || enemy_comp == NULL)
		return;
	tr->position =\
(sf_vector_3d_t){pos_x, 300, 0};
	rect = (sfFloatRect){tr->position.x - offset, tr->position.y - 15,\
sprite_bounds.width, 10};
	enemy_comp->life_bar_go = create_prefab_loadbar(engine, rect,\
enemy->life);
}

gameobject_t *create_prefab_fenemy(sf_engine_t *engine, fight_enemy_t *enemy,\
int pos, fight_t *fight)
{
	gameobject_t *new_enemy = create_gameobject("fight_enemy");
	int enemy_count = my_sf_list_size(fight->ennemies);

	if (engine == NULL || new_enemy == NULL)
		return (NULL);
	if (add_components(new_enemy) == 84) {
		new_enemy->destroy(new_enemy);
		my_puterror("[ERROR]enemy: Could not add components!\n");
		return (NULL);
	}
	if (setup_components(engine, new_enemy, enemy, fight) == 84) {
		new_enemy->destroy(new_enemy);
		my_puterror("[ERROR]enemy: Could not setup components!\n");
		return (NULL);
	}
	after_init(new_enemy, engine, enemy,\
get_enemy_posx(engine, enemy_count, pos));
	engine->add_update(engine, new_enemy, update_enemy);
	return (new_enemy);
}