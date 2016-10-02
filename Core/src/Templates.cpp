#include "Templates.h"

#include <string>
#include <fstream>

void Templates::init() {
	XHTML::fetch();
	SVG::fetch();
}

// INNER CLASS: XHTML ------------------------

const std::string Templates::XHTML::_path = "../templates/xhtml/";

void Templates::XHTML::fetch() {
	std::ifstream ifs(_path);
	ifs.close();
	ifs.clear();
}

std::string Templates::XHTML::generate() {
	std::string generated;
	return generated;
}

// INNER CLASS: SVG --------------------------

const std::string Templates::SVG::_path = "../templates/svg/";

void Templates::SVG::fetch() {
	std::ifstream ifs(_path);
	ifs.close();
	ifs.clear();
}

std::string Templates::SVG::generate() {
	std::string generated;
	return generated;
}