#include "stdafx.h"
#include "Market.h"

const std::vector<Product> & Market::getProducts(void) const
{
	return products;
}

int Market::getQuantityOf(int productId) const
{
	return quantities.at(productId);
}

int Market::getOriginalQuantityOf(int productId) const
{
	return originalQuantities.at(productId);
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
	originalQuantities[product.getId()] = quantity;
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

void Market::buy(const std::vector<std::pair<Product, int>> & cart)
{
	Bill bill;
	for (const std::pair<Product, int> & item : cart)
		bill.addBillItem(item.first, item.second);
	addBill(bill);
}