#pragma once

#include <memory>

class Pendulum {
public:
    Pendulum(int w, int h);
    ~Pendulum();
    std::unique_ptr<unsigned char> step(double delta_t);
    
private:
    int _width;
    int _height;

    double* _theta_1;
    double* _d_theta_1;
    double* _dd_theta_1;

    double* _theta_2;
    double* _d_theta_2;
    double* _dd_theta_2;
};