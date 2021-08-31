#include <game.h>
#include <table/table.h>

void start()
{
	Table *table = table->get_instance();
	table->init_cards();
	std::vector<Card*> cards;
	Card *card = new Card(0, 4);
	cards.push_back(card);
	card = new Card(2, 2);
	cards.push_back(card);
	table->print_cards(cards);
}

int main()
{
	start();
	return 0;
}
