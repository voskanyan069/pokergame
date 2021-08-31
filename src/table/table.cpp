#include <iostream>
#include <table/table.h>

Table *Table::instance_ = nullptr;

Table* Table::get_instance()
{
	if (this->instance_ == nullptr)
	{
		this->instance_ = new Table();
	}
	return this->instance_;
}

Card **Table::get_cards()
{
	return *this->cards_;
}

void Table::init_cards()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			cards_[i][j] = new Card(i, j);
		}
	}
}

void Table::print_cards(std::vector<Card*> cards)
{
	for (int i = 0; i < cards.size(); ++i)
	{
		this->draw_card(cards[i]->get_suit(), cards[i]->get_rank());
	}
}

void Table::draw_card(int suit_, int rank_)
{
	int rank = rank_ + 1;
	std::string card = "U+F0";
	std::string rank_str;
	switch (rank)
	{
		case 10:
			rank_str = "A";
			break;
		case 11:
			rank_str = "B";
			break;
		case 12:
			rank_str = "C";
			break;
		case 13:
			rank_str = "D";
			break;
		case 14:
			rank_str = "E";
			break;
		default:
			rank_str = std::to_string(rank);
	}
	switch (suit_)
	{
		case 0:
			card += "A";
			break;
		case 1:
			card += "B";
			break;
		case 2:
			card += "C";
			break;
		case 3:
			card += "D";
			break;
	}
	card += rank_str;
	std::cout << card << std::endl;
}
