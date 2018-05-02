/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Prefab for fight text
*/

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"
#include "utils.h"

static int text_update(void *data,\
UNUSED int elapsed_milliseconds)
{
	sf_text_t *text = (sf_text_t *)data;
	sf_transform_t *transform = get_component(text->parent, TRANSFORM);

	if (text == NULL || transform == NULL)
		return (84);
	sfText_setPosition(text->text,\
(sfVector2f){transform->position.x, transform->position.y});
	return (0);
}

static int setup_components(sf_engine_t *engine, gameobject_t *go,\
sf_vector_3d_t pos, attack_t *attack)
{
	sf_text_t *text = get_component(go, TEXT);
	sf_transform_t *transform = get_component(go, TRANSFORM);

	if (text == NULL || transform == NULL)
		return (84);
	text->font = sfFont_createFromFile("assets/fonts/crazy_krabs.otf");
	sfText_setCharacterSize(text->text, 30);
	sfText_setColor(text->text, sfGreen);
	sfText_setString(text->text, attack->name);
	sfText_setFont(text->text, text->font);
	transform->position = pos;
	engine->add_to_layer(engine, UI_TEXT, (void **)&text->text);
	engine->add_update(engine, text, &text_update);
	return (0);
}

static int add_components(gameobject_t *text)
{
	if (text->add_component(text, TEXT) == NULL) {
		my_puterror("[ERROR]text: Could not add text!\n");
		return (84);
	}
	if (text->add_component(text, TRANSFORM) == NULL) {
		my_puterror("[ERROR]text: Could not add tranform\n");
		return (84);
	}
	return (0);
}

gameobject_t *create_prefab_ftext(sf_engine_t *engine,\
sf_vector_3d_t pos, attack_t *attack, fight_t *fight)
{
	gameobject_t *new_text = create_gameobject("fight_text");
	sf_text_t *text = NULL;

	if (new_text == NULL)
		return (NULL);
	if (add_components(new_text) == 84) {
		new_text->destroy(new_text);
		return (NULL);
	}
	if (setup_components(engine, new_text, pos, attack) == 84) {
		new_text->destroy(new_text);
		return (NULL);
	}
	text = get_component(new_text, TEXT);
	if (text == NULL)
		return (NULL);
	if (fight->player->mana < attack->mana_cost)
		sfText_setColor(text->text, sfBlack);
	return (new_text);
}