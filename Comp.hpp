#include <iostream>

template <class T>
bool bigger(T first, T second) {
	if (first > second) return 1;
	else return 0;
}

template <class T>
bool lower(T first, T second) {
	if (first < second) return 1;
	else return 0;
}
