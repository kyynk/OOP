#ifndef BIKE_FACTORY_H
#define BIKE_FACTORY_H
#include "bits/stdc++.h"
#include "bike.h"
#include "electric_bike.h"
#include "mybike.h"

using namespace std;

template <typename T>

class BikeFactory{
public:
	static T* create_bike(int ID, int rent_price){
		return new T(ID, rent_price);
	}
	static std::vector<T*> create_bike_array(std::vector<int> IDs, std::vector<int> rent_prices){
		vector<T*> T_vec;
		for(int i=0; i<IDs.size(); i++){
			T_vec.push_back(new T(IDs[i], rent_prices[i]));
		}
		return T_vec;
	}
};
#endif