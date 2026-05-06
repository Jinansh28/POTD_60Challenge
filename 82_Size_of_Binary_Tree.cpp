#include<bits/stdc++.h>
using namespace std;



struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int getSize(Node* root) {
        // code here
        if(root == NULL) return 0;
        return getSize(root->left) + getSize(root->right) + 1;
    }
};