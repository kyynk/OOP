#include <cmath>

TEST(OrderTest, TestWithOrderEverything){
	Alcohol *alcohol1;
	Sour sour("Beer", 30, 0.2);
	alcohol1 = &sour;
	
	Alcohol *alcohol2;
	Tequila tequila("Reposado", 100, 0.15);
	alcohol2 = &tequila;
	
	Alcohol *alcohol3;
	Tequila tequila2("Diablo", 90, 0.15);
	alcohol3 = &tequila2;

	// default constructor
	Order order;
	order.append_alcohol(alcohol1);
	order.append_alcohol(alcohol2);
	order.append_alcohol(alcohol3);

	ASSERT_EQ(order.get_alcohol_count(), 3);
	ASSERT_EQ(order.get_total_price(), 220);

	// constructor
	vector<Alcohol*> temp;
	temp = order.getVector();
	Order order2(temp);

	ASSERT_EQ(order2.get_alcohol_count(), 3);
	ASSERT_EQ(order2.get_total_price(), 220);

	// copy constructor
	Order order3(order);

	ASSERT_EQ(order3.get_alcohol_count(), 3);
	ASSERT_EQ(order3.get_total_price(), 220);
}