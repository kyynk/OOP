#ifndef SOUR_H
#define SOUR_H
#include "bits/stdc++.h"
#include "alcohol.h"
using namespace std;

class Sour : public Alcohol{
public:
	/* The default constructor of the Sour. */
	Sour() = default;

	/* The constructor of the Sour. */
	Sour(std::string name, int price, double content) : Alcohol(name, price, content)
	{}

	/* The copy constructor of the Sour. */
	Sour(const Sour& temp) :Alcohol(temp)
	{}

	/* The destructor of the Sour. */
	~Sour() = default;

	void dilute() override {
		this->double_content = this->double_content * 0.7;
	}

	Sour operator+(const Sour &other){
		string temp_name = this->str_name;
		int temp_price = this->int_price + other.get_price();
		double temp_content = (this->double_content + other.get_alcohol_content()) / 2;
		Sour temp(temp_name, temp_price, temp_content);
		return temp;
	}

	bool operator==(const Sour &other){
		return this->str_name == other.get_name() && this->double_content == other.get_alcohol_content() && this->int_price == other.get_price();
	}

	Sour &operator=(const Sour &other){
		if (this != &other){
			init(other.get_name(), other.get_price(), other.get_alcohol_content());
		}
		return *this;
	}
};
#endif