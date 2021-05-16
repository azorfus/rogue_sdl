#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "game.h"
#include "player.h"
#include "map.h"

int main(int argc, char* argv[])
{
    SDL_Window* window;
    bool running = false;
    SDL_Renderer* renderer;
	bool fullscreen = false;
	if(SDL_Init(SDL_INIT_EVERYTHING)==0)
	{
		printf("SDL initialized.\n");
		if(fullscreen)
		{
			int flags = 0;
			flags = SDL_WINDOW_FULLSCREEN;
		}
		window = SDL_CreateWindow("Woods", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);
        if(window)
        {
            printf("Window Created.\n");
        }
        else
        {
            printf("Failed to create window\n");
			return 2;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            printf("Renderer Created.\n");
        }
        else
        {
            printf("Failed to create renderer\n");
			return 3;
        }
        running = true;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        
    }
    int cnt = 0;
    Player player;
    player.xpos = 0;
	player.ypos = 0;
    player_init(renderer, &player);
    const int FPS = 60;
    const int frame_delay = 1000/FPS;
    Uint32 time_start;
	Map map;
	map_load(&map);
	map_draw(renderer, &map);
    int frame_time;
    while(running)
    {
        cnt++;
		player.xpos++;
        time_start = SDL_GetTicks();
        handle_events(window, renderer, &running);
        update(cnt, &player);
		render(renderer, &player);
        frame_time = SDL_GetTicks() - time_start;
        if(frame_delay > frame_time)
        {
            SDL_Delay(frame_delay - frame_time);
        }
    }
    clean_sdl(window, renderer, &player);
    
	return 0;
}
