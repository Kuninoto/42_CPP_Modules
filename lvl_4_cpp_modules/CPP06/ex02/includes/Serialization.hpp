#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <string>
# include <stdint.h>
# include "Data.hpp"

using std::string;

class Serialization {
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif // SERIALIZATION_HPP