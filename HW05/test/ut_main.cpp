#include <gtest/gtest.h>

#include "../src/alcohol.h"
#include "../src/sour.h"
#include "../src/tequila.h"

#include "ut_alcohol.h"
#include "ut_sour.h"
#include "ut_tequila.h"

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
