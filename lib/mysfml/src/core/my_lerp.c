/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** lerp
*/

/* File created the 18/03/2018 at 14:38:09 by julian.frabel@epitech.eu */

float my_lerp(float v0, float v1, float t)
{
	return ((1 - t) * v0 + t * v1);
}