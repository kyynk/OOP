#ifndef SANDWICH_FACTORY_H
#define SANDWICH_FACTORY_H
#include "bits/stdc++.h"
#include "sandwich.h"
#include "beef_sandwich.h"
#include "sweet_sandwich.h"
using namespace std;

template <typename T>

class SandwichFactory{
public:

	static T* create_sandwich(int price, int id){
		return new T(price, id);
	}
	static vector<T*> create_sandwich_array(int price, int count, std::vector<int> id_list){
		if(count < 0)
			throw std::invalid_argument("count < 0");
		vector<T*> T_Vec;
		for(int i=0; i<count; i++){
			T_Vec.push_back(new T(price, id_list[i]));
		}
		return T_Vec;
	}
// private:
// 	static vector<T*> T_Vec;
};
// template <typename T>
// vector<T*> SandwichFactory<T>::T_Vec = {};
// 放在外面的時候
/*
template <typename T>
T* SandwichFactory<T>::create_sandwich(int price, int id){
	return new T(price, id);
}
template <typename T>
vector<T*> SandwichFactory<T>::create_sandwich_array(int price, int count, std::vector<int> id_list){
	if(count < 0)
		throw std::invalid_argument("count < 0");
	vector<T*> T_Vec;
	for(int i=0; i<count; i++){
		T_Vec.pushback(new T(price, id_list[i]));
	}
	return T_Vec;
}
*/
#endif