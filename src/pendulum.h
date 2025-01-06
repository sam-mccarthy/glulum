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

struct State {
    double theta_1;
    double theta_2;
    double omega_1;
    double omega_2;
};

class Pendulum {
public:
    Pendulum(int w, int h, Parameters p);
    ~Pendulum();
    std::unique_ptr<unsigned char> step(double delta_t);
private:
    State calculate_step(double t1, double t2, double v1, double v2);

    int _width;
    int _height;

    Parameters _params;

    double* _theta_1;
    double* _d_theta_1;

    double* _theta_2;
    double* _d_theta_2;
};