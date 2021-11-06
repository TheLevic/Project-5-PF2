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
    element_type size();
    Linkedlist(); //Done
    Linkedlist(const Linkedlist &orig); //Don't know how to implement
    explicit Linkedlist(unsigned int n); //Done
    virtual ~Linkedlist(); //Confused on what's different b/w this and clear
    void check() const; //Done
    void rcheck() const; //Done
    bool empty() const; //Done
    void clear(); //Done
    reference back();//Done
    const_reference back() const; //Done
    reference front(); //Done
    const_reference front() const; //Done
    //Linkedlist& operator=(const Linkedlist& l); //Confused
    void pop_back(); //Done
    void pop_front(); //Done
    void insert(unsigned int pos, const element_type& x);

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

