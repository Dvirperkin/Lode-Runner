#Stages file.
configure_file("Levels.txt" ${CMAKE_BINARY_DIR} COPYONLY)

#Textures.
configure_file("Player.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("StupidEnemy.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("RandEnemy.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("SmartEnemy.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Wall.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Coin.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Ladder.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Pole.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Gift.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("StageDetails.jpg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("StageBackGround.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("MenuBackGround.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("WinScreen.png" ${CMAKE_BINARY_DIR} COPYONLY)

#Sounds and Music
configure_file("MainMenuMusic.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("SyringeSound.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("LowTime.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("CurtainOpen.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("LevelUp.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("LiveGift.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("ScoreGift.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("TimeGift.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("EnemyGift.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("EnemyCollision.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("Victory.ogg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("GameOver.ogg" ${CMAKE_BINARY_DIR} COPYONLY)

