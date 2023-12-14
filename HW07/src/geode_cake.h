#ifndef GEODE_CAKE_H
#define GEODE_CAKE_H
#include "bits/stdc++.h"
#include "cake.h"
using namespace std;

class GeodeCake : public Cake{
public:
	/* The constructor of the GeodeCake. */
	GeodeCake(int price, int sweet) : Cake(price, sweet)
	{
		// cout << "GeodeCake" << endl;
		count_GeodeCake ++;
	}

	/* The destructor of the GeodeCake. */
	~GeodeCake(){
		count_GeodeCake --;
	}

	std::string to_string() override{
		char chP_des[1000];
		sprintf(chP_des, "| %-21s|%11d |%11d |", "GeodeCake", int_price, int_sweet);
		return chP_des;
	}

	static int get_count(){
		return count_GeodeCake;
	}
private:
	static int count_GeodeCake;
};
int GeodeCake::count_GeodeCake = 0;
#endif