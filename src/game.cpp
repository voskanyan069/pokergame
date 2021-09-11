#include <game.h>
#include <table/table.h>
#include <players/dealer.h>
#include <players/player.h>

void print_bots(std::vector<Player*>);

void start()
{
	Table *table = table->get_instance();
	Dealer *dealer = dealer->get_instance();
	table->init_cards();

	std::string username = getenv("USER");
	Player *my_player = new Player(username, false);
	std::vector<Player*> bots;
	for (int i = 0; i < 4; ++i)
	{
		std::string name = "Bot_" + std::to_string(i+1);
		Player *bot = new Player(name);
		bots.push_back(bot);
	}

	my_player->print();
	print_bots(bots);
	dealer->open_card();
}

void print_bots(std::vector<Player*> bots)
{
	for (auto const &bot : bots)
	{
		bot->print();
	}
}

int main()
{
	start();
	return 0;
}
