// ppd-lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Market.h"
#include "Product.h"
#include "Bill.h"
#include "InventoryChecker.h"

int main()
{
	Market market;

	Product apple { 2 };
	Product pear { 3 };

	market.addProduct(apple, 30);
	market.addProduct(pear, 15);

	Bill bill1;
	bill1.addBillItem(apple, 1);
	bill1.addBillItem(apple, 2);
	bill1.addBillItem(pear, 3);

	Bill bill2;
	bill2.addBillItem(pear, 8);
	bill2.addBillItem(apple, 20);
	bill2.addBillItem(pear, 1);

	market.addBill(bill1);
	market.addBill(bill2);
	std::cout << InventoryChecker::check(market);
}

