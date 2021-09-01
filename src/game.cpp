#include <game.h>
#include <table/table.h>

void test()
{
	Table *table = table->get_instance();
	std::vector<Card*> cards;
	Card *card = new Card(0, 12);
	cards.push_back(card);
	card = new Card(2, 2, false);
	cards.push_back(card);
	table->print_cards(cards);
}

void start()
{
	Table *table = table->get_instance();
	table->init_cards();
	test();
}

int main()
{
	start();
	return 0;
}
