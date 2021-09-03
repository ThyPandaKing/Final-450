#include <bits/stdc++.h>
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
    Node* reverse(struct Node* head) {
        if (head == NULL) return NULL;

        Node* nxt = head->next;
        Node* pre = NULL;
        Node* temp = head;

        while (temp != NULL) {
            temp->next = pre;
            pre = temp;
            temp = nxt;
            if (temp) nxt = temp->next;
        }

        return pre;
    }

    Node* addOne(Node* head) {
        Node* newHead = reverse(head);
        Node* node = newHead;

        while (node != NULL) {
            if (node->data + 1 < 10) {
                node->data = node->data + 1;

                return reverse(newHead);
            } else {
                node->data = (node->data + 1) % 10;

                node = node->next;
            }
        }

        Node* newnewhead = new Node(1);

        newnewhead->next = newHead;

        return newnewhead;
    }
};

