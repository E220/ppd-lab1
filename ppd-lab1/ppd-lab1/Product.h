#pragma once
class Product
{
public:
	Product(int price, int quantity);

	int getPrice(void) const;
	int getQuantity(void) const;

	void setQuantity(int quantity);
private:
	const int price;
	int quantity;
};

