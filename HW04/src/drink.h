#include <string>
#include <vector>
#include "topping.h"
using namespace std;

class Drink{
public:

	Drink() = default;

	/* The constructor of the Drink. */
	Drink(std::string name, double sweetness_level, int price){
		if (name.length() <= 4)
            throw std::string("name length <= 4");
        this->str_name = name;
        
		if (sweetness_level < 0 || sweetness_level > 1)
            throw std::string("sweetness_level out of range");
        this->double_sweetness = sweetness_level;

		if (price < 0)
            throw std::string("price < 0");
        this->int_price = price;
	}

	/* The destructor of the Drink. */
	~Drink(){}

	/* Return the name of drink. */
	std::string getName() const {
		if (str_name.length() <= 4)
			throw std::string("name length <= 4");
		return str_name;
	}

	/* Return the level of sweetness. */
	double getSweetnessLevel() const {
		if (double_sweetness > 1 || double_sweetness < 0)
			throw std::string("sweetness_level out of range");
		return double_sweetness;
	}

	/* Return the price of drink. */
	int getPrice() const {
		if (int_price < 0)
			throw std::string("price < 0");
		return int_price;
	}

	/* Add a topping to the drink. */
	void addTopping(Topping topping){
		top_topping.push_back(topping);
		double_sweetness += topping.getSweetnessLevel();
		int_price += topping.getPrice();
	}

	/* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
	Topping getToppingByIndex(int index) const {
		try{
			return top_topping.at(index);
		}catch(out_of_range& o_o_r){
			throw std::string("index out of range");
		}
	}

	/* Get the count of topping in drink. */
	int getToppingCount() const{
		return this->top_topping.size();
	}

	/* Operator overloading */
	Drink &operator=(const Drink& other){
		if (this != &other){
			this->str_name = other.getName();
			this->double_sweetness = other.getSweetnessLevel();
			this->int_price = other.getPrice();
			this->top_topping = other.top_topping;
		}
		return *this;
	}

private:
	/* Put some attribute on here if necessary. */
	vector <Topping> top_topping;
	string str_name = "";
	double double_sweetness = -1;
	int int_price = -1;
};
