/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Fighting backgound creation and destruction
*/

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

static int fplayer_animation_update(sf_animation_2d_t *anim,\
UNUSED int elapsed_milliseconds)
{
	sf_transform_t *transform = get_component(anim->parent, TRANSFORM);

	if (anim == NULL || transform == NULL)
		return (84);
	sfSprite_setPosition(anim->sprite,\
(sfVector2f){transform->position.x, transform->position.y});
	return (0);
}

static int setup_components(sf_engine_t *engine, gameobject_t *player,\
fight_t *fight)
{
	sf_animation_2d_t *anim = get_component(player, ANIMATION_2D);
	sf_transform_t *transform = get_component(player, TRANSFORM);
	sf_player_t *player_comp = get_component(player, FPLAYER);

	if (anim == NULL || transform == NULL || player_comp == NULL)
		return (84);
	anim->update = fplayer_animation_update;
	anim->set_sprite(anim, engine->get_sprite(engine,\
fight->player->sprite_path));
	register_animation(engine, anim, GAME);
	scale_elem_to_size(anim->sprite);
	transform->position =\
(sf_vector_3d_t){fight->player->position.x, fight->player->position.y, 0};
	player_comp->datas = fight->player;
	player_comp->fight = fight;
	player_comp->mana_text_go = create_prefab_mana_text(engine,\
fight->player);
	return (0);
}

static void after_init(gameobject_t *go, sf_engine_t *engine,\
fight_player_t *player)
{
	const int offset = (100 - FIGHT_ELEMENT_SIZE) / 2;
	sf_transform_t *tr = NULL;
	sf_player_t *player_comp = NULL;
	sfFloatRect rect = {0, 0, 0, 0};

	tr = get_component(go, TRANSFORM);
	player_comp = get_component(go, FPLAYER);
	if (tr == NULL || player_comp == NULL)
		return;
	rect = (sfFloatRect){tr->position.x - offset, tr->position.y + 70,\
100, 10};
	player_comp->life_bar_go = create_prefab_loadbar(engine, rect,\
player->life);
}

static int add_components(gameobject_t *player)
{
	if (player->add_component(player, ANIMATION_2D) == NULL) {
		my_puterror("[ERROR]Player: Could not add animation!\n");
		return (84);
	}
	if (player->add_component(player, TRANSFORM) == NULL) {
		my_puterror("[ERROR]Player: Could not add tranform\n");
		return (84);
	}
	if (add_custom_component(player, (void *(*)(gameobject_t *))\
&create_player_comp, FPLAYER) == NULL)
		return (84);
	return (0);
}

gameobject_t *create_prefab_fplayer(sf_engine_t *engine, fight_t *fight)
{
	gameobject_t *new_player = create_gameobject("fight_player");

	if (new_player == NULL)
		return (NULL);
	if (add_components(new_player) == 84) {
		new_player->destroy(new_player);
		my_puterror("[ERROR]Player: Could not add components!\n");
		return (NULL);
	}
	if (setup_components(engine, new_player, fight) == 84) {
		new_player->destroy(new_player);
		my_puterror("[ERROR]Player: Could not setup components!\n");
		return (NULL);
	}
	after_init(new_player, engine, fight->player);
	engine->add_update(engine, new_player, update_player);
	return (new_player);
}