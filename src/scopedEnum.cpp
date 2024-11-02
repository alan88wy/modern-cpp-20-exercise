#include <iostream>

enum class myEnum
{
    myFirstValue,
    mySecondValue,
    MyThirdValue
};

int main()
{

    myEnum mye = myEnum::myFirstValue;

    mye = myEnum::mySecondValue;

    return 1;
}