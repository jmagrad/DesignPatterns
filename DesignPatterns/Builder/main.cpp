#include <iostream>
#include "PersonBuilder.hpp"
#include "Person.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonJobBuilder.hpp"

using namespace std;

int main()
{
	Person p = Person::create().lives().at("123 London Rd")
		.with_postcode("98102").in("London")
		.works().at("Blue")
		.as_a("SDE").earning(800000);

	return 0;
}