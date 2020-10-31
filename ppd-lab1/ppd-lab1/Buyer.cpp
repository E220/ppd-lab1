#include "stdafx.h"
#include "Buyer.h"

void Buyer::buyRandomProducts(Market & market)
{
	const int nrItems = rand() % 10 + 1;
	const std::vector<Product> & products = market.getProducts();
	for (int i = 0; i < nrItems; i++)
	{
		const Product & product = products[rand() % products.size()];
		const int quantity = rand() % 20 + 1;
		cart.push_back(Bill { product.getId(), quantity });
	}
	for (const Bill & bill : cart)
		market.buyProduct(bill);
	cart.clear();
}