#ifndef ARC_H_

#define ARC_H_

#define MIN(x, y):	(x > y) ? y : x

#define MAX(x, y):	(x > y) ? x : y

template <typename page_t>
class ARC {
private:
	size_t sz_;
	size_t p;
	LRU T1, T2, B1, B2;


	ARC(size_t sz): sz_(sz), T1(sz), T2(sz), B1(sz), B2(sz) {}
	
	~ARC() {}

	refer(page_t)

};




#undef MIN
#undef MAX

#endif				// ARC_H_
