#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstddef>

struct Data {
    int value;
};

class Serializer {
public:
    static std::size_t serialize(Data* ptr);
    static Data* deserialize(std::size_t raw);

private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();  
};

#endif
