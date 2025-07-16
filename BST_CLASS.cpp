#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

class BinarySearchTree {
private:
    struct TreeNode {
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    TreeNode *root;

    TreeNode* Add(TreeNode *node, int val) {
        if (node == nullptr) return new TreeNode(val);
        if (val < node->data) {
            node->left = Add(node->left, val);
        } else if (val > node->data) {
            node->right = Add(node->right, val);
        }
        return node;
    }

    TreeNode* FindMin(TreeNode *node) {
        while (node && node->left) node = node->left;
        return node;
    }

    TreeNode* Delete(TreeNode *node, int val) {
        if (node == nullptr) return nullptr;
        if (val < node->data) {
            node->left = Delete(node->left, val);
        } else if (val > node->data) {
            node->right = Delete(node->right, val);
        } else {
            if (node->left == nullptr) {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            } else {
                TreeNode *temp = FindMin(node->right);
                node->data = temp->data;
                node->right = Delete(node->right, temp->data);
            }
        }
        return node;
    }

    bool Search(TreeNode *node, int val) const {
        if (node == nullptr) return false;
        if (val == node->data) return true;
        if (val < node->data) return Search(node->left, val);
        return Search(node->right, val);
    }

    void Inorder(TreeNode *node) const {
        if (node) {
            Inorder(node->left);
            cout << node->data << " ";
            Inorder(node->right);
        }
    }

    void Free(TreeNode *node) {
        if (node) {
            Free(node->left);
            Free(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        Free(root);
    }

    void Insert(int val) {
        root = Add(root, val);
    }

    void Remove(int val) {
        root = Delete(root, val);
    }

    bool Exists(int val) const {
        return Search(root, val);
    }

    void PrintInorder() const {
        Inorder(root);
        cout << endl;
    }
};

#endif
