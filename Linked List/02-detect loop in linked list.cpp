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

void loopHere(Node* head, Node* tail, int position) {
    if (position == 0) return;

    Node* walk = head;
    for (int i = 1; i < position; i++) walk = walk->next;
    tail->next = walk;
}


class Solution {
   public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        struct Node* tor = head;
        struct Node* hare = head;

        do {
            tor = tor->next;
            hare = hare->next;

            if (hare) hare = hare->next;

        } while (hare != NULL and hare != tor);

        return hare != NULL;
    }
};