#pragma once

#include <vector>

class Index
{
public:
	class Entry;

	Index(std::string archive_path, std::string archive_filename);
	~Index();
	std::vector<Entry> entries();
	bool good();

private:
	std::string _archive_path, _archive_name;
	std::vector<Entry> _entries;
	bool _valid;

	void _fetch(std::string path);
};

class Index::Entry
{
public:
	std::string name, path;

	Entry(std::string name, std::string path);
	~Entry();
};

