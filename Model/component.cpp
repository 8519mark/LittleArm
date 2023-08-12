#include "component.h"

Component2D::Component2D(const double &x, const double &y) {
  this->localFrame[0] = 1;
  this->localFrame[1] = 0;
  this->localFrame[2] = 0;
  this->localFrame[3] = 0;
  this->localFrame[4] = 1;
  this->localFrame[5] = 0;
  this->localFrame[6] = 0;
  this->localFrame[7] = 0;
  this->localFrame[8] = 1;

  this->x = x;
  this->y = y;
};
Component2D::Component2D(Component2D *parent, const double &x, const double &y) {
  double angle = std::atan2(parent->y, parent->x);

  this->localFrame[0] = std::cos(angle);
  this->localFrame[1] = -std::sin(angle);
  this->localFrame[2] = parent->x;
  this->localFrame[3] = std::sin(angle);
  this->localFrame[4] = std::cos(angle);
  this->localFrame[5] = parent->y;
  this->localFrame[6] = parent->localFrame[6];
  this->localFrame[7] = parent->localFrame[7];
  this->localFrame[8] = parent->localFrame[8];

  this->x = x;
  this->y = y;

  parent->link(this);
}
void Component2D::transform(const double &dx, const double &dy, const double &dangle) {
  double transformMatrix[9] = {
    std::cos(dangle), -std::sin(dangle), dx,
    std::sin(dangle),  std::cos(dangle), dy,
    0               ,                 0,  1
  };
  double resultVector[3];
  for (int i = 0; i < 3; ++i) {
    resultVector[i] = 0.0;
    resultVector[i] += 
    transformMatrix[3 * i + 0] * this->x + 
    transformMatrix[3 * i + 1] * this->y + 
    transformMatrix[3 * i + 2] * 1;
  }

  // transform the end point
  this->x = resultVector[0];
  this->y = resultVector[1];

  // translate next local frame
  if (this->child == NULL) {
    return;
  }

  double newLocalFrame[9];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      newLocalFrame[i * 3 + j] = 0.0;
      for (int k = 0; k < 3; ++k) {
        newLocalFrame[i * 3 + j] += transformMatrix[i * 3 + k] * this->child->localFrame[k * 3 + j];
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    this->child->localFrame[i] = newLocalFrame[i];
  }
};

const double Component2D::getX() const {
  return this->x;
};

const double Component2D::getY() const {
  return this->y;
};

const double *Component2D::getLocalFramer() const {
  return this->localFrame;
};

const Component2D *Component2D::getChild() const {
  return this->child;
}

void Component2D::link(Component2D *child) {
  this->child = child;
};



void Component2D::getGlobalCoordinatesHelper(const Component2D *component, const double *accumulatedFrame, std::vector<std::vector<double>> &returnVector) const {
  double localX = component->getX();
  double localY = component->getY();
  double localVector[3] = {localX, localY, 1};
  // Transform local coordinates to global coordinates using the accumulated transformation frame
  double globalVector[3];
  for (int i = 0; i < 3; ++i) {
    globalVector[i] = 0.0;
    globalVector[i] += 
    accumulatedFrame[3 * i + 0] * localVector[0] + 
    accumulatedFrame[3 * i + 1] * localVector[1] + 
    accumulatedFrame[3 * i + 2] * localVector[2];
  }
  returnVector.push_back({globalVector[0], globalVector[1]});

  if (component->getChild() != NULL) {
    double childAccumulatedFrame[9];
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        childAccumulatedFrame[i * 3 + j] = 0.0;
        for (int k = 0; k < 3; ++k) {
          childAccumulatedFrame[i * 3 + j] += accumulatedFrame[i * 3 + k] * component->getChild()->getLocalFramer()[k * 3 + j];
        }
      }
    }
    getGlobalCoordinatesHelper(component->getChild(), childAccumulatedFrame, returnVector);
  }
}

std::vector<std::vector<double>> Component2D::getGlobalCoordinates() const {
  std::vector<std::vector<double>> returnVector;
  const double initialFrame[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  getGlobalCoordinatesHelper(this, initialFrame, returnVector);
  return returnVector;
}