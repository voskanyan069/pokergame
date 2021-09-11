#include <iostream>
#include <table/table.h>
#include <players/player.h>

void Player::get_cards()
{
	Table* table = table->get_instance();
	cards = table->init_player_cards(!is_other_);
}

void Player::print_cards()
{
	Table* table = table->get_instance();
	table->print_cards(cards);
}

void Player::print()
{
	std::cout << get_name() << ":\t";
	this->print_cards();
}

std::string Player::get_name()
{
	return this->name_;
}
