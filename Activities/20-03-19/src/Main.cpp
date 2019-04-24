#include <iostream>
#include "Classes.h"

Menus menus;
List *arrList;


int main(int argc, char const *argv[]) {

  long int cantList = 0;
  long int mainDATA = 0;
  int dirList = 0;
  long int search = 0;

  while (menus.mainMENU() != 3) {
    std::cout << "[OPTION]: " << menus.option << '\n';
    switch (menus.option) {
      case 1:
        while (menus.m_Lista() != 11) {
          std::cout << "[OPTION]: " << menus.option << '\n';
          switch (menus.option) {
        case 1:

          std::cout << "[###############]" << '\n'
                    << "[## ATTENTION ##]" << '\n'
                    << "[###############]"
                    << "[CANT LIST TO CREATE]: ";
                    std::cin >> cantList;
                    cantList = cantList+1;
                    arrList = new List[cantList];
                    for (int dirList = 1; dirList < cantList; dirList++) {
                        arrList[dirList].create();
                        std::cout << "[LIST]: " << dirList << '\t'
                                  << "[SUCSSES]" << '\n';
                  }

          break;

        case 2:

          for (dirList = 1; dirList < cantList; dirList++) {
            if (arrList[dirList].test()) {
              std::cout << "[Lista]: " << dirList << '\t';
              std::cout << "[WARNING]: hay una lista creada y esta vacia" << '\n';
            }else{
              std::cout << "[ERROR]: algo a salido mal :( " << '\n';
            }
          }

          break;

        case 3:
        std::cout << "que lista desea modificar." << '\n'
                  << "[List]: ";
                  std::cin >> dirList;
                  if (dirList > cantList || dirList <= 0) {
                    std::cout << "[ERROR]: La direccion ingresada es erronea." << '\n'
                              << "[ATTENTION]: Intente nuevamente." << '\n';
                              break;
                  }else {
                    std::cout << "[ATTENTION]: agregando un nodo en el comienzo de la lista." << '\n'
                              << "[LIST SIZE]: " << arrList[dirList].size << '\n'
                              << "[INPUT DATA]: ";
                              std::cin >> mainDATA;
                    arrList[dirList].addinFirst(mainDATA);
                    std::cout << "[FIRST UPDATED]: " << arrList[dirList].viewFirst() << '\n'
                              << "[SIZE UPDATED]: " << arrList[dirList].size << '\n';
                            }

          break;

        case 4:
          std::cout << "que lista desea modificar." << '\n'
                    << "[LIST]: ";
                    std::cin >> dirList;
                    if (dirList > cantList || dirList <= 0) {
                      std::cout << "[ERROR]: Direccion erronea." << '\n';
                      break;
                    }else{
                        Node* out = arrList[dirList].outList();
                      std::cout << "[ATTENTION]: agregando un nodo en un punto." << '\n'
                                << "[LIST SIZE]: " << arrList[dirList].size << '\n';
                      std::cout << "[ATTENTION]: despues de que dato va a Insertar." << '\n';
                      std::cout << "[# " << dirList << " #]::";
                      if (!arrList[dirList].empty) {
                        for (int info = 0; info < arrList[dirList].size; info++) {
                          std::cout << "[ " << out->data << " ]" ;
                          out = out ->nxt;
                        }
                        std::cout << '\n';

                      }else{
                        std::cout << "[EMPTY]" << '\n';
                      }

                      std::cout << "[SEARCH DATA]: ";
                                std::cin >> search;
                      std::cout << "[INPUT DATA]: ";
                                std::cin >> mainDATA;
                        arrList[dirList].addinMiddle(mainDATA, search);
                    }
          break;


        case 5:
          std::cout << "que lista desea modificar." << '\n'
                    << "[List]: ";
                    std::cin >> dirList;
                    if (dirList > cantList || dirList <= 0) {
                      std::cout << "[ERROR]: La direccion ingresada es erronea." << '\n'
                                << "[ATTENTION]: Intente nuevamente." << '\n';
                                break;
                    }else {
                      std::cout << "[ATTENTION]: agregando un nodo al final de la lista." << '\n'
                                << "[LIST SIZE]: " << arrList[dirList].size << '\n'
                                << "[INPUT DATA]: ";
                                std::cin >> mainDATA;
                                arrList[dirList].addinTail(mainDATA);
                                std::cout << "[SIZE UPDATED]: " << arrList[dirList].size << '\n';
                    }

          break;


        case 6:
        std::cout << "[CREATED LISTS]: " << cantList-1 << '\n';
          for (dirList = 1; dirList < cantList; dirList++) {
            Node* out = arrList[dirList].outList();
            std::cout << "[LIST SIZE]: " << arrList[dirList].size << '\n';
            std::cout << "[# " << dirList << " #]::";
              if (!arrList[dirList].empty) {
                for (int info = 0; info < arrList[dirList].size; info++) {
                  std::cout << "[ " << out->data << " ]" ;
                  out = out ->nxt;
                }
                std::cout << '\n';

              }else{
                std::cout << "[EMPTY]" << '\n';
              }

              }
          break;


        case 7:
          std::cout << "Que lista desea modificar" << '\n'
                    << "[LIST]: ";
                    std::cin >> dirList;
          std::cout << "[ATTENTION]: [## DELETE HEAD ##] " << '\n';
          arrList[dirList].eliminateFirst();
          std::cout << "[LIST SIZE]: " << arrList[dirList].size << '\n';

          break;

        case 8:
          std::cout << "Que lista desea modificar." << '\n'
                    << "[LIST]: ";
                    std::cin >> dirList;
                    std::cout << "Que dato desea eliminar." << '\n'
                              << "[SEARCH DATA]: ";
                              std::cin >> mainDATA;
                    arrList[dirList].eliminateinMiddle(mainDATA);

          break;


        case 9:
          std::cout << "[WARNING] Destruir [LIST]:";
                    std::cin >> dirList;
          char op = 0;
          std::cout << "[WARNING ATTENTION]: Usted va a destruir la lista." << '\n'
                    << " SURE?? s/n: ";
                      std::cin >> op;
                        if (op == 115 || op == 83) {
                          arrList[dirList].destroyList();
                        }else{
                          break;
                        }
          break;
        }

        if (menus.option == 10) {


          while (menus.m_listOperations() != 2) {
            std::cout << "[OPTION]: " << menus.option << '\n';
            if (menus.option == 1) {
              std::cout << "[OPTION]: " << menus.option << '\n';
                int dL1 = 0, dL2 = 0;

                std::cout << "[CREATED LISTS]: " << cantList-1 << '\n';
                  for (dirList = 1; dirList < cantList; dirList++) {
                    Node* out = arrList[dirList].outList();
                    std::cout << "[LIST SIZE]: " << arrList[dirList].size << '\n';
                    std::cout << "[# " << dirList << " #]::";
                      if (!arrList[dirList].empty) {
                        for (int info = 0; info < arrList[dirList].size; info++) {
                          std::cout << "[ " << out->data << " ]" ;
                          out = out ->nxt;
                        }
                        std::cout << '\n';

                      }else{
                      std::cout << "[EMPTY]" << '\n';
                      }

                    }

                    std::cout << ":: ¿que listas desea sumar?" << '\n'
                              << "[LIST 1]: ";
                              std::cin >> dL1;
                    std::cout << "[LIST 2]: ";
                              std::cin >> dL2;

                              Node* out1 = arrList[dL1].outList();

                              Node* out2 = arrList[dL2].outList();
                    std::cout << "[# RESULT #]::";
                  while (out1 != NULL || out2 != NULL) {
                    std::cout << "[ " << out1->data + out2->data << " ]";
                    out1 = out1->nxt;
                    out2 = out2->nxt;
                  }
                  std::cout << '\n';
                  delete out1;
                  delete out2;
                }
            }

          }


        }
      break;
      case 2:
      std::cout << "NOW IN CASE 10" << '\n';
        break;

  }

  }
  return 0;
}
