#pragma once

#include <memory>
#include <SDL.h>

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
    void step(SDL_Surface* surface);
private:
    State calculate_step(double t1, double t2, double v1, double v2);

    int _width;
    int _height;

    Parameters _params;

    double* _theta_1;
    double* _omega_1;

    double* _theta_2;
    double* _omega_2;
};