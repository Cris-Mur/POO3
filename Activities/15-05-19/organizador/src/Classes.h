#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

class Node {
public:
	int data;
	Node* nxt;
	Node();
	Node(int);
	~Node();
};

class List {
private:
	Node* first;
	bool control, empty, organized;
	int inputData;
	int outputData;
	int size;
public:
	List();
	~List();

	void set_inputData(int);
	void create();
	bool test();
	int get_size();
	void addinFirst(int);
	void addinMiddle(int, int);
	void addinTail(int);
	int viewFirst();
	int set_outputData(int);
	int get_outputData();
	void lineal_Organize();
	void lineal_Search();
	Node* outList();
	void readList();
	void eliminateFirst();
	void eliminateinMiddle(int);
	void eliminateTail();
	void destroyList();
};

class Menus{
public:
	int option;
	Menus();
	~Menus();

	int Menu();
	int MenuIncert();
	int MenuDelete();
};

#include "Classes.cpp"
