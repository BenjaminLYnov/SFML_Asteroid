import os

request = "cd ./Code && g++ -std=c++14 -O3 main.cpp DataGame/DataGame.cpp DataGame\Asteroid/Asteroid.cpp DataGame\Asteroid/AsteroidEngine.cpp DataGame\Collision/Collision.cpp DataGame\Math/RandomNumber.cpp DataGame\Math/Vector2D.cpp DataGame\Menu/Menu.cpp DataGame\OVNI/OVNI.cpp DataGame\Player/Invulnerable.cpp DataGame\Player/MovePlayer.cpp DataGame\Player/Player.cpp DataGame\Player\Skills/Laser.cpp DataGame\Player\Skills/Skills.cpp DataGame\Player\Skills/Teleportation.cpp DataGame\ScoreManager/ScoreManager.cpp DataGame\SfmlAudio/SfmlAudio.cpp DataGame\Shapes/AsteroidShape.cpp DataGame\Shapes/BattleShip.cpp DataGame\Shapes/LaserShape.cpp DataGame\Shapes/OVNIShape.cpp DataGame\Shapes/Shape.cpp DataGame\Timer/Timer.cpp DataGame/UHD/UHD.cpp DataGame\Wraparound/Wraparound.cpp Game/Game.cpp Game/GameEngine.cpp Game/GameOverEngine.cpp  -o ./../Game/Game.exe -I SFML-2.5.1/include -L SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio"
os.system(request)

    