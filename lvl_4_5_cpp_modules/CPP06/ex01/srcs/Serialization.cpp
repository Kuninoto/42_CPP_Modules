#include "Serialization.hpp"

uintptr_t Serialization::serialize(data_t *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

data_t *Serialization::deserialize(uintptr_t raw) {
	return reinterpret_cast<data_t*>(raw);
}
