#pragma once
#include "Person.hpp"

class PersonBuilderBase
{
protected:
	Person& person;
	PersonBuilderBase(Person& person) : person(person) {}

	PersonAddressBuilder 
};
class PersonBuilder: public PersonBuilderBase
{
	Person p;
public:
	PersonBuilder();
};

