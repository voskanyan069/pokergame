#include <table/table.h>
#include <players/dealer.h>

Dealer *Dealer::instance_ = nullptr;

Dealer* Dealer::get_instance()
{
	if (instance_ == nullptr)
	{
		instance_ = new Dealer();
	}
	return instance_;
}

void Dealer::open_card()
{
	Table *table = table->get_instance();
	if (cards_count == 0)
	{
		table->get_table_cards(2);
		cards_count = 3;
	}
	else if (cards_count == 3 || cards_count == 4)
	{
		table->open_hidden_card(cards_count);
		++cards_count;
	}
}
