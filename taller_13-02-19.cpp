/*  compilar archivo
      g++ taller_13-02-19.cpp -o main
    Ejecutar archivo
    ./main */
#include <iostream>

void menuPrincipal();
void menuCondicionales();
void menuRepetitiva();
void programa1();// Ejercicio 1 punto 1
void programa2();// Ejercicio 2 punto 1
int programa3(int,int);// Ejercicio 3 punto 1
int programa4(int);// Ejercicio 4 punto 1
void programa5();// Ejercicio 5 punto 2
void programa6();// Ejercicio 6 punto 2
void programa7();// Ejercicio 7 punto 2

class Vectorsito {
int sizeObjetc;
public:
void set_sizeObject(int);
void array (){
        int a[sizeObjetc];
        std::cout << "el tamaño del arreglo es: "<< sizeObjetc << '\n';
}
};

void Vectorsito::set_sizeObject(int x) {
        sizeObjetc = x;
}

int main(int argc, char const *argv[]) {
        int opG, opCondicional, opRepetitiva, aux=0,
            result, aux2=0;
        do {
                menuPrincipal();
                std::cin >> opG;
                switch (opG) { //switch principal
                case 1: // Menu Condicional
                        menuCondicionales();
                        std::cin >> opCondicional;
                        switch (opCondicional) { // Switch Condicional
                        case 1:
                                programa1(); // Ejercicio 1 punto 1
                                break;
                        case 2:
                                programa2(); // Ejercicio 2 punto 1
                                break;
                        case 3:
                                std::cout << "digite dos numeros para mostrarle su mcd" << '\n'
                                          << "Numero 1: ";
                                std::cin >> aux;
                                std::cout << "Numero 2: ";
                                std::cin >> aux2;
                                result = programa3(aux, aux2); // Ejercicio 3 punto 1
                                std::cout << "su maximo comun divisor es: " << result << '\n';
                                break;
                        case 4:
                                std::cout << "digite un numero para imprimir su factorial." << '\n'
                                          << "Numero: ";
                                std::cin >> aux;
                                result = programa4(aux); // Ejercicio 4 punto 1
                                std::cout << "su factorial es: " << result << '\n';
                                break;
                        }
                        break;
                case 2:
                        menuRepetitiva(); // Menu Repetitiva
                        std::cin >> opRepetitiva;
                        switch (opRepetitiva) { // switch Repetitiva
                        case 1:
                                programa5(); //Ejercicio 5 punto 2
                                break;
                        case 2:
                                programa6(); //Ejercicio 6 punto 2
                                break;
                        case 3:
                                programa7(); //Ejercicio 7 punto 2
                                break;
                        }
                        break;
                case 3:
                        std::cout << "this is vector" << '\n';
                        Vectorsito arreglo;
                        std::cout << "tamaño del vector: ";
                        std::cin >> aux;
                        arreglo.set_sizeObject(aux);
                        arreglo.array();
                        break;
                case 4:
                        std::cout << "Fin programa" << '\n';
                }
        } while(opG != 4);

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

int programa3(int n1, int n2) {
        int r;
        if (n2 != 0) {
                r = programa3( n2,(n1%2));
                return r;
        }else{
                r = n1;
                return r;
        }
}

int programa4(int n){
        int r;
        if (n < -1) {
                r=0;
                return r;
        }else if (n > -1 && n < 2) {
                r=1;
                return r;
        }else{
                r = n*(programa4((n-1)));
                return r;
        }

}

void programa5() {
        int nInicial, contador;
        std::cout << "Ingrese el numero donde comenzar." << '\n'
                  << "Numero: ";
        std::cin >> nInicial;
        contador = 100 + nInicial;


        for (nInicial; nInicial < contador; nInicial++) {
                std::cout << "3 X " << nInicial << " = " << 3*nInicial << '\n';
        }

}

void programa6() {
        int sizeArray, aux;
        std::cout << "ingrese el tamaño del arreglo." << '\n'
                  << "tamaño: ";
        std::cin >> sizeArray;
        int array[sizeArray];     //hasta aca funciona no me jodas
}

void programa7() {
        int matriz[10][10];
        for (int columnas = 0; columnas < 10; columnas++) {
                for (int filas = 0; filas < 10; filas++) {
                        matriz[columnas][filas]=(columnas+1)+(filas+1);
                        if (matriz[columnas][filas] < 9) {
                                std::cout << "   " << matriz[columnas][filas];
                        }else{
                                std::cout << "  " << matriz[columnas][filas];
                        }
                }
                std::cout << '\n';
        }
}
