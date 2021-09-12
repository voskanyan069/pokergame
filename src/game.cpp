#include <iostream>
#include <game.h>
#include <log/print.h>
#include <table/table.h>
#include <players/dealer.h>
#include <players/player.h>
#include <config/data.h>
#include <config/read_file.h>

void start()
{
	Table *table = table->get_instance();
	Dealer *dealer = dealer->get_instance();
	Data *data = data->get_instance();
	table->init_cards();
	table->set_is_check(0);
	table->set_call_chips(data->value<int>("stakes"));

	my_player = new Player(data->value<std::string>("username"), 0);
	for (int i = 0; i < 4; ++i)
	{
		std::string name = "Bot_" + std::to_string(i+1);
		Player *bot = new Player(name);
		bots.push_back(bot);
	}

	play();
}

void play()
{
	Table *table = table->get_instance();
	Dealer *dealer = dealer->get_instance();

	while (game)
	{
		my_player->print();
		print_bots();
		ask_action();
		play_bots();

		if (table->get_is_check() == 1)
		{
			dealer->open_card();
		}
		if (dealer->is_all_cards_openned())
		{
			success("Game endded\nUser winned\n\nNew game");
			new_hand();
		}
	}
}

void new_hand()
{
	Table *table = table->get_instance();
	Dealer *dealer = dealer->get_instance();
	Data *data = data->get_instance();

	my_player->init_cards();
	for (auto const &bot : bots)
	{
		bot->init_cards();
	}
	dealer->reset_cards();
	table->init_cards();
	table->reset();
	table->set_is_check(0);
	table->set_call_chips(data->value<int>("stakes"));
}

void ask_action()
{
	Table *table = table->get_instance();
	char action;
	bool is_check = table->get_is_check();
	std::cout << "[F]old / ";
	if (is_check)
		std::cout << "[C]heck";
	else
		std::cout << "[C]all " << table->get_call_chips();
	std::cout << " / [R]aise\n $> ";
	std::cin >> action;
	switch (action)
	{
		case 'f':
		case 'F':
			my_player->fold();
			break;
		case 'c':
		case 'C':
			if (is_check)
				my_player->check();
			else
				my_player->call();
			break;
		case 'r':
		case 'R':
			if (!my_player->raise())
			{
				warning("You retured");
				ask_action();
			}
			break;
		default:
			error("Not matching action");
			ask_action();
	}
	std::cout << std::endl;
}

void play_bots()
{
	Table *table = table->get_instance();
	bool is_check = table->get_is_check();
	
	for (auto const &bot : bots)
	{
		if (is_check)
		{
			bot->check();
		}
		else
		{
			bot->call();
		}
	}

	table->set_call_chips(0);
	table->set_is_check(1);
}

void configure()
{
	Data *data = data->get_instance();
	ReadFile *rf = rf->get_instance();
	rf->read();
	int pc = rf->value<int>("players_count");
	int sc = rf->value<int>("start_chips");
	int st = rf->value<int>("stakes");
	std::string un = rf->value<std::string>("username");
	if (un == "null")
	{
		un = getenv("USER");
	}

	data->insert("players_count", pc);
	data->insert("start_chips", sc);
	data->insert("stakes", st);
	data->insert("username", un);
}

void print_bots()
{
	for (auto const &bot : bots)
	{
		bot->print();
	}
	std::cout << std::endl;
}

int main()
{
	configure();
	start();

	return 0;
}
