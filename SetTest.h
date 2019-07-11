//
// Created by Amir on 10.07.2019.
//

#pragma once

#include <time.h>

class SetTest {
public:
    void insert(Set *x, int n, double &time) {
        size_t size = sizeof(int);

        clock_t start = clock();

        for (int i = 0; i < n; i++)
            x->insert(&i, size);

        clock_t end = clock();
        time = (double) (end - start) / CLOCKS_PER_SEC;


        for (int i = 0; i < n; i++)
            if (x->find(&i, size) == nullptr) {
                cout << "SetTest 'insert' failed!" << endl;
                x->clear();
                return;
            };

        x->clear();
        cout << "SetTest 'insert' passed in " << time << " seconds." << endl;
    }

    void remove(Set *x, int n, double &time) {
        size_t size = sizeof(int);

        clock_t start = clock();

        for (int i = 0; i < n; i++)
            x->insert(&i, size);

        clock_t end = clock();
        time = (double) (end - start) / CLOCKS_PER_SEC;

        for (Container::Iterator *it = x->begin(); !x->empty();)
            x->remove(it);

        for (int i = 0; i < n; i++)
            if (x->find(&i, size) != nullptr) {
                cout << "SetTest 'remove' failed!" << endl;
                x->clear();
                return;
            }

        cout << "SetTest 'remove' passed in " << time << " seconds." << endl;
    }

    void remove_even(Set *x, int n, double &time) {
        size_t size = sizeof(int);
        for (int i = 0; i < n; i++)
            x->insert(&i, size);

        Container::Iterator *it = x->begin();
        clock_t start = clock();

        for (int i = 0; i < n; i++)
            if (*(int *) it->getElement(size) % 2 == 1)
                x->remove(it);
            else
                it->goToNext();

        clock_t end = clock();
        time = (double) (end - start) / CLOCKS_PER_SEC;

        for (int i = 0; i < n; i++)
            if ((i % 2 == 0 && x->find(&i, size) == nullptr) || (i % 2 == 1 && x->find(&i, size) != nullptr)) {
                cout << "SetTest 'remove_even' failed!" << endl;
                x->clear();
                return;
            }

        x->clear();
        cout << "SetTest 'remove_even' passed in " << time << " seconds." << endl;
    }

    void find(Set *x, int n, double &time) {
        bool ret = true;
        size_t size = sizeof(int);
        for (int i = 0; i < n; i++)
            x->insert(&i, size);

        clock_t start = clock();
        for (int i = 0; i < n; i++)
            if (x->find(&i, size) == nullptr) {
                ret = false;
                break;
            }
        clock_t end = clock();

        time = (double) (end - start) / CLOCKS_PER_SEC;

        if (!ret)
            cout << "SetTest 'find' failed!" << endl;
        else
            cout << "SetTest 'find' passed in " << time << " seconds." << endl;

        x->clear();
    }

    void clear(Set *x, int n, double &time) {
        size_t size = sizeof(int);
        for (int i = 0; i < n; i++)
            x->insert(&i, size);

        clock_t start = clock();
        x->clear();
        clock_t end = clock();
        time = (double) (end - start) / CLOCKS_PER_SEC;

        for (int i = 0; i < n; i++)
            if (x->find(&i, size) != nullptr) {
                cout << "SetTest 'clear' failed!" << endl;
                x->clear();
                return;
            }

        cout << "SetTest 'clear' passed in " << time << " seconds." << endl;
    }
};