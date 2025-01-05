#include "pendulum.h"

Pendulum::Pendulum(int w, int h){
    _width = w;
    _height = h;

}

Pendulum::~Pendulum(){

}

std::unique_ptr<unsigned char> Pendulum::step(double delta_t){

}