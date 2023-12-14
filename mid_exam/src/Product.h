#ifndef PRODUCT_H
#define PRODUCT_H
#include "bits/stdc++.h"
using namespace std;

class Product{
    private:
        string str_name = "";
        int int_price = -1;
    public:
        Product() = default;
        Product(std::string name, int price){
            if (name.length() < 4)
                throw std::string("name length < 4");
            str_name = name;
            if (price < 0)
                throw std::string("price < 0");
            int_price = price;
        }
        ~Product(){}
        std::string getName() const{
            // Return the name of product.
            if (str_name.length() < 4)
                throw std::string("name length < 4");
            return str_name;
        }
        int getPrice() const{
            // Return the price of product.
            if (int_price < 0)
                throw std::string("price < 0");
            return int_price;
        }

        Product& operator=(const Product& other){
            // The copy assignment of Product class.
            if (this != &other){
                this -> str_name = other.getName();
                this -> int_price = other.getPrice();
            }
            return *this;
        }
        
        bool operator==(const Product& other){
            // The equals function of two Product class, to compare two product is equals or not.
            if ((this->str_name == other.getName()) and (this->int_price == other.getPrice()))
                return true;
            return false;
        }
};
#endif