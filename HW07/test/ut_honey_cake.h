#include "bits/stdc++.h"
TEST(HoneyCakeTest, TestHoney){
	ASSERT_EQ(HoneyCake::get_count(), 0);
	
	HoneyCake cake1(70, 15);
	HoneyCake cake2(50, 10);

	string str1 = cake1.to_string();
	ASSERT_EQ(str1, "| HoneyCake            |         70 |         15 |");

	string str2 = cake2.to_string();
	ASSERT_EQ(str2, "| HoneyCake            |         50 |         10 |");
	
	ASSERT_EQ(HoneyCake::get_count(), 2);
}