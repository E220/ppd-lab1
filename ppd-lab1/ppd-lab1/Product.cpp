#include "stdafx.h"
#include "Product.h"

int Product::nextId = 0;

Product::Product(int price) :
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