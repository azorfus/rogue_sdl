#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "game.h"
#include "player.h"

int main(int argc, char* argv[])
{
    SDL_Window* window;
    bool running = false;
    SDL_Renderer* renderer;
    init(window, renderer, "Woods", 640, 640, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, false, &running);
    int cnt = 0;
    Player player;
    player.xpos = 0;
	player.ypos = 0;
    player_init(renderer, &player);
    const int FPS = 60;
    const int frame_delay = 1000/FPS;
    Uint32 time_start;
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
