#include <iostream>
#include <stdio.h>

#define FUN_IN std::cout << "In " << __FUNCTION__ << std::endl;
#define FUN_OUT std::cout << "Out " << __FUNCTION__ << std::endl << std::endl;

#define MULTI_LINE { std::cout << "Line 1" << std::endl; \
                     std::cout << "Line 2" << std::endl; \
                     std::cout << "Line 3" << std::endl; \
                   }

// DEBUG_LOG(str)
// INFO_LOG(...)
#define FOO(...) printf(__VA_ARGS__)

void Test()
{
    FUN_IN;

    std::cout << "This is " << __FUNCTION__ << " functionality" << std::endl;

    FUN_OUT;
}

void Test2()
{
    FUN_IN;

    std::cout << "This is " << __FUNCTION__ << " functionality" << std::endl;

    FUN_OUT;
}

int main()
{
    Test();

    Test2();

    MULTI_LINE;

    FOO("[%s %d, %d] Hello World", "March", 26, 2009);

    return 0;
}
