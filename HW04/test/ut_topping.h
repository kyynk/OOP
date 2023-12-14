#include <cmath>

TEST(ToppingTest, TestWithCopyConstructor){
    Topping topping("Bubble", 0.4, 5);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_EQ(topping.getSweetnessLevel(), 0.4);
    ASSERT_EQ(topping.getPrice(), 5);
}

TEST(ToppingTest, TestWithCopyAssignment){
    Topping topping;
    topping = Topping("Bubble", 0.4, 5);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_EQ(topping.getSweetnessLevel(), 0.4);
    ASSERT_EQ(topping.getPrice(), 5);
}

TEST(ToppingTest, TestWithWrongValue){
    ASSERT_THROW(Topping("Bub", 0.4, 5), std::string);
    ASSERT_THROW(Topping("Bubble", -0.1, 5), std::string);
    ASSERT_THROW(Topping("Bubble", 0.4, -5), std::string);
}

TEST(DRINK, Drink_drink){
    Drink drink("Signature Black Tea with Milk", 0.3, 60);
    ASSERT_EQ(drink.getName(), "Signature Black Tea with Milk");
    ASSERT_EQ(drink.getSweetnessLevel(), 0.3);
    ASSERT_EQ(drink.getPrice(), 60);
}
TEST(DRINK, Drink_drink_throw){
    // drink throw
    ASSERT_THROW(Drink drink("tea", -1, -1), std::string);
    ASSERT_THROW(Drink drink("black tea", -1, -2), std::string);
    ASSERT_THROW(Drink drink("black tea", 0.5, -2), std::string);
}
TEST(DRINK, Drink_getName_throw){
    // getName throw
    // name is empty
    Drink drink;
    ASSERT_THROW(drink.getName(), std::string);
}
TEST(DRINK, Drink_getSweetnessLevel_throw){
    // getSweetnessLevel throw
    // SweetnessLevel out of range
    Drink drink;
    ASSERT_THROW(drink.getSweetnessLevel(), std::string);
}
TEST(DRINK, Drink_getPrice_throw){
    // getPrice throw
    // Price < 0
    Drink drink;
    ASSERT_THROW(drink.getPrice(), std::string);
}
TEST(DRINK, Drink_Topping){
    Drink drink("milk tea", 0.3, 35);
    drink.addTopping(Topping("pudding", 0.2, 10));
    drink.addTopping(Topping("more_ice", 0, 3));
    Topping topping1 = drink.getToppingByIndex(0);
    Topping topping2 = drink.getToppingByIndex(1);
    ASSERT_EQ(topping1.getName(), "pudding");
    ASSERT_EQ(topping1.getSweetnessLevel(), 0.2);
    ASSERT_EQ(topping1.getPrice(), 10);
    ASSERT_EQ(topping2.getName(), "more_ice");
    ASSERT_EQ(topping2.getSweetnessLevel(), 0);
    ASSERT_EQ(topping2.getPrice(), 3);
    ASSERT_EQ(drink.getSweetnessLevel(), 0.5);
    ASSERT_EQ(drink.getPrice(), 48);
    ASSERT_EQ(drink.getToppingCount(), 2);
}
TEST(DRINK, Drink_getToppingByIndex_throw){
    Drink drink("milk tea", 0.3, 35);
    ASSERT_THROW(drink.getToppingByIndex(5), std::string);
    drink.addTopping(Topping("pudding", 0.2, 10));
    drink.addTopping(Topping("more_ice", 0, 3));
    ASSERT_THROW(drink.getToppingByIndex(3), std::string);
}
TEST(DRINK, Drink_operator){
    Drink drink_other("milk tea", 0.8, 30);
    drink_other.addTopping(Topping("more_ice", 0, 3));
    Drink drink;
    drink = drink_other;
    ASSERT_EQ(drink.getName(), "milk tea");
    ASSERT_EQ(drink.getSweetnessLevel(), 0.8);
    ASSERT_EQ(drink.getPrice(), 33);
    Topping topping = drink.getToppingByIndex(0);
    ASSERT_EQ(topping.getName(), "more_ice");
    ASSERT_EQ(topping.getSweetnessLevel(), 0);
    ASSERT_EQ(topping.getPrice(), 3);
}