#include <iostream>

#include "Funciones.h"

#include "Classes.h"

int main(int argc, char const *argv[]) {
	int op=0, pm, helper_dir, dato;
	Lista lista;
	while (op != 8) {
		menuPrincipal();
		std::cin >> op;
		switch (op) {
		case 1:
		std::cout << "ingrese el tamaño." << '\n'
							<< "tamaño: ";
							std::cin >> pm;
			lista.create(pm);
			std::cout << "Lista creada con exito :)" << '\n';
			break;
		case 2:
			if (lista.cleanTest()) {
				std::cout << "la lista existe y esta vacia" << '\n'
					<< lista.cleanTest();
			}
			else {
				std::cout << "la lista no encuentra o no est� vacia." << '\n'
					<< lista.cleanTest();
			}
			break;
		case 3:
			if (lista.cleanTest()) {

			std::cout << "ingrese dato." << '\n'
			<< "Dato: ";
			std::cin >> dato;
			lista.add(helper_dir, dato);
		}else{
			std::cout << "ingrese dato." << '\n'
			<< "Dato: ";
			std::cin >> dato;
			std::cout << "ingrese la direccion" << '\n'
								<< "direccion";
								std::cin >> helper_dir;
			lista.add(helper_dir, dato);
		}
			break;

		case 4:
			if (lista.cleanTest()) {
				std::cout << "la lista esta vacia, no hay nada que ver..." << '\n';
			}
			else if (lista.size > 0) {
				std::cout << "ingrese la posicion que desea ver." << '\n'
					<< "posicion: ";
				std::cin >> helper_dir;
				std::cout << "lista [ " << helper_dir << " ]:" << lista.view() << '\n';
			}
			else {
				std::cout << "algo ha salido mal :( " << '\n';
			}
			break;

		}
		std::cin.get();
	}

	return 0;
}
