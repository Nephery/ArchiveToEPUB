#include <iostream>
#include <string>

#include "Index.h"
#include "Templates.h"

int main(int argc, char **argv)
{
	char *archive;
	if (argc < 2) {
		std::cout << "No file specified." << std::endl;
		std::cin.get();
		return(0);
	}
	else {
		archive = argv[1];
	}

	Index idx(archive, "index.txt");
	if (!idx.good()) {
		std::cout << "index.txt not found." << std::endl;
		std::cin.get();
		return(0);
	}
	for (size_t i = 0; i < idx.entries().size(); i++) {
		std::cout << "NAME: " + idx.entries()[i].name + "\nPATH: " + idx.entries()[i].path << std::endl;
	}

	Templates::init();

	/*char *svg0 = gen_SVG(tmpts->svg, 3333, 4444, idx->entries[0].path);
	char *svg1 = gen_SVG(tmpts->svg, 1234, 5555, idx->entries[1].path);
	char *buffer = malloc_sf((strlen(svg0) + strlen(svg1))*sizeof(char));
	strcat_n(buffer, svg0, svg1);
	printf("Testing file generation...\n");
	printf("\n%s\n", gen_XHTML(tmpts->xhtml, idx->entries[1].name, buffer));*/
	
	idx.~Index();
	std::cin.get();
	return(0);
}