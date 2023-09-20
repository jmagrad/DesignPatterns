#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

enum class Color {red,green, blue};
enum class Size {small, medium, large };

class Product
{
public:
	std::string name;
	Color color;
	Size size;
};

struct ProductFilter
{
	static std::vector<Product*> by_color(std::vector<Product*> items, Color color)
	{
		std::vector<Product*> result;
		for (auto& i : items)
		{
			if (i->color == color)
			{
				result.push_back(i);
			}
		}
		return result;
	}
};

template <typename T> class Specification
{
public:
	virtual bool is_satisfied(T* item) = 0;

	AndSpecification<T> operator &&(Specification<T>&& other)
	{
		return AndSpecification<T>(*this, other);
	}
};

template <typename T> class Filter
{
public:
	virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) = 0;
};

class BetterFilter : public Filter<Product>
{
public:
	std::vector<Product*> filter(std::vector<Product*> items, Specification<Product>& spec) override
	{
		std::vector<Product*> result;
		for (auto& item : items)
			if (spec.is_satisfied(item))
				result.push_back(item);
		return result;
	}
};

class ColorSpecification : public Specification<Product>
{
public:
	Color color;
	ColorSpecification(Color color) : color(color) {}

	bool is_satisfied(Product* item) override
	{
		return item->color == color;
	}
};

class SizeSpecification : public Specification<Product>
{
public:
	Size size;
	SizeSpecification(Size size) : size(size) {}

	bool is_satisfied(Product* item) override
	{
		return item->size == size;
	}
};

template <typename T> class AndSpecification : public Specification<T>
{
public:
	AndSpecification(Specification<T>& first, Specification<T>& second) :first(first), second(second)
	{}
	
	bool is_satisfied(T* item) override
	{
		return first.is_satisfied(item) && second.is_satisfied(item);
	}

	Specification<T>& first;
	Specification<T>& second;


};

int main()
{
	Product apple{ "Apple", Color::green, Size::small };
	Product tree{ "Tree", Color::green, Size::large };
	Product house{ "House", Color::blue, Size::large };

	std::vector<Product*> items{ &apple, &tree, &house };

	auto green_things = ProductFilter::by_color(items, Color::green);

	BetterFilter bf;
	ColorSpecification green(Color::green);

	for (auto& item : bf.filter(items, green))
	{
		std::cout << item->name << " is green." << std::endl;
	}

	SizeSpecification large(Size::large);
	AndSpecification<Product> green_and_large(green, large);

	for (auto& item : bf.filter(items, green_and_large))
	{
		std::cout << item->name << " is green and large." << std::endl;
	}
	return 0;
}