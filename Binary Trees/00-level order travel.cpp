#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


class Solution {
   public:
    // Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node) {
        queue<Node*> q;

        vector<int> level;

        q.push(node);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            level.push_back(node->data);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return level;
    }
};