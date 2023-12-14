#ifndef DRINK_H
#define DRINK_H
#include "bits/stdc++.h"
using namespace std;

class Drink{
public:
    Drink(){
        str_name = "";
        double_sweetness = -1;
    }
    /* The constructor of the Drink. */
    Drink(std::string name, double sweetness_level){
        if (name.length() <= 4)
            throw std::string("name length <= 4");
        this->str_name = name;
        if (sweetness_level < 0 || sweetness_level > 1)
            throw std::string("sweetness_level out of range");
        this->double_sweetness = sweetness_level;
    }
    /* The destructor of the Drink. */
    ~Drink() = default;

    /* Return the name of drink. */
    std::string getName(){
        if (str_name.length() <= 4)
            throw std::string("name length <= 4");
        return str_name;
    }
    /* Return the level of sweetness. */
    double getSweetnessLevel(){
        if (double_sweetness > 1 || double_sweetness < 0)
            throw std::string("sweetness_level out of range");
        return double_sweetness;
    }
    /* Add a topping to the drink. */
    void addTopping(std::string topping){
        strVec_topping.push_back(topping);
    }
    /* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
    std::string getToppingByIndex(int index){
        // if (index >= strVec_topping.size())
        //     throw std::string("hi");
        // return strVec_topping.at(index);
        try{
            return strVec_topping.at(index);
        }catch(out_of_range& o_o_r){
            throw std::string("index out of range");
        }
    }
    /* Get the count of topping in drink. */
    int getToppingCount(){
        return this->strVec_topping.size();
    }
private:
    /* Put some attribute on here if necessary. */
    vector <string> strVec_topping;
    string str_name;
    double double_sweetness;
};
#endif