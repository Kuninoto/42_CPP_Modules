#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serialization {
	public:
		static uintptr_t serialize(data_t *ptr);
		static data_t *deserialize(uintptr_t raw);
};

#endif // SERIALIZATION_HPP