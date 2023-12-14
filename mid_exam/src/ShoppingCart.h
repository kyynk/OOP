#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include "bits/stdc++.h"
#include "Product.h"
using namespace std;

int InVec(vector<Product> Pro_vec , const Product &comp){
    for (int i=0; i<Pro_vec.size(); i++){
        if(Pro_vec[i] == comp)
            return i;
    }
    return -1;
}

class ShoppingCart{
    private:
        int int_size = 0;
        // Product *Pro_item;
        int int_price = 0;
        vector<Product> Pro_i;
    public:
        ShoppingCart() = default;
        ShoppingCart(int item_list_size, Product* item_list){
            int_size = item_list_size;
            for (int i = 0; i < int_size; i++){
                for (int j = i+1; j < int_size; j++){
                    if (item_list[i] == item_list[j])
                        throw std::string("contains repeat item");
                }
                Pro_i.push_back(item_list[i]);
                int_price += item_list[i].getPrice();
            }
        }
        ShoppingCart(int item_list_size, vector<Product> item_list){
            int_size = item_list_size;
            for (int i = 0; i < int_size; i++){
                for (int j = i+1; j < int_size; j++){
                    if (item_list[i] == item_list[j])
                        throw std::string("contains repeat item");
                }
                Pro_i.push_back(item_list[i]);
                int_price += item_list[i].getPrice();
            }
        }
        ~ShoppingCart(){}
        int getItemCount() const{
            // Return the count of item in shopping cart.
            return int_size;
        }
        Product getItemByIndex(int index) const{
            // Return the product in shopping cart by index.
            // If the index is out of range, you should throw a string exception.
            // if (index >= Pro_i.size())
            //     throw std::string("index is out of range");
            // return Pro_i[index];
            try{
                return Pro_i.at(index);
            }catch(out_of_range& o_o_r){
                throw std::string("index out of range");
            }
        }
        void setItemByIndex(int index, Product product){
            // Set the exist product in shopping cart by index.
            // If the index is out of range, you should throw a string exception.
            // If this action will appear duplicate item, you should throw a string exception.
            if (index >= int_size)
                throw std::string("index out of range");
            Pro_i[index] = product;
            for (int i = 0; i < int_size; i++){
                for (int j = i+1; j < int_size; j++){
                    if(Pro_i[i].getName() == Pro_i[j].getName())
                        throw std::string("contains repeat item");
                }
            }
        }
        void appendItem(Product product){
            // Append the product to the shopping list.
            // If the product already in the list, you should throw a string exception.
            for (int i = 0; i < int_size; i++){
                if(Pro_i[i] == product)
                    throw std::string("contains repeat item");
            }
            int_size ++;
            int_price += product.getPrice();
            Pro_i.push_back(product);           
        }
        int getTotalCost() const{
            // Return the total cost in shopping cart.
            return int_price;
        }
        ShoppingCart operator+(const ShoppingCart& other){
            // Do the union by two shopping cart. (See Problem Content)
            ShoppingCart tt1(*this);
            for (int i =0;i < other.getItemCount();i++){
                if (InVec(this->Pro_i,other.getItemByIndex(i)) == -1)
                    tt1.appendItem(other.getItemByIndex(i));
            }
            return tt1;
        }
        
        ShoppingCart operator-(const ShoppingCart& other){
            // Do the difference by two shopping cart. (See Problem Content)
            ShoppingCart tt2;
            int same[other.getItemCount()];
            for (int i =0;i < other.getItemCount();i++){
                same[i] = InVec(this->Pro_i,other.getItemByIndex(i));
            }
            for (int i = 0; i < this->int_size; i++){            //Po_i
                int ok = 1;
                for (int j =0;j < other.getItemCount();j++){    //same i
                    if (i == same[j])
                        ok = 0;
                }
                if (ok == 1)
                    tt2.appendItem(Pro_i[i]);
            }
            
            // cout<<tt2.getItemCount()<<endl;
            // cout<<tt2.getTotalCost()<<endl;
            return tt2;
        }
        ShoppingCart& operator=(const ShoppingCart& other){
            // The copy assignment of ShoppingCart.
            if (this != &other){
                this->int_size = other.getItemCount();
                this->int_price = 0;
                this->Pro_i.clear();
                for (int i = 0; i < this->int_size; i++){
                    this->Pro_i.push_back(other.getItemByIndex(i));
                    this->int_price += this->Pro_i[i].getPrice();
                }
            }
            return *this;
        }
        
};
#endif