#pragma once
#include <string>

class PersonBuilder;
class Person
{
	std::string street_address, post_code, city;

	std::string company_name, position;
	int annual_income{ 0 };
public:
	static PersonBuilder create();

	friend class PersonBuilder;
	friend class PersonJobBuilder;
	friend class PersonAddressBuilder;
};