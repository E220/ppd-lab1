#include "stdafx.h"
#include "Bill.h"

const std::vector<Bill::BillItem> & Bill::getBillItems() const
{
	return billItems;
}

void Bill::addBillItem(const Product & product, int quantity)
{
	billItems.emplace_back(product, quantity);
}

Bill::BillItem::BillItem(const Product & product, int quantity) :
	product { product }, quantity { quantity }, total { product.getPrice() * quantity }
{
}

const Product & Bill::BillItem::getProduct(void) const
{
	return product;
}

int Bill::BillItem::getQuantity() const
{
	return quantity;
}

int Bill::BillItem::getTotal() const
{
	return total;
}
