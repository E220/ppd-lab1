// ppd-lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Market.h"
#include "Product.h"
#include "Bill.h"
#include "InventoryChecker.h"
#include "Buyer.h"

int main()
{
	srand(time(NULL));

	Market market;

	Product apple { 2 };
	Product pear { 3 };
	Product beer { 5 };
	Product wine { 15 };

	market.addProduct(apple, 300);
	market.addProduct(pear, 150);
	market.addProduct(beer, 100);
	market.addProduct(wine, 50);

	Buyer buyers[5];

	for (Buyer & buyer : buyers)
		buyer.buyRandomProducts(market);

	std::cout << InventoryChecker::check(market);
}

