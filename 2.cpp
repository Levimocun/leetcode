/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode *p,*result=NULL,*current;
	int integer=0,mod;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		integer = 0;
		while(l1 && l2){
			p = (ListNode *)malloc(sizeof(ListNode));
			mod = (l1->val+l2->val+integer)%10;
			integer = (l1->val+l2->val+integer)/10;
			p->val = mod;
			p->next = NULL;
			if(!result)
				result = p;
			else
				current->next = p;
			current = p;
			l1 = l1->next;
			l2 = l2->next;
		}
		
		if(l1)
			p = l1;
		else if(l2)
			p = l2;
		else
			p = NULL;
		current->next = p;
		if(integer){
			while(integer){
				if(!p){
					p = (ListNode *)malloc(sizeof(ListNode));
					p->val = 0;
					p->next = NULL;
				}
				mod = (p->val + integer)%10;
				integer = (p->val + integer)/10;
				p->val = mod;
				current->next = p;
				current = p;
				p = p->next;
			}
		}
		return result;
    }
};




int main(int argc, char** argv) {
	int num1,num2;
	ListNode *p,*current,*result1,*result2;
	result1 = NULL;
	cin >> num1;
	for(int i=0;i<num1;i++){
		p = (ListNode *)malloc(sizeof(ListNode));
		cin >> (p->val);
		p->next = NULL; 
		if(!result1)
			result1 = p;
		else
			current->next = p;
		current = p;
	} 
	result2 = NULL;
	cin >> num2;
	for(int i=0;i<num2;i++){
		p = (ListNode *)malloc(sizeof(ListNode));
		cin >> (p->val);
		p->next = NULL;
		if(!result2)
			result2 = p;
		else
			current->next = p;
		current = p;
	} 
	Solution solution;
	p = solution.addTwoNumbers(result1,result2);
	while(p){
		cout << p->val << "  ";
		p = p->next;
	}
	return 0;
}