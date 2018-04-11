#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

// Name: Patrick Darcy
// Login: C00226157
// Date: 11/04/2018
// Approximate time taken: 10 hrs
//---------------------------------------------------------------------------
// Project Description: This is a program that rotates and prints the co-ordinates of a cube
// ---------------------------------------------------------------------------
// Known Bugs:
// 

#include "Game.h"

int main()
{
	Game game;
	game.run();
}