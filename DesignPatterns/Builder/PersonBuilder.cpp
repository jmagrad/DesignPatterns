#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonJobBuilder.hpp"

PersonBuilderBase::PersonBuilderBase(Person& person) : person(person) {}

PersonBuilder::PersonBuilder() : PersonBuilderBase(person) {}


PersonAddressBuilder PersonBuilderBase::lives() const
{
	return PersonAddressBuilder{ person };
}

PersonJobBuilder PersonBuilderBase::works() const
{
	return PersonJobBuilder{person};
}

