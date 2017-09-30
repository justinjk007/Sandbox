#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    this_thread::sleep_for(std::chrono::seconds(5));
    SDL_Quit();
    return 0;
}
