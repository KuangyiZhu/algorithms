#include<cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *h, *p, *q;
	h=p=q=new ListNode(0);
	q->next=head;
	int i=0;
	while(q->next!=NULL&&i<n){
		q=q->next;
		i++;
	}
	if(i<n)
		return head;
	while(q->next!=NULL){
		q=q->next;
		p=p->next;
	}
	p->next=p->next->next;
	return h->next;
}

