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
    ListNode* end_of_first_half (ListNode* curr){
        ListNode* fast_pointer = curr;
        ListNode* slow_pointer = curr;
            while((fast_pointer->next!=NULL)&& (fast_pointer->next->next!=NULL)){
            fast_pointer = fast_pointer->next->next;
            slow_pointer = slow_pointer->next;
        }
        return slow_pointer->next;
    }

    ListNode* reverseList (ListNode* head){
        ListNode* prev_node = NULL;
        ListNode* curr_node = head;
        while(curr_node != NULL){    
            ListNode* temp_node = curr_node->next;
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = temp_node;      
        }
        //cout<<"Reverse list starting node = "<<prev_node->val<<endl;
        return prev_node;
    }

    bool isPalindrome(ListNode* head) {
        if (head->next==NULL) return true;
        ListNode* currNode = head;
        ListNode* first_half_end_node =  end_of_first_half(currNode);
        ListNode* second_half_start_node = reverseList(first_half_end_node);
        ListNode* ptr1 = head;
        ListNode* ptr2 = second_half_start_node;
        //cout<<"ptr1_val = "<<ptr1->val<<endl;
        //cout<<"ptr2_val = "<<ptr2->val<<endl;
        bool result = true;
        while ((ptr2 != NULL)&&(result!=false)){
            if (ptr1->val == ptr2->val){
                ptr1 = ptr1->next;//Definition for singly-linked list.


                ptr2 = ptr2->next; 
            }
            else
                result = false;
        }
        return result;
    }
};