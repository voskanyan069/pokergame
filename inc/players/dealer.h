#ifndef _PLAYERS_DEALER_H 
#define _PLAYERS_DEALER_H 

class Dealer
{
public:
	Dealer* get_instance();
	void open_card();

	~Dealer()
	{
	}

private:
	static Dealer *instance_;
	int cards_count = 0;

	Dealer()
	{
	}
};

#endif // _PLAYERS_DEALER_H 
