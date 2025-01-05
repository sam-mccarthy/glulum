#include <iostream>
#include <SDL.h>

int main(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Window* window = SDL_CreateWindow("chip8 emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    if(!window){
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Surface* surface = SDL_GetWindowSurface(window);
    if(!surface){
        std::cout << "Error getting window surface" << SDL_GetError() << std::endl;
        return false;
    }
    
    while(true){
        
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}