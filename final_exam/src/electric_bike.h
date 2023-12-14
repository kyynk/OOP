#ifndef ELECTRIC_BIKE_H
#define ELECTRIC_BIKE_H
#include "bits/stdc++.h"
#include "bike.h"
using namespace std;

class ElectricBike : public Bike{
protected:
	double db_power = 0;
public:
	ElectricBike(int ID, int rent_price, double power = 0) : Bike(ID, rent_price)
	{
		if(power > 1 || power < 0)
			throw std::invalid_argument("power out of range");
		db_power = power;
	}
	~ElectricBike(){}
	double get_power() const{
		return db_power;
	}
	void set_power(double power){
		if(power > 1 || power < 0)
			throw std::invalid_argument("power out of range");
		db_power = power;
	}
	std::string to_string() override{
		char str[100];
		sprintf(str, "%d-ElectricBike price=%d power=%.2f", int_id, int_price, db_power);
		return str;
	}
};
#endif