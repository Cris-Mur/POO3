#include "Classes.h"

Node::Node(){
  nxt = NULL;
}

Node::Node(long int dato){
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

List::~List(){}

void List::create() {
  first = NULL;
  control = true;
  empty = true;
  size = 0;
}

bool List::test(){
  if (empty) {
    return true;
  }else{
    return false;
  }
}

void List::set_inputData(long int dat) {
	inputData = dat;
}

void List::addinFirst(long int dat) {
  set_inputData(dat);
  Node* tempNode = new Node(inputData);
  tempNode -> nxt = first;
  first = tempNode;
  empty = false;
  size++;
  return;
}

void List::addinMiddle(long int dat, long int srch){
  Node* headNode = first;
  set_inputData(dat);
  Node* tempNode = new Node(inputData);
  while (headNode->data != srch) {
    headNode = headNode->nxt;
  }
  tempNode->nxt = headNode->nxt;
  headNode->nxt = tempNode;
  size++;
}

void List::addinTail(long int dat) {
  Node* headNode = first;
  set_inputData(dat);
  Node* tempNode = new Node(inputData);
  if (test()) {
    addinFirst(dat);
  }else{
      while (headNode->nxt != NULL) {
        headNode = headNode->nxt;
    }
  }
  headNode->nxt = tempNode;
  size++;
}

long int List::viewFirst(){
  return first->data;
}

Node* List::outList(){
  return first;
}

void List::eliminateFirst() {
  Node* headNode = first;
  if (first == NULL) {
    control = false;
    if (!test()) {
      empty = true;
    }
  }else {
    first = first->nxt;
    delete headNode;
    size--;
    if (first == NULL) {
      empty = true;
    }
  }
}

void List::eliminateinMiddle(long int srch) {
  Node* headNode = first;
  if(first == NULL){
    control = false;
    if (!test()) {empty = true;}
  }else{
    while (headNode->nxt->data != srch) {
      headNode = headNode->nxt;
    }
    Node* tempNode = headNode->nxt;
    headNode->nxt = headNode->nxt->nxt;
    delete tempNode;
    size--;
  }
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

int Menus::mainMENU(){
  Menus();
  std::cout << "########## MENU ##########" << '\n'
            << "# 1. Lista. ##############" << '\n'
            << "# 2. Operaciones. ########" << '\n'
            << "# 3. Salir. ##############" << '\n'
            << "##########################" << '\n'
            << "Opcion: ";
            std::cin >> option;
  return option;
}

int Menus::m_Lista(){
  Menus();
  std::cout << "############ MENU ############" << '\n'
            << "# 1. Crear listas vacias. ####" << '\n'
            << "# 2. Probar cabezas. #########" << '\n'
            << "# 3. Insertar al comienzo. ###" << '\n'
            << "# 4. Insertar al medio. ######" << '\n'
            << "# 5. Insertar al final. ######" << '\n'
            << "# 6. Ver lista completa. #####" << '\n'
            << "# 7. Eliminar primero. #######" << '\n'
            << "# 8. Eliminar en medio. ######" << '\n'
            << "# 9. Destruir lista. #########" << '\n'
            << "# 10. Suma de listas. ########" << '\n'
            << "# 11. Salir. #################" << '\n'
            << "##############################" << '\n'
            << "Opcion: ";
            std::cin >> option;
  return option;
}

int Menus::m_listOperations(){
  Menus();
  std::cout << "########## MENU #########" << '\n'
            << "# 1. Suma de listas. ####" << '\n'
            << "# 2. Salir. #############" << '\n'
            << "#########################" << '\n'
            << "Opcion: ";
            std::cin >> option;
  return option;
}
