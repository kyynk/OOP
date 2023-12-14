#include "bits/stdc++.h"
TEST(GeodeCakeTest, TestGeode){
	ASSERT_EQ(GeodeCake::get_count(), 0);
	
	GeodeCake cake1(70, 15);
	GeodeCake cake2(50, 10);

	string str1 = cake1.to_string();
	ASSERT_EQ(str1, "| GeodeCake            |         70 |         15 |");

	string str2 = cake2.to_string();
	ASSERT_EQ(str2, "| GeodeCake            |         50 |         10 |");
	
	ASSERT_EQ(GeodeCake::get_count(), 2);
}