//
// Created by Amir Mullagaliev on 05-May-19.
//

#pragma once

#include <time.h>

// Здесь нужно подключить соответствующий контейнер:
#include "Set.h"

class Test {
public:
    // Первый параметр - контейнер, второй - число вызовов соответствующего метода
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
        for (int i = 0; i < n; i++)
            t.clear();
        clock_t end = clock();
        return (double) (end - start) / CLOCKS_PER_SEC;
    }
};
