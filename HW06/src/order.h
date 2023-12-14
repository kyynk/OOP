#ifndef ORDER_H
#define ORDER_H
#include "bits/stdc++.h"
#include "alcohol.h"
using namespace std;

class Order{
public:
	/* The default constructor of the Order. */
	Order() = default;

	/* The constructor of the Order. */
	Order(vector <Alcohol*> temp){
		alcVec = temp;
	}

	/* The copy constructor of the Order. */
	Order(const Order& temp) = default;

	/* The destructor of the Order. */
	~Order() = default;

	vector<Alcohol*>& getVector() {
		return alcVec;
	}

	void append_alcohol(Alcohol* alcohol){
		alcVec.push_back(alcohol);
	}

	int get_alcohol_count(){
		return alcVec.size();
	}
	
	int get_total_price(){
		int total_price = 0;
		for (int i=0; i<alcVec.size(); i++){
			total_price += alcVec[i]->get_price();
		}
		return total_price;
	}

private:
	vector <Alcohol*> alcVec;
};
#endif