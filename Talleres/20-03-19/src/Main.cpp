/* Nodes.cpp : Este archivo contiene la función "main".
La ejecución del programa comienza y termina ahí.
*/

#include "pch.h"
#include <iostream>
#include "Classes.h"

int main(int argc, char const *argv[]) {
  Menus menus;
  int cantList = 0;
  List *arrList;
  int mainDATA = 0;
  while (menus.m_General() != 2) {
    std::cout << "[OPTION]: " << menus.option << '\n';
    while (menus.m_Lista() != 8) {
      std::cout << "[OPTION]: " << menus.option << '\n';
      switch (menus.option) {
        case 1:
          std::cout << "[ATTENTION]: cuantas listas desea crear?" << '\n'
                    << "[CANT LIST]: ";
                    std::cin >> cantList;
                    arrList = new List[cantList];
                    for (int i = 0; i < cantList; i++) {
                      arrList[cantList]->arrList.create()
                    }
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
            for (int i = 0; i < lista.size; i++){
                lista.view();
                std::cout << "[DATA]: " << lista.get_outputData << '\n';
                }
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
