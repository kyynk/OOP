#include "bits/stdc++.h"
#include "../src/beef_sandwich.h"
#include "../src/sandwich_factory.h"
#include "../src/sandwich.h"
#include "../src/sweet_sandwich.h"
TEST(Sandwich, BeefAndSweetThrow){
	ASSERT_THROW(BeefSandwich beef(-1, 0), std::invalid_argument);
	ASSERT_THROW(SweetSandwich sweet(-1, 1), std::invalid_argument);
}

TEST(Sandwich, BeefAndSweet){
	/* Pre create these sandwich */
	Sandwich *bf1 = new BeefSandwich(25, 10);
	Sandwich *sw1 = new SweetSandwich(15, 11);
	Sandwich *bf2 = new BeefSandwich(45, 12);
	Sandwich *sw2 = new SweetSandwich(25, 13);

	/* Check record in sandwich */
	ASSERT_EQ(BeefSandwich::record_has_specific_id(10), true); // TRUE
	ASSERT_EQ(SweetSandwich::record_has_specific_id(13), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(10), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(11), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(12), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(13), true); // TRUE

	/* Check record size in sandwich */
	ASSERT_EQ(BeefSandwich::get_size_of_record_container(), 2); // 2
	ASSERT_EQ(SweetSandwich::get_size_of_record_container(), 2); // 2
	ASSERT_EQ(Sandwich::get_size_of_record_container(), 4); // 4

	/* Delete some sandwich and check record */
	delete sw1;
	delete bf1;

	/* Check record in sandwich */
	ASSERT_EQ(BeefSandwich::record_has_specific_id(10), false); // FALSE
	ASSERT_EQ(SweetSandwich::record_has_specific_id(13), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(10), false); // FALSE
	ASSERT_EQ(Sandwich::record_has_specific_id(11), false); // FALSE
	ASSERT_EQ(Sandwich::record_has_specific_id(12), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(13), true); // TRUE

	/* Check record size in sandwich */
	ASSERT_EQ(BeefSandwich::get_size_of_record_container(), 1); // 1
	ASSERT_EQ(SweetSandwich::get_size_of_record_container(), 1); // 1
	ASSERT_EQ(Sandwich::get_size_of_record_container(), 2); // 2

	delete sw2;
	delete bf2;
}

TEST(Sandwich, FactoryWithOneCreate){
	BeefSandwich* beef_sandwich = SandwichFactory<BeefSandwich>::create_sandwich(20, 31415926);
	// It should return a BeefSandwich pointer with price 20 and ID 31415926.
	ASSERT_EQ(beef_sandwich->get_price(), 20);
	ASSERT_EQ(beef_sandwich->get_id(), 31415926);
	delete beef_sandwich;
}

TEST(Sandwich, FactoryWithArrayCreateThrow){
	ASSERT_THROW(SandwichFactory<BeefSandwich>::create_sandwich_array(1, -1, {1, 11, 111}), std::invalid_argument);
	ASSERT_THROW(SandwichFactory<SweetSandwich>::create_sandwich_array(8, -6, {1, 11, 111}), std::invalid_argument);
}

TEST(Sandwich, FactoryWithArrayCreate){
	vector<BeefSandwich*> beef_sandwich_set = SandwichFactory<BeefSandwich>::create_sandwich_array(1, 3, {1, 11, 111});
	// It should return a BeefSandwich pointer array.
	// beef_sandwich_set[0]: price 1, ID 1
	// beef_sandwich_set[1]: price 1, ID 11
	// beef_sandwich_set[2]: price 1, ID 111
	ASSERT_EQ(beef_sandwich_set[0]->get_price(), 1);
	ASSERT_EQ(beef_sandwich_set[0]->get_id(), 1);
	ASSERT_EQ(beef_sandwich_set[1]->get_price(), 1);
	ASSERT_EQ(beef_sandwich_set[1]->get_id(), 11);
	ASSERT_EQ(beef_sandwich_set[2]->get_price(), 1);
	ASSERT_EQ(beef_sandwich_set[2]->get_id(), 111);

	for(int i=0; i<beef_sandwich_set.size(); i++){
		delete beef_sandwich_set[i];
	}
}