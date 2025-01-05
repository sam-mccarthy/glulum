#pragma once

#include <memory>

class Pendulum {
public:
    Pendulum(int w, int h);
    ~Pendulum();
    std::unique_ptr<unsigned char> step(double delta_t);
    
private:
    int width;
    int height;

    double* theta_1;
    double* d_theta_1;
    double* dd_theta_1;

    double* theta_2;
    double* d_theta_2;
    double* dd_theta_2;
};