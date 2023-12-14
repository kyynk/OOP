#ifndef SWEET_SANDWICH_H
#define SWEET_SANDWICH_H
#include "bits/stdc++.h"
#include "sandwich.h"
using namespace std;

class SweetSandwich : public Sandwich{
public:
	SweetSandwich(int price, int id) : Sandwich(price, id)
	{
		sweet_record.insert(id);
	}
	~SweetSandwich(){
		sweet_record.erase(int_id);
	}
	static bool record_has_specific_id(int id){
		if(sweet_record.count(id))
			return true;
		return false;
	}
	static int get_size_of_record_container(){
		return sweet_record.size();
	}
private:
	static set<int> sweet_record;
};
set<int> SweetSandwich::sweet_record = {};
#endif