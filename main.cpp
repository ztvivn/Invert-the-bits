#include <iostream>
#include <vector>
#include <memory>
#include <bitset>


template <class Type>
void invertBit(Type *ptr, const std::vector<size_t>& bit_position)//function that inverts only the selected bits in the memory section
{
    if(ptr == nullptr)//checking an empty pointer
    {
        std::cout << "Your pointer is equal to nullptr.\n";
        return;
    }
    
    for(size_t bit : bit_position)//inverting the selected bits
    {
        if(bit < (sizeof(Type) * 8))
        {
            (*ptr) ^= (1 << bit);
        }
        else
        {
            std::cout << "Bit position: " << bit << " is out of range.\n";
        }
    }
}

int main()
{
    std::unique_ptr<uint8_t> ptr(new uint8_t(52));
    std::vector<size_t> bit_position = {0, 1, 4, 5, 7};//bit indexes that need to be inverted

    std::cout << "Memory before inverting: " << std::bitset<sizeof(*ptr) * 8>((*ptr)) << '\n';

    invertBit(ptr.get(), bit_position);

    std::cout << "Memory  after inverting: " <<std::bitset<sizeof(*ptr) * 8>((*ptr)) << '\n';


    return 0;
}