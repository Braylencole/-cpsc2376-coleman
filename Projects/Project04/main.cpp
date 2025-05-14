#include "engine.h"
#include "game.h"

int main() {
    const int width = 700;
    const int height = 600;

    Engine engine("Connect Four", width, height);
    Game game;

    while (engine.isRunning()) {
        SDL_Event e = engine.pollEvent();

        if (e.type == SDL_MOUSEBUTTONDOWN && game.status() == ONGOING) {
            int x;
            SDL_GetMouseState(&x, nullptr);
            int col = x / 100;
            game.play(col);
        }

        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_r) {
                game.reset();
            }
            else if (e.key.keysym.sym == SDLK_ESCAPE) {
                break;
            }
        }

        engine.clear();
        game.draw(engine.getRenderer());
        engine.present();
    }

    return 0;
}
