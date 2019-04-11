#pragma once

class Lista{
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
	void eliminate(int, int);
	void destroy(int, int);
};


class Pila{
public:
	int base, top;
	int size;
	int *pila;
	bool control;

	Pila();
	~Pila();
	void set_sizePila(int);
	int create(int);
	bool cleanTest();
	void add(int,int);
	int view(int, int);
	void eliminate(int, int);
	void destroy(int, int);
};


#include "Funciones_Structure.cpp"
