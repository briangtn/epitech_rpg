/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** main file
*/

/* File created the 22/03/2018 at 10:44:24 by julian.frabel@epitech.eu */

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"
#include "utils.h"

int has_display_vars(char **env)
{
	char *key = "DISPLAY";
	int key_len = my_strlen(key);

	if (env == NULL || key == NULL) {
		my_puterror("Environnement was NULL, couldn't find DISPLAY.\n");
		return (0);
	}
	for (int i = 0; env[i] != NULL; i++) {
		if (!my_strncmp(key, env[i], key_len) && env[i][key_len] == '=')
			return (1);
	}
	my_puterror("Couldn't find DISPLAY in environnement.\n");
	return (0);
}

sf_engine_t *get_new_engine(char **env)
{
	sfRenderWindow *window = NULL;
	sf_engine_t *new_engine = NULL;

	if (!has_display_vars(env))
		return (NULL);
	window = sfRenderWindow_create((sfVideoMode){WINDOW_SIZE_X, \
WINDOW_SIZE_Y, 32}, WINDOW_NAME, sfClose, NULL);
	if (window == NULL) {
		my_puterror("[ERROR]Window could not be created!\n");
		return (NULL);
	}
	sfRenderWindow_setFramerateLimit(window, FPS_LIMIT);
	sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
	new_engine = create_engine(window);
	if (new_engine == NULL) {
		my_puterror("[ERROR]Engine could not be created!\n");
		sfRenderWindow_destroy(window);
		return (NULL);
	}
	srand((long)new_engine);
	return (new_engine);
}

int load_scenes(sf_engine_t *engine)
{
	int ret = 0;

	if (create_game_scene(engine) == NULL)
		ret = (84);
	if (create_fight_scene(engine, NULL) == NULL)
		ret = (84);
	if (create_menu_scene(engine) == NULL)
		ret = (84);
	if (create_pause_scene(engine) == NULL)
		ret = (84);
	if (create_speak_scene(engine) == NULL)
		ret = (84);
	if (create_end_scene(engine) == NULL)
		ret = (84);
	if (create_intro_scene(engine) == NULL)
		ret = (84);
	return (ret);
}

int main(UNUSED int ac, UNUSED char **av, char **env)
{
	sf_engine_t *engine = get_new_engine(env);
	parser_to_game_t *ptg = create_parser_to_game("config_file");

	if (engine == NULL)
		return (84);
	if (load_scenes(engine) == 84 || ptg == NULL) {
		engine->destroy(engine);
		return (84);
	}
	engine->change_scene(engine, "intro", ptg);
	while (sfRenderWindow_isOpen(engine->window)) {
		engine->update(engine);
		if (engine->current_scene)
			engine->current_scene->loop(engine, ptg);
		engine->render(engine);
	}
	engine->destroy(engine);
	destroy_parser_to_game(ptg);
	return (0);
}