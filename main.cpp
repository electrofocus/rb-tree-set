#include <iostream>
#include <time.h>
#include "Mem.h"
#include "Set.h"
#include "Test.h"
#include "SearchTree.h"
#include <vector>

using namespace std;

int main() {
//    Mem mymem(500);
//    Set myset(mymem);
//    Test mytest;
//    int i;
//    size_t size = sizeof(int);
//
//    cout << mytest.insert(myset, 10000000);

//    int a;
//
//    Mem mymem(500);
//    SearchTree mytree(mymem);
//    for (a= 0; a < 500; a++)
//        mytree.insert(&a, sizeof(int));
//
//    a = 50;
//
//    Container::Iterator *it = mytree.find(&a, sizeof(int));
//
//    mytree.print("out.txt");

    return 0;
}

//#include <fstream>

//    void print(Node *x, int i, std::ofstream *f) {
//        if (x->right != nil)
//            print(x->right, i + 1, f);
//        for (int j = 0; j < i; j++)
//            *f << "    ";
//        *f << *(int *) x->key;
//        *f << ((x->color) ? "-R" : "-B") << std::endl;
//        if (x->left != nil)
//            print(x->left, i + 1, f);
//    }

//    void print(const string &dst) {
//        if (_size > 10000)
//            return;
//        std::ofstream f(dst);
//        if (root == nil)
//            f << "Empty tree" << std::endl;
//        else
//            print(root, 0, &f);
//        f.close();
//    }