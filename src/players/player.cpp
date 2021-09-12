#include <iostream>
#include <table/table.h>
#include <players/player.h>
#include <config/data.h>
#include <log/print.h>

void Player::init_cards()
{
	Table* table = table->get_instance();
	cards = table->init_player_cards(!is_other_);
}

void Player::print_cards()
{
	Table* table = table->get_instance();
	table->print_cards(cards);
}

void Player::set_chips()
{
	Data *data = data->get_instance();
	chips_count = data->value<int>("start_chips");
}

void Player::print_chips()
{
	std::cout << chips_count << '\t';
}

void Player::print()
{
	std::cout << get_name() << ":\t";
	this->print_chips();
	this->print_cards();
}

std::string Player::get_name()
{
	return this->name_;
}

void Player::fold()
{
	cards.clear();
}

void Player::check()
{
}

void Player::call()
{
	Table *table = table->get_instance();
	int cc = table->get_call_chips();
	if (cc >= chips_count)
	{
		success("ALL IN!!!");
		chips_count = 0;
	}
	else
	{
		chips_count -= cc;
	}
}

bool Player::raise()
{
	Table *table = table->get_instance();
	int r;
	std::cout << "\nEnter chips to raise (0 if want to return)\n $> ";
	std::cin >> r;
	if (r == 0)
	{
		return false;
	}
	else if (r < 0)
	{
		warning("Please enter the correct value");
		raise();
	}
	else if (r > chips_count)
	{
		warning("Too much!\nPlease enter the correct value");
		raise();
	}
	else if (r == chips_count)
	{
		chips_count -= r;
		success("ALL IN!!!");
		table->set_is_check(0);
		table->set_call_chips(r);
	}
	else
	{
		chips_count -= r;
		success("You have raised " + std::to_string(r) + " chips");
		table->set_is_check(0);
		table->set_call_chips(r);
	}
	return true;
}
