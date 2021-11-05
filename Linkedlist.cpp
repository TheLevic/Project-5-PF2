/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Linkedlist.cpp
 * Author: wingning
 * 
 * Created on October 29, 2021, 1:35 PM
 */

#include "Linkedlist.h"

//My personal methods
int Linkedlist::size(){
    if (head == NULL){
        return 0;
    }
    Node *tmp = head;
    int count = 0;
    for (count = 1; tmp->next != NULL; count++){
        tmp = tmp->next; //Counts the amount of Nodes in the list
        cout << count << endl;
    } 
    return count;
}


//Constructors:

Linkedlist::Linkedlist() {//Default
    Node * tmp = new Node;
    head = tail = tmp;
    tmp->next = NULL;
    tmp->prev = NULL;
}

Linkedlist::Linkedlist(const Linkedlist& orig) { //Copy
}

Linkedlist::~Linkedlist(){
    Node *tmp = head;
    while (tmp != NULL){
        head = head->next;
        delete(tmp);
        tmp = head;
    }
}

Linkedlist::Linkedlist(unsigned int n){ //Create a linked list of size n
    //Making the first node (head).
    head = new Node();
    head->elem = 0;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
    
    //Making the rest of the nodes
    for (int i = 1; i < n; i++)
    {
        //Creating the new node
        Node* node = new Node(); 
        node->elem = i;
        node->prev = tail; //Setting the prev equal to the current tail (which is head in the first iteration)
        node->next = NULL; //Setting the Node.next = NULL
        
        //Setting the current tail.next to the new node
        tail->next = node;
        
        tail = node; //Setting the new node to the new tail
    }
}


Linkedlist::~Linkedlist() { //Destructor

}

void Linkedlist::check() const
{
    Node* current = head;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node " << i << "\tElem: " << '\t' << current->elem << "\tAddress: " << current << "\tNext Address: " << current->next << endl;
        current = current->next;
        i++;
    }
    
    cout << "----------------------------------------------------------------------" << endl;
}

bool Linkedlist::empty() const{
    if (head == NULL){
        return true;
    }
    else{
        return false;
    }
}

void Linkedlist::clear(){
    Node *tmp = head; //Setting tmp = to the head
    //Deleting nodes until we reach tmp.next = NULL
    while (tmp != NULL){
        head = head->next;
        delete(tmp);
        tmp = head;
    }
}

reference Linkedlist::back(){
    return tail->elem;
}

const_reference Linkedlist::back() const{
    return tail->elem;
}

reference Linkedlist::front(){
    return head->elem;
}

const_reference Linkedlist::front() const{
    return head->elem;
}

void Linkedlist::pop_back(){
    if (tail != head){
        Node *tmp = tail;
        tail = tail->prev;
        delete tmp;
        tail->next = NULL;
    }
    
}

void Linkedlist::pop_front(){
    if (head->next != NULL){
        Node *tmp = head->next;
        delete head;
        head = tmp;
        head->prev = NULL;
    }
}








