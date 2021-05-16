#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct Map
{
	SDL_Texture* floor;
	SDL_Texture* wall;
	SDL_Rect src, dest;
	int map[20][20];
} Map;

void map_init(SDL_Renderer* renderer, Map *map);
void map_load(Map *map);
void map_draw(SDL_Renderer* renderer, Map *map);

#endif // MAP_H
