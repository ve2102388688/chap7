#pragma once

#ifndef __FINDBEFORE_H
#define __FINDBEFORE_H

/// @breif ���ض�ֵ��ǰһλ��
template <typename InputIterator, typename T>
inline InputIterator find_before(InputIterator first, InputIterator last, const T& val) {
	if (first == last)
		return first;

	InputIterator next(first);
	++next;
	while (next != last && !(*next==val)){
		++first;
		++next;
	}
	return first;
}


/// @breif ����������ǰһλ��
template <typename InputIterator, typename Pred>
inline InputIterator find_before_if(InputIterator first, InputIterator last, Pred pred) {
	if (first == last)
		return first;

	InputIterator next(first);
	++next;
	while (next != last && !pred(*next)) {
		++first;
		++next;
	}
	return first;
}




#endif // !__FINDBEFORE_H
