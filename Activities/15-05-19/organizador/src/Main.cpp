#include <iostream>
#include "Classes.h"
#include <fstream>
Menus menu;
List lista;

void crear();
void incertarFirst();
void incertarMiddle();
void incertarTail();
void ver();
void saveFile();
void readFile();
void organizarLineal();

int main(int argc, char const *argv[]) {
  while (menu.option != 12) {
    switch (menu.Menu()) {
      case 1:
        crear();
      break;

      case 2:
        switch (menu.MenuIncert()) {
          case 2:
            incertarFirst();
          break;
          case 3:
            incertarMiddle();
          break;
          default:
            incertarTail();
        }
      break;

      case 3:
        ver();
      break;

      case 4:
        saveFile();
      break;

      case 5:
        readFile();
      break;

      case 6:
        organizarLineal();
      break;
    }
  }
  return 0;
}

void crear() {

  std::cout << ":: Creando Lista..." << '\n';
  lista.create();
    if (lista.test()) {
      std::cout << "[ATTENTION]:: Lista creada." << '\n';
    }else{
      std::cout << "[ERROR]:: Algo ha salido mal..." << '\n';
    }
  return;

}

void incertarFirst() {
  int dato;
  std::cout << ":: Incertando al comienzo de la lista..." << '\n'
            << "[size of list]:: [ " << lista.get_size() << " ]"
            << ":: Ingrese el dato." << '\n'
            << "::[DATA]:";
            std::cin >> dato;
            lista.addinFirst(dato);
            if (lista.test()) {
              std::cout << "[ATTENTION]:: Dato ingresado." << '\n';
            }else{
              std::cout << "[ERROR]:: Algo ha salido mal." << '\n';
            }
            return;
}

void incertarMiddle() {
  int dato, search;
  std::cout << ":: Incertando en punto de la lista..." << '\n'
            << "[size of list]:: [ " << lista.get_size() << " ]"
            << ":: Ingrese el dato." << '\n'
            << "::[DATA]:";
            std::cin >> dato;
            ver();
            std::cout << ":: Ingrese donde quiere incertar." << '\n'
                      << "::[POINT]:: ";
                      std::cin >> search;
            lista.addinMiddle(dato, search);
            if (lista.test()) {
              std::cout << "[ATTENTION]:: Dato ingresado." << '\n';
            }else{
              std::cout << "[ERROR]:: Algo ha salido mal." << '\n';
            }
            return;
}

void incertarTail() {
  int dato;
  std::cout << ":: Incertando al final de la lista..." << '\n'
            << "[size of list]:: [ " << lista.get_size() << " ]"
            << ":: Ingrese el dato." << '\n'
            << "::[DATA]:";
            std::cin >> dato;
            lista.addinTail(dato);
            if (lista.test()) {
              std::cout << "[ATTENTION]:: Dato ingresado." << '\n';
            }else{
              std::cout << "[ERROR]:: Algo ha salido mal." << '\n';
            }
            return;
}

void ver() {
  if (lista.test()) {
    Node* view = lista.outList();
    int tempSize=0;
    std::cout << "[SIZE]:: " << lista.get_size() << '\n';
    std::cout << "[LIST]::";
    while (view != NULL) {
      while (tempSize != lista.get_size()) {
        std::cout << "[ "<< view->data <<" ]::";
        if (view->nxt != NULL) {
          view=view->nxt;
        }
        tempSize++;
      }
      std::cout << '\n';
      return;
    }
  }else{std::cout << "[ERROR]:: No hay nada que mostrar" << '\n';}
  std::cout << '\n';
  return;
}



void saveFile() {
  Node* backup = lista.outList();
  int tempSize=0;
  char sprtr = 58;
  std::ofstream gList("LIST.txt", std::ios::binary | std::ios::out);
  if (gList.is_open()){
    std::cout << ":: Guardando lista..." << '\n';
        while (backup) {
          while (tempSize != lista.get_size()) {
            std::cout << ":: saved data..." << '\n';
            gList << backup->data;
            if (backup->nxt != NULL) {
              gList << sprtr;
            }
            backup=backup->nxt;
            tempSize++;
            std::cout << "tempSize:: " << tempSize << '\n';
          }
        }
      }else{std::cout << "[ERROR]:: file not openned." << '\n';}
      gList.close();
      std::cout << "::Lista guardada" << '\n';
      return;
}

void readFile() {
  lista.readList();
}

void organizarLineal() {
  std::cout << "[ATTENTION]:: organizando lista..." << '\n';
    for (int i = 0; i < lista.get_size(); i++) {
      lista.lineal_Organize();
    }
}

/*
if (headNode->data != comparator->data) {
  if (headNode->data > comparator->data) {
    Node* aux = new Node(comparator->data);
    eliminateinMiddle(comparator->data);
    addinFirst(aux->data);
  }
}
*/
