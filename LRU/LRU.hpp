#ifndef LRU_H_

#define LRU_H_

#include <list>
#include <cstdlib>
#include <unordered_map>
#include <iostream>


template <typename page_t>
class LRU {
private:
	size_t sz_;
	std::list<page_t> L;
	using ListIt = typename std::list<page_t>::iterator;
	ListIt It;
	std::unordered_map<page_t, ListIt> M;
	using MapIt = typename std::unordered_map<page_t, ListIt>::iterator;

public:
	LRU(size_t sz): sz_(sz) {}
	
	~LRU() {}
	
	bool refer(page_t page) {
		bool found = false;
		if (M.find(page) == M.end()) {
			if (L.size() == sz_) {
				page_t last = L.back();
				L.pop_back();
				M.erase(last);
			}
		} else {
			found = true;
			L.erase(M[page]);
		}
		L.push_front(page);
		M[page] = L.begin();
		return found;
	}

	void display() {
		for (ListIt it = L.begin(); it != L.end(); it ++) {
			std::cout << (*it) << " ";
		}
		std::cout << std::endl;
	}
};


#endif			// LRU_H_
