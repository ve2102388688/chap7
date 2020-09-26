#include <iostream>
#include <set>
#include <deque>
#include <vector>
#include <iterator>

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& str = "") {
	std::cout << str;
	for (const auto& e : coll)
		std::cout << e << " ";
	std::cout << std::endl;
}

int main()
{
	{
		int carray[] = { 2,3,17,33,45,77 };

		std::set<int> coll(std::begin(carray), std::end(carray));
		PRINT_ELEMENTS(coll, "copy: ");
	}

	{
		// 下面二选一，注意第二种的两层括号
		//std::deque<int> coll{ std::istream_iterator<int>(std::cin), std::istream_iterator<int>() };
		//std::cin.clear();			// 上次读完已经触发了错误标志位，需要清除才能读下一次
		//std::deque<int> coll2((std::istream_iterator<int>(std::cin)), (std::istream_iterator<int>()));
	}

	{
		// move 很快
		std::vector<int> v1 = { 2,3,17,33,45,77 };
		std::vector<int> v2 = std::move(v1);
	}





}
