Lode Runner (corona virus version)

General Description:

    This project is an implementation of the game Lode Runner.

    The project displays the game world and lets the user to control the player,
    and will manage collisions between different game objects.

Game Instructions:

    The goal of the player is to save the world from the corona viruses by collecting
    all the vaccines.
    
    In order to control the player, the user can use the arrow keys or the {'W', 'A', 'S', 'D'} keys.
    In order to open a curtain on the left bottom side of the player, the user can use the 'Z' or 'Q' keys,
    and for the right bottom side, the user can use the 'X' or 'E' keys.
    In order to commit suicide for some reason, the user can use the 'K' key.

Design:

    The game world contains several objects:
    Player - collect a vaccine to defeat the viruses.
    Virus - chasing the player to make him sick and kill him.
    Good Gift - the player can collect this gift and get more lives, score or time.
    Bad Gift - the player can collect this gift and add one more viruse to the game.
    Ladder - the player and the viruses can climb up and down on the ladder or fall to the side.
    Rope - the player and the viruses can dangle on the rope right and left or fall down.
    
    The rest of the objects are listed in files list.
    
Levels.txt:
    
    The stages of the game are in the file Levels.txt that in the resources folder.
    In order to add more stage the user can open this file
    and then write the level size (height, width) and the allotted time, then "draw" the level.
    
    Example:
    15 15 30
    ###############
    #   H         #
    #   H   *+    #
    #   H##########
    #   H         #
    #   H         #
    #   H         #
    # + H         #
    ####H----     #
    #   H    -*   #
    #   H     -*  #
    #  @H      -* #
    ####H       - #
    ####H %     * #
    ###############
    
    @ - Player
    % - Virus
    * - Vaccine
    + - Gift
    # - Curtain
    H - Ladder
    - - Rope

Files list:

    Resources folder includes files that the program load for the game - textures, fonts, sounds and musics, the files types are ogg , jpg , jpeg, ttf and png.
    GameController.h , GameController.cpp - A class that control all the game screens.
    Screen.h , Screen.cpp - An abstract class that represents a screen in the game.
    Stage.h , Stage.cpp - A class that represents the stage screen of the game.
    MainMenu.h , MainMenu.cpp - A class that represents the main menu screen of the game.
    MenuButton.h , MenuButton.cpp - A class that represents a button in the main menu.
    GameObject.h , GameObject.cpp - An abstract class that represents an object in the game.
    MovingObject.h , MovingObject.cpp - An abstract class that represents a moving object in the game.
    StaticObject.h , StaticObject.cpp - An abstract class that represents a static object in the game.
    Player.h , Player.cpp - A class that represents the player.
    Virus.h , Virus.cpp - An abstract class that represents virus.
    StupidVirus.h , StupidVirus.cpp - A class that represents stupid virus.
    RandVirus.h , RandVirus.cpp - A class that represents random virus.
    SmartVirus.h , SmartVirus.cpp - A class that represents smart virus.
    Ladder.h , Ladder.cpp - A class that represents a ladder in the game.
    Rope.h , Rope.cpp - A class that represents a rope in the game.
    Curtain.h , Curtain.cpp - A class that represents a curtain in the game.
    SpecialObject.h , SpecialObject.cpp - An abstract class that represents a special object in the game.
    Vaccine.h , Vaccine.cpp - A class that represents the vaccine in the game.
    Gift.h , Gift.cpp - An abstract class that represents a gift in the game.
    VirusGift.h , VirusGift.cpp - A class that represents a gift that add an virus to the stage.
    ScoreGift.h , ScoreGift.cpp - A class that represents a gift that gives score to the player.
    LiveGift.h , LiveGift.cpp - A class that represents a gift that gives a life to the player.
    TimeGift.h , TimeGift.cpp - A class that represents a gift that gives the player 10 more seconds to finish the stage.
    GameGraph.h , GameGraph.cpp - A class that represents a graph of the stage.
    StageDetails.h , StageDetails.cpp - A class that responsible for all the stage details.
    Font.h , Font.cpp - A singleton class that responsible for the font that used in the game screens.
    Sound.h , Sound.cpp - A singleton class that responsible for all the sounds in the game.
    Textures.h , Textures.cpp - A singleton class that responsible for all the textures that used in the game.
    Macros.h - A file that includes all the constant variables in the program.
    main.cpp - Responsible to run the game.

Main data structures and their role:

    std::vector<std::unique_ptr<Screen>> m_screens : A vector of unique_ptr to screen objects, use to display the wanted window.
    std::vector<NodesData> m_graph : A vector that includes structs of kind NodesData that use to represent the game graph.
    std::vector<MenuButton> m_menuButton : A vector of MenuButton objects, use to draw the menu buttons in the main menu window.
    std::vector<std::unique_ptr<Virus>> m_viruses : A vector of unique_ptr to virus objects, use to hold all the viruses data.
    std::vector<std::vector<std::unique_ptr<StaticObject>>> m_staticObjects : A vector of vectors of unique_ptrs to static objects, use to hold all the static objects data.
    std::vector<Curtain *> m_openCurtain : A vector of pointers to curtains, use to hold all the open curtains.

Worth Notes Algorithms:

    The game is using a BFS algorithm that calculate all the distances from the player to the rest of the objects
    (Not including curtains, they arent part of the walking path).
    Each smart virus in the game sends his array position and receives his predecessor that indicates the virus which direction he should go.
    If the smart virus receives that he has no predecessor it means that he cannot reach the player.

Known bugs (in development):

    When the smart virus try to repair itself it cant pass between curtains.
    When the smart virus on a ladder that near to one of the extreme sides of the stage it's gets stuck (If the player stands under it , it breaks free).
    More than one virus can fall into the same open curtain.
    Sometimes when a virus fall into an open curtain and the player moves right and try to step over the virus it get stuck on the virus (Can be fixed by moving left and right quickly until it breaks free).
    If the player tries to walk on an virus that fell into an open curtain and there is a curtain above the player it gets stuck (Can commit suicide or wait 5 seconds until the virus will kill him).
    If the smart virus fall on a rope it cannot stay on the rope , it will keep falliing.

Other Comments:
    
    None