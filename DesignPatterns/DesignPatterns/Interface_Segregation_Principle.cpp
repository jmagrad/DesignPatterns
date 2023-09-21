#include <iostream>


class Document;

class IMachine
{
	virtual void print(Document& doc) = 0;
	virtual void scan(Document& doc) = 0;
	virtual void fax(Document& doc) = 0;
};

class MFP : public IMachine
{
	void print(Document& doc) override
	{

	}
	void scan(Document& doc) override
	{

	}
	void fax(Document& doc) override
	{

	}
};

int main()
{

	return 0;
}