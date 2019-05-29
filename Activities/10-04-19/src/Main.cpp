
#include <iostream>
#include "Classes.h"

Header headers;
SINGLELink singleLink;
DoubleLink doubleLink;
//triNode headerLink;
triNode* outHEAD;
Menus menu;
int main(int argc, char const *argv[]) {
  char namaero, search, opchar;
  int data, TyNode = 0;

  while ( menu.MENU() != 2) {
    std::cout << "[OPTION]: " << menu.option << '\n';
    if (menu.option > 3 || menu.option < 1) {
      return 0;
    }
    while (menu.MENU01() != 11) {
      std::cout << "[OPTION]: " << menu.option << '\n';
      switch (menu.option) {
        case 1:
          headers.create();
          std::cout << "[##################################]" << '\n'
                    << "[############ ATTENTION ###########]" << '\n'
                    << "[##### YOU HAS CREATED A LIST #####]" << '\n'
                    << "[##################################]" << '\n';
          break;
        case 2:
          std::cout << ":: ¿Que lista desea modificar?" << '\n'
                    << "[HEAD]: ";
          std::cin >> search;
          std::cout << ":: ¿Tipo de nodo a usar?" << '\n'
                    << "[1]... Nodo Simple. " << '\n'
                    << "[2]... Nodo Doble. " << '\n'
                    //<< "[3]... Nodo Cabecera. " << '\n'
                    << "[4]... NIGUNO. " << '\n'
                    << "[]..";
          std::cin >> TyNode;
          if (TyNode == 1) {
            singleLink.create();
          }else if (TyNode == 2) {
            doubleLink.create();
          }else if (TyNode == 3) {
            //triNode.create();
          }else if (TyNode == 4) {
            //break;
          }
            while (menu.MENU03()!= 9) {
                switch (menu.option) {
                  case 1:
                    if (TyNode == 1) {
                        std::cout << "[ATTENTION]" << '\n'
                                  << ":: Ingresando dato al inicio." << '\n'
                                  << "[DATA]: ";
                                  std::cin >> data;
                                  singleLink.addinFirst(data);

                      }else if (TyNode == 2) {
                        std::cout << "[ATTENTION]" << '\n'
                                  << ":: Ingresando dato al inicio." << '\n'
                                  << "[DATA]: ";
                                  std::cin >> data;
                        doubleLink.addinFirst(data);
                      }else if (TyNode == 3) {
                        /*std::cout << "[ATTENTION]" << '\n'
                                  << ":: Ingresando dato al inicio." << '\n'
                                  << "[DATA]: ";
                                  std::cin >> data;
                        triNode.create();*/
                      }

                    break;
                    case 2:
                    int schr;
                        if (TyNode == 1) {
                            std::cout << "[ATTENTION]" << '\n'
                                      << ":: Ingresando dato en un punto." << '\n'
                                      << "[DATA]: ";
                                      std::cin >> data;
                            std::cout << "[ATTENTION]" << '\n'
                                      << ":: ¿despues de cual dato?" << '\n'
                                      << "[SEARCH DATA]: ";
                                      std::cin >> schr;
                            singleLink.addinMiddle(data, schr);
                          }else if (TyNode == 2) {
                            std::cout << "[ATTENTION]" << '\n'
                                      << ":: Ingresando dato al inicio." << '\n'
                                      << "[DATA]: ";
                                      std::cin >> data;
                            std::cout << "[ATTENTION]" << '\n'
                                      << ":: ¿despues de cual dato?"
                                      << "[SEARCH DATA]: ";
                                      std::cin >> schr;
                            doubleLink.addinMiddle(data, schr);
                          }else if (TyNode == 3) {
                            /*std::cout << "[ATTENTION]" << '\n'
                                      << ":: Ingresando dato al inicio." << '\n'
                                      << "[DATA]: ";
                                      std::cin >> data;
                            std::cout << "[ATTENTION]" << '\n'
                                      << ":: ¿despues de cual dato?"
                                      << "[SEARCH DATA]: ";
                                      std::cin >> schr;
                            triNode.create();*/
                          }
                      break;
                      case 3:
                          if (TyNode == 1) {
                            std::cout << "[ATTENTION]" << '\n'
                                      << ":: Ingresando dato al final." << '\n'
                                      << "[DATA]: ";
                                      std::cin >> data;
                                      singleLink.addinTail(data);
                            }else if (TyNode == 2) {
                                      std::cout << "[ATTENTION]" << '\n'
                                                << ":: Ingresando dato al inicio." << '\n'
                                                << "[DATA]: ";
                                                std::cin >> data;
                                      std::cout << "[ATTENTION]" << '\n'
                                                << ":: ¿despues de cual dato?"
                                                << "[SEARCH DATA]: ";
                                                std::cin >> schr;
                                      doubleLink.addinTail(data);
                            }else if (TyNode == 3) {
                                      /*std::cout << "[ATTENTION]" << '\n'
                                                << ":: Ingresando dato al inicio." << '\n'
                                                << "[DATA]: ";
                                                std::cin >> data;
                                      std::cout << "[ATTENTION]" << '\n'
                                                << ":: ¿despues de cual dato?"
                                                << "[SEARCH DATA]: ";
                                                std::cin >> schr;
                                      triNode.create();*/
                                    }
                        break;
                      case 4:
                          if (TyNode == 1) {
                              outHEAD = headers.outStructure();
                              while (outHEAD -> name != search) {
                                outHEAD = outHEAD->nxt;
                              }
                              oneNode* out = singleLink.view();
                              std::cout << "[SIZE]: " << singleLink.size << '\n'
                                        << "[LIST]" << '\n'
                                        << "[ " << outHEAD->name << " ]";
                              for (int fix = 0; fix < singleLink.size; fix++) {
                                std::cout << "[ " << out->data <<" ]";
                                out = out->nxt;
                              }
                              std::cout << '\n';

                              outHEAD->strctONENode = singleLink.view();
                              outHEAD->Listsize = singleLink.size;
                              headers.syncUP(outHEAD);


                            }else if (TyNode == 2) {
                              outHEAD = headers.outStructure();
                              while (outHEAD -> name != search) {
                                outHEAD = outHEAD->nxt;
                              }
                              doubleNode* out = doubleLink.view();
                              std::cout << "[SIZE]: " << doubleLink.size << '\n'
                                        << "[LIST]" << '\n'
                                        << "[ " << outHEAD->name << " ]";
                              for (int fix = 0; fix < doubleLink.size; fix++) {
                                std::cout << "[ " << out->data <<" ]";
                                out = out->nxt;
                              }
                              std::cout << '\n';

                              outHEAD->strctDOUBLNode = doubleLink.view();
                              outHEAD->Listsize = doubleLink.size;
                              headers.syncUP(outHEAD);
                            }else if (TyNode == 3) {
                              //triNode.create();
                            }
                        break;
                }
              }
              /*aqui va el coso*/



          break;
        case 3:
          std::cout << "[ATTENTION]: agregando una cabecera." << '\n'
                    << "[INPUT NAME]: ";
                    std::cin >> namaero;
                    headers.addinFirst(namaero);
          break;
        case 4:
          std::cout << "[ATTENTION]: agregando una cabecera." << '\n'
                    << "[INPUT NAME]: ";
                    std::cin >> namaero;
          std::cout << ":: ¿despues de la lista?" << '\n'
                    << "[HEAD]: ";
                    std::cin >> search;
          headers.addinMiddle(namaero, search);

          break;
        case 5:
          std::cout << "[ATTENTION]: agregando una cabecera." << '\n'
                    << "[INPUT NAME]: ";
                    std::cin >> namaero;
          headers.addinTail(namaero);
          break;
        case 6:
          outHEAD = headers.outStructure();
          for (int headdir = 0; headdir < headers.size; headdir++) {
            if (outHEAD->) {
              /* code */
            }
            std::cout << "[ " << outHEAD->name  << " ]::";
            for (int i = 0; i < outHEAD->Listsize; i++) {
              if (out = NULL) {
                std::cout << "["<< dout->data <<"]";
              }else{
                std::cout << "["<< out->data <<"]";
              }
              out = out->nxt;
            }
            std::cout << '\n';
            outHEAD = outHEAD->nxt;
          }
          break;
        case 7:
          std::cout << "[WARNING]: eliminando cabecera." << '\n'
                    << "[SURE?] s/n : ";
                    std::cin >> opchar;
                    if (opchar == 115 || opchar == 83) {
                      if (headers.size < 1) {
                        std::cout << ":: No hay nada que eliminar ('_') " << '\n';
                      }else{
                        headers.eliminateFirst();
                      }
                    }
          break;
        case 8:
          std::cout << "[WARNING]: eliminando cabecera." << '\n'
                    << "[SURE?] s/n : ";
                    std::cin >> opchar;
                    if (opchar == 115 || opchar == 83) {
                      if (headers.size < 1) {
                        std::cout << ":: No hay nada que eliminar ('_') " << '\n';
                      }else{
                        std::cout << ":: ¿Cual cabeza desea eliminar? " << '\n'
                                  << "[HEAD]: ";
                                  std::cin >> search;
                        headers.eliminateinMiddle(search);
                      }
                    }
          break;
        case 9:
          std::cout << "[WARNING]: eliminando cabacera." << '\n'
                    << "[SURE?] s/n : ";
                    std::cin >> opchar;
                    if (opchar == 115 || opchar == 83) {
                      if (headers.size < 1) {
                        std::cout << ":: No hay nada que eliminar ('_') " << '\n';
                      }else{
                        std::cout << "[ATTENTION]: eliminando ultima cabeza." << '\n';
                        headers.eliminateTail();
                      }
                    }
          break;
        case 10:
          std::cout << "[WARNING]: eliminando lista." << '\n'
                    << "[SURE?] s/n : ";
                    std::cin >> opchar;
                    if (opchar == 115 || opchar == 83) {
                      while (menu.MENU02() != 3) {
                        std::cout << "[OPTION]: " << menu.option << '\n';
                          headers.destroyList(menu.option);
                      }
                    }
            break;

      }
    }
  }

  std::cin.get();
  std::cin.get();

  return 0;
}
