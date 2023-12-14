#ifndef BIKE_H
#define BIKE_H
#include "bits/stdc++.h"
using namespace std;

class Bike{
protected:
	int int_price = 0;
	int int_id = 0;
public:
	Bike(int ID, int rent_price){
		if(rent_price < 0)
			throw std::invalid_argument("price < 0");
		int_price = rent_price;
		int_id = ID;
	}
	virtual ~Bike(){}
	int get_id() const{
		return int_id;
	}
	int get_rental_price() const{
		return int_price;
	}
	virtual std::string to_string() = 0;
};
#endif