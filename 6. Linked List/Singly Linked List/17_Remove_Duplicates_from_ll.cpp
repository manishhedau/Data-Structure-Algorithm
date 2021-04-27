// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;


class node {

public:
	int data;
	node *next;

	// constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};


// converting an array into an linked list
node *create_ll(int *arr, int n) {
	// head pointer
	node *head = new node(arr[0]);

	// temp pointer which always point to next node
	node *last_node = head;
	for (int i = 1; i < n; i++) {
		last_node->next = new node(arr[i]);
		last_node = last_node->next;
	}
	return head;
}

// Printing the nodes value
// By travesing in entire linked list
void printNode(node *head) {
	// check ll is empty
	if (head == NULL) {
		cout << "Linked List is empty " << endl;
		return;
	}
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}
// function for removing consicative duplicates node from linked list
/
/*
Approach -
-----------
1. Check ll is empty
2. create two pointer curr and prev
3. curr = head->next (means second node)
4. prev = head (means first node)
5. iterate over the loop upto curr==NULL
	a. check prev->data == curr->data
		yes -  1) prev->next = curr->next
			   2) delete curr
			   3) curr = prev->next

		no -   1) prev = curr
			   2) curr = curr->next

6. prev->next = NULL
 */

void removeDuplicates(node *&head) {
	// check ll is empty
	if (head == NULL) {
		return;
	}

	node *curr = head->next;
	node *prev = head;
	while (curr != NULL) {
		if (prev->data == curr->data) {
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
	prev->next = NULL;
}
int main() {
	int arr[10] = { 1, 1, 3, 3, 5, 6, 6, 6, 7};
	int n = 9;
	node *head = create_ll(arr, n);
	printNode(head);
	cout << "Removing Consicative Duplicates : " << endl;
	removeDuplicates(head);
	printNode(head);

	return 0;
}

/*
Output :-
---------
1 -> 1 -> 3 -> 3 -> 5 -> 6 -> 6 -> 6 -> 7 ->
Removing Consicative Duplicates :
1 -> 3 -> 5 -> 6 -> 7 ->
*/