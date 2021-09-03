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
    void removeLoop(Node* head) {
        struct Node* tor = head;
        struct Node* hare = head;

        do {
            tor = tor->next;
            hare = hare->next;

            if (hare) hare = hare->next;
        } while (hare != NULL && hare != tor);

        if (hare == NULL) return;

        hare = head;

        while (hare != tor) {
            hare = hare->next;
            tor = tor->next;
        }

        struct Node* meet = hare;

        while (true) {
            if (hare->next == meet) {
                hare->next = NULL;
                return;
            }
            hare = hare->next;
        }
    }
};