// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
   public:
    struct node* reverse(struct node* head, int k) {
        if (head == NULL) return NULL;

        int val = 0;

        struct node* nxt = head->next;
        struct node* pre = NULL;
        struct node* temp = head;

        while (val < k && temp != NULL) {
            val++;

            temp->next = pre;
            pre = temp;
            temp = nxt;
            if (temp) nxt = temp->next;
        }

        // while(temp!=NULL)cout<<temp->data<<" ",temp=temp->next;

        head->next = reverse(temp, k);

        return pre;
    }
};
