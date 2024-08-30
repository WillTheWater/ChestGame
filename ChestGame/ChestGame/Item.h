#pragma once
class Item
{
public:
	void AddAmount(int amt);
	int GetAmount();

private:
	int amount;
};

// each chest-> spawn 8 to 14 items.
// of the 8-14 items, 2-3 will be rare.
// of those 2-3 rare items
// each will have a random chance to be the rarest.
// 8 drop 1/6
// 