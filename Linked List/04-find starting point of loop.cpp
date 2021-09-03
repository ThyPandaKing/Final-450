#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
   public:
    // Function to remove a loop in the linked list.
    struct Node*  findFirstLoop(Node* head) {
        struct Node* tor = head;
        struct Node* hare = head;

        do {
            tor = tor->next;
            hare = hare->next;

            if (hare) hare = hare->next;
        } while (hare != NULL && hare != tor);

        if (hare == NULL) return NULL;

        hare = head;

        while (hare != tor) {
            hare = hare->next;
            tor = tor->next;
        }

        return hare;
    }
};