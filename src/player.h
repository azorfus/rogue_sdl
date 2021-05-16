/* date = May 15th 2021 10:06 pm */

#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct player
{
    int HP;
    int xpos;
    int ypos;
    SDL_Texture* player_tex;
	SDL_Rect dest;
} Player;

void player_init(SDL_Renderer* renderer, Player* player);
void player_update(Player *player);
void player_draw(SDL_Renderer* renderer, Player *player);

#endif //PLAYER_H
