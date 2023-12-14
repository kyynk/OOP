#include <bits/stdc++.h>
#include "../src/cookie.h"
#include <gtest/gtest.h>
/* The function help you to create the empty grid. */
/* You can use this function or create by yourself. */
bool** create_grid(){
    bool** array = new bool*[10];
    for(int i = 0; i < 10; i++){
        array[i] = new bool[10];
        for(int j = 0; j < 10; j++){
            array[i][j] = false;
        }
    }
    array[9][0] = true;
    return array;
}
/* The function help you to delete the grid. */
/* You should implement this by yourself. */
void delete_grid(bool** array){
    for(int i = 0; i < 10; i++){
        delete[] array[i];
    }
    delete[] array;
}
/* Add some test in here. */

/* 
TEST(Cookie, SomeTest){
    ...
}
*/
//[10%] Write 2 testcase to test regular situation, contains calculate any row or column.
TEST(Cookie, Sample1){
    bool** Array = create_grid();
    placeTop(Array);
    placeRight(Array);
    placeTop(Array);
    placeRight(Array);
    int output1 = calcRow(Array, 8); // The first output
    ASSERT_EQ(output1, 2);
    int output2 = calcColumn(Array, 1); // The second output
    ASSERT_EQ(output2, 2);
    //print_grid(Array);
    delete_grid(Array);
}
//[10%] Write 2 testcase to test regular situation, contains calculate any row or column.
TEST(Cookie, Sample2){
    bool** Array = create_grid();
    placeTop(Array);
    placeTop(Array);
    placeTop(Array);
    int output1 = calcRow(Array, 0); // The first output
    ASSERT_EQ(output1, 0);
    int output2 = calcRow(Array, 8); // The second output
    ASSERT_EQ(output2, 1);
    int output3 = calcColumn(Array, 0); // The third output
    ASSERT_EQ(output3, 4);
    //print_grid(Array);
    delete_grid(Array);
}
//[10\%][10%] Write 2 testcase to test that the placed cookie out or grid range.
TEST(Cookie, Sample3){
    bool** Array = create_grid();
    placeTop(Array);
    placeTop(Array);
    placeTop(Array);
    placeTop(Array);
    placeTop(Array);
    placeTop(Array);
    placeTop(Array);
    placeTop(Array);
    placeTop(Array);

    //print_grid(Array);
    ASSERT_THROW(placeTop(Array), std::string);
    delete_grid(Array);
}
//[10%] Write 2 testcase to test that the query of calculate column or row is out of grid range.
TEST(Cookie, Sample4){
    bool** Array = create_grid();
    //print_grid(grid);
    int output = calcRow(Array, 48763);
    ASSERT_EQ(output, -1);
    delete_grid(Array);
}
//[10\%][10%] Write 2 testcase to test that the placed cookie out or grid range.
TEST(Cookie, place_out_of_range){
    bool** Array = create_grid();
    placeRight(Array);
    placeRight(Array);
    placeRight(Array);
    placeRight(Array);
    placeRight(Array);
    placeRight(Array);
    placeRight(Array);
    placeRight(Array);
    placeRight(Array);
    
    //print_grid(Array);
    ASSERT_THROW(placeRight(Array), std::string);
    delete_grid(Array);
}
//[10%] Write 2 testcase to test that the query of calculate column or row is out of grid range.
TEST(Cookie, calc_out_of_range){
    bool** Array = create_grid();
    //print_grid(Array);
    int output = calcColumn(Array, 36784);
    ASSERT_EQ(output, -1);
    delete_grid(Array);
}
//[5%] Write 1 testcase to test that place over 10 times, then calculate any row or column.
TEST(Cookie, place_over_10times){
    bool** Array = create_grid();
    placeTop(Array);
    placeRight(Array);
    placeTop(Array);
    placeRight(Array);
    placeTop(Array);
    placeRight(Array);
    placeTop(Array);
    placeRight(Array);
    placeTop(Array);
    placeRight(Array);
    placeTop(Array);
    placeRight(Array);
    int output1 = calcRow(Array, 5);
    ASSERT_EQ(output1, 2);
    int output2 = calcColumn(Array, 3);
    ASSERT_EQ(output2, 2);
    //print_grid(Array);
    delete_grid(Array);
}