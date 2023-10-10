#pragma once
#include <string>

class Person
{

	std::string street_address, post_code, city;

	std::string company_name, position;
	int annual_income{ 0 };

	friend class PersonBuilder;
	friend class PersonJobBuilder;
	friend class PersonAddressBuilder;
};