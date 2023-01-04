#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast_ptr = head;
        ListNode *slow_ptr = head;

        if ((slow_ptr==NULL)||(slow_ptr->next==NULL)){ return false;}
        if (slow_ptr->next == slow_ptr){return true;}

        while (fast_ptr!=NULL && fast_ptr->next!=NULL){
            fast_ptr=fast_ptr->next->next;
            slow_ptr=slow_ptr->next;
            if (fast_ptr==slow_ptr){
                return true;
            }
            else{
                continue;
            }
        }
        cout<<"last false";
        return false;
    }
};