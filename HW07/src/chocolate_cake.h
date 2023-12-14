#ifndef CHOCOLATE_CAKE_H
#define CHOCOLATE_CAKE_H
#include "bits/stdc++.h"
#include "cake.h"
using namespace std;

class ChocolateCake : public Cake{
public:
	/* The constructor of the ChocolateCake. */
	ChocolateCake(int price, int sweet) : Cake(price, sweet)
	{
		// cout << "ChocolateCake" << endl;
		count_Chocolate ++;
	}

	/* The destructor of the ChocolateCake. */
	~ChocolateCake(){
		// cout << "~ChocolateCake" << endl;
		count_Chocolate --;
	}

	std::string to_string() override{
		char chP_des[1000];
		sprintf(chP_des, "| %-21s|%11d |%11d |", "ChocolateCake", int_price, int_sweet);
		return chP_des;
	}

	static int get_count(){
		return count_Chocolate;
	}
private:
	static int count_Chocolate;
};
int ChocolateCake::count_Chocolate = 0;
#endif