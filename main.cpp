#include <iostream>
#include "Mem.h"
#include "Set.h"
#include "Test.h"
#include <list>

using namespace std;

int main() {
    Mem mymem(500);
    SearchTree mytree(mymem);

    for (int i = 0; i < 100; i++)
        mytree.insert(&i, sizeof(int));

    Container::Iterator *i = mytree.begin();
    i->goToNext();

    mytree.remove(i);



    return 0;
}