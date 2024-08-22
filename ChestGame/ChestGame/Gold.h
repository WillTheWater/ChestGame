#pragma once
#include "Item.h"
#include <random>
class Gold : public Item
{
public:
	Gold(const std::string& texturePath);
private:
	void UpdateTextureRect();
};

