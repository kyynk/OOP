#include "bits/stdc++.h"
TEST(CakeShowcaseTest, CakeShowcaseTest){
	// vector<Cake*> cake;
	// cake.push_back(new ChocolateCake(70, 15));
	// cake.push_back(new GeodeCake(80, 25));
	// cake.push_back(new HoneyCake(50, 20));

	Cake* rr[2]={new HoneyCake(50, 20), new ChocolateCake(70, 15)};
	CakeShowcase <Cake>showcase(2, rr);
	ASSERT_EQ(showcase.calc_total_price(), 120);
	ASSERT_EQ(showcase.calc_total_sweet(), 35);
	string str;

	str += "| CakeName             | Price      | Sweet      |\n"
		   "| -------------------- | ---------- | ---------- |\n"
		   "| HoneyCake            |         50 |         20 |\n"
		   "| ChocolateCake        |         70 |         15 |\n"
		   "| -------------------- | ---------- | ---------- |";
	// cout<<showcase.to_string();
	ASSERT_EQ(showcase.to_string(), str);
	ASSERT_EQ(showcase[0]->get_price(), 50);
	ASSERT_THROW(showcase[-1], std::out_of_range);
	for(int i=0; i<2; i++){
		delete showcase[i];
	}
}