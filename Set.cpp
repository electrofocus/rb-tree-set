//
// Created by Amir Mullagaliev on 05-May-19.
//

#include "Set.h"

Set::Set(MemoryManager &mem) : AbstractSet(mem), tree(mem) {}

int Set::size() {
    return tree.size();
}

size_t Set::max_bytes() {
    return tree.max_bytes();
}

Container::Iterator *Set::find(void *key, size_t size) {
    return tree.find(key, size);
}

Container::Iterator *Set::newIterator() {
    return tree.newIterator();
}

Container::Iterator *Set::begin() {
    return tree.begin();
}

Container::Iterator *Set::end() {
    return tree.end();
}

void Set::remove(Container::Iterator *it) {
    tree.remove(it);
}

int Set::insert(void *key, size_t size) {
    return tree.insert(key, size);
}

void Set::clear() {
    tree.clear();
}

bool Set::empty() {
    return tree.empty();
}
