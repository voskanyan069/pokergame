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
	for (auto const &card : cards)
	{
		this->draw_card(
				card->is_shown(),
				card->get_suit(),
				card->get_rank()
				);
	}
	std::cout << std::endl;
}

void Table::draw_card(bool is_shown, int suit, int rank)
{
	if (is_shown)
	{
		switch (suit)
		{
			case 0:
				switch (rank)
				{
					case 0:
						std::cout << "🂢 ";
						break;
					case 1:
						std::cout << "🂣 ";
						break;
					case 2:
						std::cout << "🂤 ";
						break;
					case 3:
						std::cout << "🂥 ";
						break;
					case 4:
						std::cout << "🂦 ";
						break;
					case 5:
						std::cout << "🂧 ";
						break;
					case 6:
						std::cout << "🂨 ";
						break;
					case 7:
						std::cout << "🂩 ";
						break;
					case 8:
						std::cout << "🂪 ";
						break;
					case 9:
						std::cout << "🂫 ";
						break;
					case 10:
						std::cout << "🂭 ";
						break;
					case 11:
						std::cout << "🂮 ";
						break;
					case 12:
						std::cout << "🂡 ";
						break;
				}
				break;
			case 1:
				switch (rank)
				{
					case 0:
						std::cout << "🂲 ";
						break;
					case 1:
						std::cout << "🂳 ";
						break;
					case 2:
						std::cout << "🂴 ";
						break;
					case 3:
						std::cout << "🂵 ";
						break;
					case 4:
						std::cout << "🂶 ";
						break;
					case 5:
						std::cout << "🂷 ";
						break;
					case 6:
						std::cout << "🂸 ";
						break;
					case 7:
						std::cout << "🂹 ";
						break;
					case 8:
						std::cout << "🂺 ";
						break;
					case 9:
						std::cout << "🂻 ";
						break;
					case 10:
						std::cout << "🂽 ";
						break;
					case 11:
						std::cout << "🂾 ";
						break;
					case 12:
						std::cout << "🂱 ";
						break;
				}
				break;
			case 2:
				switch (rank)
				{
					case 0:
						std::cout << "🃂 ";
						break;
					case 1:
						std::cout << "🃃 ";
						break;
					case 2:
						std::cout << "🃄 ";
						break;
					case 3:
						std::cout << "🃅 ";
						break;
					case 4:
						std::cout << "🃆 ";
						break;
					case 5:
						std::cout << "🃇 ";
						break;
					case 6:
						std::cout << "🃈 ";
						break;
					case 7:
						std::cout << "🃉 ";
						break;
					case 8:
						std::cout << "🃊 ";
						break;
					case 9:
						std::cout << "🃋 ";
						break;
					case 10:
						std::cout << "🃍 ";
						break;
					case 11:
						std::cout << "🃎 ";
						break;
					case 12:
						std::cout << "🃁 ";
						break;
				}
				break;
			case 3:
				switch (rank)
				{
					case 0:
						std::cout << "🃒 ";
						break;
					case 1:
						std::cout << "🃓 ";
						break;
					case 2:
						std::cout << "🃔 ";
						break;
					case 3:
						std::cout << "🃕 ";
						break;
					case 4:
						std::cout << "🃖 ";
						break;
					case 5:
						std::cout << "🃗 ";
						break;
					case 6:
						std::cout << "🃘 ";
						break;
					case 7:
						std::cout << "🃙 ";
						break;
					case 8:
						std::cout << "🃚 ";
						break;
					case 9:
						std::cout << "🃛 ";
						break;
					case 10:
						std::cout << "🃝 ";
						break;
					case 11:
						std::cout << "🃞 ";
						break;
					case 12:
						std::cout << "🃑 ";
						break;
				}
				break;
		}
	}
	else
	{
		std::cout << "🃟 ";
	}
}
