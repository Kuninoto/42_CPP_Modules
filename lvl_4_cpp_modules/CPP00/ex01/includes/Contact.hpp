#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
using std::string;

class Contact {
    public:
        void	setFirstName(string str);
        void	setLastName(string str);
        void	setNickName(string str);
        void	setPhoneNumber(string str);
        void	setDarkestSecret(string str);

        string	getFirstName(void);
        string	getLastName(void);
        string	getNickname(void);
        string	getPhoneNumber(void);
        string	getDarkestSecret(void);

    private:
        string	first_name;
        string	last_name;
        string	nickname;
        string	phone_number;
        string	darkest_secret;
};

#endif // CONTACT_HPP