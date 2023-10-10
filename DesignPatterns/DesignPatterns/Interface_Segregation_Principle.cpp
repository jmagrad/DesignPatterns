#include <iostream>

/*
The interface segregation principle states that 
the interface of a program should be split in a 
way that the user/client would only have access
to the necessary methods related to their needs.
*/
class Document;

//class IMachine
//{
//	virtual void print(Document& doc) = 0;
//	virtual void scan(Document& doc) = 0;
//	virtual void fax(Document& doc) = 0;
//};
//
//class MFP : public IMachine
//{
//	void print(Document& doc) override
//	{
//
//	}
//	void scan(Document& doc) override
//	{
//
//	}
//	void fax(Document& doc) override
//	{
//
//	}
//};

class IPrinter
{
public:
	virtual void print(Document& doc) = 0;
};

class IScanner
{
public:
	virtual void scan(Document& doc) = 0;
};

class IFax
{
public:
	virtual void fax(Document& doc) = 0;
};

class Printer : public IPrinter
{
public:
	virtual void print(Document& doc) override{}
};

class Scanner : public IScanner
{
public:
	virtual void scan(Document& doc) override {}
};


class IMachine : public IPrinter,public IScanner
{
	
};

class Machine : public IMachine
{
	IPrinter& printer;
	IScanner& scanner;
	Machine(IPrinter& printer, IScanner& scanner):printer(printer),scanner(scanner)
	{}
	virtual void print(Document& doc) override { printer.print(doc); }
	virtual void scan(Document& doc) override { scanner.scan(doc); }
};

int main4()
{

	return 0;
}