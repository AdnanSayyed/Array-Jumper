
#include "header/Main/GameService.h"
#include <filesystem>
#include <iostream>
int main()
{
    using namespace Main;
     std::string temp = std::filesystem::current_path();
    // Your code...
    GameService* game_service = new GameService();
    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

    delete(game_service);
    return 0;
}
