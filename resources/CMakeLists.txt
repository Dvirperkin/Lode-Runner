configure_file (C:/SFML/SFML-2.5.1/bin/openal32.dll ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Impact.ttf" ${CMAKE_BINARY_DIR} COPYONLY)

#Stages file.
configure_file("Levels.txt" ${CMAKE_BINARY_DIR} COPYONLY)

#Textures.
configure_file("Player.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("StupidVirus.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("RandVirus.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("SmartVirus.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Curtain.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Vaccine.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Ladder.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Rope.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Gift.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("StageDetails.jpg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("StageBackGround.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("MenuBackGround.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("WinScreen.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("GameOver.jpeg" ${CMAKE_BINARY_DIR} COPYONLY)

#Sounds and Music
configure_file("MainMenuMusic.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("StageMusic.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("SyringeSound.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("LowTime.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("CurtainOpen.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("LevelUp.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("LiveGift.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("ScoreGift.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("TimeGift.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("VirusGift.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("VirusCollision.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Victory.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("GameOver.ogg" ${CMAKE_BINARY_DIR} COPYONLY)

