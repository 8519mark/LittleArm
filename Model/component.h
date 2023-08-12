#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <cmath>

class Component2D {
  private:
    double localFrame[9];
    double x;
    double y;
    Component2D *child = NULL;
    void link(Component2D *child);
    void getGlobalCoordinatesHelper(const Component2D *component, const double *accumulatedFrame, std::vector<std::vector<double>> &returnVector) const;
  public:
    Component2D(const double &x, const double &y);
    Component2D(Component2D *parent, const double &x, const double &y);
    void transform(const double &dx, const double &dy, const double &dangle);
    const double getX() const;
    const double getY() const;
    const double *getLocalFramer() const;
    const Component2D *getChild() const;
    std::vector<std::vector<double>> getGlobalCoordinates() const;
};

#endif