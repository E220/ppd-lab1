#pragma once
#include "Product.h"

class Bill
{
public:
	class BillItem
	{
	public:
		BillItem(const Product & product, int quantity);

		const Product & getProduct() const;
		int getQuantity() const;
		int getTotal() const;
	private:
		const Product & product;
		const int quantity;
		const int total;
	};

	const std::vector<BillItem> & getBillItems(void) const;

	void addBillItem(const Product & product, int quantity);
private:
	std::vector<BillItem> billItems;
};

