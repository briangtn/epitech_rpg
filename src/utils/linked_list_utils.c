/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Utils for linked list
*/

#include "my_sfml.h"

sf_linked_list_t *get_elem_at_index(int index, sf_linked_list_t *list)
{
	sf_linked_list_t *copy = list;

	for (int i = 0; copy && copy->next && i < index; i++)
		copy = copy->next;
	return (copy);
}