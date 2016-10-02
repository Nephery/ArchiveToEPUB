#pragma once

#include <vector>

class Index
{
public:

	// Inner Classes ---------------------

	class Entry;

	// Constructor/Destructor ------------

	Index(std::string archive_path, std::string archive_filename);
	~Index();

	// Variables ------------------

	std::vector<Index::Entry> entries;
	bool valid;

private:

	// Variables -----------------

	std::string _archive_path, _archive_name;

	// Methods --------------------

	void _fetch(std::string path);
};

class Index::Entry
{
public:

	// Constructor/Destructor -----------

	Entry(std::string name, std::string path);
	~Entry();

	// Variables --------------

	std::string name, path;
};

