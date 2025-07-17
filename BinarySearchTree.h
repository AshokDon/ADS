#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
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
    //insert
    TreeNode *root = nullptr;
    TreeNode* ADD(int val, TreeNode *root){
        if(root==NULL)return new TreeNode(val);
        if(val < root->data){
            root->left = ADD(val, root->left);
        }
        else{
            root->right = ADD(val, root->right);
        }
        return root;
    }
    void Insert(int val){
        root = ADD(val, root);
    }
    void PrintInorder(TreeNode *root){
        if(root==nullptr)return;
        PrintInorder(root->left);
        cout << root->data <<" ";
        PrintInorder(root->right);
    }
    void Inorder(){
        PrintInorder(root);
    }
    //Delete

    //search 
};


#endif
