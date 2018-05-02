/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Fight scene header
*/

/* File created the 04/04/2018 at 12:05:23 by julian.frabel@epitech.eu */

#ifndef __FIGHT__H_
	#define __FIGHT__H_

	#include "my_sfml.h"
	#define FIGHT_ELEMENT_SIZE 64
	#define FIGHT_ENEMY_SPACE 50
	#define AMENU_SELECTOR "assets/spritesheets/arrow_mattack.png"

	typedef enum direction {
		HORIZONTAL,
		VERTICAL
	} direction_t;

	typedef struct attack {
		gameobject_t *go;
		char *name;
		float damage;
		int mana_cost;
	} attack_t;

	typedef struct fight_enemy {
		gameobject_t *go;
		char *name;
		float life;
		char *sprite_path;
		sf_linked_list_t *attacks;
	} fight_enemy_t;

	typedef struct fight_player {
		gameobject_t *go;
		float life;
		int max_mana;
		int curr_max_mana;
		int mana;
		char *sprite_path;
		sf_vector_2d_t position;
		sf_linked_list_t *attacks;
	} fight_player_t;

	typedef struct my_fight {
		char *background_path;
		fight_player_t *player;
		sf_linked_list_t *ennemies;
		attack_t *last_attack;
	} fight_t;

	#pragma region components

	typedef struct arrow_elem_base {
		gameobject_t *go;
	} arrow_elem_base_t;

	typedef struct fight_arrow {
		void (*destroy)();
		gameobject_t *parent;
		int elem_index;
		int elem_offset;
		int elem_size;
		direction_t dir;
		sf_linked_list_t *list;
		void *callback_param;
		sf_linked_list_t *(*get_elem)(struct fight_arrow *);
		sf_engine_t *engine;
		int (*update)(gameobject_t *, int);
		int (*display_update)(sf_animation_2d_t *, int);
		int (*callback)(void *, sf_linked_list_t *,\
struct fight_arrow *);
	} sf_fight_arrow_t;

	typedef struct attack_menu {
		void (*destroy)();
		gameobject_t *parent;
		fight_t *fight;
		gameobject_t *arrow;
		sf_engine_t *engine;
	} sf_attack_menu_t;

	typedef struct enemy_comp {
		void (*destroy)();
		gameobject_t *parent;
		fight_t *fight;
		fight_enemy_t *datas;
		gameobject_t *life_bar_go;
		sf_engine_t *engine;
	} sf_enemy_t;

	typedef struct player_comp {
		void (*destroy)();
		gameobject_t *parent;
		fight_t *fight;
		fight_player_t *datas;
		gameobject_t *life_bar_go;
		sf_engine_t *engine;
		gameobject_t *mana_text_go;
	} sf_player_t;

	sf_linked_list_t *get_arrow_elem(sf_fight_arrow_t *arrow);
	int arrow_update(gameobject_t *arrow_go, UNUSED int delta_time);
	int arrow_display_update(sf_animation_2d_t *anim, int delta_time);
	sf_fight_arrow_t *create_farrow_comp(gameobject_t *parent);
	int menu_arrow_val(void *data, UNUSED sf_linked_list_t *elem,\
sf_fight_arrow_t *arrow);

	sf_attack_menu_t *create_fattack_menu_comp(gameobject_t *parent);

	sf_enemy_t *create_enemy_comp(gameobject_t *parent);
	int update_enemy(void *datas, UNUSED int delta_time);
	void destroy_enemy(sf_engine_t *engine, gameobject_t *go);

	sf_player_t *create_player_comp(gameobject_t *parent);
	int update_player(void *datas, UNUSED int delta_time);

	#pragma endregion

	int get_enemy_center_position(sf_engine_t *engine, int enemy_count);
	int get_total_elem_size(void);
	int get_enemy_posx(sf_engine_t *engine, int enemy_count, int pos);
	void scale_elem_to_size(sfSprite *sprite);
	void destroy_fattack_menu(sf_attack_menu_t *comp);
	void select_attack(sf_engine_t *engine, fight_t *fight, bool new_round);
	void select_enemy(sf_engine_t *engine, fight_t *fight);

#endif /* !__FIGHT__H_ */