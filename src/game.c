#include "game.h"

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

