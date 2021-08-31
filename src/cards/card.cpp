#include <cards/card.h>

int Card::get_suit()
{
	return this->cs_;
}

int Card::get_rank()
{
	return this->cr_;
}
