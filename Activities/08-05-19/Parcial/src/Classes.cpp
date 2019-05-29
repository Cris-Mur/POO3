#include "Classes.h"
#include <iostream>
int orden = 0;

Node::Node(){
  nxt = NULL;
}

Node::Node(int dat){
  data = dat;
  nxt = NULL;
}

Node::~Node(){}

List::List(){
  control = false;
  empty = false;
  size = -1;
  first = NULL;
}

List::~List(){}

void List::create() {
  control = true;
  empty = true;
  size = 0;
  first = NULL;
}
void List::set_inputData(int d) {
  input_Data = d;
}

bool List::test(){
  if (empty) {
    return true;
  }else{
    return false;
  }
}

void List::addinFirst(int dat) {
  set_inputData(dat);
  Node* tempNode = new Node(input_Data);
  tempNode -> nxt = first;
  first = tempNode;
  empty = false;
  size++;
  return;
}

void List::add(int dato) {
  set_inputData(dato);
  Node* tempNode = new Node(input_Data);
  tempNode -> nxt = first;
  first = tempNode;
  empty = false;
  size++;
  return;
}

Node* List::view() {
  return first;
}

int List::outSize(){
  return size;
}

void List::invertir() {
  Node* aux = first;
  Node* p = first;
  Node* q = first;

  if (orden==0) {
    q=q->nxt->nxt;
    p = p->nxt;
    aux -> nxt = NULL;
    p->nxt = aux;
    aux=p;
    p=q;
    orden = 1;
  }
  if (orden == 1) {
    while (q->nxt != NULL) {
      q = q->nxt;
      while (p->nxt != q) {
        p = p->nxt;
        while(aux->nxt!=p){
          p->nxt = aux;
          aux=p;
          p=q;
        }
      }
    }

    p-> nxt = aux;

    first = p;
  }
}

Menus::Menus(){
  option = 0;
}

Menus::~Menus(){}

int Menus::MENU(){
  Menus();
  std::cout << "############### MENU ###############" << '\n'
            << "# [1]... [ Crear ]................ #" << '\n'
            << "# [2]... [ Insertar ]............. #" << '\n'
            << "# [3]... [ Ver sistema completo ]. #" << '\n'
            << "# [4]... [invertir]........ #" << '\n'
            << "# [5]... [Buscar y Contar]........ #" << '\n'
            << "# [6]... [ Salir ]................ #" << '\n'
            << "####################################" << '\n'
            << "Opcion: ";
            std::cin >> option;
  return option;
}
