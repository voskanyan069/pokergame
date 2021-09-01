#ifndef _TABLE_TABLE_H
#define _TABLE_TABLE_H

#include <vector>
#include <string>
#include <cards/card.h>

class Table
{
public:
	Table *get_instance();
	Card **get_cards();
	void init_cards();
	void print_cards(std::vector<Card*>);

private:
	static Table *instance_;
	Card *cards_[4][13];
	void draw_card(bool, int, int);

	Table()
	{
	}
};

#endif // _TABLE_TABLE_H
