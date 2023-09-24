#ifndef CACHE_H

#define CACHE_H

typedef page_t int;

page_t getpage();


template <typename T, typename KeyT = int>
class cache_t {
	size_t sz_;

	cache_t(size_t sz, size_t sz2): sz_(sz) {}
	

};




#endif				// CACHE_H
