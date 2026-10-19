#include <iostream>
using namespace std;

class Node {
 public:
	int data;
	Node *next;
	Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
	Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node* merge(Node* &head1, Node* &head2){
	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;

	Node* dummyNode = new Node(-1);
	Node* res = dummyNode;
	while(head1 != NULL && head2 != NULL){
		if(head1 -> data < head2 -> data){
			res -> child = head1;
			res = head1;
			head1 = head1 -> child;
		}
		else{
			res -> child = head2;
			res = head2;
			head2 = head2 -> child;
		}
		res -> next = NULL;
	}

	if(head1 != NULL) res -> child = head1;
	if(head2 != NULL) res -> child = head2;

	// FIX 2: leftover tail ka first node bhi next = NULL hona chahiye
	if(res -> child) res -> child -> next = NULL;

	// FIX 1: list child se bani hai, isliye dummy ka child return karo
	return dummyNode -> child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head -> next == NULL) return head;

	Node* mergeHead = flattenLinkedList(head -> next);
	head = merge(head, mergeHead);
	return head;
}

Node* makeChildList(int arr[], int n){
	Node* head = new Node(arr[0]);
	Node* tail = head;
	for(int i = 1; i < n; i++){
		tail->child = new Node(arr[i]);
		tail = tail->child;
	}
	return head;
}

void printFlattened(Node* head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->child;
	}
	cout << endl;
}

int main() {
	int a[] = {5, 7, 8, 30};
	int b[] = {10, 20};
	int c[] = {19, 22, 50};
	int d[] = {28, 35, 40, 45};

	Node* h1 = makeChildList(a, 4);
	Node* h2 = makeChildList(b, 2);
	Node* h3 = makeChildList(c, 3);
	Node* h4 = makeChildList(d, 4);

	h1->next = h2;
	h2->next = h3;
	h3->next = h4;

	Node* res = flattenLinkedList(h1);

	cout << "Flattened: ";
	printFlattened(res);

	// next pointers sab NULL hone chahiye
	bool ok = true;
	for(Node* t = res; t; t = t->child) if(t->next) ok = false;
	cout << "All next NULL: " << (ok ? "yes" : "NO") << endl;

	return 0;
}