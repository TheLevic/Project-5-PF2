/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Linkedlist.h
 * Author: wingning
 *
 * Created on October 29, 2021, 1:35 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdlib>
#include <iostream>
typedef int element_type;
typedef element_type &reference;
typedef const element_type &const_reference;

using namespace std;

class Linkedlist {
public:
    Linkedlist(); //Done
    explicit Linkedlist(unsigned int n); //Done
    virtual ~Linkedlist(); //Done
    void check() const; //Done
    void rcheck() const; //Done
    bool empty() const; //Done
    void clear(); //Done
    reference back();//Done
    const_reference back() const; //Done
    reference front(); //Done
    const_reference front() const; //Done
    //Linkedlist& operator=(const Linkedlist& l); //Need to do
    void pop_back(); //Done
    void pop_front(); //Done
    void push_back ( const element_type& x ); //Done
    void push_front ( const element_type& x ); //Done
    void sort(); //Done
    void insert(unsigned int pos, const element_type& x); //Done
    void erase(unsigned int pos); //Done
    

private:
    struct Node
    {
    element_type elem;  // Data
    Node *next;        // Pointer to the next node in the chain
    Node *prev;        // Pointer to the previous node in the chain, not used for lab 7
    };
    Node *head;
    Node *tail;
    

    

};

#endif /* LINKEDLIST_H */

