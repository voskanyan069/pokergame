#ifndef _CARDS_CARD_H
#define _CARDS_CARD_H

class Card
{
public:
	Card(int cs, int cr, bool is_shown=1) :
		cs_(cs), cr_(cr), is_shown_(is_shown)
	{
	}

	int get_suit();
	int get_rank();
	bool is_shown();

private:
	int cs_;
	int cr_;
	bool is_shown_;
};

#endif // _CARDS_CARD_H
