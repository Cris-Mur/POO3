#include "Classes.h"

Lista::Lista() {
	dir = -1;
		size = -1;
		control = false;
}

Lista::~Lista() {

}

void Lista::set_size(int pm) {
	size = pm;
}

int Lista::create(int pm) {
	set_size(pm);
	arr = new int[size];
	dir = 0;
	return dir;
}

bool Lista::cleanTest() {
	if (dir == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Lista::add(int helper_dir, int dato) {
		int j;
		if (dir < size) {
			control = true;
			if (helper_dir <= dir + 1) {
				j = dir;
				while (j >= helper_dir) {
					arr[j + 1] = arr[j];
					j = j - 1;
				}
				arr[helper_dir] = dato;
				dir = dir + 1;
			}
			else {
				control = false;
			}
		}else {
			control = false;
		}

}

int Lista::view(int helper_dir, int dato) {
	if (Lista::cleanTest()) {
    control = false;
		dato = arr[0];
		return dato;
  }else{
  control = true;
  dato = arr[helper_dir];
	return dato;
  }
}

void Lista::eliminate(int helper_dir, int dato) {
	int cont = helper_dir;
	if (cont <= dir) {

		while (cont <= dir) {
			arr[cont] = arr[cont+1];
			cont++;
		}
		arr[dir]=arr[0];
		control = true;
		dir = dir - 1;

	}else{
		control = false;
		dato = arr[0];
	}
}

void Lista::destroy(int helper_dir, int dato) {
	helper_dir = 1;
	while (dir > 0) {
		eliminate(helper_dir, dato);
	}
	Lista();
	arr = NULL;
}



Pila::Pila(){
	base = -1;
	top = -1;
	control = false;
}

Pila::~Pila() {

}

void Pila::set_sizePila(int pm) {
	size = pm;
}

int Pila::create(int pm) {
	set_sizePila(pm);
	pila = new int[size];
	base = 0;
	top = 0;
	return top;
}

bool Pila::cleanTest() {
	if (base == 0 && top == 0) {
		return true;
	}
	else {
		return false;
	}
}


void Pila::add(int helper_top, int dato) {
	int j;
		if (top < size) {
			control = true;
			if (helper_top <= top +1) {
				j = top;
				while (j >= helper_top) {

					pila[j + 1] = pila[j];
					j = j -1;
				}
				pila[helper_top] = dato;
				top = top + 1;
			}else{
				control = false;
			}
		}else{
			control = false;
		}
}

int Pila::view(int helper_top, int dato) {
	if (cleanTest()) {
		control = false;
		dato = pila[base];
		return dato;
	}else{
		control = true;
		dato = pila[helper_top];
		return dato;
	}
}

void Pila::eliminate(int helper_top, int dato) {
	int cont = helper_top;
		if (cont <= top) {
			while (cont <= top) {
				pila[cont] = pila[cont + 1];
				cont++;
			}
			pila[top] = pila[base];
			control = true;
			top = top - 1;
		}else{
			control = false;
			dato = pila[base];
		}
}

void Pila::destroy(int helper_top, int dato) {
	helper_top = 1;
	while (top > 0) {
		eliminate(helper_top, dato);
	}
	Pila();
	pila = NULL;
}
