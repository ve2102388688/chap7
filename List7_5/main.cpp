#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void printLists(const std::list<int>& list1, const std::list<int>& list2) {
	std::cout << "\nlist1: ";
	std::copy(list1.cbegin(), list1.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\nlist2: ";
	std::copy(list2.cbegin(), list2.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}


int main()
{
	{
		std::list<int> coll;

		if (!coll.empty())							// 为空，不能访问首尾元素
			std::cout << coll.front();
	}

	{
		std::list<int> list1, list2;

		for (size_t i = 0; i < 6; i++) {
			list1.push_back(i);
			list2.push_front(i);
		}
		printLists(list1, list2);

		// 将list1合并到list2的3之前,此时list1已经空出来了
		list2.splice(std::find(list2.cbegin(), list2.cend(), 3), list1);
		printLists(list1, list2);

		// 将list2中第一个元素移动到最后一个
		list2.splice(list2.end(), list2, list2.begin());
		printLists(list1, list2);

		// 对list2排序，并赋值给list1，再删除list2中重复的元素
		list2.sort();
		list1 = list2;
		list2.unique();
		printLists(list1, list2);

		// merge list1 & list2
		list1.merge(list2);
		printLists(list1, list2);



	}
}