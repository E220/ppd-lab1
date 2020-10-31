#include "stdafx.h"
#include "InventoryChecker.h"

bool InventoryChecker::check(Market & market)
{
	std::unordered_map<int, int> quantitySold;
	int moneySoldFor = 0;

	market.lock();

	for (const Bill & bill : market.getBills())
	{
		quantitySold[bill.getProductId()] += bill.getQuantity();
		moneySoldFor += bill.getQuantity() * market.getProducts()[bill.getProductId()].getPrice();
	}

	for (const std::pair<int, int> & quantity : quantitySold)
		if (market.getOriginalQuantityOf(quantity.first) - market.getQuantityOf(quantity.first) != quantity.second)
		{
			market.unlock();
			return false;
		}

	std::cout << moneySoldFor << " vs " << market.getMoney() << std::endl;
	if (moneySoldFor != market.getMoney())
	{
		market.unlock();
		return false;
	}
	market.unlock();

	return true;
}
