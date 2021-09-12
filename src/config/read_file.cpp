#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <config/read_file.h>
#include <typeinfo>

ReadFile *ReadFile::instance_ = nullptr;

ReadFile *ReadFile::get_instance()
{
	if (instance_ == nullptr)
	{
		instance_ = new ReadFile();
	}
	return instance_;
}

void ReadFile::read()
{
	read_json("pokerrc");
}

void ReadFile::read_json(std::string filename)
{
	std::ifstream file(filename);
	j = nlohmann::json::parse(file);
}
