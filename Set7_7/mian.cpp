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
		// ����һ������Ķ˵�-pair<iterator, iterator>,ע������ҿ���[4,4)��������
		std::cout << "equal_range(3): " << *c.equal_range(3).first << " " << *c.equal_range(3).second << std::endl;


		std::cout << "\nlower_bound(5): " << *c.lower_bound(5) << std::endl;
		std::cout << "lower_bound(5): " << *c.upper_bound(5) << std::endl;
		// ����һ������Ķ˵�-pair<iterator, iterator>,ע������ҿ�
		std::cout << "equal_range(5): " << *c.equal_range(5).first << " " << *c.equal_range(5).second << std::endl;

	}

	{
		// ɾ��mutiset�ĵ�һ��Ԫ��
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
		
		// �����ظ���Ԫ��4.�ۿ����
		auto status = coll1.insert(4);
		if (status.second) {
			std::cout << "4 inserted as element " << std::distance(coll1.cbegin(), status.first) + 1 << std::endl;
		} else {
			std::cout << "4 is already exists" << std::endl;
		}
		
		// �����coll2
		std::set<int> coll2(coll1.cbegin(), coll1.cend());
		PRINT_ELEMENTS(coll2, "coll2: ");
		
		// ɾ��3֮ǰ��Ԫ��,ע���ұ��ǿ����䣬ʵ����ֻɾ����1 2 
		coll2.erase(coll2.begin(), coll2.find(3));

		int num = coll2.erase(5);
		std::cout << num << " elements removed." << std::endl;
		PRINT_ELEMENTS(coll2, "coll2: ");

		// mutisetֻ������λ�ã�����ȥ�жϳɹ�����ʧ��

	}

	{
		typedef std::set<int, RuntimeCmp> IntSet;

		IntSet coll1 = { 4,7,5,1,6,2,5 };
		PRINT_ELEMENTS(coll1, "coll1: ");

		// ����һ������ıȽϷ�ʽ
		RuntimeCmp reverse_order(RuntimeCmp::reverse);
		IntSet coll2(reverse_order);
		coll2 = { 4,7,5,1,6,2,5 };
		PRINT_ELEMENTS(coll2, "coll2: ");

		coll1 = coll2;				// ��ֵ������Ԫ�ض��ұȽϷ�ʽҲ�ᱻ����
		coll1.insert(3);
		PRINT_ELEMENTS(coll1, "coll1: ");

		if (coll1.value_comp() == coll2.value_comp()) {
			std::cout << "coll1 & coll2 have same sorting criterion";
		}else {
			std::cout << "coll1 & coll2 have different sorting criterion";
		}

	}

}