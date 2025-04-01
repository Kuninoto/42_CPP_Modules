#include "Harl.hpp"
#include <iostream>

using std::cout;
using std::endl;

#define HARL_DEBUG  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
#define HARL_INFO  "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
#define HARL_WARNING  "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n"
#define HARL_ERROR  "This is unacceptable! I want to speak to the manager now.\n"

Harl::Harl(void) {};
Harl::~Harl(void) {};


void Harl::debug(void) {
	cout << "[ DEBUG ]" << endl;
	cout << HARL_DEBUG << endl;
}

void Harl::info(void) {
	cout << "[ INFO ]" << endl;
	cout << HARL_INFO << endl;
}

void Harl::warning(void) {
	cout << "[ WARNING ]" << '\n'
		 << HARL_WARNING << endl;
}

void Harl::error(void) {
	cout << "[ ERROR ]" << '\n'
		 << HARL_ERROR << endl;
}

void Harl::complain(std::string level)
{
	harl_func_t	harl_funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i += 1)
	{
		if (level == levels[i])
		{
			switch (i)
			{
				case 0:
					(this->*harl_funcs[0])();
					(this->*harl_funcs[1])();
					(this->*harl_funcs[2])();
					(this->*harl_funcs[3])();
					break;
				case 1:
					(this->*harl_funcs[1])();
					(this->*harl_funcs[2])();
					(this->*harl_funcs[3])();
					break;
				case 2:
					(this->*harl_funcs[2])();
					(this->*harl_funcs[3])();
					break;
				case 3:
					(this->*harl_funcs[3])();
					break;
				default:
					break;
			}
			return;
		}
	}
	cout << "[ Probably complaining about insignificant problems ]" << endl;
}