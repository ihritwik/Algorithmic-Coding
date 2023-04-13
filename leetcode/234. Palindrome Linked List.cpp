#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* find_second_half_start_node(ListNode* temp){
        ListNode* fast_pointer= temp;
        ListNode* slow_pointer= temp;
        while(fast_pointer->next!=NULL && fast_pointer->next->next!=NULL){
            fast_pointer=fast_pointer->next->next;
            slow_pointer=slow_pointer->next;
        }
        return slow_pointer->next;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* flag = head;
        while(curr!=NULL){
            flag = curr->next;
            curr->next=prev;
            prev=curr;
            curr=flag;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        bool response=true;
        ListNode* second_half_start = find_second_half_start_node(head);
        ListNode* second_half_reversed_head = reverseList(second_half_start);

        ListNode* ptr1 = head;
        ListNode* ptr2 = second_half_reversed_head;

        while ((ptr2!=NULL)&&(response!=false)){
            if (ptr1->val == ptr2->val){
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            else response = false;
        }
        return response;
    }
};
