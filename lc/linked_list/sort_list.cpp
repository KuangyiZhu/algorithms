#include<cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* start, ListNode* end){
	if(start==end)
		return start;
	if(start->next==end)
		return start;
	int pivot = start->val;
	ListNode *p, *q, *lstart, *rstart;
	lstart=rstart=p=start;
	while(p->next!=end){
		if(p->next->val<pivot){
			q=p->next;
			p->next=p->next->next;
			q->next=lstart;
			lstart=q;
		}
		else if(p->next->val==pivot){
			if(p!=rstart){
				q=rstart->next;
				rstart->next=p->next;
				p->next=p->next->next;
				rstart->next->next=q;
			}
			else{
				p=p->next;
			}
			rstart=rstart->next;
		}
		else{
			p=p->next;
		}
	}
	rstart->next=sortList(rstart->next, end);
	return sortList(lstart, start);
}
ListNode* sortList(ListNode* head) {
	return sortList(head, NULL);
}
