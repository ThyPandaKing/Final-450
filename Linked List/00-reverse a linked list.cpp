#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
   public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
        if (head == NULL || head->next == NULL) return head;

        struct Node* node = head;
        struct Node* next = head;
        struct Node* pre = NULL;

        while (node != NULL) {
            next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }

        return pre;
    }
};
