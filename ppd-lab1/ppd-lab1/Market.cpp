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

void Market::buyProduct(const Bill & bill)
{
	const int productId = bill.getProductId();

	mutex.lock();

	const int quantity = quantities[productId];
	quantities[productId] = quantity - bill.getQuantity();
	money += bill.getQuantity() * products[bill.getProductId()].getPrice();
	bills.push_back(bill);

	mutex.unlock();
}

void Market::lock(void)
{
	mutex.lock();
}

void Market::unlock(void)
{
	mutex.unlock();
}