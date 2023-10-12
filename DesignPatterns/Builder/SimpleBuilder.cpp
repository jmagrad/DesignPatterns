#include <memory>
#include <iostream>
#include <vector>
#include <sstream>

class HtmlElement
{
public:
	std::string name, txt;
	std::vector<HtmlElement> elements;

	const size_t indent_size = 2;

	HtmlElement() {}

	HtmlElement(const std::string& name, const std::string& text) : name(name), txt(text)
	{}

	std::string str(int indent = 0) const
	{
		std::ostringstream oss;
		std::string i(indent_size * indent, ' ');
		oss << i << "<" << name << ">" << std::endl;
		if (txt.size() > 0)
		{
			oss << std::string(indent_size * (indent + 1), ' ') << txt << std::endl;
		}
		for (const auto& e : elements)
			oss << e.str(indent + 1);

		oss << i << "</" << name << ">" << std::endl;
		return oss.str();
	}
};

class HtmlBuilder
{
public:
	HtmlElement root;

	HtmlBuilder(std::string root_name)
	{
		root.name = root_name;
	}

	void add_child(std::string child_name, std::string child_text)
	{
		HtmlElement e{ child_name, child_text };
		root.elements.emplace_back(e);
	}

	std::string str() const { return root.str(); }
};

int main1()
{
	HtmlBuilder builder{ "ul" };
	builder.add_child("li", "hello");
	builder.add_child("li", "world");
	std::cout << builder.str() << std::endl;
	return 0;
}