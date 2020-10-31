#pragma once
#include "Market.h"
#include "Product.h"

class Buyer
{
public:
	void buyRandomProducts(Market & market);
private:
	std::vector<Bill> cart;
};

