# include "Serializer.hpp"

int main()
{
    Data Dta;
    Dta.var = 42;
    
    Data* originalPtr = &Dta;

    uintptr_t serializedValue = Serializer::serialize(originalPtr);
    Data* deserializedValue = Serializer::deserialize(serializedValue);

    std::cout << "Serialize: " << serializedValue << std::endl;
    std::cout << "Deserialize: " << deserializedValue << std::endl;

    if (originalPtr == deserializedValue)
        std::cout << "Success: Pointers are equal." << std::endl;
    else
        std::cout << "Error: Pointers are different." << std::endl;
}