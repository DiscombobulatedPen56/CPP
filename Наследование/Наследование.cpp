
#include <iostream>

#include "B.h"
#include "A.h"
#include "RectMatrix.h"
#include "SquareMatrix.h"

int main(int argc, char* argv[])
{
    //SquareMatrix sm(5);
    //std::cout << sm << std::endl;

    A* a = new B();
    a->f();

    return 0;
}
