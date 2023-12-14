#include <cmath>

TEST(TequilaTest, TestWithCopyConstructor){
	Tequila tequila1("Margarita", 90, 0.15);
	ASSERT_EQ(tequila1.get_name(), "Margarita");
	ASSERT_EQ(tequila1.get_price(), 90);
	ASSERT_EQ(tequila1.get_alcohol_content(), 0.15);

	Tequila tequila2(tequila1);
	ASSERT_EQ(tequila2.get_name(), "Margarita");
	ASSERT_EQ(tequila2.get_price(), 90);
	ASSERT_EQ(tequila2.get_alcohol_content(), 0.15);
}

TEST(TequilaTest, TestWithCopyAssignment){
	Tequila tequila;
	tequila = Tequila("Tequila Sunrise", 80, 0.1);
	ASSERT_EQ(tequila.get_name(), "Tequila Sunrise");
	ASSERT_EQ(tequila.get_price(), 80);
	ASSERT_EQ(tequila.get_alcohol_content(), 0.1);
}

TEST(TequilaTest, TestWithAddAssignment){
	Tequila tequila1("Tequila Sunrise", 80, 0.1);
	Tequila tequila2("Diablo", 90, 0.15);
	Tequila tequila3;
	tequila3 = tequila1 + tequila2;
	ASSERT_EQ(tequila3.get_name(), "Tequila Sunrise");
	ASSERT_EQ(tequila3.get_price(), 170);
	ASSERT_EQ(tequila3.get_alcohol_content(), 0.125);
}

TEST(TequilaTest, TestWithEqualAssignment){
	Tequila tequila1("Daiquiri", 100, 0.2);
	Tequila tequila2("Wine", 80, 0.2);
	Tequila tequila3("Wine", 80, 0.2);
	ASSERT_EQ(tequila1 == tequila2, false);
	ASSERT_EQ(tequila1 == tequila3, false);
	ASSERT_EQ(tequila2 == tequila3, true);
}

TEST(TequilaTest, TestWithDilute){
	Tequila tequila("Daiquiri", 90, 0.2);
	ASSERT_EQ(tequila.get_name(), "Daiquiri");
	ASSERT_EQ(tequila.get_price(), 90);
	ASSERT_EQ(tequila.get_alcohol_content(), 0.2);
	tequila.dilute();
	ASSERT_EQ(tequila.get_alcohol_content(), 0.19);
}

TEST(TequilaTest, TestWithWrongValue){
	ASSERT_THROW(Tequila("", 10, 0.1), std::invalid_argument);
	ASSERT_THROW(Tequila("Diablo", -1, 0.1), std::invalid_argument);
	ASSERT_THROW(Tequila("Rosita", 80, 2), std::invalid_argument);
	ASSERT_THROW(Tequila("Rosita", 80, -1), std::invalid_argument);
}