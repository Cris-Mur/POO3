#pragma once
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
