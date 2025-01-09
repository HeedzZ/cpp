#include "Serializer.hpp"

std::size_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<std::size_t>(ptr);
}

Data* Serializer::deserialize(std::size_t raw)
{
    return reinterpret_cast<Data*>(raw);
}


Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { (void)other; }
Serializer& Serializer::operator=(const Serializer& other)
{ 
	(void)other;
	return *this;
}
Serializer::~Serializer() {}