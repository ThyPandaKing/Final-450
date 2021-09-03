#include <bits/stdc++.h>

struct Node {
    int data;
    struct Node* next;

} * start;


struct Node* removeDuplicates(struct Node* head) {
    struct Node* node = head;
    struct Node* sol = head;

    int val = node->data;

    while (node != NULL) {
        while (node != NULL && node->data == val) {
            node = node->next;
        }

        sol->next = node;
        sol = node;
        if (sol) val = sol->data;
    }

    return head;
}