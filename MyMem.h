//
// Created by Amir Mullagaliev on 05-May-19.
//

#pragma once

#include <iostream>
#include "../../iv/MemoryManager.h"

class MyMem : protected MemoryManager {
private:
    char *mem;
    bool *bit;
    size_t *sizes;

    size_t _size;
    size_t free;

public:
    explicit MyMem(size_t n) : MemoryManager(n) {
        mem = (char *) malloc(n * sizeof(char));
        bit = (bool *) malloc(n * sizeof(bool));
        sizes = (size_t *) malloc(n * sizeof(size_t));
        for (int i = 0; i < n; i++) {
            bit[i] = true;
            sizes[i] = 0;
        }
        _size = n;
        free = n;
    }

    size_t maxBytes() override {
        return -1;
    }

    void *allocMem(size_t n) override {
        if (free == 0)
            return nullptr;
        int i, j;
        for (i = 0; i < _size; i++) {
            if (bit[i]) {
                j = i;
                while(j < _size && bit[j]) j++;
                if (j - i <= n)
                    return mem + i;
                i = j;
            }
        }

    }

    void freeMem(void *p) override {

    }
};