#include <iostream>
#include "cEstructura.h"

void menuPrincipal();

int main(int argc, char const *argv[]) {
  C_estructura lista;

  int op, dir,dato;
  menuPrincipal();
  switch (op) {
    case 1:
    lista.Crear_lista();
    break;
    case 2:
    lista.Probar_lista();
    break;
    case 3:
    lista.Ver_lista(dir, dato);
    break;
    case 4:
    lista.Incertar_lista(dir, dato);
    break;
    case 5:
    lista.Eliminar_lista(dir, dato);
    break;
    case 6:
    lista.Destruir_lista(dir, dato);
    break;

  }
  return 0;
}

void menuPrincipal() {
        std::cout << "################ MENU ################" << '\n'
                  << "# 1. Crear lista. ####################" << '\n'
                  << "# 2. probar lista. ###################" << '\n'
                  << "# 3. ver lista. ######################" << '\n'
                  << "# 4. incertar dato. ##################" << '\n'
                  << "# 5. Eliminar dato. ##################" << '\n'
                  << "# 6. Destruir lista. #################" << '\n'
                  << "######################################" << '\n'
                  << "## Opcion: ";
}
