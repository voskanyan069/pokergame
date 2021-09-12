#include <config/data.h>

Data *Data::instance_ = nullptr;

Data *Data::get_instance()
{
	if (instance_ == nullptr)
	{
		instance_ = new Data();
	}
	return instance_;
}
