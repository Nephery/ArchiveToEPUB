#pragma once

#include <vector>

class Index
{
public:
	class Entry;

	Index(std::string archive_path, std::string archive_filename);
	const Entry get(int i) const;
	size_t size() const;
	bool good() const;

private:
	const std::string _archive_path, _archive_name;

	std::vector<Entry> _entries;
	bool _valid;

	void _fetch(std::string path);
};

class Index::Entry
{
public:
	const std::string name, path;
	Entry(std::string name, std::string path);
};

