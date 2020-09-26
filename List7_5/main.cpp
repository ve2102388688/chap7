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

		if (!coll.empty())							// Ϊ�գ����ܷ�����βԪ��
			std::cout << coll.front();
	}

	{
		std::list<int> list1, list2;

		for (size_t i = 0; i < 6; i++) {
			list1.push_back(i);
			list2.push_front(i);
		}
		printLists(list1, list2);

		// ��list1�ϲ���list2��3֮ǰ,��ʱlist1�Ѿ��ճ�����
		list2.splice(std::find(list2.cbegin(), list2.cend(), 3), list1);
		printLists(list1, list2);

		// ��list2�е�һ��Ԫ���ƶ������һ��
		list2.splice(list2.end(), list2, list2.begin());
		printLists(list1, list2);

		// ��list2���򣬲���ֵ��list1����ɾ��list2���ظ���Ԫ��
		list2.sort();
		list1 = list2;
		list2.unique();
		printLists(list1, list2);

		// merge list1 & list2
		list1.merge(list2);
		printLists(list1, list2);



	}
}