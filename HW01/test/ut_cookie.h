#include <gtest/gtest.h>
#include "../src/cookie.h"

// A single test case has the following form:
//
// TEST(TestSuiteName, TestName) {
//   ... test body ...
// }

TEST(COOKIE, N_even_1) {
    int arr[]={1, 2, 3, 4};
    int output = max_dv(4, arr);
    ASSERT_EQ(output, 6);
}
TEST(COOKIE, N_even_2) {
    int arr[]={5, 10, 2};
    int output = max_dv(3, arr);
    ASSERT_EQ(output, 10);
}
TEST(COOKIE, N_odd_1) {
    int arr[]={5, 2, 7, 4};
    int output = max_dv(4, arr);
    ASSERT_EQ(output, 12);
}
TEST(COOKIE, N_odd_2) {
    int arr[]={11, 9, 23};
    int output = max_dv(3, arr);
    ASSERT_EQ(output, 34);
}
TEST(COOKIE, dv_neg_1) {
    int arr[]={1, -3, 3, 4};
    int output = max_dv(4, arr);
    ASSERT_EQ(output, -1);
}
TEST(COOKIE, dv_neg_2) {
    int arr[]={61, 27, -55};
    int output = max_dv(3, arr);
    ASSERT_EQ(output, -1);
}
TEST(COOKIE, N_neg_1) {
    int arr[]={1, -3, 3, 4};
    int output = max_dv(-4, arr);
    ASSERT_EQ(output, -1);
}
TEST(COOKIE, N_neg_2) {
    int arr[]={39, 81, 35, 76, 20};
    int output = max_dv(-5, arr);
    ASSERT_EQ(output, -1);
}
