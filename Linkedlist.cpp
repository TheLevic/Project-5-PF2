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

Linkedlist::Linkedlist() {//Default
    Node * tmp = new Node;
    head = tail = tmp;
    tmp->next = NULL;
    tmp->prev = NULL;
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

void Linkedlist::rcheck() const{
    Node *current = tail;
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node " << i << "\tElem: " << '\t' << current->elem << "\tAddress: " << current << "\tNext Address: " << current->next << endl;
        current = current->prev;
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

void Linkedlist::insert(unsigned int pos, const element_type& x){
    
    //Need to iterate to the pos with Node *current
    if (head != NULL){
        if (pos > 0){ //Not sure what my condition needs to be here
        Node *Current = head;
        for (int i = 0; i < pos - 1; i++){
            if (Current->next == NULL){
                Node *tmp = new Node();
                tmp->elem = x;
                tmp->prev = tail;
                tmp->next = NULL;
                tail->next = tmp;
                tail = tmp;
                return;
            }
            else{
                Current = Current->next;
                cout << Current->elem << endl;
            }
        }
         //Once at 1 before the pos indicated, we need to set our next = to a tmp variable
        //Set the tmp variables
        Node *tmp = new Node();
        tmp->elem = x;
        tmp->prev = Current;
        cout << Current->prev->elem;
        tmp->next = Current->next;
        //Make sure that tmp is linked
        Current->next = tmp;
        }
        if(pos == 0){
                Node *tmp = new Node(); //Make a new node and set variables
                tmp->next = head;
                tmp->prev = NULL;
                tmp->elem = x;
                head->prev = tmp;
                head = tmp;

        }
    }
    
}

//Erases the node at position pos
void Linkedlist::erase(unsigned int pos){
    //Need to get to one before the position and set a tmp variable = to it.
    if (pos == 0){
        Node *tmp = head;
        Node *current = head;
        current = current->next;
        current->prev = NULL;
        head = current;
        delete tmp;
    }
    if (pos != 0){
        Node *current = head;
        for (int i = 0; i < pos - 1; i++){
                current = current->next;
        }
        Node *tmp = current; //At the Node before the one to be deleted
        current = current->next;//Node to be deleted
        Node *tmp2 = current; //Node to be deleted
        cout << "Supposed to be deleting" << tmp2->elem << endl;
        current = current->next; //Node after
        tmp->next = current;
        current->prev = tmp;
        delete tmp2;
    }
    
}

void Linkedlist::push_back( const element_type& x ){
    Node *tmp = new Node(); //Creating new node
    tmp->elem = x; //Giving it the proper element
    tmp->next = NULL; //Since it is at the back the last will be null
    tmp->prev = tail; //Setting proper tail values
    tail->next = tmp;
    tail = tmp;
}

void Linkedlist::push_front( const element_type& x ){
    Node *tmp = new Node(); //Same as above but opposite
    tmp->elem = x;
    tmp->next = head;
    tmp->prev = NULL;
    head->prev = tmp;
    head = tmp;
}

void Linkedlist::sort(){
    bool sort= true;
    while(sort){

        sort = false; //To stop the loop;
        Node *current = head;
        while (current != NULL){
            if (current->next != NULL){
                if (current->elem > current->next->elem){
                    swap(current->elem,current->next->elem);
                    sort= true;
                }
            }
          current = current->next;
        }
    }
}
