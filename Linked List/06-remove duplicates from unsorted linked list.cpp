#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
   public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head) {
        bool vis[10004] = {0};

        struct Node *node = head->next;
        struct Node *sol = head;

        vis[sol->data] = true;

        while (node != NULL) {
            if (vis[node->data] == false) {
                vis[node->data] = true;

                sol->next = node;
                sol = node;
            }

            node = node->next;
        }

        sol->next = NULL;

        return head;
    }
};