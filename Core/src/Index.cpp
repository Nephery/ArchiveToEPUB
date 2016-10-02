#include "Index.h"
#include "Utils.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


Index::Index(std::string archive_path, std::string archive_filename)
	:_archive_path(archive_path),
	 _archive_name(archive_filename),
	 _valid(true)
{
	_fetch(_archive_path + _archive_name);
}

const Index::Entry Index::get(int i) const
{
	return _entries[i];
}

bool Index::good() const
{
	return _valid;
}

size_t Index::size() const
{
	return _entries.size();
}

void Index::_fetch(std::string path) 
{
	std::ifstream ifs(path);

	if (!ifs.good()) {
		std::cout << "error reading index.txt" << std::endl;
		_valid = false;
		ifs.close();
		ifs.clear();
		std::cin.get();
		exit(0);
	}

	for (std::string line; std::getline(ifs, line);)
	{
		if (line.length() == 0) continue;

		if (line.compare(0, 3, "\xEF\xBB\xBF") == 0) line.erase(0, 3); //Delete BOM

		std::vector<std::string> elems = strsplit(line, ':', true);

		if (elems.size() !=2) {
			std::cout << "index.txt has incorrect size at " + line + ", size is " << elems.size() << std::endl;
			_valid = false;
			ifs.close();
			ifs.clear();
			std::cin.get();
			exit(0);
		}

		Entry entry(elems[1], elems[0]);
		_entries.push_back(entry);
	}

	_entries.shrink_to_fit();
	ifs.close();
	ifs.clear();
}

// INNER CLASS: Entry ----------------------------------------

Index::Entry::Entry(std::string sub_archive_name, std::string sub_archive_path)
	:name(sub_archive_name),
	 path(sub_archive_path)
{}