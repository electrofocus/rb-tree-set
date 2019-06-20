// Created by Amir Mullagaliev on 05-May-19.

#pragma once

#include "GroupContainer.h"
#include <fstream>

enum Color {
    red,
    black
};

class SearchTree : protected GroupContainer {
private:
    struct Node {
        void *key;
        size_t size;
        Color color;
        Node *p;
        Node *left;
        Node *right;

        Node(void *key, size_t size, SearchTree *T) {
            Node::size = size;
            Node::key = T->_memory.allocMem(size);
            memcpy(Node::key, key, size);// Куда, откуда, сколько
            color = red;
            p = nullptr;
            left = T->nil;
            right = T->nil;
        }

        Node() {
            // Специальный конструктор для узла nil
            key = nullptr;
            size = 57;
            color = black;
            p = nullptr;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *nil;
    Node *root;
    int _size;

    void leftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;

        if (y->left != nil)
            y->left->p = x;
        y->p = x->p;

        if (x->p == nil)
            root = y;
        else
            if (x == x->p->left)
                x->p->left = y;
            else
                x->p->right = y;

        y->left = x;
        x->p = y;
    }

    void rightRotate(Node *x) {
        Node *y = x->left;
        x->left = y->right;

        if (y->right != nil)
            y->right->p = x;
        y->p = x->p;

        if (x->p == nil)
            root = y;
        else
            if (x == x->p->right)
                x->p->right = y;
            else
                x->p->left = y;

        y->right = x;
        x->p = y;
    }

    void insertFix(Node *z) {
        Node *y = nullptr;

        while (z->p->color == red) {
            if (z->p == z->p->p->left) {
                y = z->p->p->right;
                if (y->color == red) {
                    z->p->color = black;
                    y->color = black;
                    z->p->p->color = red;
                    z = z->p->p;
                }
                else {
                    if (z == z->p->right) {
                        z = z->p;
                        leftRotate(z);
                    }
                    z->p->color = black;
                    z->p->p->color = red;
                    rightRotate(z->p->p);
                }
            }
            else {
                y = z->p->p->left;
                if (y->color == red) {
                    z->p->color = black;
                    y->color = black;
                    z->p->p->color = red;
                    z = z->p->p;
                }
                else {
                    if (z == z->p->left) {
                        z = z->p;
                        rightRotate(z);
                    }
                    z->p->color = black;
                    z->p->p->color = red;
                    leftRotate(z->p->p);
                }
            }
        }
        root->color = black;
    }

    Node *treeMinimum(Node *x) {
        Node *y = x;
        while (y->left != nil)
            y = y->left;
        return y;
    }

    Node *treeMaximum(Node *x) {
        Node *y = x;
        while (y->right != nil)
            y = y->right;
        return y;
    }

    void transplant(Node *u, Node *v) {
        // Замещает u на v
        if (u->p == nil)
            root = v;
        else
            if (u == u->p->left)
                u->p->left = v;
            else
                u->p->right = v;
        v->p = u->p;
    }

    void deleteFix(Node *x) {
        Node *w = nullptr;

        while (x != root && x->color == black) {
            if (x == x->p->left) {
                w = x->p->right;// Запоминаем брата для x
                if (w->color == red) {
                    w->color = black;
                    x->p->color = red;
                    leftRotate(x->p);
                    w = x->p->right;
                }
                if (w->left->color == black && w->right->color == black) {
                    w->color = red;
                    x = x->p;
                }
                else {
                    if (w->right->color == black) {
                        w->left->color = black;
                        w->color = red;
                        rightRotate(w);
                        w = x->p->right;
                    }
                    w->color = x->p->color;
                    x->p->color = black;
                    w->right->color = black;
                    leftRotate(x->p);
                    x = root;
                }
            }
            else {
                w = x->p->left;
                if (w->color == red) {
                    w->color = black;
                    x->p->color = red;
                    rightRotate(x->p);
                    w = x->p->left;
                }
                if (w->right->color == black && w->left->color == black) {
                    w->color = red;
                    x = x->p;
                }
                else {
                    if (w->left->color == black) {
                        w->right->color = black;
                        w->color = red;
                        leftRotate(w);
                        w = x->p->left;
                    }
                    w->color = x->p->color;
                    x->p->color = black;
                    w->left->color = black;
                    rightRotate(x->p);
                    x = root;
                }
            }
        }
        x->color = black;
    }

    void remove(Node *z) {
        Node *x = nullptr;

        Node *y = z;
        Color y_original_color = y->color;

        if (z->left == nil) {
            x = z->right;
            transplant(z, z->right);
        }
        else
            if (z->right == nil) {
                x = z->left;
                transplant(z, z->left);
            }
            else {
                y = treeMinimum(z->right);
                y_original_color = y->color;
                x = y->right;
                if (y->p == z) {
                    x->p = y;
                }
                else {
                    transplant(y, y->right);
                    y->right = z->right;
                    y->right->p = y;
                }
                transplant(z, y);
                y->left = z->left;
                y->left->p = y;
                y->color = z->color;
            }
        if (y_original_color == black)
            deleteFix(x);

        _memory.freeMem(z->key);
        delete z;
        _size--;
    }

    int compare(void *key_1, size_t size_1, void *key_2, size_t size_2) {
        if (size_1 < size_2 || memcmp(key_1, key_2, size_1) < 0)
            return -1;// key_1 < key_2
        if (size_1 > size_2 || memcmp(key_1, key_2, size_1) > 0)
            return 1;// key_1 > key_2
        return 0;// key_1 == key_2
    }

    void clear(Node *z) {
        if (z == nil)
            return;
        clear(z->left);
        clear(z->right);

        _memory.freeMem(z->key);
        delete z;
    }

class Iter : protected Container::Iterator {
    private:
        Node *x;
        SearchTree *T;

        Iter(Node *x, SearchTree *T);

    public:
        void *getElement(size_t &size) override {
            size = x->size;
            return x->key;
        }

        bool hasNext() override;

        void goToNext() override {
            if (x == T->_end->x)// TODO: Replace condition to (x == T->nil)
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

        bool equals(Iterator *right) override {
            return x == ((Iter *) right)->x;
        }

        bool hasPrevious() {
            return x != T->treeMinimum(T->root);
        }

        void goToPrevious() {
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

        friend class SearchTree;
    };
    
    Iter *_end;

public:
    explicit SearchTree(MemoryManager &mem) : GroupContainer(mem) {
        nil = new Node;// Здесь вызывается специальный конструктор для узла nil
        root = nil;
        _end = new Iter(nil, this);
        _size = 0;
    }

    int size() override {
        return _size;
    }

    size_t max_bytes() override {
        return _memory.maxBytes();
    }

    Container::Iterator *find(void *key, size_t size) override {
        Node *x = root;// Нужно, чтобы переходить от корня глубже в дерево при поиске
        while (x != nil) {
            if (compare(key, size, x->key, x->size) < 0)// key < x->key
                x = x->left;
            else
                if (compare(key, size, x->key, x->size) > 0)
                    x = x->right;
                else
                    return new Iter(x, this);
        }
        return _end;
    }

    Container::Iterator *newIterator() override {
        return _end;
    }

    Container::Iterator *begin() override {
        if (root == nil)
            return _end;
        return new Iter(treeMinimum(root), this);
    }

    Container::Iterator *end() override {
        return _end;
    }

    int insert(void *key, size_t size) {
        Node *y = nil;// Присвоим, чтобы найти родителя для будущего нового узла
        Node *x = root;// Присвоим, чтобы переходить от корня глубже в дерево при поиске

        while (x != nil) {
            y = x;
            if (compare(key, size, x->key, x->size) < 0)// key < x->key
                x = x->left;
            else
                if (compare(key, size, x->key, x->size) > 0)
                    x = x->right;
                else
                    return 1;// Такой элемент уже был добавлен
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
        return 0;// Успешно добавлено
    }

    void remove(Container::Iterator *it) override {
        Node *z = ((Iter *) it)->x;
        if (z == nil)
            return;
        it->goToNext();
        remove(z);
    }

    void clear() override {
        clear(root);
        root = nil;
    }

    bool empty() override {
        return root == nil;
    }

    ~SearchTree() {
        clear(root);
    }

};

// TODO: Split all methods of class SearchTree into declaration and definition