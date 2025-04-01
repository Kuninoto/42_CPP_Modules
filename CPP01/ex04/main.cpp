#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::cerr;
using std::endl;

# define ARGC_ERR "Wrong number of arguments\nUsage: ./wannabe_sed <filename> <s1> <s2>"
# define FILE_OPEN_ERR "Failed to open file"

int panic(const std::string& error_msg)
{
	cerr << "wannabe_sed: error: " << error_msg << '\n';
	return EXIT_FAILURE;
}

// ./wannabe_sed <filename> <s1> <s2>
// replaces s1 with s2
int main(int argc, char **argv)
{
	if (argc != 4)
		return panic(ARGC_ERR);

	std::ifstream in_file(argv[1], std::ifstream::in);

	std::ofstream new_file;
	std::string new_file_name(argv[1]);
	new_file_name.append(".replace");

	std::string s1(argv[2]);
	std::string s2(argv[3]);
	std::string file_content;

	if (!in_file.is_open())
		return panic(FILE_OPEN_ERR);

	// get infile content until \0 (EOF)
	std::getline(in_file, file_content, '\0');

	new_file.open(new_file_name.c_str());
	
	int idx; 
	// while s1 is still on the file
	while ((idx = file_content.find(s1)) != -1)
	{
		file_content.erase(idx, s1.length());
		file_content.insert(idx, s2);
	}
	new_file << file_content;

	in_file.close();
	new_file.close();
	return EXIT_SUCCESS;
}
