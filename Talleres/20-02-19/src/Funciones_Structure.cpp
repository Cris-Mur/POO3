#include "Lista.h"

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
  }else{
  control = true;
  dato = arr[helper_dir];
	return dato;
  }
}



#include "Pila.h"

void Pila::create() {
	top = 0;
	base = 0;
}

bool Pila::test() {
	if (base >= 0) {
		return true;
	}else{
		return false;
	}
}

void Pila::add() {
	if (base == 0 && top == 0) {
		base++;
		top++;
		pila = new int[dato];
		top++;
	}else if (top > base) {
		pila = new int[dato];
		top++;
	}
}
