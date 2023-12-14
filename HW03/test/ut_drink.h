#include <bits/stdc++.h>
#include "../src/drink.h"
#include <gtest/gtest.h>

/* Place some test here */
/* TEST(GroupName, TestName){} */

// [5%] Write two test case to check Drink::Drink() work correctly.
TEST(DRINK,Drink1){
    Drink drink("black tea", 0.5);
    ASSERT_EQ(drink.getName(), "black tea");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.5, 0);
}
TEST(DRINK,Drink2){
    // name length <=4, SweetnessLevel out of range (<0)
    ASSERT_THROW(Drink drink("tea", -1), std::string);

    // name length <=4, SweetnessLevel out of range (>0)
    ASSERT_THROW(Drink drink_2("tea", 10), std::string);
    
    // name length <=4
    ASSERT_THROW(Drink drink_3("tea", 0), std::string);

    // SweetnessLevel out of range (>1)
    ASSERT_THROW(Drink drink_4("margarita", 5), std::string);

    // SweetnessLevel out of range (<0)
    ASSERT_THROW(Drink drink_5("margarita", -5), std::string);
}

// [6%] Write two test case to check Drink::getName work correctly.
TEST(DRINK,getName1){
    Drink drink("coca cola", 0.7);
    ASSERT_EQ(drink.getName(), "coca cola");
}
TEST(DRINK,getName2){
    // name is empty
    Drink drink;
    ASSERT_THROW(drink.getName(), std::string);
}

// [6%] Write two test case to check Drink::getSweetnessLevel work correctly.
TEST(DRINK,getSweetnessLevel1){
    Drink drink("milk tea", 0.5);
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.5, 0);
}
TEST(DRINK,getSweetnessLevel2){
    // SweetnessLevel out of range
    Drink drink;
    ASSERT_THROW(drink.getSweetnessLevel(), std::string);
    // // SweetnessLevel out of range (>1)
    // Drink drink_1("juice", 5);
    // ASSERT_THROW(drink_1.getSweetnessLevel(), std::string);
    // // SweetnessLevel out of range (<0)
    // Drink drink_2("juice", -0.4);
    // ASSERT_THROW(drink_2.getSweetnessLevel(), std::string);
}

// [6%] Write two test case to check Drink::addTopping work correctly.
TEST(DRINK,addTopping1){
    Drink drink("Black Tea", 0.2);
    /* Add some topping */
    drink.addTopping("Marshmallow");
    drink.addTopping("Milk");

    /* Get the topping by index */
    ASSERT_EQ(drink.getToppingByIndex(1), "Milk"); // Assert it will return Pudding.
    ASSERT_EQ(drink.getToppingByIndex(0), "Marshmallow"); // Assert it will return Bubble.
    ASSERT_THROW(drink.getToppingByIndex(2), std::string); // Assert it will throw exception because we don't have the third topping.
    ASSERT_THROW(drink.getToppingByIndex(-1), std::string);

    /* Get the count of topping */
    ASSERT_EQ(drink.getToppingCount(), 2); // Assert it will return 2.
}
TEST(DRINK,addTopping2){
    Drink drink("coca cola", 0.3);
    /* Add some topping */
    drink.addTopping("sault");
    drink.addTopping("Pudding");
    drink.addTopping("mentos");

    /* Get the topping by index */
    ASSERT_EQ(drink.getToppingByIndex(1), "Pudding");
    ASSERT_EQ(drink.getToppingByIndex(0), "sault");
    ASSERT_EQ(drink.getToppingByIndex(2), "mentos");
    ASSERT_THROW(drink.getToppingByIndex(-1), std::string);
    ASSERT_THROW(drink.getToppingByIndex(50), std::string);
    
    /* Get the count of topping */
    ASSERT_EQ(drink.getToppingCount(), 3);
}

// [6%] Write two test case to check Drink::getToppingByIndex work correctly.
TEST(DRINK,getToppingByIndex1){
    Drink drink("Milk tea", 0.3);
    /* Add some topping */
    drink.addTopping("Tapioca ball");
    drink.addTopping("Pudding");
    drink.addTopping("Ice");

    /* Get the topping by index */
    ASSERT_EQ(drink.getToppingByIndex(1), "Pudding"); // Assert it will return Pudding.
    ASSERT_EQ(drink.getToppingByIndex(0), "Tapioca ball"); // Assert it will return Tapioca ball.
    ASSERT_EQ(drink.getToppingByIndex(2), "Ice"); // Assert it will return Ice.
    
}
TEST(DRINK,getToppingByIndex2){
    Drink drink("Milk tea", 0.3);
    /* Add some topping */
    drink.addTopping("Tapioca ball");
    drink.addTopping("Pudding");
    drink.addTopping("Ice");
    
    // index out of range
    ASSERT_THROW(drink.getToppingByIndex(6), std::string);
    ASSERT_THROW(drink.getToppingByIndex(-1), std::string);
}

// [6%] Write two test case to check Drink::getToppingCount work correctly.
TEST(DRINK,getToppingCount1){
    Drink drink("coca cola", 0.3);
    /* Add some topping */
    drink.addTopping("Sault");
    drink.addTopping("Marshmallow");
    drink.addTopping("Mentos");
    
    /* Get the count of topping */
    ASSERT_EQ(drink.getToppingCount(), 3);
}
TEST(DRINK,getToppingCount2){
    Drink drink("coca cola", 0.3);
    
    /* Get the count of topping */
    ASSERT_EQ(drink.getToppingCount(), 0);

    drink.addTopping("Ice");
    ASSERT_EQ(drink.getToppingCount(), 1);
}
