/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Created on October 29, 2021, 1:33 PM
 */

#include <cstdlib>
#include "Linkedlist.h"

using namespace std;

/*
 * 
 */
int main() {
    
    Linkedlist a;
    a = Linkedlist(10);
    a.check();
    a.pop_back();
    a.check();
    a.pop_front();
    a.check();
    a.clear();
    if (a.empty() == true){
        cout << "Empty!" << endl << endl;
    }
    a = Linkedlist(20);
    a.check();
    a.insert(2,27);
    a.check();
    a.erase(0);
    a.check();
    a.push_back(10);
    a.check();
    a.push_front(11);
    a.check();

    return 0;
}

