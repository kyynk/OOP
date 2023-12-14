#ifndef MYBIKE_H
#define MYBIKE_H
#include "bits/stdc++.h"
#include "bike.h"
using namespace std;

class MyBike : public Bike{
public:
	MyBike(int ID, int rent_price) : Bike(ID, rent_price)
	{}
	~MyBike(){}
	std::string to_string() override{
		char str[100];
		sprintf(str, "%d-MyBike price=%d", int_id, int_price);
		return str;
	}
};
#endif