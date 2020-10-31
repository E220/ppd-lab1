#pragma once
#include "Product.h"

class Bill
{
public:
	Bill(int productId, int quantity);

	int getProductId() const;
	int getQuantity() const;
private:
	const int productId;
	const int quantity;
};

