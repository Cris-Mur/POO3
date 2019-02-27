#include <iostream>

#include "Funciones.h"

#include "Classes.h"

int main(int argc, char const *argv[]) {
  int op;
  Structure lista;
  while (op != 8) {
    menuPrincipal();
    std::cin >> op;
    switch (op) {
      case 1:
      lista.create();
      std::cout << "Lista creada con existo :)" << '\n'
                << lista.create();
                break;
      case 2:
      if (lista.cleanTest()) {
        std::cout << "la lista existe y esta vacia" << '\n'
                  << lista.cleanTest();
                }else {
                  std::cout << "la lista no encuentra o no está vacia." << '\n'
                  << lista.cleanTest();
                }
                break;
      case 3:
        if (lista.cleanTest()) {
          std::cout << "la lista esta vacia, no hay nada que ver..." << '\n';
        }else if (lista.size >= 0) {
        lista.view();
        std::cout << "ingrese la posicion que desea ver." << '\n'
                  << "posicion: ";
                  std::cin >> lista.helper_dir;
        std::cout << "lista [ " << lista.helper_dir << " ]:" << lista.dato << '\n';
      }else{
        std::cout << "algo ha salido mal :( " << '\n';
      }
      break;
      case 4:
        std::cout << "ingrese el tamaño de la lista." << '\n'
                  << "Tamaño: ";
                  std::cin >> lista.size;
        break;
        case 5:
        std::cout << "ingrese dato." << '\n'
                  << "Dato: ";
                  std::cin >> lista.dato;
                  lista.add();
        }
              std::cin.get();
    }

  return 0;
}
