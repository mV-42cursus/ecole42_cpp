#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

struct Data 
{
	std::string stockMarket;	// 거래시장
	std::string tickerName;		// 종목명
	int			tradeVolume;	// 거래량
	float		bidPrice; 		// 매수 호가
	float		askPrice; 		// 매도 호가
};

#endif