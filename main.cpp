#include <iostream>
#include "Mem.h"
#include "Set.h"
#include "Test.h"

using namespace std;

int main() {
    size_t sz;

    Mem mymem(500);
    Set myset(mymem);

    for (int i = 0; i < 5; i++)
        myset.insert(&i, sizeof(int));

    for (auto *it = myset.begin(); !it->equals(myset.end()); it->goToNext())
        cout << *(int*)(it->getElement(sz)) << endl;

    return 0;
}