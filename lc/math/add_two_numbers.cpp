#include<cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* l3=new ListNode(0);
	ListNode* li=l3;
	int carry=0;
	while(l1 || l2){
		carry=0;
		if(l1){
			li->val+=l1->val;
			carry+=li->val/10;
			li->val=li->val%10;
			l1=l1->next;
		}
		if(l2){
			li->val+=l2->val;
			carry+=li->val/10;
			li->val=li->val%10;
			l2=l2->next;
		}
		if(l1 || l2 || carry){
			li->next=new ListNode(carry);
			li=li->next;
		}
	}
	return l3;
}

