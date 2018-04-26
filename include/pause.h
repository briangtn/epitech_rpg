/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** All pause related stuff
*/

/* File created the 26/04/2018 at 13:18:21 by julian.frabel@epitech.eu */

#ifndef __RPG_PAUSE__H_
	#define __RPG_PAUSE__H_

	int goto_pause(sf_engine_t *engine);

	int load_pause_scene(sf_engine_t *engine, UNUSED void *data);
	int loop_pause_scene(sf_engine_t *engine, UNUSED void *data);
	int unload_pause_scene(sf_engine_t *engine, UNUSED void *data);

#endif /* !__RPG_PAUSE__H_ */