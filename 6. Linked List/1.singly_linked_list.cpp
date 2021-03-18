// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next;

	node (int d) {
		data = d;
		next = NULL;
	}
};


void insertAtTail(node *&head, int data);
// Time complexity - O(N) for iterating over LL
void printNode(node *head) {
	// iterate over the linked list for printing the value
	// iterate over the linked list till then head = NULL
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;

}

void printNode_recursive(node *head) {
	// base case
	if (head == NULL) {
		cout << endl;
		return;
	}
	// self work
	cout << head->data << " -> ";
	head = head->next;
	// recursive assumption
	printNode_recursive(head);
}

int length(node *head) {
	int len = 0;
	while (head != NULL) {
		head = head->next;
		len++;
	}
	return len;
}
// Time Complexity - O(1)
void insertAtHead(node *&head, int data) {
	// check if head is null
	if (head == NULL) {
		head = new node(data);
		return;
	}

	// if head is not null
	// then allocate new node for data
	// and new node next-> head
	// head  = new node
	node *new_bucket = new node(data);
	new_bucket->next = head;
	head = new_bucket;
	return;
}

// Time Complexity - O(N)  -N: N denote length of linked list
void insertAtMiddle(node *&head, int data, int pos) {
	// if linked list is empty and user want to insert at pos = 0
	// means at the head
	if (head == NULL || pos == 0) {
		insertAtHead(head, data);
		return;
	}
	else if (pos > length(head)) {
		// if pos value is greater then the length size then
		// just add data to the end
		insertAtTail(head, data);
		return;
	}
	else {
		// if both case are not valid
		// then user want to add data in the middle
		// so first go up to this position

		node *curr = head;
		int cnt = 0;
		while (cnt <= pos - 1) {
			curr = curr->next;
			cnt++;
		}

		// allocate node for new data
		node *new_bucket = new node(data);
		new_bucket->next = curr->next;
		curr->next = new_bucket;
	}
}

// Time Complexity - O(N)  -N: N denote length of linked list
void insertAtTail(node *&head, int data) {
	// if linked list is empty , that means we are inserting
	// at head
	if (head == NULL) {
		insertAtHead(head, data);
		return;
	}
	// iterate over the linked list till next = NULL
	node *curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}

	// allocating  new node for the data
	curr->next = new node(data);
}


bool search(node *head, int key) {
	// iterate over the linked list
	// and each iteration check wheater data == key
	// if condition is true then return true
	// else return false
	while (head != NULL) {
		if (head->data == key) {
			return true;
		}
		head = head->next;
	}

	// else part when key is not found
	return false;
}

// Time Complexity - O(1)
void deleteHead(node *&head) {
	// if linked list is empty then return to main
	if (head == NULL) {
		return;
	}
	// deleting the node from the head
	// first passing the head storing address to curr
	// head = curr->next
	// deleting(deallocate) the curr store address memory
	node *curr = head;
	head = curr->next;
	delete curr;
}

void deleteMiddle(node *&head, int pos) {
	// check if linked list is empty or not
	if (head == NULL) {
		cout << "Linked List is empty" << endl;
		return;
	}
	// curr travese over the linked list
	node *curr = head;
	// maintain prev node address
	node *prevNode;

	int cnt = 1;
	while (cnt < pos) {
		prevNode = curr;
		curr = curr->next;
		cnt++;
	}

	// if curr and head both are point to same node
	// means linked list have only one node then delete that
	// node and then head point to curr->next node
	if (curr == head) {
		head = curr->next ;
	}
	// if user want to delete the last node then
	// after deleting the last node
	// prev node->next should point to NULL.
	if (curr->next == NULL) {
		prevNode->next = NULL;
	}
	// connect next connect to prev->next
	prevNode->next = curr->next;
	// delete the curr node and curr node point to pos node
	delete curr;
}

void deleteTail(node *&head) {
	// check if linked list is empty or not
	if (head == NULL) {
		cout << "Linked List is empty" << endl;
		return;
	}

	// curr travese over the linked list
	node *curr = head;
	// maintain prev node address
	node *prevNode;
	while (curr->next != NULL) {
		prevNode = curr;
		curr = curr->next;
	}

	// if curr and head both are point to same node
	// means linked list have only one node then delete that
	// node and then head point to null.
	if (curr == head) {
		head = NULL;
	}
	else {
		// if linked list have multiple node
		// then prev->next = NULL
		prevNode->next = NULL;
	}
	// delete the curr node and curr point to last node of the linked list
	delete curr;
}

void take_input(node *&head) {
	int n;
	cin >> n;

	while (n != -1) {
		insertAtHead(head, n);
		cin >> n;
	}
}
int main() {
	node *head = NULL;

	take_input(head);
	printNode_recursive(head);
	// inserting the value at head
	// insertAtHead(head, 5);
	// insertAtHead(head, 4);
	// insertAtHead(head, 3);
	// insertAtHead(head, 2);
	// insertAtHead(head, 1);
	/*
	cout << "Inserting data At Head : " << endl;
	printNode(head);
	cout << "length : " << length(head) << endl;

	cout << "\n\nInserting data At Middle: " << endl;
	insertAtMiddle(head, 10, 3);
	insertAtMiddle(head, 12, 2);
	printNode(head);

	cout << "\n\nInserting data At Tail : " << endl;
	insertAtTail(head, 100);
	insertAtTail(head, 200);
	printNode(head);

	cout << "Recusive Print the Linked List : " << endl;
	printNode_recursive(head);

	if (search(head, 100)) {
		cout << "100 is present in Linked List" << endl;
	}
	else {
		cout << "100 is not present in Linked List" << endl;
	}

	cout << "Deletion from Head : " << endl;
	deleteHead(head);
	deleteHead(head);
	printNode_recursive(head);
	cout << "length : " << length(head) << endl;
	*/
	printNode_recursive(head);
	cout << "Deletion from middle : " << endl;
	deleteMiddle(head, 5);
	printNode_recursive(head);
	deleteMiddle(head, 2);
	printNode_recursive(head);

	// cout << "Delete from tail : " << endl;
	// printNode_recursive(head);
	// deleteTail(head);
	// printNode_recursive(head);
	// deleteTail(head);
	// printNode_recursive(head);
	return 0;
}

