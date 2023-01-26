#include <iostream> // std::cout, std::cin
#include <cstdlib> // exit() && EXIT_SUCESS macro
#include <stdio.h> // clearerr()
#include "PhoneBook.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

static inline bool is_input_valid(string input) { return input == "ADD" || input == "SEARCH" || input == "EXIT"; }

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

string get_input(void)
{
    string input;

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
    string input;

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
            exit(EXIT_SUCCESS);
        }
    }
    return EXIT_SUCCESS;
}
