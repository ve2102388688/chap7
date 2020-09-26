#pragma once

#ifndef _COMPARE_H_
#define _COMPARE_H_

class RuntimeCmp
{
public:
	enum cmp_mode { normal, reverse };
private:
	cmp_mode m_mode;
public:
	RuntimeCmp(cmp_mode m = normal) : m_mode(m) {};
	~RuntimeCmp();

	// 可调用函数
	template <typename T>
	bool operator() (const T& t1, const T& t2) const {
		return m_mode == normal ? t1<t2 : t2<t1;
	}

	// 判断两个类的的排序方式是否一致
	bool operator== (const RuntimeCmp & rhs) const {
		return m_mode == rhs.m_mode;
	}

};

RuntimeCmp::~RuntimeCmp()
{
}

#endif // !_COMPARE_H_
