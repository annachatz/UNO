#include "graphics.h"
#include "config.h"
#include "Game.h"


using namespace std;


void update(float ms)
{
    Game* mygame = reinterpret_cast<Game*>(graphics::getUserData());
    mygame->update(); // calls update function from game 
}


void draw() // draws basic game features
{
    Game* mygame = reinterpret_cast<Game*>(graphics::getUserData());
    mygame->draw(); // calls draw function from game 
}





int main()
{
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "UNO"); // creates window
    Game mygame;
    graphics::setUserData(&mygame); // transfers object to update and draw functions by reference
    graphics::setDrawFunction(draw); // sets draw() as main draw function
    graphics::setUpdateFunction(update); // sets update() as main update function

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);//
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT); // window costumization
                                                         //
    graphics::playMusic(std::string(ASSET_PATH) + "game.mp3", 0.8, true, 0); // music
    graphics::startMessageLoop(); // starts main game loop
}