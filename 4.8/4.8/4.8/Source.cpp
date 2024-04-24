#include <iostream>

struct node {
    node(int x) : left{ nullptr }, right{ nullptr }, value{ x } {};
    node* left;
    node* right;
    int value;
};

bool find(node* root, node* node) {
    if (root == nullptr) {
        return false;
    }
    if (root == node) {
        return true;
    }
    return find(root->left, node) || find(root->right, node);
}

node* ancestor(node* root, node* node1, node* node2) {
    if (root == nullptr || root == node1 || root == node2) {
        return root;
    }

    bool node1lsOnleft = find(root->left, node1);
    bool node2lsOnLeft = find(root->left, node2);
    if (node1lsOnleft != node2lsOnLeft) {
        return root;
    }
    node* side = node1lsOnleft ? root->left : root->right;
    return ancestor(side, node1, node2);
}
node* commonAncestor(node* root, node* node1, node* node2) {

    if (!find(root, node1) || !find(root, node2)) {
        return nullptr;
    }
    return ancestor(root, node1, node2);
}

int main() {
    node* root = new node(5);
    node* left = root;
    left->left = new node(10);
    left = left->left;
    left->right = new node(4);
    node* n1 = left->right;
    left->left = new node(6);
    left = left->left;
    left->left = new node(44);
    node* n2 = left->left;
    node* right = root;
    right->right = new node(3);
    right = right->right;
    right->right = new node(22);
    right = right->right;
    right->left = new node(100);



    /*
                                                    5
                                                   / \
                                                 10   3
                                                /  \   \
                                               6    4   22
                                              /    n1  /
                                            44        100
                                              n2
    */

    node* ptr = commonAncestor(root, n1, n2);
    std::cout << ptr->value;

    return 0;
}