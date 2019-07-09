//
// Created by Amir Mullagaliev on 05-May-19.
//

#pragma once

#include <iostream>
#include <set>
#include "MemoryManager.h"

class MyMem : public MemoryManager {
protected:
    char *mem;
    char *bits;
    size_t _size;
    size_t free;

    char getMark(char a, char b) {
        std::set<char> marks = {1, 2, 3};
        marks.erase(a);
        marks.erase(b);
        return *marks.begin();
    }

public:
    explicit MyMem(size_t n) : MemoryManager(n) {
        mem = new char[n];
        bits = new char[n + 1];

        for (int i = 0; i < n; i++)
            bits[i] = 0;

        bits[n] = 1;

        _size = n;
        free = n;
    }

    size_t maxBytes() override {
        return _size;
    }

    void *allocMem(size_t n) override {
        if (!free)
            return nullptr;

        for (int i = 0; i < _size; i++) {
            if (!bits[i]) {
                int j;
                for (j = i; !bits[j] && j - i < n; j++);
                if (j - i == n) {
                    char mark;
                    if (i != 0)
                        mark = getMark(bits[i - 1], bits[j]);
                    else
                        mark = getMark(0, bits[j]);

                    for (int k = i; k < j; k++)
                        bits[k] = mark;
                    return mem + i;
                }
                i = j;
            }
        }
        return nullptr;
    }

    void freeMem(void *p) override {
        char *t = (char *) p;
        if (t < mem || t > mem + _size)
            return;

        int k = t - mem;
        if (bits[k] == 0)
            return;
        char mark = bits[k];

        if (k == 0 || bits[k - 1] != mark) {
            while (bits[k] == mark)
                bits[k++] = 0;
        }
    }
};