#include <iostream>

using namespace std;

// Create a linked list using classes.
// If you are not similar whit linked lists look it up on the internet.
// Feel free to walk through some tutorials, get familiar with your implementation.

struct Node {
    char x;
    Node *next;
};

class LinkedList{
public:
    LinkedList() {
      tail = NULL;              //set tail as NULL
      head->next = tail;        //set head to point to tail (close link)
    }

    void addValue(char val) {
        Node *n = new Node();   //create a new Node
        head->x = val;          //set head value to the added parameter
        n->next = head;         //set the new node to point back to head
        head = n;               //set head to the latest node
    }

    void display() {
      Node *temp = new Node();
      temp = head->next;
      while (temp->next != NULL) {
        cout << temp->x << "->";
        temp = temp->next;
      }
      cout << temp->x;
    }

private:
    Node *head, *tail;
};

int main()
{
    LinkedList l;
    l.addValue('n');
    l.addValue('e');
    l.addValue('w');
    l.addValue('s');
    l.addValue('p');
    l.addValue('z');
    l.display();

    return 0;
}
