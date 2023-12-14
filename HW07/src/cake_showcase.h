#ifndef CAKE_SHOWCASE_H
#define CAKE_SHOWCASE_H
#include "bits/stdc++.h"
#include "cake.h"
#include "chocolate_cake.h"
#include "geode_cake.h"
#include "honey_cake.h"
using namespace std;

template <typename T>

class CakeShowcase{
public:
	CakeShowcase(int length, T** array){
		int_len = length;
		T_Vec.clear();
		for(int i=0; i<length; i++)
			T_Vec.push_back(array[i]);
	}

	~CakeShowcase(){}

	int calc_total_price(){
		int total_price = 0;
		for (int i=0; i<int_len; i++)
			total_price += T_Vec.at(i)->get_price();
		
		// cout << "total_price " << total_price << endl;
		return total_price;
	}

	int calc_total_sweet(){
		int total_sweet = 0;
		for (int i=0; i<int_len; i++)
			total_sweet += T_Vec.at(i)->get_sweet();
		
		// cout << "total_sweet " << total_sweet << endl;
		return total_sweet;
	}

	std::string to_string(){
		string str="";
		str += "| CakeName             | Price      | Sweet      |\n| -------------------- | ---------- | ---------- |\n";
		for (int i=0; i<int_len; i++){
			str += T_Vec[i]->to_string();
			str += "\n";
		}
		str += "| -------------------- | ---------- | ---------- |";
		return str;
	}

	T* operator[](int index){
		try{
			return T_Vec.at(index);
		}catch(std::out_of_range& o_o_r){
			throw std::out_of_range("out of range");
		}
	}
private:
	int int_len = 0;
	vector<T*> T_Vec;
};
#endif