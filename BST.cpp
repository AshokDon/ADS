#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

struct BinarySearchTree {
    TreeNode *root = nullptr;

    TreeNode* Add(TreeNode *root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (root->data > val) {
            root->left = Add(root->left, val);
        } else if (root->data < val) {
            root->right = Add(root->right, val);
        } 
        // Ignore duplicates
        return root;
    }

    void Insert(int val) {
        root = Add(root, val);
    }

    void printInorder(TreeNode *root) {
        if (root) {
            printInorder(root->left);
            cout << root->data << " ";
            printInorder(root->right);
        }
    }

    void Inorder() {
        printInorder(root);
    }

    TreeNode* FindMin(TreeNode* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    TreeNode* Delete(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (val < root->data) {
            root->left = Delete(root->left, val);
        } 
        else if (val > root->data) {
            root->right = Delete(root->right, val);
        } 
        else {
            //no child
            if(root->left == NULL && root->right == NULL){
                delete(root);
                return NULL;
            }
            //one child
            else if(root->left == NULL || root->right == NULL){
                TreeNode *temp;
                if(root->left != NULL){
                    temp = root->left;
                }
                else{
                    temp = root->right;
                }
                detele(root)
                return temp;
            } 
                //two child 
            else {
                TreeNode* temp = FindMin(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        return root;
    }

    void Remove(int val) {
        root = Delete(root, val);
    }

    bool Search(TreeNode* root, int val) {
        if (root == nullptr) return false;
        if (root->data == val) return true;
        if (val < root->data) return Search(root->left, val);
        return Search(root->right, val);
    }

    bool Exists(int val) {
        return Search(root, val);
    }

    void Free(TreeNode* root) {
        if (root) {
            Free(root->left);
            Free(root->right);
            delete root;
        }
    }

    ~BinarySearchTree() {
        Free(root);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    BinarySearchTree BST;
    for (int i = 0; i < n; i++) {
        BST.Insert(A[i]);
    }
    BST.Inorder();
}
