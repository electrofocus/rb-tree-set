#pragma once

#include <time.h>

/* Ниже подключается соответствующий контейнер: */

//#include "Set.h"
//#include "Queue.h"
//#include "List.h"
//#include "List2.h"
//#include "Tree.h"
//#include "Table.h"

class Test {
public:
    /* У каждого метода первый параметр - контейнер,
       второй - число вызовов соответствующего метода*/

    double insert(Set &x, int n) {
        Set t = x;
        size_t size = sizeof(int);

        clock_t start = clock();

        for (int i = 0; i < n; i++)
            t.insert(&i, size);

        clock_t end = clock();

        return (double) (end - start) / CLOCKS_PER_SEC;
    }

    double remove(Set &x, int n) {
        Set t = x;
        size_t size = sizeof(int);
        for (int i = 0; i < n; i++)
            t.insert(&i, size);

        Container::Iterator *it = t.begin();
        clock_t start = clock();
        for (int i = 0; i < n; i++)
            t.remove(it);
        clock_t end = clock();
        return (double) (end - start) / CLOCKS_PER_SEC;
    }

    double find(Set &x, int n) {
        Set t = x;
        size_t size = sizeof(int);
        for (int i = 0; i < n; i++)
            t.insert(&i, size);

        clock_t start = clock();
        for (int i = 0; i < n; i++)
            t.find(&i, size);
        clock_t end = clock();
        return (double) (end - start) / CLOCKS_PER_SEC;
    }

    double clear(Set &x, int n) {
        Set t = x;
        size_t size = sizeof(int);
        for (int i = 0; i < n; i++)
            t.insert(&i, size);

        clock_t start = clock();
        t.clear();
        clock_t end = clock();
        return (double) (end - start) / CLOCKS_PER_SEC;
    }
};
