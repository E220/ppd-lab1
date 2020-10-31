#pragma once
#include "Market.h"

class Program
{
public:
	Program(int nrBuyers, int nrProducts);
	~Program(void);

	void checkCycle(void);
	void buyCycle(void);

	Market market;
private:
	std::vector<std::thread> threads;
};

