#pragma once
#include <iostream>

class Node{
public:
	long int data;
	Node* nxt;
	Node();
	Node(long int);
	~Node();
};

class List{
private:
	Node* first;
public:
	bool control, empty;
	long int inputData;
	long int outputData;
	long int size;
	List();
	~List();
	void set_inputData(long int);
	void create();
	bool test();
	void addinFirst(long int);
	void addinMiddle(long int, long int);
	void addinTail(long int);
	long int viewFirst();
	long int set_outputData(long int);
	long int get_outputData();
	Node* outList();
	void eliminateFirst();
	void destroyList();
	void eliminateinMiddle(long int);


};

class Menus{
public:
	int option;
	Menus();
	~Menus();

	int mainMENU();
	int m_Lista();
	int m_listOperations();
};

#include "Classes.cpp"
