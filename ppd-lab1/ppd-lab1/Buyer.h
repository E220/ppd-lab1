#pragma once
#include "Market.h"
#include "Product.h"

class Buyer
{
public:
	void buyRandomProducts(Market & market);
private:
	std::vector<std::pair<Product, int>> cart;

	void buyProduct(const Product & product, int quantity);
	void finishShopping(Market & market);
};

