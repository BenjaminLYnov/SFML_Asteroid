MOURGUES PAUL & BENJAMIN LY

To compile this game :

(If you don't have the compilator g++, you can get it by installing tdm64-gcc-10.3.0-2.exe)

Open the Terminal, then go in project game repertory

cd Code
g++ -std=c++14 -O3 main.cpp DataGame/DataGame.cpp DataGame\Asteroid/Asteroid.cpp DataGame\Asteroid/AsteroidEngine.cpp DataGame\Collision/Collision.cpp DataGame\Math/RandomNumber.cpp DataGame\Math/Vector2D.cpp DataGame\Menu/Menu.cpp DataGame\OVNI/OVNI.cpp DataGame\Player/Invulnerable.cpp DataGame\Player/MovePlayer.cpp DataGame\Player/Player.cpp DataGame\Player\Skills/Laser.cpp DataGame\Player\Skills/Skills.cpp DataGame\Player\Skills/Teleportation.cpp DataGame\ScoreManager/ScoreManager.cpp DataGame\SfmlAudio/SfmlAudio.cpp DataGame\Shapes/AsteroidShape.cpp DataGame\Shapes/BattleShip.cpp DataGame\Shapes/LaserShape.cpp DataGame\Shapes/OVNIShape.cpp DataGame\Shapes/Shape.cpp DataGame\Timer/Timer.cpp DataGame\UHD/UHD.cpp DataGame\Wraparound/Wraparound.cpp Game/Game.cpp Game/GameEngine.cpp Game/GameOverEngine.cpp  -o ./../Game/Game.exe -I SFML-2.5.1/include -L SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

<It take a while> 15s for me

Then you can lauch Game.exe 

cd ./../Game && .\Game

(You can also double click on it)

You can also compile with the Python file Compile.py :
python Compile.py

(It doesn't work with double click)

Enjoy !
