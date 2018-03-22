/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Get a random number betweed two numbers
*/

/* File created the 17/03/2018 at 11:02:23 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml_core.h"

float get_randomf_vector_2d(sf_vector_2d_t vector)
{
	float low = vector.x;
	float high = vector.y;
	float return_value = 0;

	return_value = low + (float)(rand()) / (float)(RAND_MAX) * (high - low);
	return (return_value);
}

float get_randomf_between_two_values(float low, float high)
{
	return (low + (float)(rand()) / (float)(RAND_MAX) * (high - low));
}

int get_randomi_between_two_values(int low, float high)
{
	return (low + (rand()) / (RAND_MAX) * (high - low));
}