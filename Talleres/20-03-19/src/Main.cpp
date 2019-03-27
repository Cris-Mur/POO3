/* Nodes.cpp : Este archivo contiene la función "main".
La ejecución del programa comienza y termina ahí.
*/

#include "pch.h"
#include <iostream>
#include "Classes.h"
#include "Functions.h"

int main(int argc, char const *argv[]) {
  Menus menus;
  List lista;
  int mainDATA = 0;
  while (menus.m_General() != 2) {
    std::cout << "[OPTION]: " << menus.option << '\n';
    while (menus.m_Lista() != 8) {
      std::cout << "[OPTION]: " << menus.option << '\n';
      switch (menus.option) {
        case 1:
          std::cout << "[WARNING]: esta creando una lista vacia." << '\n';
          lista.create();
          std::cout << "[WARNING]: lista creada." << '\n';
          break;

        case 2:
          if (lista.test()) {
            std::cout << "[WARNING]: hay una lista creada y esta vacia" << '\n';
          }else{
            std::cout << "[ERROR]: algo a salido mal :( " << '\n';
          }
          break;
        case 3:
          std::cout << "[ATTENTION]: agregando un nodo en el comienzo de la lista." << '\n'
                    << "[LIST SIZE]: " << lista.size << '\n'
                    << "[INPUT DATA]: ";
                    std::cin >> mainDATA;
                    lista.addinFirst(mainDATA);
                    std::cout << "[FIRST UPDATED]: " << lista.viewFirst() << '\n'
                              << "[SIZE UPDATED]: " << lista.size << '\n';
          break;
        case 4:
          std::cout << "[ATTENTION]: agregando un nodo al final de la lista." << '\n'
                    << "[LIST SIZE]: " << lista.size << '\n'
                    << "[INPUT DATA]: ";
                    std::cin >> mainDATA;
                    lista.addinTail(mainDATA);
                    std::cout << "[SIZE UPDATED]: " << lista.size << '\n';
          break;
        case 5:
          std::cout << "[LIST SIZE]: " << lista.size << '\n';
          lista.viewList();
          break;
        case 6:
          std::cout << "[LIST SIZE]: " << lista.size << '\n';
          lista.eliminateFirst();
          break;
        case 7:
          char op = 0;
          std::cout << "[WARNING ATTENTION]: Usted va a destruir la lista." << '\n'
                    << " SURE?? s/n: ";
                    std::cin >> op;
                    if (op == 115 || op == 83) {
                      lista.destroyList();
                    }else{
                      break;
                    }
          break;

      }
    }

  }
  return 0;
}
