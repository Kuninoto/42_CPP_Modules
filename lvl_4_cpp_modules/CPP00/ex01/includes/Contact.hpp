#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
    public:
        void setFirstName(std::string str);
        void setLastName(std::string str);
        void setNickName(std::string str);
        void setPhoneNumber(std::string str);
        void setDarkestSecret(std::string str);

        std::string	getFirstName(void);
        std::string	getLastName(void);
        std::string	getNickname(void);
        std::string	getPhoneNumber(void);
        std::string	getDarkestSecret(void);

    private:
        std::string	first_name;
        std::string	last_name;
        std::string	nickname;
        std::string	phone_number;
        std::string	darkest_secret;
};

#endif // CONTACT_HPP