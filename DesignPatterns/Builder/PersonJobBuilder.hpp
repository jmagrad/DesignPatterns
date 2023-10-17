#pragma once
#include <string>
#include "PersonBuilder.hpp"

class PersonJobBuilder : public PersonBuilderBase
{
	typedef PersonJobBuilder self;
public:
	PersonJobBuilder(Person& person) :PersonBuilderBase(person) {}

	self& at(std::string company_name)
	{
		person.company_name = company_name;
		return *this;
	}

	self& as_a(std::string position)
	{
		person.position = position;
		return *this;
	}

	self& earning(int annual_income)
	{
		person.annual_income = annual_income;
		return *this;
	}
};

