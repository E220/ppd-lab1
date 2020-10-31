#include "stdafx.h"
#include "Market.h"

const std::vector<Product> & Market::getProducts(void) const
{
	return products;
}

int Market::getQuantityOf(const Product & product) const
{
	return quantities.at(product.getId());
}

const std::vector<Bill> & Market::getBills(void) const
{
	return bills;
}

long long Market::getMoney(void) const
{
	return money;
}

void Market::addProduct(const Product & product, int quantity)
{
	products.push_back(product);
	quantities[product.getId()] = quantity;
}

void Market::addBill(Bill bill)
{
	for (const Bill::BillItem & billItem : bill.getBillItems())
	{
		const int quantity = quantities[billItem.getProduct().getId()];
		quantities[billItem.getProduct().getId()] = quantity - billItem.getQuantity();
		money += billItem.getTotal();
	}
	bills.push_back(bill);
}