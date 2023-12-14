#include <iostream>
#include "HelloWorld.h"
/*using namespace std;
string PrintHelloWorld(){
    return "Hello World! \n";
}*/
int main(){
    cout << PrintHelloWorld();
    return 0;
}

/*#include <gtest/gtest.h>
#include "HelloWorld.h"
#include "ut_length.h"
TEST(HELLOWORLD, PrintHelloWorld){
    string output = PrintHelloWorld();
    string compare = "Hello World! \n";
    ASSERT_EQ(output, compare);
}
int main(int argc, char **argv){
    testing ::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/