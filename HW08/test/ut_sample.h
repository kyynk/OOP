#include "bits/stdc++.h"
#include "../src/beef_sandwich.h"
#include "../src/sandwich_factory.h"
#include "../src/sandwich.h"
#include "../src/sweet_sandwich.h"
TEST(Sample, Sample1){
	/* Pre create these sandwich */
	Sandwich *bf1 = new BeefSandwich(25, 0);
	Sandwich *sw1 = new SweetSandwich(15, 1);
	Sandwich *bf2 = new BeefSandwich(45, 2);
	Sandwich *sw2 = new SweetSandwich(25, 3); 

	/* Check record in sandwich */
	ASSERT_EQ(BeefSandwich::record_has_specific_id(0), true); // TRUE
	ASSERT_EQ(SweetSandwich::record_has_specific_id(1), true); // TRUE
	ASSERT_EQ(BeefSandwich::record_has_specific_id(2), true); // TRUE
	ASSERT_EQ(SweetSandwich::record_has_specific_id(3), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(0), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(1), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(2), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(3), true); // TRUE

	/* Check record size in sandwich */
	ASSERT_EQ(BeefSandwich::get_size_of_record_container(), 2); // 2
	ASSERT_EQ(SweetSandwich::get_size_of_record_container(), 2); // 2
	ASSERT_EQ(Sandwich::get_size_of_record_container(), 4); // 4

	/* Delete some sandwich and check record */
	delete sw1;
	delete bf1;

	/* Check record in sandwich */
	ASSERT_EQ(BeefSandwich::record_has_specific_id(0), false); // FALSE
	ASSERT_EQ(SweetSandwich::record_has_specific_id(1), false); // FALSE
	ASSERT_EQ(BeefSandwich::record_has_specific_id(2), true); // TRUE
	ASSERT_EQ(SweetSandwich::record_has_specific_id(3), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(0), false); // FALSE
	ASSERT_EQ(Sandwich::record_has_specific_id(1), false); // FALSE
	ASSERT_EQ(Sandwich::record_has_specific_id(2), true); // TRUE
	ASSERT_EQ(Sandwich::record_has_specific_id(3), true); // TRUE

	/* Check record size in sandwich */
	ASSERT_EQ(BeefSandwich::get_size_of_record_container(), 1); // 1
	ASSERT_EQ(SweetSandwich::get_size_of_record_container(), 1); // 1
	ASSERT_EQ(Sandwich::get_size_of_record_container(), 2); // 2

	delete sw2;
	delete bf2;
}

TEST(Sample, Sample2){
	SweetSandwich* sweet_sandwich = SandwichFactory<SweetSandwich>::create_sandwich(15, 32767);
	// It should return a SweetSandwich pointer with price 15 and ID 32767.
	ASSERT_EQ(sweet_sandwich->get_price(), 15);
	ASSERT_EQ(sweet_sandwich->get_id(), 32767);
	delete sweet_sandwich;
}

TEST(Sample, Sample3){
	vector<SweetSandwich*> sweet_sandwich_set = SandwichFactory<SweetSandwich>::create_sandwich_array(15, 5, {33, 44, 55, 66, 99});
	// It should return a SweetSandwich pointer array.
	// sweet_sandwich_set[0]: price 15, ID 33
	// sweet_sandwich_set[1]: price 15, ID 44
	// sweet_sandwich_set[2]: price 15, ID 55
	// sweet_sandwich_set[3]: price 15, ID 66
	// sweet_sandwich_set[4]: price 15, ID 99
	ASSERT_EQ(sweet_sandwich_set[0]->get_price(), 15);
	ASSERT_EQ(sweet_sandwich_set[0]->get_id(), 33);
	ASSERT_EQ(sweet_sandwich_set[1]->get_price(), 15);
	ASSERT_EQ(sweet_sandwich_set[1]->get_id(), 44);
	ASSERT_EQ(sweet_sandwich_set[2]->get_price(), 15);
	ASSERT_EQ(sweet_sandwich_set[2]->get_id(), 55);
	ASSERT_EQ(sweet_sandwich_set[3]->get_price(), 15);
	ASSERT_EQ(sweet_sandwich_set[3]->get_id(), 66);
	ASSERT_EQ(sweet_sandwich_set[4]->get_price(), 15);
	ASSERT_EQ(sweet_sandwich_set[4]->get_id(), 99);

	for(int i=0; i<sweet_sandwich_set.size(); i++){
		delete sweet_sandwich_set[i];
	}
}