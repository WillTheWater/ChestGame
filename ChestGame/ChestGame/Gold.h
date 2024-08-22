#pragma once
#include "Item.h"
#include <random>
class Gold : public Item
{
public:
	Gold();
private:
	void UpdateTextureRect();
};

