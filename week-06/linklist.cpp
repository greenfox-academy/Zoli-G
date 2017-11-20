#include <iostream>

using namespace std;

class Node {        	//Node object
public:             	//Make these public to be able to access them from Linklist class
	int data;			//Storing data (number)
	Node *next;			//Pointer pointing to the next Node type objects. Only a pointer, so not causing self-reference.
	Node *previous;		//Pointer pointing to the previous Node object.
};

class Linklist {			//List object
private:
	Node tail_node;			//Node type pointer which is pointed by the last item
	Node* tail;				//Node type pointer points to the first item
	Node* head;				//Node type pointer which is pointed by the last item
public:
	Linklist() {
		tail_node.data = 0;			//No of items in list, counter
		tail_node.previous = NULL;	//Const NULL pointer
		tail_node.next = NULL;		//Pointer to next node
		tail = &tail_node;			//Pointer to list tail
		head = &tail_node;			//Pointer to list head
	}
	void AddNode(int data) {		//Create new list item
		Node *n = new Node;			//Make a new empty node object named n.
		n->previous = head;			//Set n's prev. pointer back to the current head
		n->next = NULL;				//Set n's next  pointer to null
		n->data = data;				//Set n's data member to the inputted data
		head->next = n;				//Connect head's next pointer with n
		head = n;					//Let be n the new head
		++(tail->data);				//Increment list number counter in tail
	}
	void getList() {						//Print out linklist
		Node* iterator = tail;				//Start iterator at tail (bottom)
		while (iterator->next != NULL) {	//Loop until null pointer reached (head)
			iterator = iterator->next;		//Set iterator to the next node
			cout << iterator->data << (iterator->next == NULL ? "" : "->");
		}									//Print out data member
		cout << " (" << tail->data << " items)";
	}
	int back() {							//Get newest item
		return head->data;
	}
	int front() {							//Get oldest item
		return tail->next->data;
	}
	void pop_back() {
		if (head == tail)
			return;
		head = head->previous;
		head->next = NULL;
		--(tail->data);
	}
	void pop_front() {
		if (head == tail)
			return;
		tail->next = tail->next->next;
		tail->next->previous = tail;
		--(tail->data);
	}
	int at(unsigned int index) {
		unsigned int counter = 0;
		Node* iterator = tail->next;	//Start iterator at tail (bottom)
		while (counter != index) {		//Loop until null pointer reached (head)
			iterator = iterator->next;	//Set iterator to the next node
			++counter;
		}
		return iterator->data;
	}
};

int main() {

	Linklist l;

	l.AddNode(23);
	l.AddNode(10);
	l.AddNode(5);
	l.AddNode(112);
	l.AddNode(3);
	l.AddNode(2560);
	l.AddNode(9);
	l.AddNode(540);

	l.getList();
	cout << endl;

	cout << "Front item: " << l.front() << endl;
	cout << "Back item: " << l.back() << endl;

	l.pop_front();
	cout << "Popped the front item: "; l.getList(); cout << endl;

	l.pop_back();
	cout << "Popped the back item: "; l.getList(); cout << endl;
	l.pop_back();
	cout << "Popped the back item: "; l.getList(); cout << endl;
	l.pop_back();
	cout << "Popped the back item: "; l.getList(); cout << endl;

	cout << "Item at index 2 is: " << l.at(3);

	return 0;
}
