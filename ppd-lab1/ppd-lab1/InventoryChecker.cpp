#include "stdafx.h"
#include "InventoryChecker.h"

bool InventoryChecker::check(const Market & market)
{
	std::unordered_map<int, int> quantitySold;
	int moneySoldFor = 0;

	for (const Bill & bill : market.getBills())
		for (const Bill::BillItem & billItem : bill.getBillItems())
		{
			quantitySold[billItem.getProduct().getId()] += billItem.getQuantity();
			moneySoldFor += billItem.getTotal();
		}

	for (const std::pair<int, int> & quantity : quantitySold)
		if (market.getOriginalQuantityOf(quantity.first) - market.getQuantityOf(quantity.first) != quantity.second)
			return false;

	if (moneySoldFor != market.getMoney())
		return false;

	return true;
}
