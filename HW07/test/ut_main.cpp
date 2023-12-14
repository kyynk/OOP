#include <gtest/gtest.h>

#include "../src/cake_showcase.h"
#include "../src/cake.h"
#include "../src/chocolate_cake.h"
#include "../src/geode_cake.h"
#include "../src/honey_cake.h"

#include "ut_cake_showcase.h"
#include "ut_cake.h"
#include "ut_chocolate_cake.h"
#include "ut_geode_cake.h"
#include "ut_honey_cake.h"

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
