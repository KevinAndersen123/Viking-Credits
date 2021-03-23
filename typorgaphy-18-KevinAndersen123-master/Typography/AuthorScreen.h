#ifndef AUTHOR_SCREEN
#define AUTHOR_SCREEN

#include<SFML\Graphics.hpp>
#include "MyEnums.h"
#include "Game.h"
#include <string.h>
#include "Player.h"

class Game;

class AuthorScreen
{
public:	
	AuthorScreen(Game& t_game, sf::Font t_font);
	~AuthorScreen();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

private:
	Game& m_game; // refrence to game object used to set game state
	sf::Font m_font; // font loaded by game
	sf::Text m_madeByMessage; // sf text used for message
	sf::Time m_cumulativeTime; // timer for screen
	AnimationState m_animationState; // which mode are we dong in/out/none
	sf::Transform m_rotate; // transformation to rotate screen
	float m_exitSpeed{ 1.0f }; // translation increment for exit animation
	bool m_offset{ true }; //used to rotate text once aniclockwise
	int m_keyFrameLevel{ 100 }; // keyframe afer rotation
	int m_keyframeLeave{ 200 }; // keyframe to start departure
	int m_keyframeExit{ 300 }; // keyframe to change modes
	float m_rotationIncrement{ 0.5f }; // step back to horiziontal
	float m_rotationOffset{ 25.0f };  // initial rotation away from horiziontal
	float m_slideAmount{ 4.0f }; // amount of translation when leaving screen
	const std::string First_MESSAGE{ "Handmade by Pete" }; // message for appearance and main message
	const std::string FIRST_MESSAGE_STUB{ "Handmade by " }; // portion to remove fro first string
	const std::string SECOND_MESSAGE{ "Pete is cool" }; // message to display when exiting
};

#endif // AUTHOR_SCREEN
