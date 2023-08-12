#include <iostream>
#include <iomanip>
#include "component.h"

void printMatrix(const double *matrix) {
  std::cout << std::fixed << std::setprecision(4);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << std::setw(8) << matrix[i * 3 + j];
      if (j < 2) {
        std::cout << ", ";
      }
    }
    std::cout << std::endl;
  }
}


void printCoordinates(Component2D *root) {
  std::cout << "Global Coordinates: ";
  std::vector<std::vector<double>> globalCoordinates = root->getGlobalCoordinates();
  
  for (const auto &coords : globalCoordinates) {
    std::cout << " (" << coords[0] << ", " << coords[1] << ")" << " --> ";
  }
  
  std::cout << "End" << std::endl;
}

int main() {
  Component2D *objectO = new Component2D(1, 1);
  Component2D *objectA = new Component2D(objectO, 1.0, 0.0);
  Component2D *objectB = new Component2D(objectA, 1.0, 0.0);

  std::cout << "Initial coordinates:" << std::endl;
  std::cout << "Object O: (" << objectO->getX() << ", " << objectO->getY() << ")" << std::endl;
  std::cout << "Object A: (" << objectA->getX() << ", " << objectA->getY() << ")" << std::endl;
  std::cout << "Object B: (" << objectB->getX() << ", " << objectB->getY() << ")" << std::endl;
  std::cout << "\nLocal frame matrix for object O:" << std::endl;
  printMatrix(objectO->getLocalFramer());
  std::cout << "\nLocal frame matrix for object A:" << std::endl;
  printMatrix(objectA->getLocalFramer());
  std::cout << "\nLocal frame matrix for object B:" << std::endl;
  printMatrix(objectB->getLocalFramer());
  printCoordinates(objectO);
  std::cout << std::endl << std::endl;

  // transform O's link
  objectO->transform(0.0, 0.0, M_PI / 2.0);

  std::cout << "Transform (Rotate O):" << std::endl;
  std::cout << "Object O: (" << objectO->getX() << ", " << objectO->getY() << ")" << std::endl;
  std::cout << "Object A: (" << objectA->getX() << ", " << objectA->getY() << ")" << std::endl;
  std::cout << "Object B: (" << objectB->getX() << ", " << objectB->getY() << ")" << std::endl;
  std::cout << "\nLocal frame matrix for object O:" << std::endl;
  printMatrix(objectO->getLocalFramer());
  std::cout << "\nLocal frame matrix for object A:" << std::endl;
  printMatrix(objectA->getLocalFramer());
  std::cout << "\nLocal frame matrix for object B:" << std::endl;
  printMatrix(objectB->getLocalFramer());
  printCoordinates(objectO);
  std::cout << std::endl << std::endl;

  // transform A's link
  objectA->transform(0.0, 0.0, M_PI);

  std::cout << "Transform (Rotate A):" << std::endl;
  std::cout << "Object O: (" << objectO->getX() << ", " << objectO->getY() << ")" << std::endl;
  std::cout << "Object A: (" << objectA->getX() << ", " << objectA->getY() << ")" << std::endl;
  std::cout << "Object B: (" << objectB->getX() << ", " << objectB->getY() << ")" << std::endl;
  std::cout << "\nLocal frame matrix for object O:" << std::endl;
  printMatrix(objectO->getLocalFramer());
  std::cout << "\nLocal frame matrix for object A:" << std::endl;
  printMatrix(objectA->getLocalFramer());
  std::cout << "\nLocal frame matrix for object B:" << std::endl;
  printMatrix(objectB->getLocalFramer());
  printCoordinates(objectO);
  std::cout << std::endl << std::endl;



  // Clean up memory
  delete objectO;
  delete objectA;

  return 0;
}