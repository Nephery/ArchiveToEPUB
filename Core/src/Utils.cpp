#include <string>
#include <sstream>
#include <vector>

//http://stackoverflow.com/questions/236129/split-a-string-in-c
void _strsplit(const std::string &s, char delim, std::vector<std::string> &elems, bool stop_on_first) {
	char iter_delim = delim;

	std::stringstream ss;
	ss.str(s);
	std::string item;

	while (getline(ss, item, iter_delim)) {
		elems.push_back(item);

		if (elems.size() == 1 && stop_on_first) iter_delim = NULL;
	}

	ss.clear();
}

//http://stackoverflow.com/questions/236129/split-a-string-in-c
std::vector<std::string> strsplit(const std::string &s, char delim, bool stop_on_first) {
	std::vector<std::string> elems;
	_strsplit(s, delim, elems, stop_on_first);
	return elems;
}

std::vector<std::string> strsplit(const std::string &s, char delim) {
	return strsplit(s, delim, false);
}