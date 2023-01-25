#include <iostream>
#include <string>
#include <cstdlib>

#include "Contact.hpp"

/* SETTERS */

void Contact::setFirstName(string str) {
    this->first_name = str;
}

void Contact::setLastName(string str) {
    this->last_name = str;
}

void Contact::setNickName(string str) {
    this->nickname = str;
}

void Contact::setPhoneNumber(string str) {
    this->phone_number = str;
}

void Contact::setDarkestSecret(string str) {
    this->darkest_secret = str;
}

/* GETTERS */

string Contact::getFirstName(void) {
    return this->first_name;
}

string Contact::getLastName(void) {
    return this->last_name;
}

string Contact::getNickname(void) {
    return this->nickname;
}

string Contact::getPhoneNumber(void) {
    return this->phone_number;
}

string Contact::getDarkestSecret(void) {
    return this->darkest_secret;
}

