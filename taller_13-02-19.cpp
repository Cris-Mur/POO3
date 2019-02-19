/*  compilar archivo
      g++ taller_13-02-19.cpp -o main
    Ejecutar archivo
    ./main */
#include <iostream>

void menuPrincipal();
void menuCondicionales();
void programa1();
void programa2();
void programa3();

int main(int argc, char const *argv[]) {
  int opG, opCondicional, opRepetitiva;
  do {
    menuPrincipal();
    std::cin >> opG;
    switch (opG) {
      case 1:
        menuCondicionales();
        std::cin >> opCondicional;
        switch (opCondicional) {
          case 1:
          programa1();
          break;
          case 2:
          programa2();
          break;
          case 3:
          programa3();
          break;
        }
        break;
        case 2:
          std::cout << "this is a Repetitiva" << '\n';
          break;
        case 3:
          std::cout << "Fin programa" << '\n';
          break;
        }
    } while(opG != 3);




  return 0;
}

void menuPrincipal() {
  std::cout << "################ MENU ################" << '\n'
            << "# 1. Estructura Condicional. #########" << '\n'
            << "# 2. Estructura Repetitiva. ##########" << '\n'
            << "# 3. vectores con n dimenciones. #####" << '\n'
            << "# 4. Salida. #########################" << '\n'
            << "######################################" << '\n'
            << "## Opcion: ";
}

void menuCondicionales() {
  std::cout << "################# MENU #################" << '\n'
            << "# 1. Dos numeros ¿cual es mayor?. ######" << '\n'
            << "# 2. Tres numeros ¿cual es mayor?. #####" << '\n'
            << "# 3. Maximo comun divisor. #############" << '\n'
            << "# 4. Factorial de un  numero. ##########" << '\n'
            << "########################################" << '\n'
            << "## Opcion: ";
}

void menuRepetitiva() {
  std::cout << "################# MENU #################" << '\n'
            << "# 1. 100 numeros multiplos de 3. #######" << '\n'
            << "# 2. N primeros numeros primos. ########" << '\n'
            << "# 3. Matriz 10X10. #####################" << '\n'
            << "########################################" << '\n'
            << "## Opcion: ";
}

void programa1() {
  float a,b;
	std::cout << "ingrese el valor de a: ";
	std::cin >> a;
	std::cout << "ingrese el valor de b: ";
	std::cin >> b;
	if (a>b) {
		std::cout << "a es mayor.";
		system("pause");//el compilador de windows necesita esta funcion para mostrar en la terminal
	} else if (a==b) {
		std::cout << "a y b son iguales." << '\n';
		system("pause");//el compilador de windows necesita esta funcion para mostrar en la terminal
	} else {
		std::cout << "b es mayor" << '\n';
		system("pause");//el compilador de windows necesita esta funcion para mostrar en la terminal
	}
}

void programa2() {
  float a,b,c;
  std::cout << "ingrese el valor de a: ";
  std::cin >> a;
  std::cout << "ingrese el valor de b: ";
  std::cin >> b;
  std::cout << "ingrese el valor de c: ";
  std::cin >> c;
  if (a == b && b == c) {
    std::cout << "todos son iguales" << '\n';
    system("pause");
  } else if (a>b) {
    if (a>c) {
      std::cout << "a es mayor" << '\n';
      system("pause");
    }else{
      std::cout << "c es mayor" << '\n';
      system("pause");
    }
  } else if (b>c) {
    std::cout << "b es mayor" << '\n';
    system("pause");
  } else {
    std::cout << "c es mayor" << '\n';
    system("pause");
  }
}

void programa3() {
  //int a,b,aux;
  std::cout << "this is a programa 3" << '\n';

}
