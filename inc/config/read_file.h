#ifndef _CONFIG_READ_FILE_H
#define _CONFIG_READ_FILE_H

#include <string>
#include <nlohmann/json.hpp>

class ReadFile
{
public:
	ReadFile *get_instance();
	void read();

	template <typename T>
	T value(std::string key)
	{
		return static_cast<T>(j[key]);
	}

private:
	static ReadFile *instance_;
	void read_json(std::string);
	nlohmann::json j;

	ReadFile()
	{
	}
};

#endif // _CONFIG_READ_FILE_H
