#ifndef _CARDS_CARD_H
#define _CARDS_CARD_H

#include <ostream>

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
	void set_shown(bool);

	friend const std::ostream& operator<<(std::ostream &os, Card *card)
	{
		std::string pic;
		int suit = card->get_suit();
		int rank = card->get_rank();
		if (card->is_shown())
		{
			switch (suit)
			{
				case 0:
					switch (rank)
					{
						case 0:
							pic = "🂢 ";
							break;
						case 1:
							pic = "🂣 ";
							break;
						case 2:
							pic = "🂤 ";
							break;
						case 3:
							pic = "🂥 ";
							break;
						case 4:
							pic = "🂦 ";
							break;
						case 5:
							pic = "🂧 ";
							break;
						case 6:
							pic = "🂨 ";
							break;
						case 7:
							pic = "🂩 ";
							break;
						case 8:
							pic = "🂪 ";
							break;
						case 9:
							pic = "🂫 ";
							break;
						case 10:
							pic = "🂭 ";
							break;
						case 11:
							pic = "🂮 ";
							break;
						case 12:
							pic = "🂡 ";
							break;
					}
					break;
				case 1:
					switch (rank)
					{
						case 0:
							pic = "🂲 ";
							break;
						case 1:
							pic = "🂳 ";
							break;
						case 2:
							pic = "🂴 ";
							break;
						case 3:
							pic = "🂵 ";
							break;
						case 4:
							pic = "🂶 ";
							break;
						case 5:
							pic = "🂷 ";
							break;
						case 6:
							pic = "🂸 ";
							break;
						case 7:
							pic = "🂹 ";
							break;
						case 8:
							pic = "🂺 ";
							break;
						case 9:
							pic = "🂻 ";
							break;
						case 10:
							pic = "🂽 ";
							break;
						case 11:
							pic = "🂾 ";
							break;
						case 12:
							pic = "🂱 ";
							break;
					}
					break;
				case 2:
					switch (rank)
					{
						case 0:
							pic = "🃂 ";
							break;
						case 1:
							pic = "🃃 ";
							break;
						case 2:
							pic = "🃄 ";
							break;
						case 3:
							pic = "🃅 ";
							break;
						case 4:
							pic = "🃆 ";
							break;
						case 5:
							pic = "🃇 ";
							break;
						case 6:
							pic = "🃈 ";
							break;
						case 7:
							pic = "🃉 ";
							break;
						case 8:
							pic = "🃊 ";
							break;
						case 9:
							pic = "🃋 ";
							break;
						case 10:
							pic = "🃍 ";
							break;
						case 11:
							pic = "🃎 ";
							break;
						case 12:
							pic = "🃁 ";
							break;
					}
					break;
				case 3:
					switch (rank)
					{
						case 0:
							pic = "🃒 ";
							break;
						case 1:
							pic = "🃓 ";
							break;
						case 2:
							pic = "🃔 ";
							break;
						case 3:
							pic = "🃕 ";
							break;
						case 4:
							pic = "🃖 ";
							break;
						case 5:
							pic = "🃗 ";
							break;
						case 6:
							pic = "🃘 ";
							break;
						case 7:
							pic = "🃙 ";
							break;
						case 8:
							pic = "🃚 ";
							break;
						case 9:
							pic = "🃛 ";
							break;
						case 10:
							pic = "🃝 ";
							break;
						case 11:
							pic = "🃞 ";
							break;
						case 12:
							pic = "🃑 ";
							break;
					}
					break;
			}
		}
		else
		{
			pic = "🃟 ";
		}
		return os << pic;
	}

	~Card()
	{
	}

private:
	int cs_;
	int cr_;
	bool is_shown_;
};

#endif // _CARDS_CARD_H
