#include "game.h"

void init(SDL_Window* window, SDL_Renderer* renderer, const char* title, int width, int height, int x, int y, bool fullscreen, bool *running)
{
	if(SDL_Init(SDL_INIT_EVERYTHING)==0)
	{
		printf("SDL initialized.\n");
		if(fullscreen)
		{
			int flags = 0;
			flags = SDL_WINDOW_FULLSCREEN;
		}
		window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);
        if(window)
        {
            printf("Window Created.\n");
        }
        else
        {
            printf("Failed to create window\n");
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            printf("Renderer Created.\n");
        }
        else
        {
            printf("Failed to create renderer\n");
        }
        *running = true;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        
    }
}
void handle_events(SDL_Window* window, SDL_Renderer* renderer, bool *running)
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
        *running = false;
        break;
    }
}

void update(int cnt, Player *player)
{
    printf("%d\n", cnt);
	player_update(player);
}

void render(SDL_Renderer* renderer, Player* player)
{
    SDL_RenderClear(renderer);
	player_draw(renderer, player);
    SDL_RenderPresent(renderer);
}

void clean_sdl(SDL_Window* window, SDL_Renderer* renderer, Player* player)
{
	SDL_DestroyTexture(player->player_tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("SDL Quit.\n");
    exit(0);
}

