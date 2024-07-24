#include <fstream>
#include <iostream>
#include <sstream>

struct Data {
    std::string stockMarket;
    std::string tickerName;
    int tradeVolume;
    double bidPrice;
    double askPrice;
};

// 직렬화 함수
std::string serialize(const Data& data) {
    std::ostringstream oss;
    oss << data.stockMarket << ' '
        << data.tickerName << ' '
        << data.tradeVolume << ' '
        << data.bidPrice << ' '
        << data.askPrice;
    return oss.str();
}

int main() {
    Data d = {"NASDAQ", "AAPL", 10000, 172.5, 173.5};
    std::string serializedData = serialize(d);

    std::ofstream file("data.txt");
    file << serializedData;
    file.close();

    std::cout << "Serialized data: " << serializedData << std::endl;
    return 0;
}

// 역직렬화 함수
Data deserialize(const std::string& serializedData) {
    std::istringstream iss(serializedData);
    Data data;
    iss >> data.stockMarket >> data.tickerName >> data.tradeVolume >> data.bidPrice >> data.askPrice;
    return data;
}

int main() {
    std::ifstream file("data.txt");
    std::string serializedData;
    std::getline(file, serializedData);
    file.close();

    Data d = deserialize(serializedData);
    
    std::cout << "Deserialized data:" << std::endl;
    std::cout << "\tStock Market: " << d.stockMarket << std::endl
              << "\tTicker Name: " << d.tickerName << std::endl
              << "\tTrade Volume: " << d.tradeVolume << std::endl
              << "\tBid Price: " << d.bidPrice << std::endl
              << "\tAsk Price: " << d.askPrice << std::endl;
    return 0;
}
