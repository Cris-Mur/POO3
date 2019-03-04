#include <iostream>

#include "Funciones.h"

#include "Classes.h"

int main(int argc, char const *argv[]) {
								int op = 0, pm, dato;
								char o;
								while (op != 3) {
									menuGeneral();
									std::cin >> op;
									if (op == 1) {
										#include "lista.h"
									}else if (op == 2) {
										#include "pila.h"
									}
								}
								

								return 0;
}
