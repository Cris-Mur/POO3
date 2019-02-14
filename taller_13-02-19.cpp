#include <iostream>
void programa1();
void programa2();
void programa3();
int main(int argc, char const *argv[]) {
  int op;
  do {
  std::cout << "######## MENU ################" << '\n'
            << "# 1. Ejercicio 1. ############" << '\n'
            << "# 2. Ejercicio 2. ############" << '\n'
            << "# 3. no existe. ##############" << '\n'
            << "# 4. Salida. #################" << '\n'
            << "##############################" << '\n'
            << "## Opcion: ";
  std::cin >> op;
  switch (op) {
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
} while(op!=4);

  return 0;
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
  std::cout << "hello world" << '\n';
}
