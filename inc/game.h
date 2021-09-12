#ifndef GAME_H
#define GAME_H

#include <vector>
#include <players/player.h>

Player *my_player;
std::vector<Player*> bots;
bool game = true;

void start();
void play();
void new_hand();
void ask_action();
void play_bots();
void configure();
void print_bots();

#endif // GAME_H
