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
    // Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second) {
        struct Node* firstHead = reverse(first);
        struct Node* secondHead = reverse(second);

        struct Node* f = firstHead;
        struct Node* s = secondHead;

        int rem = 0;

        while (f != NULL && s != NULL) {
            f->data = f->data + s->data + rem;
            s->data = f->data;

            rem = f->data / 10;

            f->data = f->data % 10;
            s->data = s->data % 10;

            f = f->next;
            s = s->next;
        }

        if (s == NULL) {
            while (f != NULL && rem) {
                f->data = f->data + rem;

                rem = f->data / 10;

                f->data = f->data % 10;

                f = f->next;
            }

            if (rem == 0) {
                return reverse(firstHead);
            } else {
                struct Node* newHead = new Node(rem);

                newHead->next = reverse(firstHead);

                return newHead;
            }
        } else {
            while (s != NULL && rem) {
                s->data = s->data + rem;

                rem = s->data / 10;

                s->data = s->data % 10;

                s = s->next;
            }

            if (rem == 0) {
                return reverse(secondHead);
            } else {
                struct Node* newHead = new Node(rem);

                newHead->next = reverse(secondHead);

                return newHead;
            }
        }
    }
};
