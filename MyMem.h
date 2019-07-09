//
// Created by Amir Mullagaliev on 05-May-19.
//

#pragma once

#include <iostream>
#include "MemoryManager.h"

class MyMem : protected MemoryManager {
private:
    char *mem;
    bool *bits;

    size_t _size;
    size_t free;

public:
    explicit MyMem(size_t n) : MemoryManager(n) {
        mem = new char[n];
        bits = new bool[n];

        for (int i = 0; i < n; i++)
            bits[i] = false;

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

        }

    }

    void freeMem(void *p) override {

    }
};