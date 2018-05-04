/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** my_rpg
*/

#include "my.h"
#include "parsing.h"

const struct functions functions [] = {
	{&get_teleport_id},
	{&get_text_id},
	{&get_fight_id}
};

event_info_t *get_fight_id(event_info_t *event, char *buffer)
{
	int n = 0;

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			n++;
		if (buffer[i] == '"' && n == 9) {
			event->fight_id = my_getnbr(&buffer[i + 1]);
			break;
		}
	}
	return (event);
}

event_info_t *get_text_id(event_info_t *event, char *buffer)
{
	int n = 0;

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			n++;
		if (buffer[i] == '"' && n == 9) {
			event->text = my_strdup(&buffer[i + 1]);
			break;
		}
	}
	if (event->text == NULL)
		return (NULL);
	for (int i = 0; event->text[i] != '\0'; i++) {
		if (event->text[i] == '"') {
			event->text[i] = '\0';
			break;
		}
	}
	return (event);
}

event_info_t *get_teleport_id(event_info_t *event, char *buffer)
{
	int n = 0;

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			n++;
		if (buffer[i] == '"' && n == 9) {
			event->teleport[0] = my_getnbr(&buffer[i + 1]);
		} else if (buffer[i] == '"' && n == 11) {
			event->teleport[1] = my_getnbr(&buffer[i + 1]);
		} else if (buffer[i] == '"' && n == 13) {
			event->teleport[2] = my_getnbr(&buffer[i + 1]);
		}
	}
	return (event);
}

event_info_t *get_event(char *buffer)
{
	event_info_t *event = NULL;
	int n = 0;

	event = init_event(event);
	if (event == NULL)
		return (NULL);
	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			n++;
		if (buffer[i] == '"' && n == 7) {
			event->event_id = my_getnbr(&buffer[i + 1]);
			break;
		}
	}
	if (event->event_id > 0 && event->event_id <= 3)
		event = (functions[event->event_id - 1].ptrfunc)(event, buffer);
	if (event->event_id <= 0 || event->event_id > 3)
		event->event_id = 0;
	return (event);
}
