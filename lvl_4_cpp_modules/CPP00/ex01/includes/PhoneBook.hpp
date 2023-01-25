#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    private:
		Contact contacts[8];
        static int count;
    public:
       void addContact();
       void searchContact();
};

#endif