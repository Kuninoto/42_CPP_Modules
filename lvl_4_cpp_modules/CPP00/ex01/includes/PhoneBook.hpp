#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8
# define MAX_CONTACT_INDEX 7

class PhoneBook {
    public:
       /* Default constructor */
       PhoneBook();

       void addContact(void);
       void searchContact(void);

    private:
        size_t count;
		Contact contacts[MAX_CONTACTS];
};

#endif // PHONEBOOK_HPP