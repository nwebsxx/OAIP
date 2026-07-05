#pragma once
#include <iostream>
using namespace std;

struct Heap {
	int data;       
	Heap* left;
	Heap* right;
	Heap* parent;
};

Heap* create(int value);
void add(Heap*& root, int value);
int del(Heap*& root);    
void print(Heap* root);
bool find(Heap* root, int value);
int deletemin(Heap*& root);
void deleteindex(Heap*& root, int i);
void unionheap(Heap*& heap1, Heap*& heap2);


Heap* findplace(Heap* root);
void situp(Heap* ptr);        
void sitdown(Heap* ptr);
Heap* findlast(Heap* root);
Heap* findmin(Heap* root);
Heap* findindex(Heap* root, int& index, int current);
void copy(Heap*& to, Heap* from);
void clear(Heap*& root);


