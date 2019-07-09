// Created by Amir Mullagaliev on 05-May-19.

#include "SearchTree.h"

bool SearchTree::Iter::hasNext() {
    if (x->right == nullptr)
        return false;
    if (x->right != T->nil)
        return true;
    Node *y = x->p;
    Node *z = x;
    while (y != T->nil && z == y->right) {
        z = y;
        y = y->p;
    }
    return y != T->nil;
}

void SearchTree::Iter::goToNext() {
    if (x == T->nil)
        return;
    if (x->right != T->nil) {
        x = T->treeMinimum(x->right);
    }
    else {
        Node *y = x->p;
        while (y != T->nil && x == y->right) {
            x = y;
            y = y->p;
        }
        x = y;
    }
}

bool SearchTree::Iter::equals(Container::Iterator *right) {
    if (this == nullptr && right == nullptr)
        return true;
    else
        if (this != nullptr && right != nullptr)
            return x == ((Iter *) right)->x;
        else
            return false;
}

bool SearchTree::Iter::hasPrevious() {
    return x != T->treeMinimum(T->root);
}

void SearchTree::Iter::goToPrevious() {
    if (x == T->treeMinimum(T->root))
        return;
    if (x->left != T->nil) {
        x = T->treeMaximum(x->left);
    }
    else {
        Node *y = x->p;
        while (y != T->nil && x == y->left) {
            x = y;
            y = y->p;
        }
        x = y;
    }
}

Container::Iterator *SearchTree::find(void *key, size_t size) {
    Node *x = root;
    while (x != nil) {
        if (compare(key, size, x->key, x->size) < 0)
            x = x->left;
        else
            if (compare(key, size, x->key, x->size) > 0)
                x = x->right;
            else
                return new Iter(x, this);
    }
    return nullptr;
}

int SearchTree::insert(void *key, size_t size) {
    Node *y = nil;
    Node *x = root;

    while (x != nil) {
        y = x;
        if (compare(key, size, x->key, x->size) < 0)
            x = x->left;
        else
            if (compare(key, size, x->key, x->size) > 0)
                x = x->right;
            else
                return 1;
    }

    Node *z = new Node(key, size, this);
    z->p = y;

    if (y == nil)
        root = z;
    else
        if (compare(key, size, y->key, y->size) < 0)
            y->left = z;
        else
            y->right = z;

    insertFix(z);
    _size++;
    return 0;
}
