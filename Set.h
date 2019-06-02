//
// Created by Amir Mullagaliev on 05-May-19.
//

#pragma once

#include "SetAbstract.h"
#include "SearchTree.h"

class Set : public AbstractSet {
private:
    SearchTree tree;

public:
    explicit Set(MemoryManager &mem);

    int size() override;

    size_t max_bytes() override;

    Iterator *find(void *key, size_t size) override;

    Iterator *newIterator() override;

    Iterator *begin() override;

    Iterator *end() override;

    void remove(Iterator *it) override;

    int insert(void *key, size_t size) override;

    void clear() override;

    bool empty() override;

};