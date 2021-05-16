#include "map.h"

void map_init(SDL_Renderer* renderer, Map *map)
{
	map->floor = IMG_LoadTexture(renderer, "floor.png");
	map->wall = IMG_LoadTexture(renderer, "wall.png");
	map->src.w = map->dest.w = 64;
	map->src.h = map->dest.h = 64;
	map->src.x = map->src.y = 0;
	map->dest.x = map->dest.y = 0;
}

void map_load(Map *map)
{
	FILE* map_file;
	char map_string[420];
	map_file = fopen("map.map", "rb");
	if(!map_file)
	{
		printf("Unable to read map file\n");
	}
	else
	{
		fread(&map_string, sizeof(char), 419, map_file);
		int index = 0;
		for(int x=0;x<20;x++)
		{
			index++;
			for(int y=0;y<20;y++)
			{
				if(map_string[index+1]!='\n')
				{
					index++;
					map->map[x][y] = map_string[index];
					printf("[%c], %d", map->map[x][y], index);
				}
			}
		}
	}
}

void map_draw(SDL_Renderer* renderer, Map *map)
{
	for(int x=0;x<20;x++)
	{
		for(int y=0;y<20;y++)
		{
			map->dest.x = y*64;
			map->dest.y = x*64;
			switch(map->map[x][y])
			{
				case 0:
					SDL_RenderCopy(renderer, map->floor, &(map->src), &(map->dest));
					break;
			}
		}
	}
}
