#ifndef GAME_HPP
#define GAME_HPP

class Graphics;

class Game
{
private:
    void loop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);
public:
    Game();
    ~Game();
};

#endif
