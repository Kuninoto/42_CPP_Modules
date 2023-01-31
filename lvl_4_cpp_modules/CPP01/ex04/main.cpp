#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;

void panic(string error)
{
	cerr << "Error: " << error << endl;
	exit(EXIT_FAILURE);
}

// ./wannabe_sed <filename> <s1> <s2>
int main(int argc, char **argv)
{
	if (argc != 4)
		panic("Wrong number of arguments");

	ifstream in_file;
	string file_content;
	ofstream new_file;
	string new_file_name = argv[1];
	string s1 = argv[2];
	string s2 = argv[3];

	in_file.open(argv[1]);
	if (!in_file.is_open())
		panic("Failed to open file");

	// get infile content until \0 (EOF)
	std::getline(in_file, file_content, '\0');

	new_file_name.append(".replace");
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