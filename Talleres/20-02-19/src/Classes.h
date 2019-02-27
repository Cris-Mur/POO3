#pragma once
class Lista
{
public:
	int dir, size;
	int *arr;
	bool control;

	Lista();
	~Lista();
	void set_size(int);
	int create(int);
	bool cleanTest();
	void add(int, int);
	int view(int, int);
	void eliminate();
};


#include "Funciones_Structure.cpp"

class Pila
{
public:
	int base = -1, top = -1;
	int m, dato;
	int *pila;
	void create();
	bool test();
	void add();
};
