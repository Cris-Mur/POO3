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
    }else{
      if (lista.cleanTest()) {
        std::cout << "Pila creada y vacia." << '\n';
      }else {
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
