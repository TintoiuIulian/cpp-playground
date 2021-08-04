// Includes

// C++ system headers
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// 3rd party libs headers
#include <SimpleIni.h>

/**
	Define a simple book.
*/
class Book
{
public:
	std::string name;
	std::string authors;

	void print()
	{
		std::cout << this->name << std::endl;
		std::cout << "\t(by " << this->authors << ")" << std::endl;
	}
};

/**
	Reads a vector of books from an INI file.
	Note: the INI file shall contain a general books section with the number of books contained,
	and another INI section for each book, named [book.N], where N is a number/counter

	[books]
	count = 2;

	[book.1]
	name=The origin of truth
	author=Gusti
	[book.2]
	name  = Arhanghelul Raul
	author=Ovidiu Eftimie

	@param file_name The name of the file to read from (must include path).
	@return Vector of books.
*/
std::vector<Book> readBooksFromIniFile(const std::string& file_name)
{
	std::vector<Book> results;
	// TODO: BEGIN read the file -------------------------------------
	
	CSimpleIniA ini;
	ini.SetUnicode();
	const char* name1;
	const char* auth1;
	const char* name2;
	const char* auth2;
	const char* name3;
	const char* auth3;
	const char* name4;
	const char* auth4;

	ini.LoadFile("../../data/ermahgerd_berks.ini");

	name1 = ini.GetValue("book.1", "name");
	auth1 = ini.GetValue("book.1", "author");

	name2 = ini.GetValue("book.2", "name");
	auth2 = ini.GetValue("book.2", "author");

	name3 = ini.GetValue("book.3", "name");
	auth3 = ini.GetValue("book.3", "author");

	name4 = ini.GetValue("book.4", "name");
	auth4 = ini.GetValue("book.4", "author");

	std::string book1;
	std::string author1;
	std::stringstream ss_b1;
	std::stringstream ss_a1;

	std::string book2;
	std::string author2;
	std::stringstream ss_b2;
	std::stringstream ss_a2;

	std::string book3;
	std::string author3;
	std::stringstream ss_b3;
	std::stringstream ss_a3;

	std::string book4;
	std::string author4;
	std::stringstream ss_a4;
	std::stringstream ss_b4;

	ss_b1 << name1;
	book1 = ss_b1.str();
	ss_a1 << auth1;
	author1 = ss_a1.str();

	ss_b2 << name2;
	book2 = ss_b2.str();
	ss_a2 << auth2;
	author2 = ss_a2.str();

	ss_b3 << name3;
	book3 = ss_b3.str();
	ss_a3 << auth3;
	author3 = ss_a3.str();

	ss_b4 << name4;
	book4 = ss_b4.str();
	ss_a4 << auth4;
	author4 = ss_a4.str();

	Book myBook1;
	myBook1.name = book1;
	myBook1.authors = author1;

	results.emplace_back(myBook1);

	Book myBook2;
	myBook2.name = book2;
	myBook2.authors = author2;

	results.emplace_back(myBook2);

	Book myBook3;
	myBook3.name = book3;
	myBook3.authors = author3;

	results.emplace_back(myBook3);

	Book myBook4;
	myBook4.name = book4;
	myBook4.authors = author4;

	results.emplace_back(myBook4);



	// E.g. Book myBook;
	//		// build the section name (E.g. book.1)
	//		std::stringstream ss;
	//		ss << "book." << (i + 1);
	//		// Copy the stream to a string you can use
	//		std::string section_name(ss.str());

	//		...
	//		results.emplace_back(myBook);

	// TODO: END read file and add to results vector ------------------
	return results;
}

int main()
{
	// Read a collection of books from an INI file.
	// Using the SimpleINI C++ Lib: https://github.com/brofield/simpleini

	// Read the data
	std::string input_data("PATH_TO_INI_FILE.ini");
	std::cout << "Reading the data from " << input_data << std::endl;
	std::vector<Book> books_from_file = readBooksFromIniFile(input_data);

	// Print the data
	std::cout << "Here are all the books found in the data file..." << std::endl;
	int i = 0;
	for (auto book : books_from_file)
	{
		if (i < 4)
		{
			std::cout << "[book." << i + 1 << "]" << std::endl;
			i++;
			book.print();
		}
	}

	return 0;
}