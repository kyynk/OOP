#ifndef CAKE_H
#define CAKE_H
#include "bits/stdc++.h"
using namespace std;

class Cake{
public:
	void init(int price, int sweet){
		total ++;
		int_price = price;
		int_sweet = sweet;
	}

	Cake(int price, int sweet){
		// cout << "Cake" << endl;
		init(price, sweet);
	}

	virtual ~Cake(){
		// cout << "~Cake" << endl;
		total --;
	}

	int get_price() const{
		return int_price;
	}

	int get_sweet() const{
		return int_sweet;
	}

	static int get_total(){
		return total;
	}

	virtual std::string to_string() = 0;

protected:
	int int_price = 0;
	int int_sweet = 0;

private:
	static int total;
};
int Cake::total = 0;
#endif