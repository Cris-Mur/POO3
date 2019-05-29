#include "Classes.h"

Node::Node() {
	nxt = NULL;
}

Node::Node(int dato) {
	data = dato;
	nxt = NULL;
}

Node::~Node() {}

List::List() {
	first = NULL;
	control = false;
	empty = false;
	size = -1;
	organized = false;
}

List::~List() {}

void List::create() {
	first = NULL;
	control = true;
	empty = true;
	size = 0;
	organized = false;
}

bool List::test() {
	if ( ( !empty && size>=0 ) ||
	 		 ( organized&& size>=0 ) ||
		   (empty && size == 0) ) {
		return true;
	}
	else {
		return false;
	}
}

int List::get_size() {
	return size;
}

void List::set_inputData(int dat) {
	inputData = dat;
}

void List::addinFirst (int dat) {
	if (test()) {
		set_inputData(dat);
		Node* tempNode = new Node(inputData);
		tempNode->nxt = first;
		first = tempNode;
		empty = false;
		size++;
	}else{return;}
	return;
}

void List::addinMiddle(int dat, int srch) {
	if (test()) {
		Node* headNode = first;
		set_inputData(dat);
		Node* tempNode = new Node(inputData);
		while (headNode->data != srch) {
			headNode = headNode->nxt;
		}
		tempNode->nxt = headNode->nxt;
		headNode->nxt = tempNode;
		size++;
	}else{return;}
	return;
}

void List::addinTail(int dat) {
	if (test()) {
		Node* headNode = first;
		set_inputData(dat);
		Node* tempNode = new Node(inputData);
		if (headNode == NULL) {
			addinFirst(dat);
		}else {
			while (headNode->nxt != NULL) {
				headNode = headNode->nxt;
			}
			headNode->nxt = tempNode;
			size++;
		}
	}
}

int List::viewFirst() {
	return first->data;
}

Node* List::outList() {
	return first;
}

void List::readList() {
	create();
	int syncSize = 0, syncDATA = 0;
	char sprtr = 58; // " : "
	std::string word = "[DATA]";
	std::ifstream gList ("LIST.txt",std::ios::in);
	if ( gList.is_open() ) {
		std::string line;
		while (std::getline(gList, line, sprtr)) {
			std::cout << "[DATA]::";
			syncDATA = std::stoi(line);
			std::cout << syncDATA;
			addinTail(syncDATA);
			syncSize++;
			std::cout << "[Size Update]: " << syncSize << '\n';
		}
		gList.close();
	}
	else {
		std::cerr << "Unable to open file\n";
	}
}

void List::eliminateFirst() {
	Node* headNode = first;
	if (first == NULL) {
		control = false;
		if (!test()) {
			empty = true;
		}
	}
	else {
		first = first->nxt;
		delete headNode;
		size--;
		if (first == NULL) {
			empty = true;
		}
	}
}

void List::eliminateinMiddle(int srch) {
	Node* headNode = first;
	if (first == NULL) {
		control = false;
		if (!test()) { empty = true; }
	}
	else {
		while (headNode->nxt->data != srch) {
			headNode = headNode->nxt;
		}
		Node* tempNode = headNode->nxt;
		headNode->nxt = headNode->nxt->nxt;
		delete tempNode;
		size--;
	}
}

void List::eliminateTail() {
	Node* tail = first;
	if (first != NULL) {
		if (test()) {

			while (tail->nxt == NULL) {
				tail = tail->nxt;
			}
			delete tail;
			size--;

		}else{empty = true;}
	}else {control = false;}

}

void List::destroyList() {
	while (size != 0) {
		eliminateFirst();
	}
	control = false;
	delete first;
}

void List::lineal_Organize() {
	if (first != NULL) {
		for (Node* comp = first; comp != NULL; comp = comp->nxt) {
			for (Node* aux = comp->nxt ; aux != NULL; aux = aux->nxt) {
				if (comp->data != aux->data) {
				  if (comp->data > aux->data) {
				    Node* aux2 = new Node(aux->data);
				    eliminateinMiddle(aux->data);
				    addinFirst(aux2->data);
				  	}
					}
			}
		}
	}else{
		control = false;
		organized = false;}
		return;
}

Menus::Menus(){option = -1;}
Menus::~Menus(){}

int Menus::Menu() {
	Menus();
std::cout << "############### MENU ###############" << '\n'
					<< "# [1]... [ Crear cabecera ]....... #" << '\n'
					<< "# [2]... [ Insertar].............. #" << '\n'
					<< "# [3]... [ Ver lista completa ]... #" << '\n'
					<< "# [4]... [ Guardar lista ]........ #" << '\n'
					<< "# [5]... [ Leer lista ]........... #" << '\n'
					<< "# [6]... [ Organizar Lineal ]..... #" << '\n'
					<< "# [7]... [ Buscar Lineal ]........ #" << '\n'
					<< "# [8]... [ Eliminar ]............. #" << '\n'
					<< "# [11].. [ Destruir Lista ]....... #" << '\n'
					<< "# [12].. [ Salir ]................ #" << '\n'
					<< "####################################" << '\n'
					<< "Opcion: ";
					std::cin >> option;
return option;
}

int Menus::MenuIncert() {
	Menus();
std::cout << "############### MENU ###############" << '\n'
					<< "# [1]... [ Incertar ]............. #" << '\n'
					<< "# [2]... [ Insertar al comienzo ]. #" << '\n'
					<< "# [3]... [ Incertar al medio]..... #" << '\n'
					<< "####################################" << '\n'
					<< "Opcion: ";
					std::cin >> option;
return option;
}

int Menus::MenuDelete() {
	Menus();
std::cout << "############### MENU ###############" << '\n'
					<< "# [1]... [ Eliminar ]............. #" << '\n'
					<< "# [2]... [ Eliminar al comienzo ]. #" << '\n'
					<< "# [3]... [ Eliminar al medio]..... #" << '\n'
					<< "####################################" << '\n'
					<< "Opcion: ";
					std::cin >> option;
return option;
}
