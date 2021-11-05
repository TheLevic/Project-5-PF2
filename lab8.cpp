/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Basic linked list
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain
};

// Print details about the given list, one Node per line
void show(Node* head)
{
    Node* current = head;

    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->next;
        i++;
    }
    
    cout << "------------------------------------------------------------------------------------------" << endl;
}

// Print details about the given list in reverse order, one Node per line
void reverseShow(Node* tail)
{
    // TODO Implement in step 1.
    Node* current = tail;

    if (current == NULL){
        cout << "This is an empty list!";
    }

    int i = 0;
    while (current != NULL){
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->prev;
        i++;
    }

cout << "------------------------------------------------------------------------------------------" << endl;
}

int main() 
{
    const int size = 15;

    // Create the first node
    Node* head = new Node();
    head->elem = 0;
    head->prev = NULL;
    head->next = NULL;
    Node* tail = head;

    // Create a doubly linked list from the nodes
    for (int i = 1; i <= size; i++)
    {
        // Create the new node
        Node* node = new Node();
        node->elem = i;
        node->prev = tail;
        node->next = NULL;
        
        // Fold it into the list
        tail->next = node;
        
        // Move the tail
        tail = node;
    }
    show(head);
    reverseShow(tail);

    // TODO: Your code for steps 2-7 here.

    //Step 2
    cout << "Step 2: " << endl;
    Node *tmp = new Node(); 
    tmp->prev = nullptr; 
    tmp->next = head; 
    tmp->elem = 100; 
    head->prev = tmp; 
    head = tmp; 
    show(head);
    reverseShow(tail);

    //Step 3
    cout << "Step 3: " << endl;
    Node *newNode = new Node();
    newNode->elem = -99;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = NULL;
    tail = newNode;
    show(head);
    reverseShow(tail);

    //Step 4
    cout << "Step 4: " << endl;
    Node *firstNode = head;
    head = head->next;
    head->prev = NULL;
    delete firstNode;
    show(head);
    reverseShow(tail);

    //Step 5
    cout << "Step 5: " << endl;
    Node * lastNode = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete lastNode;
    show(head);
    reverseShow(tail);

    //Step 6
    Node *temp = tail;
    for (int i = 0; i < 3; i++){
        temp = temp->prev;
    }


    //Step 7
    cout << "Step 7: " << endl;
    Node *tempNext = temp->next;
    Node *tempPrev = temp->prev;
    delete temp;
    tempPrev->next = tempNext;
    tempNext->prev = tempPrev;
    show(head);
    reverseShow(tail);
        
    // Clean up
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
    
    return 0;
}
