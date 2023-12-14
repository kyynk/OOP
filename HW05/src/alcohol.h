#ifndef ALCOHOL_H
#define ALCOHOL_H
#include "bits/stdc++.h"
using namespace std;

class Alcohol{
public:
	/* The default constructor of the Alcohol. */
	Alcohol() = default;

	void init(std::string name, int price, double content){
		if (name.length() <= 0)
			throw std::invalid_argument("name length <= 0");
		this->str_name = name;

		if (price < 0)
			throw std::invalid_argument("price < 0");
		this->int_price = price;
		
		if (content < 0 || content > 1)
			throw std::invalid_argument("content out of range");
		this->double_content = content;
	}

	/* The constructor of the Alcohol. */
	Alcohol(std::string name, int price, double content){
		init(name, price, content);
	}

	/* The copy constructor of the Alcohol. */
	Alcohol(const Alcohol& temp){
		init(temp.get_name(), temp.get_price(), temp.get_alcohol_content());
	}

	/* The destructor of the Alcohol. */
	virtual ~Alcohol() = default;

	/* Dilute the alcohol content. */
	virtual void dilute() = 0;

	/* Return the content of the alcoholic beverage. */
	double get_alcohol_content() const {
		return double_content;
	}

	/* Return the price of the alcoholic beverage. */
	int get_price() const {
		return int_price;
	}

	/* Return the name of the alcoholic beverage. */
	std::string get_name() const {
		return str_name;
	}

protected:
	/* Put some attribute on here if necessary. */
	string str_name = "";
	double double_content = -1;
	int int_price = -1;
};
#endif