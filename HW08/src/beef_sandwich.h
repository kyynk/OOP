#ifndef BEEF_SANDWICH_H
#define BEEF_SANDWICH_H
#include "bits/stdc++.h"
#include "sandwich.h"
using namespace std;

class BeefSandwich : public Sandwich{
public:
	BeefSandwich(int price, int id) : Sandwich(price, id)
	{
		beef_record.insert(id);
	}
	~BeefSandwich(){
		beef_record.erase(int_id);
	}
	static bool record_has_specific_id(int id){
		if(beef_record.count(id))
			return true;
		return false;
	}
	static int get_size_of_record_container(){
		return beef_record.size();
	}
private:
	static set<int> beef_record;
};
set<int> BeefSandwich::beef_record = {};
#endif