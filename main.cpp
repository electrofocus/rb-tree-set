#include <iostream>
#include "Mem.h"
#include "Set.h"
#include "Test.h"

using namespace std;

int main() {
    size_t sz;

    Mem mymem(500);
//    Set myset(mymem);
//    Test mytest;

//    cout << mytest.insert(myset, 1000) << endl;

//    for (int i = 1; i <= 1000; i++)
//        myset.insert(&i, sizeof(int));

//    for (auto *it = myset.begin(); !it->equals(myset.end());) {
//        if (*(int*)it->getElement(sz) % 2 == 0)
//            myset.remove(it);
//        else
//            it->goToNext();
//    }

//    for (auto *it = myset.begin(); !it->equals(myset.end()); it->goToNext())
//        cout << *(int*)(it->getElement(sz)) << endl;


    SearchTree mytree(mymem);

    for (int i = 1; i <= 100; i++)
        mytree.insert(&i, sizeof(int));

    mytree.print("out.txt");

//     for (auto *it = mytree.begin(); !it->equals(mytree.end());) {
//        if (*(int*)it->getElement(sz) % 2 == 1)
//            mytree.remove(it);
//        else
//            it->goToNext();
//    }

    return 0;
}