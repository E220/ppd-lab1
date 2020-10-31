#include "stdafx.h"
#include "Product.h"

int Product::nextId = 1;

Product::Product(int price, int quantity) :
	id { nextId++ }, price { price }
{
}

int Product::getId(void) const
{
	return id;
}

int Product::getPrice(void) const
{
	return price;
}