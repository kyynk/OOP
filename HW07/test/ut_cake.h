#include "bits/stdc++.h"
TEST(CakeTest, Cake){
	vector<Cake*> cake;
	cake.push_back(new ChocolateCake(70, 15));
	cake.push_back(new GeodeCake(80, 25));
	
	ASSERT_EQ(Cake::get_total(), 2);

	cake.push_back(new HoneyCake(50, 20));
	ASSERT_EQ(Cake::get_total(), 3);
	
	ASSERT_EQ(cake[0]->get_price(), 70);
	ASSERT_EQ(cake[1]->get_price(), 80);
	ASSERT_EQ(cake[2]->get_price(), 50);
	ASSERT_EQ(cake[0]->get_sweet(), 15);
	ASSERT_EQ(cake[1]->get_sweet(), 25);
	ASSERT_EQ(cake[2]->get_sweet(), 20);
	
	for (int i=0; i<cake.size(); i++)
		delete cake[i];
	
	ASSERT_EQ(Cake::get_total(), 0);
}