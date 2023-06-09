﻿// 1669. Merge In Between Linked Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(-1, list1);
        ListNode* prev = dummy, * curr = list1;
        int idx = 0;
        while (idx < a) {
            prev = curr;
            curr = curr->next;
            idx++;
        }

        prev->next = list2;

        while (idx < b) {
            curr = curr->next;
            idx++;
        }

        ListNode* nodeB = curr->next;

        curr = list2;
        while (curr->next) {
            curr = curr->next;
        }

        curr->next = nodeB;

        return dummy->next;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
