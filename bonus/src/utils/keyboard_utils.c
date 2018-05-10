/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Keyboard utils
*/

#include "my_sfml.h"
#include "rpg.h"

bool is_key_just_pressed(sfKeyCode key_code)
{
	static sf_linked_list_t *codes = NULL;
	bool find_in_list = false;
	sf_linked_list_t *copy = codes;

	while (copy) {
		if ((sfKeyCode)copy->data == key_code)
			find_in_list = true;
		copy = copy->next;
	}
	if (!find_in_list && sfKeyboard_isKeyPressed(key_code)) {
		codes = sf_push((void *)key_code, my_int_to_str(key_code),\
codes);
		return (true);
	} else if (find_in_list && !sfKeyboard_isKeyPressed(key_code)) {
		sf_remove(my_int_to_str(key_code), &codes);
	}
	return (false);
}