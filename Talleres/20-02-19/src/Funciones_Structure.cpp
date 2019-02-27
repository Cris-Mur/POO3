#include <iostream>
int Structure::create(){
  size = 1;
  dir = 0;
  return dir;
}

bool Structure::cleanTest(){
  if(dir == 0){
    return true;
  }else{
    return false;
  }

}

void Structure::view() {
  Structure::cleanTest();
  std::cout << "Lista: " << *arr << std::endl;
  // if (Structure::cleanTest()) {
  //   control = false;
  // }else{
  //   control = true;
  //   dato = arr[helper_dir];
  // }
}


void Structure::add() {
  std::cout << "test:" <<Structure::cleanTest() << '\n';
  if (Structure::cleanTest()) {
    std::cout << "size: " << size << std::endl;
    std::cout << "dir: " << dir << std::endl;
    std::cout << "arr: " << arr << std::endl;
    size = size +1;
    dir = dir +1;
    arr=new int[dato];
  }


/*
  int helper;
  if (dir < size) {
    control = true;
    if (helper_dir <= dir+1) {
      helper = dir;
      while (helper >= helper_dir) {
        arr[helper] = arr[helper + 1];
        helper = helper - 1;
      }
      arr[helper_dir] = dato;
      dir = dir+1;
    }else {
      control = false;
    }
  }else{
    control = false;
  }
  */
}
