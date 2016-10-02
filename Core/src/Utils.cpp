#include <string>
#include <sstream>
#include <vector>

void _strsplit(const std::string &s, char delim, std::vector<std::string> &elems, bool first_occur) {
	char iter_delim = delim;

	std::stringstream ss;
	ss.str(s);
	std::string item;

	while (getline(ss, item, iter_delim)) {
		elems.push_back(item);

		if (elems.size() == 1 && first_occur) iter_delim = NULL;
	}

	ss.clear();
}

std::vector<std::string> strsplit(const std::string &s, char delim, bool first_occur) {
	std::vector<std::string> elems;
	_strsplit(s, delim, elems, first_occur);
	return elems;
}

std::vector<std::string> strsplit(const std::string &s, char delim) {
	return strsplit(s, delim, false);
}