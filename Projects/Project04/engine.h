#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>

class Engine {
public:
    Engine(const char* title, int width, int height);
    ~Engine();

    bool isRunning() const;
    SDL_Event pollEvent();
    SDL_Renderer* getRenderer();

    void clear();
    void present();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
};

#endif

