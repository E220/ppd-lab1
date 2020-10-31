#include "stdafx.h"
#include "Bill.h"


Bill::Bill(int productId, int quantity) :
	productId { productId }, quantity { quantity }
{
}

int Bill::getProductId(void) const
{
	return productId;
}

int Bill::getQuantity() const
{
	return quantity;
}
