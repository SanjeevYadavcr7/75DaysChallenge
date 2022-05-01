#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int _val){
		val = _val;
		next = NULL;
	}
};
typedef pair<int,ListNode*> customPair;

void display(ListNode* head) {
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n = lists.size();
	if(n == 0) return NULL;
	
	ListNode* head = new ListNode(-1);
	ListNode* curr = head;
	priority_queue<customPair, vector<customPair>, greater<>> minHeap;
	
	for(int i=0; i<n; i++){
    	if(lists[i]) minHeap.push({lists[i]->val, lists[i]});   
    }
    if(minHeap.size() == 0) return NULL;
    
	while(!minHeap.empty()) {
		auto it = minHeap.top();
		minHeap.pop();

		ListNode* node = it.second;
		curr->next = node;
		curr = curr->next;
		
		if(node->next) minHeap.push({node->next->val, node->next});
	}
	return head->next;	
}

int main() {
	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(4);
	head1->next->next = new ListNode(5);

	ListNode* head2 = new ListNode(1);
	head2->next = new ListNode(3);
	head2->next->next = new ListNode(4);	
	
	ListNode* head3 = new ListNode(2);
	head3->next = new ListNode(6);
	
	vector<ListNode*> lists = {head1, head2, head3};
	ListNode* head = mergeKLists(lists);
	display(head);
	
	return 0;
}
