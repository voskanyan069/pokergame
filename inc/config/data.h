#ifndef _CONFIG_DATA_H
#define _CONFIG_DATA_H

#include <map>
#include <any>

class Data
{
public:
	Data *get_instance();

	template <typename T>
	T value(std::string key)
	{
		return std::any_cast<T>(data[key]);
	}

	template <typename T>
	void insert(std::string key, T val)
	{
		data.insert(std::pair<std::string, T>(key, val));
	}

private:
	static Data *instance_;
	std::map<std::string, std::any> data;

	Data()
	{
	}
};

#endif // _CONFIG_DATA_H
