#ifndef _CARDS_CARD_H
#define _CARDS_CARD_H

class Card
{
public:
	Card(int cs, int cr) :
		cs_(cs), cr_(cr)
	{
	}

	int get_suit();
	int get_rank();

private:
	int cs_;
	int cr_;
};

#endif // _CARDS_CARD_H
