#include <memory>
#include <iostream>
#include <vector>
#include <sstream>
class HtmlElement
{
private:
	friend class HtmlBuilder;
	HtmlElement() {}

	HtmlElement(const std::string& name, const std::string& text) : name(name), txt(text)
	{}
public:
	std::string name, txt;
	std::vector<HtmlElement> elements;

	const size_t indent_size = 2;



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

	//static HtmlBuilder create(std::string root_name)
	//{
	//	return { root_name };
	//}

	
};

class HtmlBuilder
{

private:
	HtmlElement root;
public:
	

	HtmlBuilder(std::string root_name)
	{
		root.name = root_name;
	}

	HtmlBuilder& add_child(std::string child_name, std::string child_text)
	{
		HtmlElement e{ child_name, child_text };
		root.elements.emplace_back(e);
		return *this;
	}

	HtmlBuilder* add_child_2(std::string child_name, std::string child_text)
	{
		HtmlElement e{ child_name, child_text };
		root.elements.emplace_back(e);
		return this;
	}

	HtmlElement build() { return root; }

	std::string str() const { return root.str(); }
	operator HtmlElement() const { return root; }
};

int main2()
{
	HtmlBuilder builder{ "ul" };
	builder.add_child("li", "hello").add_child("li", "world");
	std::cout << builder.str() << std::endl;

	//auto builder2 = HtmlElement::create("ul").add_child("", "");

	return 0;
}