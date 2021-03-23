// author Kevin Andersen
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MyEnums.h"  // gameState, animationState
#include <string>
#include "Player.h"
#include "boat.h"
#include "fire.h"
#include "textAnimation.h"
#include "TextLoader.h"
class Game
{
public:
	Game();
	~Game();

	void run();
	GameState m_currentGameState{ GameState::Author }; // used for whatever mode game is in
	Viking m_viking;
	Boat m_boat;
private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void setupText();
	void moveBoat();
	void checkScreen();
	void textUpdate(sf::Time t_deltaTime);
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_font; // font used by message
	sf::View mainView;
	sf::Music m_backgroundMusic;
	sf::Music m_waves;
	fire fires[50];
	textAnimation m_logo;
	textAnimation m_producerTextSp;
	bool m_exitGame; // control exiting game
	double m_animationSpeed{ 1.0 };
	sf::Sprite m_bg;
	sf::Texture m_bgTexture;
	sf::Sprite m_cloud;
	sf::Texture m_cloudTexture;
	const int BOAT_FINAL_POS = 3010;
	const int PLAYER_CREDIT_STOP = 3199;
	const int AUTHOR_SCREEN = 800;
	const int LICENCE_SCREEN = 1600;
	const int PRODUCER_SCREEN = 2400;
	const int SPLASH_SCREEN = 3200;
	int m_timer{ 0 };
	bool creditContinue = false;
	sf::Text m_authorText;
	sf::Text m_liscenceText;
	sf::Text m_producerText;
	sf::Text m_continueMsg;
	std::string m_AUTHOR = "Made by Kevin\n    Andersen";
	std::string m_LISCENCE = "Made with";
	std::string m_PRODUCER = "Produced by PeteIsCool industries LTD.";
	std::string m_AND_ALSO = "& is also";
	sf::Text m_names;
	sf::Text m_title;
	LevelData m_creditData;
	int currentGroup{ 0 };
};

#endif // !GAME

