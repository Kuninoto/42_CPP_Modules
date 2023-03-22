#include <iostream>
#include <cstdlib>
#include "Serialization.hpp"

using std::cout;
using std::cerr;
using std::endl;

int	main(int argc, char **argv)
{
    if (argc > 1 && argv)
    {
        cerr << "serializer: error: command-line arguments aren't supported" << endl;
        return EXIT_FAILURE;
    }

    Data foo;
    uintptr_t reinterpreted;

    foo.dummy_str = string("test");
    reinterpreted = Serialization::serialize(&foo);

    cout << "OG foo (Data) Address = " << &foo << endl
         << "dummy_str value = " << foo.dummy_str << endl;

    cout << endl;

    cout << "Reinterpreted foo value = " << reinterpreted << endl;

    cout << endl;

    Data *deserialized;

    deserialized = Serialization::deserialize(reinterpreted);

    cout << "Deserialized Address = " << deserialized << endl
         << "dummy_str value = " << deserialized->dummy_str << endl;

    return EXIT_SUCCESS;
}
