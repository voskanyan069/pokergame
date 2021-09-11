#ifndef _PLAYERS_PLAYER_H
#define _PLAYERS_PLAYER_H

#include <iostream>
#include <cards/card.h>

class Player
{
public:
	Player(std::string name, bool is_other=1) :
		name_(name), is_other_(is_other)
	{
		get_cards();
	}

	void get_cards();
	void print();

private:
	const std::string name_;
	const bool is_other_;
	std::vector<Card*> cards;

	void print_cards();
	std::string get_name();
};

#endif // _PLAYERS_PLAYER_H
