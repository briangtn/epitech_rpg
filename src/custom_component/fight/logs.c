/*
** EPITECH PROJECT, 2017
** My rph
** File description:
** Fight logs
*/

#include <stdlib.h>
#include "rpg.h"
#include "fight.h"

int update_logs_component(gameobject_t *go, UNUSED int delta_time)
{
	sf_logs_t *logs = get_component(go, LOGS);
	sf_transform_t *tr = get_component(go, TRANSFORM);
	sf_transform_t *cur_tr = NULL;
	sf_linked_list_t *copy = NULL;
	int pos = 0;

	if (logs == NULL || tr == NULL)
		return (84);
	copy = logs->messages;
	while (copy) {
		cur_tr = get_component((gameobject_t *)copy->data, TRANSFORM);
		if (cur_tr == NULL)
			return (84);
		cur_tr->position = tr->position;
		cur_tr->position.y += pos;
		pos += 35;
		copy = copy->next;
	}
	return (0);
}

void init_log_messages(sf_logs_t *logs, int count)
{
	gameobject_t *current = NULL;

	for (int i = 0; i < count; i++) {
		current = create_prefab_log_message(logs->engine);
		if (current == NULL)
			return;
		logs->messages = sf_push(current, "message", logs->messages);
	}
}

void add_log_message(sf_logs_t *logs, char *message)
{
	sf_linked_list_t *copy = logs->messages;
	char *tmp_save = NULL;
	char *next = message;
	gameobject_t *tmp = NULL;
	sf_text_t *text = NULL;

	while (copy) {
		tmp = (gameobject_t *)copy->data;
		text = get_component(tmp, TEXT);
		if (text == NULL)
			return;
		tmp_save = (char *)sfText_getString(text->text);
		sfText_setString(text->text, next);
		next = tmp_save;
		copy = copy->next;
	}
}

static void destroy_component(sf_logs_t *comp)
{
	if (comp == NULL)
		return;
	free(comp);
}

sf_logs_t *create_log_comp(gameobject_t *parent)
{
	sf_logs_t *logs = malloc(sizeof(*logs));

	if (logs == NULL)
		return (NULL);
	logs->parent = parent;
	logs->destroy = &destroy_component;
	logs->engine = NULL;
	logs->messages = NULL;
	return (logs);
}