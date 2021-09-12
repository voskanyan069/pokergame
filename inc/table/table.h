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
	void reset();
	void init_cards();
	void drop_card(Card*);
	void get_table_cards(int);
	void open_hidden_card(int);
	void print_cards(std::vector<Card*>);
	std::vector<Card*> init_player_cards(bool);
	bool get_is_check();
	void set_is_check(bool);
	unsigned int get_call_chips();
	void set_call_chips(int);
	
	~Table()
	{
	}

private:
	static Table *instance_;
	Card *cards_[4][13];
	std::vector<Card*> table_cards;
	bool is_check;
	unsigned int call_chips;

	void draw_card(bool, int, int);

	Table()
	{
	}
};

#endif // _TABLE_TABLE_H
