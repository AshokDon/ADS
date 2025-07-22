#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int data;
    int height;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        data = val;
        height = 0;
        left = right = NULL;
    }
};

struct AVLTree{
    TreeNode *root;
    //inseret 
    AVLTree(){
        root = NULL;
    }
    int Height(TreeNode *node){
        if(node == NULL)return 0;
        return node->height;
    }
    TreeNode *LeftRotate(TreeNode *P){
        TreeNode *X = P->right;
        TreeNode *Y = X->left;

        X->left = P;
        P->right = Y;

        X->height = max(Height(X->left),Height(X->right))+1;
        P->height = max(Height(P->left) , Height(P->right))+1;
        return X;
    }
    TreeNode *RightRotate(TreeNode *P){
        TreeNode *X = P->left;
        TreeNode *Y = X->right;

        //change 
        X->right = P;
        P->left = Y;

        X->height = max(Height(X->left),Height(X->right))+1;
        P->height = max(Height(P->left) , Height(P->right))+1;
        return X;
    }
    TreeNode *ADD(TreeNode *root, int val){
        if(root == NULL) return new TreeNode(val);

        if(val > root->data){
            root->right = ADD(root->right, val);
        }
        else{
            root->left = ADD(root->left, val);
        }
        

        //i need to check the balance factor
        //to know the balance factor -> right hight , left hight
        //balnce factor = leftHight - rightHight

        int balanceFator = Height(root->left) - Height(root->right);
        root->height = max(Height(root->left) , Height(root->right))+1;


        if(balanceFator > 1 && val < root->left->data){
            RightRotate(root);
        }
        if(balanceFator > 1 && val > root->left->data){
            root->left = LeftRotate(root->left);
            RightRotate(root);
        }
        if(balanceFator < -1 && val > root->right->data){
            LeftRotate(root);
        }
        if(balanceFator < -1 && val < root->right->data){
            root->right = RightRotate(root->right);
            LeftRotate(root);
        }
        return root;


    }
    void Insert(int val){
        root = ADD(root,val);
    }

    //Delete 


    //Search

};


int main(){
    int n; // n -> nodes 
    cin >> n; // 7
    vector<int>A(n); //
    AVLTree AVL;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
    for(int i = 0 ; i < n ; i++){
        AVL.Insert(A[i]);
    }
    cout << AVL.root->data;
    //70 20 10 50 80 100 7
}
