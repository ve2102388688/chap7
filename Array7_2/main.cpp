#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>				// accumulate
#include <string>
#include <array>

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
		std::array<int, 4> x;						// 初值不明确
		std::array<int, 4> x1{};					// 初值0
		std::array<int, 4> x2 = {42};				// 剩余初值0
		//std::array<int, 4> x2 = {42, 1, 2, 3, 4};	// Complie ERROR

		std::array<int, 5> x3({ 1, 2, 3, 4, 5 });
		std::array<int, 5> x4{ { 1, 2, 3, 4, 5 } };	// 注意双花括号
		PRINT_ELEMENTS(x4, "x4: ");

		x4.fill(10);								// 一次性填充
		PRINT_ELEMENTS(x4, "x4: ");
	}

	{
		// array当成C-style array，使用data()
		std::array<char, 41> a;
		strcpy(&a[0], "hello, world");				// 必须&a[0]，不能是a
		printf("%s\n", &a[0]);

		strcpy(a.data(), "hello, C++");
		printf("%s\n", a.data());

		// begin()返回的是迭代器指针
		//printf("%s\n", a.begin());			// 不要这么干....
	}

	{
		typedef std::array<std::string, 5> FiveString;
		FiveString a = { "hello", "nico", "how", "are", "you" };

		std::cout << std::get<1>(a) << std::endl;
	}

	{
		std::array<int, 10> a = { 11, 22, 33, 44 };
		PRINT_ELEMENTS(a, "a: ");

		// modify last two elements;
		a.back() = 8888;
		a[a.size() - 2] = 10;					// -2是倒数第二个
		PRINT_ELEMENTS(a, "change a: ");

		// sum of array
		std::cout << "sum a: " << std::accumulate(a.cbegin(), a.cend(), 0) << std::endl;

		// negative all element
		std::transform(a.begin(), a.end(), a.begin(), std::negate<int>());
		PRINT_ELEMENTS(a, "negate a: ");
	}
}