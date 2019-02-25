#include "cEstructura.h"

void C_estructura::Crear_lista(){
  N = 0;
}
bool C_estructura::Probar_lista(){

  if(N==0){
      return true;
    }else {
        return false;
      }

}
void C_estructura::Ver_lista(int k, int dato){
  if (Probar_lista()) {
    I=false;
  }else{
    I=true;
    dato = arr[k];
  }
}
void C_estructura::Incertar_lista(int k, int dato){
  int j;
  if (N < M) {
    I = true;
    if (k <= N+1) {
      j = N;
      while (j >= k) {
        arr[j+1] = arr[j];
        j = j-1;
      }
      arr[k]= dato;
      N = N+1;
    }else{
      I=false;
    }
  }else{
    I=false;
  }
}
void C_estructura::Eliminar_lista(int k, int dato){
  int cont = k;
  if (k < N) {
    dato = arr[k];
    while (cont < N) {
      arr[cont]=arr[cont+1];
    }
    I=true;
    N = N-1;
  }else{
    I=false;
  }
}
void C_estructura::Destruir_lista(int k, int dato){
  while (N > 0) {
    Eliminar_lista(k, dato);
  }
  N = -1;
}
