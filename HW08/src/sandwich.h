#ifndef SANDWICH_H
#define SANDWICH_H
#include "bits/stdc++.h"
using namespace std;

class Sandwich{
public:
	Sandwich(int price, int id){
		if(price < 0)
			throw std::invalid_argument("price < 0");
		int_price = price;
		int_id = id;

		record.insert(id);
	}
	virtual ~Sandwich(){
		record.erase(int_id);
	}
	int get_price() const{
		return int_price;
	}
	int get_id() const{
		return int_id;
	}
	static bool record_has_specific_id(int id){
		if(record.count(id))
			return true;
		return false;
	}
	static int get_size_of_record_container(){
		return record.size();
	}
protected:
	int int_price = 0;
	int int_id = 0;
private:
	static set<int> record;
};
set<int> Sandwich::record = {};
#endif