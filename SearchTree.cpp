//
// Created by Amir on 05-May-19.
//

#include "SearchTree.h"


SearchTree::Iter::Iter(SearchTree::Node *x, SearchTree *T) {
    Iter::x = x;
    Iter::T = T;
}

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
