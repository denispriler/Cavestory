#include <Game.hpp>

namespace
{
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
} // namespace

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->loop();
}

Game::~Game()
{
}

void Game::loop()
{
    Graphics graphics;
    Input input;
    SDL_Event event;

    // TODO: Add globals and use it.

    this->_player = Sprite(graphics, "data/MyChar.pbm", 0, 0, 16, 16, 100.0f, 100.0f);

    int LAST_UPDATE_TIME_MS = SDL_GetTicks();
    // Start the loop
    while (true)
    {
        input.frame();

        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                if (!event.key.repeat)
                {
                    input.keyDownEvent(event);
                }
                break;

            case SDL_KEYUP:
                input.keyUpEvent(event);
                break;

            case SDL_QUIT:
                return;
                break;

            default:
                break;
            }
        }

        if (input.isKeyPressed(SDL_SCANCODE_ESCAPE))
        {
            return;
        }

        const int CURRENT_TIME_MS = SDL_GetTicks();
        const int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME_MS;

        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));

        LAST_UPDATE_TIME_MS = CURRENT_TIME_MS;

        this->draw(graphics);
    }
}

void Game::draw(Graphics &graphics)
{
    graphics.clear();

    this->_player.draw(graphics, 100, 100);

    graphics.flip();
}

void Game::update(float elapsedTime)
{
    //SDL_Log("Update. %f\n", elapsedTime);
}
