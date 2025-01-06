#pragma once

#include <memory>

struct Parameters {
    double gravity;

    double mass_1;
    double mass_2;

    double length_1;
    double length_2;

    double step_size;
};

class Pendulum {
public:
    Pendulum(int w, int h, Parameters p);
    ~Pendulum();
    std::pair<double, double> calculate_dd(double t1, double t2, double v1, double v2);
    std::pair<double, double> calculate_d(double t1, double t2, double v1, double v2);
    std::unique_ptr<unsigned char> step(double delta_t);
private:
    int _width;
    int _height;

    Parameters _params;

    double* _theta_1;
    double* _d_theta_1;
    double* _dd_theta_1;

    double* _theta_2;
    double* _d_theta_2;
    double* _dd_theta_2;
};