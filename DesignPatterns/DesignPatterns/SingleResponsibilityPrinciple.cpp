#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

struct Journal
{
	std::string title;
	std::vector<std::string> entries;
	Journal(const std::string& title) :title(title) {}

	void add_entry(const std::string& entry)
	{
		static int count = 1;
		entries.push_back(boost::lexical_cast<std::string>(count++) + ": " + entry);
	}
};

//moved save funciton out of journal
struct PersistanceManager
{
	static void save(const Journal& j, const std::string& filename)
	{
		std::ofstream ofs(filename);
		for (auto& e : j.entries)
			ofs << e << std::endl;
	}
};

int main1()
{
	Journal journal{ "diary" };
	journal.add_entry("today i programmed");
	journal.add_entry("I was good");

	PersistanceManager::save(journal, "C:\\Users\\jmagradey\\Documents\\DesignPatterns\\DesignPatterns\\journal.txt");
	return 0;
}