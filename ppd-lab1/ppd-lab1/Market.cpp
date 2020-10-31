#include "stdafx.h"
#include "Market.h"

const std::vector<Product> & Market::getProducts(void) const
{
	return products;
}

const std::vector<Bill> & Market::getBills(void) const
{
	return bills;
}

void Market::addProduct(Product product)
{
	products.push_back(product);
}

void Market::addBill(Bill bill)
{
	bills.push_back(bill);
}