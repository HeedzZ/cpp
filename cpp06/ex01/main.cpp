#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 123;

    std::cout << "=== Test 1: Objet simple ===" << std::endl;
    std::size_t raw = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Valeur originale: " << data.value << std::endl;
    std::cout << "Valeur désérialisée: " << deserializedData->value << std::endl;
    std::cout << "Pointeurs identiques: " << (deserializedData == &data ? "Oui" : "Non") << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 2: Pointeur nul ===" << std::endl;
    Data* nullData = NULL;
    raw = Serializer::serialize(nullData);
    deserializedData = Serializer::deserialize(raw);

    std::cout << "Pointeur désérialisé est nul: " << (deserializedData == NULL ? "Oui" : "Non") << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 3: Plusieurs objets ===" << std::endl;
    Data data1, data2;
    data1.value = 42;
    data2.value = 84;

    std::size_t raw1 = Serializer::serialize(&data1);
    std::size_t raw2 = Serializer::serialize(&data2);

    Data* deserializedData1 = Serializer::deserialize(raw1);
    Data* deserializedData2 = Serializer::deserialize(raw2);

    std::cout << "Valeur objet 1: " << deserializedData1->value << std::endl;
    std::cout << "Valeur objet 2: " << deserializedData2->value << std::endl;
    std::cout << "Pointeurs identiques pour objet 1: " << (deserializedData1 == &data1 ? "Oui" : "Non") << std::endl;
    std::cout << "Pointeurs identiques pour objet 2: " << (deserializedData2 == &data2 ? "Oui" : "Non") << std::endl;
    std::cout << std::endl;
    return 0;
}
