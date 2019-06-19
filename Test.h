#include <time.h>
#include "Set.h"

class Test {
public:
    /* У каждого метода первый параметр - контейнер,
       второй - число вызовов соответствующего метода*/

    bool insert(Set &x, int n, double &time) {
        Set t = x;
        size_t size = sizeof(int);

        clock_t start = clock();

        for (int i = 0; i < n; i++)
            t.insert(&i, size);

        clock_t end = clock();
        time = (double) (end - start) / CLOCKS_PER_SEC;

        for (int i = 0; i < n; i++)
            if (t.find(&i, size) == t.end())
                return false;

        return true;
    }

    bool remove(Set &x, int n, double &time) {
        Set t = x;
        size_t size = sizeof(int);
        for (int i = 0; i < n; i++)
            t.insert(&i, size);

        Container::Iterator *it = t.begin();
        clock_t start = clock();
        for (int i = 0; i < n; i++)
            t.remove(it);
        clock_t end = clock();
        time = (double) (end - start) / CLOCKS_PER_SEC;

        for (int i = 0; i < n; i++)
            if (t.find(&i, size) != t.end())
                return false;

        return true;
    }

    bool remove_even(Set &x, int n, double &time) {
        Set t = x;
        size_t size = sizeof(int);
        for (int i = 0; i < n; i++)
            t.insert(&i, size);

        Container::Iterator *it = t.begin();
        clock_t start = clock();

        for (int i = 0; i < n; i++)
            if (*(int *) it->getElement(size) % 2 == 1)
                t.remove(it);
            else
                it->goToNext();

        clock_t end = clock();
        time = (double) (end - start) / CLOCKS_PER_SEC;

        for (int i = 0; i < n; i++)
            if ((i % 2 == 0 && t.find(&i, size) == t.end()) || (i % 2 == 1 && t.find(&i, size) != t.end()))
                return false;

        return true;
    }

    bool find(Set &x, int n, double &time) {
        Set t = x;
        bool ret = true;
        size_t size = sizeof(int);
        for (int i = 0; i < n; i++)
            t.insert(&i, size);

        clock_t start = clock();
        for (int i = 0; i < n; i++)
            if (t.find(&i, size) == t.end()) {
                ret = false;
                break;
            }
        clock_t end = clock();

        time = (double) (end - start) / CLOCKS_PER_SEC;

        return ret;
    }

    bool clear(Set &x, int n, double &time) {
        Set t = x;
        size_t size = sizeof(int);
        for (int i = 0; i < n; i++)
            t.insert(&i, size);

        clock_t start = clock();
        t.clear();
        clock_t end = clock();
        time = (double) (end - start) / CLOCKS_PER_SEC;

        for (int i = 0; i < n; i++)
            if (t.find(&i, size) != t.end())
                return false;

        return true;
    }
};
