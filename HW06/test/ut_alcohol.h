#include <cmath>

TEST(AlcoholTest, TestWithCopyConstructor){
	Alcohol *alcohol1;
	Sour sour("Beer", 30, 0.2);
	alcohol1 = &sour;
	ASSERT_EQ(alcohol1->get_name(), "Beer");
	ASSERT_EQ(alcohol1->get_price(), 30);
	ASSERT_EQ(alcohol1->get_alcohol_content(), 0.2);
	
	Alcohol *alcohol2(alcohol1);
	ASSERT_EQ(alcohol2->get_name(), "Beer");
	ASSERT_EQ(alcohol2->get_price(), 30);
	ASSERT_EQ(alcohol2->get_alcohol_content(), 0.2);

	Alcohol *alcohol3;
	Tequila tequila("Diablo", 90, 0.15);
	alcohol3 = &tequila;
	ASSERT_EQ(alcohol3->get_name(), "Diablo");
	ASSERT_EQ(alcohol3->get_price(), 90);
	ASSERT_EQ(alcohol3->get_alcohol_content(), 0.15);
	
	Alcohol *alcohol4(alcohol3);
	ASSERT_EQ(alcohol4->get_name(), "Diablo");
	ASSERT_EQ(alcohol4->get_price(), 90);
	ASSERT_EQ(alcohol4->get_alcohol_content(), 0.15);
}

TEST(AlcoholTest, TestWithWrongValue){
	ASSERT_THROW(Sour("", 10, 0.1), std::invalid_argument);
	ASSERT_THROW(Sour("Screwdriver", -1, 0.1), std::invalid_argument);
	ASSERT_THROW(Sour("Vodka Lime", 95, 2), std::invalid_argument);
	ASSERT_THROW(Sour("Vodka Lime", 95, -1), std::invalid_argument);
	ASSERT_THROW(Tequila("", 10, 0.1), std::invalid_argument);
	ASSERT_THROW(Tequila("Diablo", -1, 0.1), std::invalid_argument);
	ASSERT_THROW(Tequila("Rosita", 80, 2), std::invalid_argument);
	ASSERT_THROW(Tequila("Rosita", 80, -1), std::invalid_argument);
}