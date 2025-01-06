#include "pendulum.h"

Pendulum::Pendulum(int w, int h, Parameters p){
    _width = w;
    _height = h;

    _params = p;

    _theta_1 = new double[_width * _height];
    _theta_2 = new double[_width * _height];

    _omega_1 = new double[_width * _height];
    _omega_2 = new double[_width * _height];
}

Pendulum::~Pendulum(){
    delete _theta_1;
    delete _theta_2;

    delete _omega_1;
    delete _omega_2;
}

State Pendulum::calculate_step(double t1, double t2, double v1, double v2){
    double g = _params.gravity;
    double m1 = _params.mass_1;
    double m2 = _params.mass_2;
    double l1 = _params.length_1;
    double l2 = _params.length_2;
    double h = _params.step_size;
    
    double omega_1_k1 = v1;
    double omega_2_k1 = v2;
    double denom_k1 = 2 * m1 + m2 - m2 * cos(2 * t1 - 2 * t2);
    double d_omega_1_k1 = (-g * (2 * m1 + m2) * sin(t1) - m2 * g * sin(t1 - 2 * t2) - 2 * sin(t1 - t2) * m2 * (v2 * v2 * l2 + v1 * v1 * l1 * cos(t1 - t2))) / (l1 * denom_k1);
    double d_omega_2_k1 = (2 * sin(t1 - t2) * (omega_1_k1 * omega_1_k1 * l1 * (m1 + m2) + g * (m1 + m2) * cos(t1) + omega_2_k1 * omega_2_k1 * l2 * m2 * cos(t1 - t2))) / (l2 * denom_k1);

    double k2_t1 = t1 + 0.5 * h * omega_1_k1;
    double k2_t2 = t1 + 0.5 * h * omega_2_k1;
    double omega_1_k2 = v1 + 0.5 * h * d_omega_1_k1;
    double omega_2_k2 = v2 + 0.5 * h * d_omega_2_k1;
    double denom_k2 = 2 * m1 + m2 - m2 * cos(2 * t1 - 2 * t2);
    double d_omega_1_k2 = (-g * (2 * m1 + m2) * sin(k2_t1) - m2 * g * sin(k2_t1 - 2 * k2_t2) - 2 * sin(k2_t1 - k2_t2) * m2 * (omega_2_k2 * omega_2_k2 * l2 + omega_1_k2 * omega_1_k2 * l1 * cos(k2_t1 - k2_t2))) / (l1 * denom_k2);
    double d_omega_2_k2 = (2 * sin(k2_t1 - k2_t2) * (omega_1_k2 * omega_1_k2 * l1 * (m1 + m2) + g * (m1 + m2) * cos(k2_t1) + omega_2_k2 * omega_2_k2 * l2 * m2 * cos(k2_t1 - k2_t2))) / (l2 * denom_k2);

    double k3_t1 = t1 + 0.5 * h * omega_1_k2;
    double k3_t2 = t1 + 0.5 * h * omega_2_k2;
    double omega_1_k3 = v1 + 0.5 * h * d_omega_1_k2;
    double omega_2_k3 = v2 + 0.5 * h * d_omega_2_k2;
    double denom_k3 = 2 * m1 + m2 - m2 * cos(2 * k3_t1 - 2 * k3_t2);
    double d_omega_1_k3 = (-g * (2 * m1 + m2) * sin(k3_t1) - m2 * g * sin(k3_t1 - 2 * k3_t2) - 2 * sin(k3_t1 - k3_t2) * m2 * (omega_2_k3 * omega_2_k3 * l2 + omega_1_k3 * omega_1_k3 * l1 * cos(k3_t1 - k3_t2))) / (l1 * denom_k3);
    double d_omega_2_k3 = (2 * sin(k3_t1 - k3_t2) * (omega_1_k1 * omega_1_k1 * l1 * (m1 + m2) + g * (m1 + m2) * cos(k3_t1) + omega_2_k3 * omega_2_k3 * l2 * m2 * cos(k3_t1 - k3_t2))) / (l2 * denom_k3);

    double k4_t1 = t1 + h * omega_1_k3;
    double k4_t2 = t1 + 0.5 * h * omega_2_k3;
    double omega_1_k4 = v1 + 0.5 * h * d_omega_1_k3;
    double omega_2_k4 = v2 + 0.5 * h * d_omega_2_k3;
    double denom_k4 = 2 * m1 + m2 - m2 * cos(2 * k4_t1 - 2 * k4_t2);
    double d_omega_1_k4 = (-g * (2 * m1 + m2) * sin(k4_t1) - m2 * g * sin(k4_t1 - 2 * k4_t2) - 2 * sin(k4_t1 - k4_t2) * m2 * (omega_2_k4 * omega_2_k4 * l2 + omega_1_k4 * omega_1_k4 * l1 * cos(k4_t1 - k4_t2))) / (l1 * denom_k4);
    double d_omega_2_k4 = (2 * sin(k4_t1 - k4_t2) * (omega_1_k1 * omega_1_k1 * l1 * (m1 + m2) + g * (m1 + m2) * cos(k4_t1) + omega_2_k4 * omega_2_k4 * l2 * m2 * cos(k4_t1 - k4_t2))) / (l2 * denom_k4);

    State result = {
        .theta_1 = t1 + (h / 6) * (omega_1_k1 + 2 * omega_1_k2 + 2 * omega_1_k3 + omega_1_k4),
        .theta_2 = t2 + (h / 6) * (omega_2_k1 + 2 * omega_2_k2 + 2 * omega_2_k3 + omega_2_k4),
        .omega_1 = v1 + (h / 6) * (d_omega_1_k1 + 2 * d_omega_1_k2 + 2 * d_omega_1_k3 + d_omega_1_k4),
        .omega_2 = v2 + (h / 6) * (d_omega_2_k1 + 2 * d_omega_2_k2 + 2 * d_omega_2_k3 + d_omega_2_k4)
    };

    return result;
}

void Pendulum::step(SDL_Surface* surface){
    for(int x = 0; x < _width; x++){
        for(int y = 0; y < _height; y++){
            int index = y * _width + x;
            State result = calculate_step(_theta_1[index], _theta_2[index], _omega_1[index], _omega_2[index]);

            _theta_1[index] = result.theta_1;
            _theta_2[index] = result.theta_2;
            _omega_1[index] = result.omega_1;
            _omega_2[index] = result.omega_2;

            unsigned char r = 255 * (_theta_1[index] / M_2_PI + 0.5);
            unsigned char g = 255 * (_theta_2[index] / M_2_PI + 0.5);
            unsigned char b = 255;

            SDL_LockSurface(surface);
            uint32_t* const pixel = (uint32_t*)((uint8_t) surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel);
            pixel[0] = b;
            pixel[1] = g;
            pixel[2] = r;
            pixel[3] = 255;
            SDL_UnlockSurface(surface);
        }
    }
}

