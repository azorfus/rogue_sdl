#include "player.h"

void player_init(SDL_Renderer* renderer, Player *player)
{
    player->player_tex = IMG_LoadTexture(renderer, "player.png");
}

void player_update(Player* player)
{
    player->dest.h = 64;
    player->dest.w = 64;
    player->dest.x = player->xpos;
    player->dest.y = player->ypos;
}

void player_draw(SDL_Renderer* renderer, Player *player)
{
    SDL_RenderCopy(renderer, player->player_tex, NULL, &(player->dest));
}
