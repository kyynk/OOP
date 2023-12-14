#include <gtest/gtest.h>

#include "../src/beef_sandwich.h"
#include "../src/sandwich_factory.h"
#include "../src/sandwich.h"
#include "../src/sweet_sandwich.h"

#include "ut_sample.h"
#include "ut_sandwich.h"

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
