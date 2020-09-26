#include <iostream>
#include <forward_list>
#include <algorithm>
#include <iterator>
#include "findBefore.hpp"

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
		// forward_list没有size等函数，可以用distance代替
		std::forward_list<int> l;
		std::cout << "l.size(): " << std::distance(l.cbegin(), l.cend()) << std::endl;		// distance具有线性复杂度
	}

	{
		// 再前面插入4 5 6
		std::forward_list<int> fwlist = { 1, 2, 3 };
		fwlist.insert_after(fwlist.cbefore_begin(), { 4,5,6 });
		PRINT_ELEMENTS(fwlist, "fwlist: ");

		//fwlist.insert_after(fwlist.end(), 55);			// RUNTIME ERROR 绝不可在最后调用insert_after
		}

	{
		// funtion 在第一个偶数前面插入42
		std::forward_list<int> fwlist = { 1, 2, 3, 4, 5, 6 };

		std::forward_list<int>::iterator pre = fwlist.before_begin();
		for (auto pos = fwlist.begin(); pos != fwlist.end(); ++pos, ++pre) {
			if (*pos % 2 == 0)
				break;
		}
		fwlist.insert_after(pre, 42);
		PRINT_ELEMENTS(fwlist, "fwlist: ");

		// 另外一种做法，使用C++的next
		pre = fwlist.before_begin();
		for (; std::next(pre) != fwlist.end(); ++pre) {
			if (*std::next(pre) % 2 == 0)
				break;
		}
		fwlist.insert_after(pre, 42);
		PRINT_ELEMENTS(fwlist, "fwlist: ");

	}

	{
		// funtion 在第一个偶数前面插入42
		std::forward_list<int> fwlist = { 1, 2, 3, 4, 5, 6 };

		auto pre = find_before_if(fwlist.before_begin(), fwlist.end(),
			[](int i) { 
				return i % 2 == 0; 
			});

		fwlist.insert_after(pre, 42);
		PRINT_ELEMENTS(fwlist, "fwlist: ");
	}

	{
		std::forward_list<int> l1 = { 1, 2, 3, 4, 5, 6 };
		std::forward_list<int> l2 = { 97, 98, 99 };

		auto pre1 = find_before(l1.before_begin(), l1.end(), 3);		// 查找3在L1
		auto pre2 = find_before(l2.before_begin(), l2.end(), 99);		// 查找99在L2

		l2.splice_after(pre2, l1, pre1);
		PRINT_ELEMENTS(l1, "l1: ");
		PRINT_ELEMENTS(l2, "l2: ");

		//l2.splice_after(l2.end(), l2, l2.begin());						// ERROR 不可在end()调用splice_after
	}
}





