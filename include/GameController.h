#pragma once
#include <cstdio>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Window.h"
#include "MainMenu.h"
#include "Stage.h"

//#include "StageConstruction.h"

class GameController {
public:
    GameController();
    void Run();

private:
    std::vector<std::unique_ptr<Window>> m_screens;
    enum ScreenType_t m_currentScreen;
};
