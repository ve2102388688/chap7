#include <iostream>
#include <deque>
#include <string>
#include <iterator>
#include <algorithm>

int main()
{
	std::deque<std::string>  coll;

	// ¿½±´³õÊ¼»¯
	coll.assign(3, std::string("string"));
	coll.push_back("last string");
	coll.push_front("first string");

	// Êä³ö
	std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
	std::cout << std::endl;

	coll.pop_back();
	coll.pop_front();

	for (size_t i = 1; i < coll.size(); i++) {
		coll[i] = "another " + coll[i];
	}

	coll.resize(4, "resized string");
	std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
	std::cout << std::endl;

}



