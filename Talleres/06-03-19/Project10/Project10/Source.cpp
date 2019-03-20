#include <iostream>

#include "Funciones.h"

#include "Classes.h"

void menuGeneral();
void menuLista();
void menuPila();

int main(int argc, char const *argv[]) {
	int op = 0, pm, dato;
	char o;
	while (op != 3) {
		menuGeneral();
		std::cin >> op;
		if (op == 1) {
			op = 0;
			int helper_dir;
			Lista lista;
			while (op != 7) {
				menuLista();
				std::cin >> op;
				switch (op) {
				case 1:
					std::cout << "Ingrese tamaño de la lista." << '\n'
						<< "Tamaño: ";
					std::cin >> pm;
					lista.create(pm);
					std::cout << "lista de tamaño: " << lista.size << '\n'
						<< "Creada satisfactoriamente" << '\n';
					break;
				case 2:
					if (lista.size == -1) {
						std::cout << "la lista no existe." << '\n';
					}
					else {
						if (lista.cleanTest()) {
							std::cout << "Pila creada y vacia." << '\n';
						}
						else {
							std::cout << "la pila no existe o no esta vacia." << '\n';
						}

					}
					break;
				case 3:
					std::cout << "Direccion y dato a ingresar en la lista." << '\n'
						<< "Direccion: ";
					std::cin >> helper_dir;
					std::cout << "Dato: ";
					std::cin >> dato;
					lista.add(helper_dir, dato);
					break;
				case 4:
					std::cout << "Direccion de la lista que desea ver." << '\n'
						<< "Direccion: ";
					std::cin >> helper_dir;
					std::cout << "lista [ " << helper_dir << " ]: "
						<< lista.view(helper_dir, dato) << '\n';
					break;
				case 5:
					std::cout << "ultima posicion ingresada de la lista: "
						<< lista.dir << '\n';
					std::cout << "Direccion a eliminar de la lista." << '\n'
						<< "Direccion: ";
					std::cin >> helper_dir;
					lista.eliminate(helper_dir, dato);
					std::cout << "elemento eliminado." << '\n';
					std::cout << "ACTUALIZADO lista [ " << helper_dir << " ]: "
						<< lista.view(helper_dir, dato) << '\n';
					break;
				case 6:
					std::cout << "ATENCION:" << '\n'
						<< "Va a destruir la lista está seguro?" << '\n'
						<< "Opcion s/n :  ";
					std::cin >> o;
					switch (o) {
					case 115:
						lista.destroy(helper_dir, dato);
						std::cout << "la lista ha sido destruida..." << '\n';
						break;
					case 110:
						break;
					}
					break;

				}
			}

		}
		else if (op == 2) {
			op = 0;
			int helper_top;
			Pila pila;
			while (op != 7) {
				menuPila();
				std::cin >> op;
				switch (op) {
				case 1:
					std::cout << "Ingrese tamaño de la pila." << '\n'
						<< "Tamaño: ";
					std::cin >> pm;
					pila.create(pm);
					std::cout << "Pila de tamaño: " << pila.size << '\n'
						<< "Creada satisfactoriamente" << '\n';
					break;
				case 2:
					if (pila.size == -1) {
						std::cout << "la pila no existe." << '\n';
					}
					else {
						if (pila.cleanTest()) {
							std::cout << "Pila creada y vacia." << '\n';
						}
						else {
							std::cout << "la pila no existe o no esta vacia." << '\n';
						}

					}
					break;
				case 3:
					std::cout << "Direccion y dato a ingresar en la lista." << '\n'
						<< "Direccion: ";
					std::cin >> helper_top;
					std::cout << "Dato: ";
					std::cin >> dato;
					pila.add(helper_top, dato);
					break;
				case 4:
					std::cout << "Direccion de la lista que desea ver." << '\n'
						<< "Direccion: ";
					std::cin >> helper_top;
					std::cout << "lista [ " << helper_top << " ]: "
						<< pila.view(helper_top, dato) << '\n';
					break;
				case 5:
					std::cout << "ultima posicion ingresada de la pila: "
						<< pila.top << '\n';
					std::cout << "Direccion a eliminar de la lista." << '\n'
						<< "Direccion: ";
					std::cin >> helper_top;
					pila.eliminate(helper_top, dato);
					std::cout << "elemento eliminado." << '\n';
					std::cout << "ACTUALIZADO pila [ " << helper_top << " ]: "
						<< pila.view(helper_top, dato) << '\n';
					break;
				case 6:
					std::cout << "ATENCION:" << '\n'
						<< "Va a destruir la pila está seguro?" << '\n'
						<< "Opcion s/n :  ";
					std::cin >> o;
					switch (o) {
					case 115:
						pila.destroy(helper_top, dato);
						std::cout << "la pila ha sido destruida..." << '\n';
						break;
					case 110:
						break;
					}
					break;
				}
			}

		}
	}


	return 0;
}