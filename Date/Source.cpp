#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    Date d(30, 4, 2024);
    d.AddDay();
    d.PrintDate();
}
