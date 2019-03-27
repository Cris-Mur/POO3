#include "pch.h"
#include "Classes.h"

Node::Node(){
  nxt = NULL;
}

Node::Node(int dato){
  data = dato;
  nxt = NULL;
}

Node::~Node(){}

List::List(){
  first = NULL;
  control = false;
  empty = false;
  size = -1;
}

List::~List(){/* instrucciones para la liberacion de nodos */}

void List::create() {
  first = NULL;
  control = true;
  empty = true;
  size = 0;
}

bool List::test(){
  if (control) {
    return true;
  }else{
    return false;
  }
}

void List::set_inputData(int dat) {
	inputData = dat;
}

void List::addinFirst(int dat) {
  set_inputData(dat);
  Node* tempNode = new Node(inputData);
  tempNode -> nxt = first;
  first = tempNode;
  empty = false;
  size++;
}

void List::addinTail(int dat) {
  Node* headNode = first;
  set_inputData(dat);
  Node* tempNode = new Node(inputData);
  while (headNode->nxt != NULL) {
    headNode = headNode->nxt;
  }
  headNode->nxt = tempNode;
  size++;
}

int List::viewFirst(){
  Node* headNode = first;
  return first->data;
}

void List::view(){
  Node* headNode = first;
  while (headNode != NULL){
	  get_outputData(headNode->data);
	  headNode = headNode->nxt;
  }
}

void List::eliminateFirst() {
  Node* headNode = first;
  first = first->nxt;
  delete headNode;
  size--;
}

void List::destroyList() {
  while (size != 0) {
    eliminateFirst();
  }
  control = false;
  delete first;
}

Menus::Menus(){
  option = 0;
}

Menus::~Menus(){}

int Menus::m_General(){
  Menus();
  std::cout << "########## MENU ##########" << '\n'
            << "# 1. Lista. ##############" << '\n'
            << "# 2. Salir. ##############" << '\n'
            << "##########################" << '\n'
            << "Opcion: ";
            std::cin >> option;
  return option;
}

int Menus::m_Lista(){
  Menus();
  std::cout << "############ MENU ############" << '\n'
            << "# 1. Crear listas vacias. ####" << '\n'
            << "# 2. Probar cabeza. ##########" << '\n'
            << "# 3. Insertar al comienzo. ###" << '\n'
            << "# 4. Insertar al final. ######" << '\n'
            << "# 5. Ver lista completa. #####" << '\n'
            << "# 6. Eliminar primero. #######" << '\n'
            << "# 7. Destruir lista. #########" << '\n'
            << "# 8. Salir. ##################" << '\n'
            << "##############################" << '\n'
            << "Opcion: ";
            std::cin >> option;
  return option;
}
