#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() 
{
    {
        std::cout << "=============== [Original Method] ================" << std::endl;
        Data d = {"NASDAQ", "APPL", 10000, 172.5, 173.5};
        Data* ptr = &d;

        // Converting pointer to uintptr_t
        uintptr_t numeric_address = reinterpret_cast<uintptr_t>(ptr);

        // Converting back to pointer from uintptr_t
        Data* original_ptr = reinterpret_cast<Data*>(numeric_address);

        std::cout << "Original address: " << ptr << std::endl;
        std::cout << "Numeric address: " << numeric_address << std::endl;
        std::cout << "Reconstructed address: " << original_ptr << std::endl;
        std::cout << "\t\t\tStock Market :: [" << original_ptr->stockMarket << "]" << std::endl
                  << "\t\t\tTicker Name :: [" << original_ptr->tickerName << "]" << std::endl
                  << "\t\t\tTrade Volume :: [" << original_ptr->tradeVolume << "]" << std::endl
                  << "\t\t\tBid Price :: [" << original_ptr->bidPrice << "]" << std::endl
                  << "\t\t\tAsk Price :: [" << original_ptr->askPrice << "]" << std::endl;
    }
    {
        std::cout << "=============== [Serialization Method] ================" << std::endl;
        Data d = {"NASDAQ", "APPL", 10000, 172.5, 173.5};
        Data* ptr = &d;

        // Converting pointer to uintptr_t
        uintptr_t numeric_address = Serializer::serialize(ptr);

        // Converting back to pointer from uintptr_t
        Data* original_ptr = Serializer::deserialize(numeric_address);

        std::cout << "Original address: " << ptr << std::endl;
        std::cout << "Numeric address: " << numeric_address << std::endl;
        std::cout << "Reconstructed address: " << original_ptr << std::endl;
        std::cout << "\t\t\tStock Market :: [" << original_ptr->stockMarket << "]" << std::endl
                  << "\t\t\tTicker Name :: [" << original_ptr->tickerName << "]" << std::endl
                  << "\t\t\tTrade Volume :: [" << original_ptr->tradeVolume << "]" << std::endl
                  << "\t\t\tBid Price :: [" << original_ptr->bidPrice << "]" << std::endl
                  << "\t\t\tAsk Price :: [" << original_ptr->askPrice << "]" << std::endl;
    }
    {
        std::cout << "=============== [NULL Pointer Test] ================" << std::endl;
        Data* nullPtr = NULL;
        uintptr_t serializedNullPtr = Serializer::serialize(nullPtr);
        Data* deserializedNullPtr = Serializer::deserialize(serializedNullPtr);

        if (deserializedNullPtr == NULL)
            std::cout << "Test Case 2: Serialization and deserialization of NULL pointer successful." << std::endl;
        else
            std::cout << "Test Case 2: Serialization and deserialization of NULL pointer failed." << std::endl;
    }
    return 0;
}
