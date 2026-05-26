// Copyright 2022 NNTU-CS
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  std::ofstream fout("data.txt");

    unsigned int seed = time(nullptr);

  for (int n = 10; n <= 500; n += 10) {
    Train t1;
    Train t2;
    Train t3;

    // all off
    for (int i = 0; i < n; i++) {
      t1.addCar(false);
    }

    // all on
    for (int i = 0; i < n; i++) {
      t2.addCar(true);
    }

    // random
    for (int i = 0; i < n; i++) {
      t3.addCar(rand_r(&seed) % 2);   
    }

    t1.getLen();
    t2.getLen();
    t3.getLen();

    fout << n << " "
         << t1.getOpCount() << " "
         << t2.getOpCount() << " "
         << t3.getOpCount() << std::endl;
  }

  fout.close();

  return 0;
}
