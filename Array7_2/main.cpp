#pragma warning(disable:4996)
#include <iostream>
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
		std::array<int, 4> x;						// ��ֵ����ȷ
		std::array<int, 4> x1{};					// ��ֵ0
		std::array<int, 4> x2 = {42};				// ʣ���ֵ0
		//std::array<int, 4> x2 = {42, 1, 2, 3, 4};	// Complie ERROR

		std::array<int, 5> x3({ 1, 2, 3, 4, 5 });
		std::array<int, 5> x4{ { 1, 2, 3, 4, 5 } };
		PRINT_ELEMENTS(x4, "x4: ");

		x4.fill(10);
		PRINT_ELEMENTS(x4, "x4: ");
	}

	{
		// array����C-style array
		std::array<char, 41> a;
		strcpy(&a[0], "hello, world");		// ����&a[0]��������a
		printf("%s\n", &a[0]);

		strcpy(a.data(), "hello, C++");
		printf("%s\n", a.data());


		//printf("%s\n", a.begin());			// ��Ҫ��ô��....

	}
}