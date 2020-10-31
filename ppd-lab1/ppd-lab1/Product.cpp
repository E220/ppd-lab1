#include "stdafx.h"
#include "Product.h"


Product::Product(int price, int quantity) : price { price }, quantity { quantity }
{
}

int Product::getPrice(void) const
{
	return price;
}

int Product::getQuantity(void) const
{
	return quantity;
}

void Product::setQuantity(int quantity)
{
	this->quantity = quantity;
}