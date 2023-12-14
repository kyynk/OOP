#include <cmath>

TEST(SourTest, TestWithCopyConstructor){
	Sour sour1("Margarita", 90, 0.15);
	ASSERT_EQ(sour1.get_name(), "Margarita");
	ASSERT_EQ(sour1.get_price(), 90);
	ASSERT_EQ(sour1.get_alcohol_content(), 0.15);

	Sour sour2(sour1);
	ASSERT_EQ(sour2.get_name(), "Margarita");
	ASSERT_EQ(sour2.get_price(), 90);
	ASSERT_EQ(sour2.get_alcohol_content(), 0.15);
}

TEST(SourTest, TestWithCopyAssignment){
	Sour sour;
	sour = Sour("Daiquiri", 100, 0.2);
	ASSERT_EQ(sour.get_name(), "Daiquiri");
	ASSERT_EQ(sour.get_price(), 100);
	ASSERT_EQ(sour.get_alcohol_content(), 0.2);
}

TEST(SourTest, TestWithAddAssignment){
	Sour sour1("Daiquiri", 100, 0.2);
	Sour sour2("Wine", 80, 0.2);
	Sour sour3;
	sour3 = sour1 + sour2;
	ASSERT_EQ(sour3.get_name(), "Daiquiri");
	ASSERT_EQ(sour3.get_price(), 180);
	ASSERT_EQ(sour3.get_alcohol_content(), 0.2);
}

TEST(SourTest, TestWithEqualAssignment){
	Sour sour1("Daiquiri", 100, 0.2);
	Sour sour2("Wine", 80, 0.2);
	Sour sour3("Wine", 80, 0.2);
	ASSERT_EQ(sour1 == sour2, false);
	ASSERT_EQ(sour1 == sour3, false);
	ASSERT_EQ(sour2 == sour3, true);
}

TEST(SourTest, TestWithDilute){
	Sour sour("Margarita", 90, 0.15);
	ASSERT_EQ(sour.get_name(), "Margarita");
	ASSERT_EQ(sour.get_price(), 90);
	ASSERT_EQ(sour.get_alcohol_content(), 0.15);
	sour.dilute();
	ASSERT_EQ(sour.get_alcohol_content(), 0.105);
}

TEST(SourTest, TestWithWrongValue){
	ASSERT_THROW(Sour("", 10, 0.1), std::invalid_argument);
	ASSERT_THROW(Sour("Screwdriver", -1, 0.1), std::invalid_argument);
	ASSERT_THROW(Sour("Vodka Lime", 95, 2), std::invalid_argument);
	ASSERT_THROW(Sour("Vodka Lime", 95, -1), std::invalid_argument);
}