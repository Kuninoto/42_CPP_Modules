#include <iostream>
#include <string>
#include <cstdlib>

void    print_welcome(void)
{
    std::cout << "*-------------------------------------------*\n"
                 "*                                           *\n"
                 "*                 Kuninoto                  *\n"
                 "*                  Phone                    *\n"  
                 "*                   Book                    *\n"
                 "*                                           *\n"
                 "*          ADD - Add a new contact          *\n"
                 "*          SEARCH - Display a contact       *\n"
                 "*          EXIT - Exit PhoneBook            *\n"
                 "*                                           *\n"
                 "*-------------------------------------------*" << std::endl;
}

int main(void)
{
    print_welcome();

    return EXIT_SUCCESS;
}