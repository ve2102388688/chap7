#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>


int main()
{
	{
		std::vector<int> coll;

		if(!coll.empty())							// Ϊ�գ����ܷ�����βԪ��
			std::cout << coll.front();
	}

	{
		// vector����C-style array��ʹ��data()
		std::vector<char> a;
		a.resize(40);
		strcpy(&a[0], "hello, world");				// ����&a[0]��������a
		printf("%s\n", &a[0]);

		strcpy(a.data(), "hello, C++");
		printf("%s\n", a.data());
	}

	{
		std::vector<std::string> sentenses;
		sentenses.reserve(5);

		sentenses.push_back("Hello, ");
		sentenses.insert(sentenses.end(), {"how", "are", "you", "?"});
		std::copy(sentenses.cbegin(), sentenses.cend(), std::ostream_iterator<std::string>(std::cout, " "));	// copy to screen
		std::cout << std::endl;

		std::cout << "max_size: " << sentenses.max_size() << std::endl;
		std::cout << "size: " << sentenses.size() << std::endl;
		std::cout << "capacity: " << sentenses.capacity() << std::endl;

		// swap 2 & 4 
		std::swap(sentenses[1], sentenses[3]);

		// ��?֮ǰ����always�� β��!,����?û���ˣ��е����
		sentenses.insert(std::find(sentenses.begin(), sentenses.end(), "?"), "always");
		sentenses.back() = "!";
		std::copy(sentenses.cbegin(), sentenses.cend(), std::ostream_iterator<std::string>(std::cout, " "));	// copy to screen
		std::cout << std::endl;

		std::cout << "size: " << sentenses.size() << std::endl;
		std::cout << "capacity: " << sentenses.capacity() << std::endl;


		// ɾ���������Ԫ��
		sentenses.pop_back();
		sentenses.pop_back();
		sentenses.shrink_to_fit();;
		std::cout << "size: " << sentenses.size() << std::endl;
		std::cout << "capacity: " << sentenses.capacity() << std::endl;

		std::copy(sentenses.cbegin(), sentenses.cend(), std::ostream_iterator<std::string>(std::cout, " "));	// copy to screen
		std::cout << std::endl;
	}

	{
		std::vector<bool> bl(8);
		bl[0] = 1;
		//std::copy(bl.cbegin(), bl.cend(), std::ostream_iterator<std::string>(std::cout, " "));	// copy to screen
		//std::cout << std::endl;

	}
}


