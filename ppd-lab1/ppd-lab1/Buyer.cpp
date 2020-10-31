#include "stdafx.h"
#include "Buyer.h"

void Buyer::buyRandomProducts(Market & market)
{
	const int nrItems = rand() % 3 + 1;
	for (int i = 0; i < nrItems; i++)
	{
		const std::vector<Product> & products = market.getProducts();
		const Product & product = products[rand() % products.size()];
		const int quantity = rand() % 5 + 1;
		buyProduct(product, quantity);
	}
	finishShopping(market);
}

void Buyer::buyProduct(const Product & product, int quantity)
{
	cart.emplace_back(product, quantity);
}

void Buyer::finishShopping(Market & market)
{
	market.buy(cart);
	cart.clear();
}
