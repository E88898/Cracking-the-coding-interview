#include <iostream>

struct node {
    node(int x) : left{ nullptr }, right{ nullptr }, value{ x } {};
    node* left;
    node* right;
    int value;
};

bool isSubtree(node* root1, node* root2) {
    if (!root1 || !root2) {
        return false;
    }
    while (root1) {
        if (root1->value == root2->value) {
            break;
        }
        root1 = root2->value < root1->value ? root1->left : root1->right;
    }

    if (root1 == root2) {
        return true;
    }
    return false;
}



int main() {
    node* root2 = new node(11);
    node* left = root2;
    left->left = new node(6);
    left = left->left;
    left->right = new node(7);
    node* n1 = left->right;
    left->left = new node(3);
    left = left->left;
    left->left = new node(1);

    node* right = root2;
    right->right = new node(14);
    right = right->right;
    right->right = new node(22);
    right = right->right;
    right->left = new node(17);


   
    node* root1 = new node(82);
    left = root1;
    left->left = new node(72);
    left = left->left;
    left->right = new node(79);
    left->left = new node(44);
    left = left->left;
    left->left = root2;
    left->right = new node(50);
    left = left->right;
    left->left = new node(47);
    left->right = new node(54);
    left = left->right;
    left->right = new node(62);

    right = root1;
    right->right = new node(87);
    right = right->right;
    right->right = new node(91);
    right = right->right;
    node* tmp = right;
    right->left = new node(89);
    right = right->left;
    right->right = new node(90);
    right = tmp;
    right->right = new node(100);
    right = right->right;
    right->right = new node(132);
    right = right->right;
    right->left = new node(124);
    right = right->left;
    right->right = new node(128);
    right->left = new node(112);

    /*
                                                          root1->  82
                                                                 /   \
                                                              72      87
                                                            /   \      \
                                                         44      79     91
                                                       /   \           /  \
                                            root2-> 11      50       89    100
                                                   / \     /  \       \      \
                                                  6   14 47    54      90     132
                                                /  \   \         \           /
                                               3    7   22        62      124
                                              /        /                 /   \
                                             1       17               112     128

    */

    if (isSubtree(root1, root2)) {
        std::cout << "ok";
    }
    else {
        std::cout << ".!.";
    }

    

    return 0;
}