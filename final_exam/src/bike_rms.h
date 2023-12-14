#ifndef BIKE_RMS_H
#define BIKE_RMS_H
#include "bits/stdc++.h"
#include "bike.h"
#include "electric_bike.h"
#include "mybike.h"

using namespace std;

class BikeRMS{
private:
	vector<Bike*> Bike_vec;
	vector<int> all;
	static set<int> rent;
	static set<int> have;
	static int income;
public:
	BikeRMS(std::vector<Bike*> bikes){
		for(int i=0; i<bikes.size(); i++){
			Bike_vec.push_back(bikes[i]);
			have.insert(bikes[i]->get_id());
			// cout << *have.find(bikes[i]->get_id());
			all.push_back(bikes[i]->get_id());
			// cout << bikes[i]->get_id() << " " << Bike_vec[i]->get_id() << endl;
		}
		cout << endl;
	}
	~BikeRMS(){
		for(int i=0; i<all.size(); i++){
			// cout << all[i] << " ";
			if(rent.count(all[i]))
				rent.erase(all[i]);
			// cout << "have erase :" << have.erase(all[i]) << endl;
			have.erase(all[i]);
		}
		// cout << endl;
	}
	int get_count_of_available_bike(){
		int available = 0;
		for(int i=0; i<Bike_vec.size(); i++){
			if(rent.count(Bike_vec[i]->get_id()) == 0)
				available ++;
		}
		return available;
	}
	Bike* rent_bike(int ID){
		int inBike = -1;
		// cout << "a";
		for(int i=0; i<Bike_vec.size(); i++){
			// cout << Bike_vec[i]->get_id() << endl;
			if(all[i]== ID){
				inBike = i;
				break;
			}
		}
		// cout << ID << endl;
		if(inBike == -1)
			throw std::invalid_argument("ID out of range");
		if(rent.count(ID) == 1)
			throw std::invalid_argument("unavailable");
		// cout << "aaa" << endl;
		rent.insert(ID);
		
		income += Bike_vec[inBike]->get_rental_price();

		return Bike_vec[inBike];
	}
	void return_bike(Bike* bike){
		// cout << bike->get_id() << endl;
		if(rent.count(bike->get_id()) == 0)
			throw std::invalid_argument("ID is not belong or already exists in bikeRMS");
		rent.erase(bike->get_id());
	}
	void append_bike(Bike* bike){
		if(have.count(bike->get_id()))
			throw std::invalid_argument("already exists");
		Bike_vec.push_back(bike);
		all.push_back(bike->get_id());
		have.insert(bike->get_id());
		// cout << "append " << *have.find(bike->get_id()) << endl;
	}
	static int get_total_rental_income(){
		return income;
	}
	static void reset_total_rental_income(){
		income = 0;
	}
};
set<int> BikeRMS::rent = {};
set<int> BikeRMS::have = {};
int BikeRMS::income = 0;
#endif