#pragma once

struct oneNode{
	int data;
	oneNode* nxt;
	oneNode();
	oneNode(int);
	~oneNode();
};

struct doubleNode{
	int data;
	doubleNode* nxt;
	doubleNode* bck;
	doubleNode();
	doubleNode(int);
	~doubleNode();
};

struct triNode{
	char name;
	int Listsize;
	triNode* nxt;
	triNode* bck;
	triNode* strctNode;
	oneNode* strctONENode;
	doubleNode* strctDOUBLNode;
	int controlNode;
	triNode();
	triNode(/*std::string*/char);
	~triNode();
};

class SINGLELink{
private:
	oneNode* first;
public:
	//oneNode* first;
	bool control, empty;
	int inputData;
	int outputData;
	int size;
	SINGLELink();
	~SINGLELink();
	void set_inputData(int);
	void create();
	bool test();
	void addinFirst(int);
	void addinMiddle(int, int);
	void addinTail(int);
	int viewFirst();
	oneNode* view();
	void eliminateFirst();
	void destroyList();
	void eliminateinMiddle(int);


};

class Header{
private:
	triNode* ntry;
public:
	bool control, empty;
	char inputNAME;
	char outputNAME;
	long int size;

	Header();
	~Header();
	void set_inputNAME(char);
	void create();
	bool testEMPTY();
	void addinFirst(char);
	void addinMiddle(char, char);
	void addinTail(char);
	char viewENTRYname();
	//triNode* viewALL();
	void eliminateFirst();
	void eliminateinMiddle(char);
	void eliminateTail();
	void destroyList(int);
	triNode* outStructure();
	void syncUP(triNode*);


};

class Menus{
public:
	int option;
	Menus();
	~Menus();

	int MENU();
	int MENU01();
	int MENU02();
	int MENU03();
};

//#include "Classes.cpp"
