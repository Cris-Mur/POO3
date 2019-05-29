#pragma once
struct Node{
	int data;
	Node* nxt;
	Node();
	Node(int);
	~Node();
};


class List{
Node* first;
bool control, empty;
int input_Data;
int size;
public:
	List();
	~List();
	void create();
	bool test();
	void set_inputData(int);
	void addinFirst(int);
	void add(int);
	Node* view();
	int outSize();
	void invertir();
};

class Menus{
public:
	int option;

	Menus();
	~Menus();

	int MENU();
};
