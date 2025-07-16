#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};
struct BinarySearchTree{
    TreeNode *root = NULL;
    TreeNode *Add(TreeNode *root, int val){
        if(root == NULL)return new TreeNode(val);
        if(root->data > val){
            root->left = Add(root->left,val);
        }
        if(root->data < val){
            root->right = Add(root->right,val);
        }
        return root;
    }
    void Insert(int val){
        root = Add(root,val);
    }
    void printInorder(TreeNode *root){
        if(root){
        printInorder(root->left);
        cout << root->data <<" ";
        printInorder(root->right);
        }
    }
    void Inorder(){
        printInorder(root);
    }
    
    //Delete Data form BST 

    //Search Data in BST 


};


int main(){
    int n;
    cin >> n;
    vector<int>A(n);
    //6
    //30 10 70 9 25 40
    for(int i = 0 ; i < n ; i++)cin >> A[i];
    BinarySearchTree BST; 
    for(int i = 0 ; i < n ; i++){
        BST.Insert(A[i]);
    }
    BST.Inorder();
}
