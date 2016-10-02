#include "Index.h"
#include "Utils.h"
#include <iostream>

#include <fstream>
#include <sstream>
#include <string>


Index::Index(std::string archive_path, std::string archive_filename)
{
	this->valid = true;
	this->_archive_name = archive_filename;
	this->_archive_path = archive_path;

	_fetch(_archive_path + _archive_name);
}

Index::~Index()
{
	entries.clear();
	_archive_name.clear();
	_archive_path.clear();
}

void Index::_fetch(std::string path) 
{
	std::ifstream ifs(path);

	if (!ifs.good()) {
		this->valid = false;
		ifs.close();
		ifs.clear();
		return;
	}

	for (std::string line; std::getline(ifs, line);)
	{
		if (line.length() == 0) continue;

		if (line.compare(0, 3, "\xEF\xBB\xBF") == 0) line.erase(0, 3); //Delete BOM

		std::vector<std::string> elems = strsplit(line, ':', true);

		if (elems.size() !=2) {
			std::cout << "index.txt has incorrect size at " + line + ", size is " << elems.size() << std::endl;
			this->valid = false;
			ifs.close();
			ifs.clear();
			return;
		}

		Index::Entry entry(elems[1], elems[0]);
		entries.push_back(entry);
	}

	entries.shrink_to_fit();
	ifs.close();
	ifs.clear();
}

// INNER CLASS: Entry ----------------------------------------

Index::Entry::Entry(std::string name, std::string path)
{
	this->name = name;
	this->path = path;
}


Index::Entry::~Entry()
{
	name.clear();
	path.clear();
}