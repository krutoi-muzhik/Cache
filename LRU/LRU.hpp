#ifndef LRU_H_

#define LRU_H_

#include <list>
#include <cstdlib>
#include <unordered_map>
#include <iostream>


template <typename page_num_t, typename page_t>
class LRU {
private:
	size_t sz_;
	std::list<page_t> L;
	using ListIt = typename std::list<page_t>::iterator;
	ListIt It;
	std::unordered_map<page_num_t, ListIt> M;
	using MapIt = typename std::unordered_map<page_num_t, ListIt>::iterator;

public:
	LRU(size_t sz): sz_(sz) {}
	~LRU() {}
	bool hit(page_num_t pn);
	bool refer(page_num_t pn, page_t p);
	void display();
};

template<typename page_num_t, typename page_t>
bool LRU<page_num_t, page_t>::hit(page_num_t pn) {
	if (M.find(pn) == M.end())
		return false;

	return true;
}

template<typename page_num_t, typename page_t>
bool LRU<page_num_t, page_t>::refer(page_num_t pn, page_t p) {
	bool hit_;
	hit_ = hit(pn);

	if (hit_) {
		L.erase(M[pn]);
	} else {
		if (L.size() == sz_) {
			M.erase(M.find(L.end()));
			L.pop_back();
		}
	}

	L.push_front(p);
	M[pn] = L.begin();

	return hit_;
}

template<typename page_num_t, typename page_t>
void LRU<page_num_t, page_t>::display() {
	for (ListIt it = L.begin(); it != L.end(); it ++) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}

#endif			// LRU_H_
