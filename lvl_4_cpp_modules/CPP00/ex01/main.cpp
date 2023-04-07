#include <iostream> // cin, cout, endl
#include <string> // string class
#include <cstdlib> // exit() && EXIT_* macros
#include <stdio.h> // clearerr()
#include "PhoneBook.hpp"

using std::cin;
using std::cout;
using std::endl;

static inline bool is_input_valid(std::string input) { return input == "ADD" || input == "SEARCH" || input == "EXIT"; }

void print_welcome(void)
{
    cout << "*-------------------------------------------*\n"
            "|                                           |\n"
            "|                 Kuninoto                  |\n"
            "|                  Phone                    |\n"  
            "|                   Book                    |\n"
            "|                                           |\n"
            "|          ADD - Add a new contact          |\n"
            "|          SEARCH - Display a contact       |\n"
            "|          EXIT - Exit PhoneBook            |\n"
            "|                                           |\n"
            "*-------------------------------------------*" << endl;
}

std::string get_input(void)
{
    std::string input;

    while (1)
    {
        cout << "pb> ";
        getline(cin, input);
        if (cin.eof() == true)
        {
            cin.clear();
            clearerr(stdin);
        }
        if (!input.empty() && is_input_valid(input))
            break;
        cin.clear();
        cout << "Please insert a valid input" << endl;
    }
    return input;
}

int main(void)
{
    PhoneBook phone_book;
    std::string input;

    print_welcome();
    while (1)
    {
        input = get_input();
        if (input == "ADD")
            phone_book.addContact();
        else if (input == "SEARCH")
            phone_book.searchContact();
        else
        {
            cout << "See ya later aligator! 🦖" << endl;
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}
