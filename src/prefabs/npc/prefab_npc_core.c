/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Core of npc
*/

/* File created the 19/04/2018 at 13:27:02 by julian.frabel@epitech.eu */

/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Player creation and destruction
*/

/* File created the 04/04/2018 at 14:10:22 by julian.frabel@epitech.eu */

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

static void setup_animation(sf_engine_t *engine, sf_animation_2d_t *anim)
{
	anim->max_rect = (sfIntRect){0, 0, NPC_NB_FRAME_ANIMATION * \
TILE_SIZE, TILE_SIZE};
	anim->play = 0;
	anim->set_sprite(anim, engine->get_sprite(engine, NPC_SPRITE_SHEET));
	anim->speed = NPC_ANIMATION_SPEED;
	anim->view_rect = (sfIntRect){0, 0, TILE_SIZE, TILE_SIZE};
	sfSprite_setTextureRect(anim->sprite, anim->view_rect);
}

static int setup_components(sf_engine_t *engine, gameobject_t *new_npc)
{
	sf_animation_2d_t *anim = get_component(new_npc, ANIMATION_2D);
	sf_interaction_t *inte = get_component(new_npc, INTERACTION);
	sf_npc_t *npc = get_component(new_npc, NPC);

	setup_animation(engine, anim);
	inte->engine = engine;
	inte->interaction = &npc_interaction;
	npc->speak->set_text(npc->speak, "test text");
	npc->speak->set_font(npc->speak, FONT_SPEAK);
	register_animation(engine, anim, GAME);
	engine->add_gameobject(engine, new_npc);
	engine->add_physic_object(engine, new_npc);
	return (0);
}

static int add_components(gameobject_t *new_npc)
{
	if (new_npc->add_component(new_npc, ANIMATION_2D) == NULL)
		return (84);
	if (new_npc->add_component(new_npc, TRANSFORM) == NULL)
		return (84);
	if (new_npc->add_component(new_npc, RIGIDBODY_2D) == NULL)
		return (84);
	if (new_npc->add_component(new_npc, COLLIDER_2D) == NULL)
		return (84);
	if (new_npc->add_custom_component(new_npc, (void *(*)(gameobject_t *))\
&create_interaction, INTERACTION) == NULL)
		return (84);
	if (new_npc->add_custom_component(new_npc, (void *(*)(gameobject_t *))\
&create_npc_comp, NPC) == NULL)
		return (84);
	return (0);
}

gameobject_t *create_prefab_npc(sf_engine_t *engine)
{
	gameobject_t *new_npc = create_gameobject("npc");

	if (new_npc == NULL)
		return (NULL);
	if (add_components(new_npc) == 84) {
		new_npc->destroy(new_npc);
		my_puterror("[ERROR]Player: could not add components!\n");
		return (NULL);
	}
	if (setup_components(engine, new_npc) == 84) {
		new_npc->destroy(new_npc);
		my_puterror("[ERROR]Player: could not setup components!\n");
		return (NULL);
	}
	return (new_npc);
}