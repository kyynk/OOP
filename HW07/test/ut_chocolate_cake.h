#include "bits/stdc++.h"
TEST(ChocolateCakeTest, TestChocolate){
	ASSERT_EQ(ChocolateCake::get_count(), 0);
	
	ChocolateCake cake1(70, 15);
	ChocolateCake cake2(50, 10);

	string str1 = cake1.to_string();
	ASSERT_EQ(str1, "| ChocolateCake        |         70 |         15 |");

	string str2 = cake2.to_string();
	ASSERT_EQ(str2, "| ChocolateCake        |         50 |         10 |");
	
	ASSERT_EQ(ChocolateCake::get_count(), 2);
}