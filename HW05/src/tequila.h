#ifndef TEQUILA_H
#define TEQUILA_H
#include "bits/stdc++.h"
#include "alcohol.h"
using namespace std;

class Tequila : public Alcohol{
public:
	/* The default constructor of the Tequila. */
	Tequila() = default;

	/* The constructor of the Tequila. */
	Tequila(std::string name, int price, double content) : Alcohol(name, price, content)
	{}

	/* The copy constructor of the Tequila. */
	Tequila(const Tequila& temp) :Alcohol(temp)
	{}

	/* The destructor of the Tequila. */
	~Tequila() = default;

	void dilute() override {
		this->double_content = this->double_content * 0.95;
	}

	Tequila operator+(const Tequila &other){
		string temp_name = this->str_name;
		int temp_price = this->int_price + other.get_price();
		double temp_content = (this->double_content + other.get_alcohol_content()) / 2;
		Tequila temp(temp_name, temp_price, temp_content);
		return temp;
	}

	bool operator==(const Tequila &other){
		return this->str_name == other.get_name() && this->double_content == other.get_alcohol_content() && this->int_price == other.get_price();
	}

	Tequila &operator=(const Tequila &other){
		if (this != &other){
			init(other.get_name(), other.get_price(), other.get_alcohol_content());
		}
		return *this;
	}
};
#endif