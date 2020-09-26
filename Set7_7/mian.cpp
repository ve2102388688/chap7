#include <iostream>
#include <set>
#include <functional>
#include "compare.hpp"

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
		std::set<int> c;
		for (size_t i = 0; i < 7; i++) {
			c.insert(i);
		}
		c.erase(3);

		std::cout << "lower_bound(3): " << *c.lower_bound(3) << std::endl;
		std::cout << "lower_bound(3): " << *c.upper_bound(3) << std::endl;
		// 返回一个区间的端点-pair<iterator, iterator>,注意左闭右开，[4,4)即不存在
		std::cout << "equal_range(3): " << *c.equal_range(3).first << " " << *c.equal_range(3).second << std::endl;


		std::cout << "\nlower_bound(5): " << *c.lower_bound(5) << std::endl;
		std::cout << "lower_bound(5): " << *c.upper_bound(5) << std::endl;
		// 返回一个区间的端点-pair<iterator, iterator>,注意左闭右开
		std::cout << "equal_range(5): " << *c.equal_range(5).first << " " << *c.equal_range(5).second << std::endl;

	}

	{
		// 删除mutiset的第一个元素
		std::multiset<int> coll = { 1, 2, 2, 3, 4, 6 };
		PRINT_ELEMENTS(coll, "Origin: ");

		std::multiset<int>::iterator pos = coll.find(2);
		if (pos != coll.end()) {
			coll.erase(pos);
		}
		PRINT_ELEMENTS(coll, "After: ");
	}

	{
		std::set<int, std::greater<int>> coll1;
		coll1.insert({ 4,3,5,1,6,2 });
		coll1.insert(5);
		PRINT_ELEMENTS(coll1, "coll1: ");
		
		// 插入重复的元素4.观看输出
		auto status = coll1.insert(4);
		if (status.second) {
			std::cout << "4 inserted as element " << std::distance(coll1.cbegin(), status.first) + 1 << std::endl;
		} else {
			std::cout << "4 is already exists" << std::endl;
		}
		
		// 反序给coll2
		std::set<int> coll2(coll1.cbegin(), coll1.cend());
		PRINT_ELEMENTS(coll2, "coll2: ");
		
		// 删除3之前的元素,注意右边是开区间，实际上只删除了1 2 
		coll2.erase(coll2.begin(), coll2.find(3));

		int num = coll2.erase(5);
		std::cout << num << " elements removed." << std::endl;
		PRINT_ELEMENTS(coll2, "coll2: ");

		// mutiset只返回新位置，不用去判断成功还是失败

	}

	{
		typedef std::set<int, RuntimeCmp> IntSet;

		IntSet coll1 = { 4,7,5,1,6,2,5 };
		PRINT_ELEMENTS(coll1, "coll1: ");

		// 定义一个反序的比较方式
		RuntimeCmp reverse_order(RuntimeCmp::reverse);
		IntSet coll2(reverse_order);
		coll2 = { 4,7,5,1,6,2,5 };
		PRINT_ELEMENTS(coll2, "coll2: ");

		coll1 = coll2;				// 赋值，不仅元素而且比较方式也会被拷贝
		coll1.insert(3);
		PRINT_ELEMENTS(coll1, "coll1: ");

		if (coll1.value_comp() == coll2.value_comp()) {
			std::cout << "coll1 & coll2 have same sorting criterion";
		}else {
			std::cout << "coll1 & coll2 have different sorting criterion";
		}

	}

}