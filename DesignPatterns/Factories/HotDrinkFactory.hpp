#pragma once
#include "HotDrink.hpp"

class HotDrinkFactory
{
public:
	virtual std::unique_ptr<HotDrink> make() const = 0;
};

class TeaFactory : public HotDrinkFactory
{
public:
	virtual std::unique_ptr<HotDrink> make() const override
	{
		return std::make_unique<Tea>();
	}
};

class CoffeeFactory : public HotDrinkFactory
{
public:
	virtual std::unique_ptr<HotDrink> make() const override
	{
		return std::make_unique<Coffee>();
	}
};