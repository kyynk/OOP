#include <cmath>

TEST(AlgorithmTest, TestWithSortByContent){
	Alcohol *alcohol1;
	Sour sour("Beer", 30, 0.2);
	alcohol1 = &sour;
	
	Alcohol *alcohol2;
	Tequila tequila("Reposado", 100, 0.15);
	alcohol2 = &tequila;
	
	Alcohol *alcohol3;
	Tequila tequila2("Diablo", 90, 0.15);
	alcohol3 = &tequila2;

	Alcohol *alcohol4;
	Tequila tequila3("Mezcal brandy", 100, 0.3);
	alcohol4 = &tequila3;

	Order order;
	order.append_alcohol(alcohol1);
	order.append_alcohol(alcohol2);
	order.append_alcohol(alcohol3);
	order.append_alcohol(alcohol4);

	sort_alcohol_by_content(order.getVector());

	ASSERT_EQ(order.getVector()[0]->get_alcohol_content(), 0.15);
	ASSERT_EQ(order.getVector()[0]->get_name(), "Diablo");
	ASSERT_EQ(order.getVector()[1]->get_alcohol_content(), 0.15);
	ASSERT_EQ(order.getVector()[1]->get_name(), "Reposado");
	ASSERT_EQ(order.getVector()[2]->get_alcohol_content(), 0.2);
	ASSERT_EQ(order.getVector()[2]->get_name(), "Beer");
	ASSERT_EQ(order.getVector()[3]->get_alcohol_content(), 0.3);
	ASSERT_EQ(order.getVector()[3]->get_name(), "Mezcal brandy");
}

TEST(AlgorithmTest, TestWithSortByName){
	Alcohol *alcohol1;
	Sour sour("Beer", 30, 0.2);
	alcohol1 = &sour;
	
	Alcohol *alcohol2;
	Tequila tequila("Mezcal wine", 100, 0.15);
	alcohol2 = &tequila;
	
	Alcohol *alcohol3;
	Tequila tequila2("Mezcal brandy", 90, 0.3);
	alcohol3 = &tequila2;

	Order order;
	order.append_alcohol(alcohol1);
	order.append_alcohol(alcohol2);
	order.append_alcohol(alcohol3);

	sort_alcohol_by_name(order.getVector());

	ASSERT_EQ(order.getVector()[0]->get_alcohol_content(), 0.2);
	ASSERT_EQ(order.getVector()[0]->get_name(), "Beer");
	ASSERT_EQ(order.getVector()[1]->get_alcohol_content(), 0.3);
	ASSERT_EQ(order.getVector()[1]->get_name(), "Mezcal brandy");
	ASSERT_EQ(order.getVector()[2]->get_alcohol_content(), 0.15);
	ASSERT_EQ(order.getVector()[2]->get_name(), "Mezcal wine");
}

TEST(AlgorithmTest, TestWithGetGreatestContent){
	Alcohol *alcohol1;
	Sour sour("Beer", 30, 0.2);
	alcohol1 = &sour;
	
	Alcohol *alcohol2;
	Tequila tequila("Reposado", 100, 0.15);
	alcohol2 = &tequila;
	
	Alcohol *alcohol3;
	Tequila tequila2("Diablo", 90, 0.3);
	alcohol3 = &tequila2;

	Alcohol *alcohol4;
	Tequila tequila3("Mezcal brandy", 100, 0.3);
	alcohol4 = &tequila3;

	Order order;
	order.append_alcohol(alcohol1);
	order.append_alcohol(alcohol2);
	order.append_alcohol(alcohol3);
	order.append_alcohol(alcohol4);

	Alcohol* greatest;
	greatest = get_greatest_content_of_alcohol(order.getVector());

	ASSERT_EQ(greatest->get_alcohol_content(), 0.3);
	ASSERT_EQ(greatest->get_name(), "Mezcal brandy");
}

TEST(AlgorithmTest, TestWithGetSmallestContent){
	Alcohol *alcohol1;
	Sour sour("Beer", 30, 0.2);
	alcohol1 = &sour;
	
	Alcohol *alcohol2;
	Tequila tequila("Reposado", 100, 0.15);
	alcohol2 = &tequila;
	
	Alcohol *alcohol3;
	Tequila tequila2("Diablo", 90, 0.15);
	alcohol3 = &tequila2;

	Alcohol *alcohol4;
	Tequila tequila3("Mezcal brandy", 100, 0.3);
	alcohol4 = &tequila3;

	Order order;
	order.append_alcohol(alcohol1);
	order.append_alcohol(alcohol2);
	order.append_alcohol(alcohol3);
	order.append_alcohol(alcohol4);

	Alcohol* smallest;
	smallest = get_smallest_content_of_alcohol(order.getVector());

	ASSERT_EQ(smallest->get_alcohol_content(), 0.15);
	ASSERT_EQ(smallest->get_name(), "Diablo");
}