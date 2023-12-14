#ifndef HONEY_CAKE_H
#define HONEY_CAKE_H
#include "bits/stdc++.h"
#include "cake.h"
using namespace std;

class HoneyCake : public Cake{
public:
	/* The constructor of the HoneyCake. */
	HoneyCake(int price, int sweet) : Cake(price, sweet)
	{
		// cout << "HoneyCake" << endl;
		count_Honey ++;
	}

	/* The destructor of the HoneyCake. */
	~HoneyCake(){
		count_Honey --;
	}

	std::string to_string() override{
		char chP_des[1000];
		sprintf(chP_des, "| %-21s|%11d |%11d |", "HoneyCake", int_price, int_sweet);
		return chP_des;
	}

	static int get_count(){
		return count_Honey;
	}
private:
	static int count_Honey;
};
int HoneyCake::count_Honey = 0;
#endif