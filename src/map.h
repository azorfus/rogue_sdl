#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct Map
{
	SDL_Texture* floor;
	SDL_Texture* wall;
	SDL_Rect src, dest;
	int map[50][50];
} Map;

void map_init(SDL_Renderer* renderer, Map *map);
void map_load(SDL_Renderer* renderer, int arr[50][50], Map *map);
void map_draw(SDL_Renderer*, Map *map);

#endif // MAP_H
