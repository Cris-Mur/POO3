#pragma once
#include <iostream>

class Node{
public:
	int data;
	Node* nxt;
	Node();
	Node(int);
	~Node();
};

class List{
private:
	Node* first;
public:
	bool control, empty;
	int inputData;
	int size;
	List();
	~List();
	void set_inputData(int);
	void create();
	bool test();
	void addinFirst(int);
	void addinTail(int);
	int viewFirst();
	void viewList();
	void eliminateFirst();
	void destroyList();
};

class Menus{
public:
	int option;
	Menus();
	~Menus();

	int m_General();
	int m_Lista();
};
