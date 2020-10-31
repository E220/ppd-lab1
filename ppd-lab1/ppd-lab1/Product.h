#pragma once
class Product
{
public:
	Product(int price);

	int getId(void) const;
	int getPrice(void) const;
private:
	const int id;
	const int price;

	static int nextId;
};

