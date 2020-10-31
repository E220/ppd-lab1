#include "stdafx.h"
#include "Program.h"
#include "InventoryChecker.h"
#include "Buyer.h"

Program::Program(int nrBuyers, int nrProducts)
{
	for (int i = 0; i < nrProducts; i++)
	{
		Product product { rand() % 20 };
		market.addProduct(product, rand() % 1000);
	}
	for (int i = 0; i < nrBuyers; i++)
		threads.push_back(std::thread { [this]() { this->buyCycle(); } });
	threads.push_back(std::thread { [this]() { this->checkCycle(); } });
}

void Program::buyCycle()
{
	Buyer buyer;
	for (int i = 0; i < 1000; i++)
		buyer.buyRandomProducts(market);
}

void Program::checkCycle(void)
{
	for (int i = 0; i < 50; i++)
		std::cout << "check ok: " << InventoryChecker::check(market) << std::endl;
}

Program::~Program()
{
	for (int i = 0; i < threads.size(); i++)
		threads[i].join();
	std::cout << "final check:" << std::endl;
	std::cout << "check ok: " << InventoryChecker::check(market) << std::endl;
	getchar();
}
