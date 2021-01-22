#pragma once
#include <cstdio>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Screen.h"
#include "MainMenu.h"
#include "Stage.h"


class GameController {
public:
    //--------------------Constructor/Destructor Section--------------------
    GameController();
    void Run();

private:
    std::vector<std::unique_ptr<Screen>> m_screens;
    enum ScreenType_t m_currentScreen;
};
