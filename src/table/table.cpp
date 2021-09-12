#include <iostream>
#include <stdlib.h> 
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

void Table::reset()
{
	table_cards.clear();
}

void Table::init_cards()
{
	srand(time(0));
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			cards_[i][j] = new Card(i, j);
		}
	}
}

std::vector<Card*> Table::init_player_cards(bool is_shown)
{
	std::vector<Card*> cards;
	Card *card;

	for (int i = 0; i < 2; ++i)
	{
		do
		{
			int suit = rand() % 4;
			int rank = rand() % 13;
			card = cards_[suit][rank];
		} while (card == NULL);

		card->set_shown(is_shown);
		cards.push_back(card);
		drop_card(card);
	}

	return cards;
}

void Table::get_table_cards(int hidden_cards)
{
	bool is_shown = 1;
	Card *card;
	hidden_cards = 4 - hidden_cards;
	for (int i = 0; i < 5; ++i)
	{
		do
		{
			int suit = rand() % 4;
			int rank = rand() % 13;
			card = cards_[suit][rank];
		} while (card == NULL);

		card->set_shown(is_shown);
		table_cards.push_back(card);
		drop_card(card);

		if (i == hidden_cards)
		{
			is_shown = 0;
		}
	}
	print_cards(table_cards);
}

void Table::open_hidden_card(int index)
{
	Card *card;
	do
	{
		int suit = rand() % 4;
		int rank = rand() % 13;
		card = cards_[suit][rank];
	} while (card == NULL);
	table_cards[index] = card;
	drop_card(card);
	print_cards(table_cards);
}

void Table::print_cards(std::vector<Card*> cards)
{
	for (auto const &card : cards)
	{
		std::cout << card;
	}
	std::cout << std::endl;
}

void Table::drop_card(Card *card)
{
	cards_[card->get_suit()][card->get_rank()] = NULL;
}

void Table::draw_card(bool is_shown, int suit, int rank)
{
}

bool Table::get_is_check()
{
	return is_check;
}

void Table::set_is_check(bool ic)
{
	is_check = ic;
}

unsigned int Table::get_call_chips()
{
	return call_chips;
}

void Table::set_call_chips(int cc)
{
	call_chips = cc;
}
