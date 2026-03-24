#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};


class Solution {
  public:
    
    struct Info {
        int minVal, maxVal, size;
        bool isBST;
    };
    
    Info solve(Node* root, int &ans) {
        if (!root) {
            return {INT_MAX, INT_MIN, 0, true};
        }
        
        Info left = solve(root->left, ans);
        Info right = solve(root->right, ans);
        
        Info curr;

        if (left.isBST && right.isBST &&
            root->data > left.maxVal &&
            root->data < right.minVal) {
            
            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->data, left.minVal);
            curr.maxVal = max(root->data, right.maxVal);
            
            ans = max(ans, curr.size);
        }
        else {
            curr.isBST = false;
            curr.size = 0;
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }
        
        return curr;
    }
    
    int largestBst(Node *root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};