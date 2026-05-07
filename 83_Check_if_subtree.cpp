#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

class Solution {
  public:
    bool isSame(Node *root1, Node *root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        if(root1->data != root2->data) return false;
        return isSame(root1->right, root2->right) && isSame(root1->left, root2->left);
    }
    
    bool isSubTree(Node *root1, Node *root2) {
        if(root1 == NULL) return false;
        if(isSame(root1, root2)) return true;
        return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
        
    }
};