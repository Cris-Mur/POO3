/*
Universidad Militar Nueva Granada
Nombres:
 Javier Pinzon Fonseca
 Cristian Murcia Torres

 Parcial Corte 2
*/
#include <iostream>
#include "Classes.h"
int main(int argc, char const *argv[]) {
  Menus menu;
  List lista;
  int dato = 0;
  while (menu.option != 6) {
    switch (menu.MENU()) {
      case 1:
        lista.create();
        std::cout << ":: Su lista se ha creado." << '\n';
        break;
      case 2:
        std::cout << "[ATTENTION]: Ingresando DATA" << '\n'
                  << ":: [DATA]: ";
                  std::cin >> dato;
                  lista.add(dato);
        break;
      case 3:

			Node* Lout = lista.view();
          for (int i = 0; i < lista.outSize() ; i++) {
            std::cout << "[ " << Lout->data << " ]-";
            Lout = Lout ->nxt;
          }std::cout << '\n';
          lista.invertir();

        break;
		
	  case 4:
		  Node* co = lista.view();
	  break;
		

    }
  }
  return 0;
}
