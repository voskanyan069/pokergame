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
		init_cards();
		set_chips();
	}

	void init_cards();
	void print();
	void fold();
	void check();
	void call();
	bool raise();

private:
	const std::string name_;
	unsigned int chips_count;
	const bool is_other_;
	std::vector<Card*> cards;

	void print_cards();
	void print_chips();
	void set_chips();
	std::string get_name();
};

#endif // _PLAYERS_PLAYER_H
