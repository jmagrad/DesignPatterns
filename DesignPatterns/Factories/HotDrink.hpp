#pragma once
#include <iostream>
#include <memory>
class HotDrink
{
public:
	virtual ~HotDrink() = default;
	virtual void prepare(int volume) = 0;
};

class Tea : public HotDrink
{
public:
	void prepare(int volume) override
	{
		std::cout << "Take tea bag, boid water, pour " << volume << "ml, add some lemon \n";
	}
};

class Coffee : public HotDrink
{
public:
	void prepare(int volume) override
	{
		std::cout << "Grind some beans boil water, pour " << volume << "ml, add some cream \n";
	}
};