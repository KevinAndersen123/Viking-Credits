/// <summary>
/// typography introduction
/// 
/// @author Kevin Andersen
/// @summary: typography for a viking themed credits
/// @date 12-11-2018
/// @date 19-11-2018
/// @date 26-11-2018
/// @date 28-11-2018
/// @date 1-12-2018
/// estimated time: 14hrs
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"libyaml-cppmdd") 

#include "Game.h"

/// <summary>
/// main enrtry point
/// </summary>
/// <returns>true</returns>
int main()
{
	Game game;
	game.run();

	return 1;
}