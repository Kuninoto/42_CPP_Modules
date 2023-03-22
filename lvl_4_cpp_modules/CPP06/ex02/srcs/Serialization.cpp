#include <iostream>
#include "Serialization.hpp"

using std::cout;
using std::endl;

uintptr_t Serialization::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialization::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
