#pragma once
#include "Product.h"
#include "Bill.h"

class Market
{
public:
	int getQuantityOf(const Product & product) const;
	const std::vector<Product> & getProducts(void) const;
	const std::vector<Bill> & getBills(void) const;
	long long getMoney(void) const;

	void addProduct(const Product & product, int quantity);
	void addBill(Bill bill);
private:
	std::vector<Product> products;
	std::unordered_map<int, int> quantities;
	std::vector<Bill> bills;
	long long money;
};

