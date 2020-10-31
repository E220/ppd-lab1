#pragma once
#include "Product.h"
#include "Bill.h"

class Market
{
public:
	const std::vector<Product> & getProducts(void) const;
	const std::vector<Bill> & getBills(void) const;

	void addProduct(Product product);
	void addBill(Bill bill);
private:
	std::vector<Product> products;
	std::vector<Bill> bills;
};

