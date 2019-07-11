#include <iostream>
#include "Mem.h"
#include "Set.h"
#include "SetTest.h"

using namespace std;

int main() {
    Mem mymem(10000);
    Set myset(mymem);
    SetTest mytest;

    double time;
    int n = 10000000;

    mytest.insert(&myset, n, time);

    mytest.remove(&myset, n, time);

    mytest.remove_even(&myset, n, time);

    mytest.find(&myset, n, time);

    mytest.clear(&myset, n, time);

    return 0;
}