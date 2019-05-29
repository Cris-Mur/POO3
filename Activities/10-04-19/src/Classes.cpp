#include "Classes.h"
#include <iostream>

triNode::triNode(){
  Listsize = 0;
  nxt = NULL;
  bck = NULL;
  strctNode = NULL;
  strctONENode = NULL;
}

triNode::triNode(/*ANY DATA TYPE n*/ char n){
  Listsize = 0;
  name = n;
  nxt = NULL;
  bck = NULL;
  strctNode = NULL;
  strctONENode = NULL;
}

triNode::~triNode(){}

oneNode::oneNode(){
  nxt = NULL;
}

oneNode::oneNode(int dat){
  data = dat;
  nxt = NULL;
}

oneNode::~oneNode(){}

doubleNode::doubleNode(){
  nxt = NULL;
  bck = NULL;
}

doubleNode::doubleNode(int dat){
  nxt = NULL;
  data = dat;
  bck = NULL;
}

doubleNode::~doubleNode(){}

Header::Header(){
  ntry = NULL;
  control = false;
  empty = false;
  size = -1;
}

Header::~Header(){}

void Header::set_inputNAME(char n){
  inputNAME = n;
}

void Header::create() {
  ntry = NULL;
  control = true;
  empty = true;
  size = 0;
}

bool Header::testEMPTY() {
  if (empty) {
    control = true;
    return control;
  }else{
    control = false;
    return control;
  }
}

void Header::addinFirst(char name) {
  set_inputNAME(name);
  triNode* newHeader = new triNode(inputNAME);
  if (testEMPTY()){
      control = true;
	   ntry = newHeader;
     ntry->nxt = ntry;
     ntry->bck = ntry->nxt;
     empty = false;
  }else{
    control = true;

    triNode* tail = ntry -> bck;

    newHeader->nxt = ntry;
    ntry->bck = newHeader;

    tail->nxt = newHeader;
    newHeader->bck = tail;

    ntry = newHeader;
  }
  size++;
}

void Header::addinMiddle(char name, char srch) {
  triNode* header = ntry;
  triNode* headerNXT;
  set_inputNAME(name);
  triNode* tempNode = new triNode(inputNAME);

  if (!testEMPTY()) {

    while (header->name != srch) {
      header = header->nxt;
    }
    headerNXT = header->nxt;

    header->nxt = tempNode;
    tempNode->bck = header;

    tempNode->nxt = headerNXT;
    headerNXT->bck = tempNode;

  }else{
    addinFirst(name);
  }


  size++;
}

void Header::addinTail(char name) {
  set_inputNAME(name);
  triNode* header = ntry;
  triNode* tempNode = new triNode(inputNAME);
  triNode* headerBCK = ntry->bck;

  if (!testEMPTY()) {

    header->bck = tempNode;
    tempNode->nxt = header;

    headerBCK->nxt = tempNode;
    tempNode->bck = headerBCK;

  }else{
    addinFirst(name);
    return;
  }

  size++;
}

char Header::viewENTRYname() {
  return ntry->name;
}

triNode* Header::outStructure() {
  return ntry;
}

void Header::syncUP(triNode* sync) {
  ntry = sync;
}

void Header::eliminateFirst() {
  triNode* freenode = ntry;

  if (freenode != NULL || size > 0) {
    control = true;

    ntry = ntry->nxt;
    ntry->bck = NULL;

    freenode->nxt = NULL;

    delete freenode;

    size--;
  }else{control = false;}

}

void Header::eliminateinMiddle(char srch) {
  triNode* header = ntry;
  triNode* headerBCK;
  if (header != NULL || size > 0) {
    control = true;
    while (header->name != srch) {
      header = header->nxt;
    }
    headerBCK = header->bck;

    triNode* freenode = header;

    headerBCK->nxt = header->nxt;
    header = header->nxt;
    header->bck = headerBCK;

    freenode->nxt = NULL;
    freenode->bck = NULL;

    delete freenode;
    size--;
  }else{control = false;}
}

void Header::eliminateTail() {
  triNode* tail = ntry;
  triNode* freenode;

  if (tail != NULL || size > 0) {
    control = true;
    for (int i = 0; i < size; i++) {
      tail = tail->nxt;
    }
    freenode = tail;

    tail = tail->bck;
    tail->nxt = ntry;

    freenode->nxt = NULL;
    freenode->bck = NULL;

    delete freenode;

    size--;
  }else{
    control = false;
  }

}

void Header::destroyList(int op) {
  if (op == 1) {
    while (ntry != NULL) {
      eliminateFirst();
    }
  }else if (op == 2) {
    while (ntry != NULL) {
      eliminateTail();
    }
  }
}

SINGLELink::SINGLELink(){
  first = NULL;
  control = false;
  empty = false;
  size = -1;
}

SINGLELink::~SINGLELink(){/* instrucciones para la liberacion de nodos */}

void SINGLELink::create() {
  first = NULL;
  control = true;
  empty = true;
  size = 0;
}

bool SINGLELink::test(){
  if (control) {
    return true;
  }else{
    return false;
  }
}

void SINGLELink::set_inputData(int dat) {
	inputData = dat;
}

void SINGLELink::addinFirst(int dat) {
  set_inputData(dat);
  oneNode* tempNode = new oneNode(inputData);
  tempNode -> nxt = first;
  first = tempNode;
  empty = false;
  size++;
}

void SINGLELink::addinMiddle(int dat, int srch){
  oneNode* headNode = first;
  set_inputData(dat);
  oneNode* tempNode = new oneNode(inputData);
  while (headNode->data != srch) {
    headNode = headNode->nxt;
  }
  tempNode->nxt = headNode->nxt;
  headNode->nxt = tempNode;
  size++;
}

void SINGLELink::addinTail(int dat) {
  oneNode* headNode = first;
  set_inputData(dat);
  oneNode* tempNode = new oneNode(inputData);
  if (headNode == NULL) {
    addinFirst(dat);
  }else{
      while (headNode->nxt != NULL) {
        headNode = headNode->nxt;
    }
  }
  headNode->nxt = tempNode;
  size++;
}

int SINGLELink::viewFirst(){
  return first->data;
}

oneNode* SINGLELink::view() {
  return first;
}

void SINGLELink::eliminateFirst() {
  oneNode* headNode = first;
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

void SINGLELink::eliminateinMiddle(int srch) {
  oneNode* headNode = first;
  if(first == NULL){
    control = false;
    if (!test()) {empty = true;}
  }else{
    while (headNode->nxt->data != srch) {
      headNode = headNode->nxt;
    }
    oneNode* tempNode = headNode->nxt;
    headNode->nxt = headNode->nxt->nxt;
    delete tempNode;
    size--;
  }
}

void SINGLELink::destroyList() {
  while (size != 0) {
    eliminateFirst();
  }
  control = false;
  delete first;
}

DoubleLink::DoubleLink(){
  ntry = NULL;
  control = false;
  empty = false;
  size = -1;
}

DoubleLink::~DoubleLink(){}

void DoubleLink::set_inputNAME(int n){
  inputNAME = n;
}

void DoubleLink::create() {
  ntry = NULL;
  control = true;
  empty = true;
  size = 0;
}

bool DoubleLink::testEMPTY() {
  if (empty) {
    control = true;
    return control;
  }else{
    control = false;
    return control;
  }
}

void DoubleLink::addinFirst(int name) {
  set_inputNAME(name);
  doubleNode* newHeader = new doubleNode(inputNAME);
  if (testEMPTY()){
      control = true;
	   ntry = newHeader;
     ntry->nxt = ntry;
     ntry->bck = ntry->nxt;
     empty = false;
  }else{
    control = true;

    doubleNode* tail = ntry -> bck;

    newHeader->nxt = ntry;
    ntry->bck = newHeader;

    tail->nxt = newHeader;
    newHeader->bck = tail;

    ntry = newHeader;
  }
  size++;
}

void DoubleLink::addinMiddle(int name, int srch) {
  doubleNode* header = ntry;
  doubleNode* headerNXT;
  set_inputNAME(name);
  doubleNode* tempNode = new doubleNode(inputNAME);

  if (!testEMPTY()) {

    while (header->data != srch) {
      header = header->nxt;
    }
    headerNXT = header->nxt;

    header->nxt = tempNode;
    tempNode->bck = header;

    tempNode->nxt = headerNXT;
    headerNXT->bck = tempNode;

  }else{
    addinFirst(name);
  }


  size++;
}

void DoubleLink::addinTail(int name) {
  set_inputNAME(name);
  doubleNode* header = ntry;
  doubleNode* tempNode = new doubleNode(inputNAME);
  doubleNode* headerBCK = ntry->bck;

  if (!testEMPTY()) {

    header->bck = tempNode;
    tempNode->nxt = header;

    headerBCK->nxt = tempNode;
    tempNode->bck = headerBCK;

  }else{
    addinFirst(name);
    return;
  }

  size++;
}

int DoubleLink::viewENTRYname() {
  return ntry->data;
}

doubleNode* DoubleLink::view() {
  return ntry;
}

/*void DoubleLink::syncUP(doubleNode* sync) {
  ntry = sync;
}*/

void DoubleLink::eliminateFirst() {
  doubleNode* freenode = ntry;

  if (freenode != NULL || size > 0) {
    control = true;

    ntry = ntry->nxt;
    ntry->bck = NULL;

    freenode->nxt = NULL;

    delete freenode;

    size--;
  }else{control = false;}

}

void DoubleLink::eliminateinMiddle(int srch) {
  doubleNode* header = ntry;
  doubleNode* headerBCK;
  if (header != NULL || size > 0) {
    control = true;
    while (header->data != srch) {
      header = header->nxt;
    }
    headerBCK = header->bck;

    doubleNode* freenode = header;

    headerBCK->nxt = header->nxt;
    header = header->nxt;
    header->bck = headerBCK;

    freenode->nxt = NULL;
    freenode->bck = NULL;

    delete freenode;
    size--;
  }else{control = false;}
}

void DoubleLink::eliminateTail() {
  doubleNode* tail = ntry;
  doubleNode* freenode;

  if (tail != NULL || size > 0) {
    control = true;
    for (int i = 0; i < size; i++) {
      tail = tail->nxt;
    }
    freenode = tail;

    tail = tail->bck;
    tail->nxt = ntry;

    freenode->nxt = NULL;
    freenode->bck = NULL;

    delete freenode;

    size--;
  }else{
    control = false;
  }

}

void DoubleLink::destroyList(int op) {
  if (op == 1) {
    while (ntry != NULL) {
      eliminateFirst();
    }
  }else if (op == 2) {
    while (ntry != NULL) {
      eliminateTail();
    }
  }
}


Menus::Menus(){
  option = 0;
}

Menus::~Menus(){}

int Menus::MENU(){
  Menus();
  std::cout << "########### MENU ##########" << '\n'
            << "# [1]... [ LISTAS ]...... #" << '\n'
            << "# [2]... [ SALIR ]....... #" << '\n'
            << "#########################" << '\n'
            << "Opcion: ";
            std::cin >> option;
  return option;
}

int Menus::MENU01(){
  Menus();
  std::cout << "############### MENU ###############" << '\n'
            << "# [1]... [ Crear cabecera ]....... #" << '\n'
            << "# [2]... [ Gestionar cabezas ].... #" << '\n'
            << "# [3]... [ Insertar al comienzo ]. #" << '\n'
            << "# [4]... [ Insertar al medio ].... #" << '\n'
            << "# [5]... [ Insertar al final ].... #" << '\n'
            << "# [6]... [ Ver sistema completo ]. #" << '\n'
            << "# [7]... [ Eliminar primero ]..... #" << '\n'
            << "# [8]... [ Eliminar en medio ].... #" << '\n'
            << "# [9]... [ Eliminar al final ].... #" << '\n'
            << "# [10].. [ Destruir lista ]....... #" << '\n'
            << "# [11].. [ Salir ]................ #" << '\n'
            << "####################################" << '\n'
            << "Opcion: ";
            std::cin >> option;
  return option;
}

int Menus::MENU02() {
  Menus();
  std::cout << "###### DELETE ########" << '\n'
            << "# [1]... [INICIO]....#" << '\n'
            << "# [2]... [FINAL].....#" << '\n'
            << "# [3]... [SALIR].....#" << '\n'
            << "######################" << '\n'
            << ":: Opcion: ";
            std::cin >> option;
    return option;
}


int Menus::MENU03(){
  Menus();
  std::cout << "############### MENU ###############" << '\n'
            << "# [1]... [ Insertar al comienzo ]. #" << '\n'
            << "# [2]... [ Insertar al medio ].... #" << '\n'
            << "# [3]... [ Insertar al final ].... #" << '\n'
            << "# [4]... [ Ver sistema completo ]. #" << '\n'
            << "# [5]... [ Eliminar primero ]..... #" << '\n'
            << "# [6]... [ Eliminar en medio ].... #" << '\n'
            << "# [7]... [ Eliminar al final ].... #" << '\n'
            << "# [8]... [ Destruir lista ]....... #" << '\n'
            << "# [9]... [ Salir ]................ #" << '\n'
            << "####################################" << '\n'
            << "Opcion: ";
            std::cin >> option;
  return option;
}
