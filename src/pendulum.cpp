#include "pendulum.h"

Pendulum::Pendulum(int w, int h, Parameters p){
    _width = w;
    _height = h;

    _params = p;

    _theta_1 = new double[_width * _height];
    _theta_2 = new double[_width * _height];

    _d_theta_1 = new double[_width * _height];
    _d_theta_2 = new double[_width * _height];

    _dd_theta_1 = new double[_width * _height];
    _dd_theta_2 = new double[_width * _height];
}

Pendulum::~Pendulum(){
    delete _theta_1;
    delete _theta_2;

    delete _d_theta_1;
    delete _d_theta_2;

    delete _dd_theta_1;
    delete _dd_theta_2;
}

std::pair<double, double> Pendulum::calculate_dd(double t1, double t2, double v1, double v2){
    double g = _params.gravity;
    double m1 = _params.mass_1;
    double m2 = _params.mass_2;
    double l1 = _params.length_1;
    double l2 = _params.length_2;

    //double w1 = -g * (2 * m1 + m2) - m2 * g * sin(t1 - 2 * t2) - 2 * sin(t1 - t2) * m2 * ();
}

std::pair<double, double> Pendulum::calculate_d(double t1, double t2, double v1, double v2){
    double h = _params.step_size;
    
}

std::unique_ptr<unsigned char> Pendulum::step(double delta_t){
    for(int x = 0; x < _width; x++){
        for(int y = 0; y < _height; y++){
            _dd_theta_1[x + y * _width] = 
        }
    }
}