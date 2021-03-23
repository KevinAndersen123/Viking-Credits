// author Kevin Andersen

#include "Game.h"
#include <iostream>


/// <summary>
/// constructor for game setup window and initial state
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Credits" },
	m_exitGame{false} //when true game will exit,
{
	try 
	{
		TextLoader::load(m_creditData);
	}
	catch (std::exception & e)
	{
		std::cout << "File loading failure" << std::endl;
		std::cout << e.what() << std::endl;
		throw e;
	}

	setupText(); // load font 
	mainView.setCenter(400.0f, 300.0f);
	mainView.setSize(800, 600);
	for (int i = 0; i < 10; i++)
	{
		fires[i].Initialise(sf::Vector2f(4000 + 4 * i, 360));
	}
	for (int i = 10; i < 20; i++)
	{
		fires[i].Initialise(sf::Vector2f(4200 + 4 * i, 360));
	}
	for (int i = 20; i < 35; i++)
	{
		fires[i].Initialise(sf::Vector2f(4400 + 4 * i, 360));
	}
	for (int i = 35; i < 50; i++)
	{
		fires[i].Initialise(sf::Vector2f(4500 + 4 * i, 360));
	}

	if (!m_bgTexture.loadFromFile("ASSETS/IMAGES/background.png"))
	{
		std::cout << "Error, cannot load photo" << std::endl;
	}
	if (!m_cloudTexture.loadFromFile("ASSETS/IMAGES/cloud.png"))
	{
		std::cout << "Error, cannot load photo" << std::endl;
	}
	m_cloud.setTexture(m_cloudTexture);
	m_cloud.setPosition(696, -50);
	m_cloud.setScale(0.119, 0.119);
	if (!m_backgroundMusic.openFromFile("music.ogg"))
	{
		std::cout << "Error, cannot load audio" << std::endl;
	}
	if (!m_waves.openFromFile("waves.ogg"))
	{
		std::cout << "Error, cannot load audio" << std::endl;
	}
	m_backgroundMusic.play();
	m_backgroundMusic.setLoop(true);
	m_waves.play();
	m_waves.setLoop(true);
	m_waves.setPlayingOffset(sf::seconds(5.0f));
	m_waves.setVolume(55);
	m_bg.setTexture(m_bgTexture);
	m_bg.setScale(0.8, 0.8);
	
}

/// <summary>
/// destructor for game class
/// </summary>
Game::~Game()
{
	
}

/// <summary>
/// main method for game executes the main game loop
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
		
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_boat.getPosition().x <= BOAT_FINAL_POS-1)
	{
		moveBoat();
	}
	if (m_viking.m_pos.x >= BOAT_FINAL_POS-1 && m_viking.m_pos.x < SPLASH_SCREEN)
	{
		m_animationSpeed = 0.5;
		mainView.move(m_animationSpeed, 0.0f);
		m_viking.moveRight();
	}
	if (creditContinue == true && m_viking.m_pos.x <= 5300)
	{
		m_animationSpeed = 0.5;
		m_viking.walkAnimation();
		m_viking.moveRight();
	}
	if (m_viking.m_pos.x <= 4600 && creditContinue == true)
	{
		mainView.move(m_animationSpeed, 0.0f);

	}
	if (m_viking.m_pos.x > 5300)
	{
		m_window.close();
	}

	
	
	checkScreen();
	textUpdate(t_deltaTime);

	for (int i = 0; i < 10; i++)
	{
		fires[i].Initialise(sf::Vector2f(4000 + 8 * i, 360));
	}
	for (int i = 10; i < 20; i++)
	{
		fires[i].Initialise(sf::Vector2f(4200 + 8 * i, 300));
	}
	for (int i = 20; i < 35; i++)
	{
		fires[i].Initialise(sf::Vector2f(4400 + 8 * i, 360));
	}
	for (int i = 35; i < 50; i++)
	{
		fires[i].Initialise(sf::Vector2f(4500 + 8 * i, 360));
	}

	for (int i = 0; i < 50; i++)
	{
		fires[i].Update();
	}
	
}

/// <summary>
/// moves boat animation
/// </summary>
void Game::moveBoat()
{
	if (m_boat.getPosition().x < BOAT_FINAL_POS-1)
	{
		m_boat.moveRight();
		m_viking.setPos(m_boat.getPosition());
		mainView.move(m_animationSpeed, 0.0f);
		m_boat.rotate();
		m_viking.rotate();
	}

}

/// <summary>
/// checks which screen player is in
/// </summary>
void Game::checkScreen()
{
	if (m_boat.getPosition().x == BOAT_FINAL_POS-1)
	{
		m_viking.changeTexture();
	}

	if (m_boat.getPosition().x < AUTHOR_SCREEN)
	{
		std::cout << "First screen" << std::endl;
		m_currentGameState = GameState::Author;
	}
	if (m_boat.getPosition().x > AUTHOR_SCREEN && m_boat.getPosition().x < LICENCE_SCREEN)
	{
		std::cout << "Second screen" << std::endl;
		m_currentGameState = GameState::Licence;
	}
	if (m_boat.getPosition().x > LICENCE_SCREEN && m_boat.getPosition().x < PRODUCER_SCREEN)
	{
		std::cout << "third screen" << std::endl;
		m_currentGameState = GameState::Producer;
	}
	if (m_boat.getPosition().x > PRODUCER_SCREEN &&  m_viking.m_pos.x < SPLASH_SCREEN)
	{
		std::cout << "4th screen" << std::endl;
		m_waves.setVolume(80);
		m_currentGameState = GameState::Splash;
	}

	if (m_viking.m_pos.x == SPLASH_SCREEN)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			std::cout << "credits" << std::endl;
			creditContinue = true;
			m_waves.stop();
			m_currentGameState = GameState::Credits;
		}
	}
	
}
void Game::textUpdate(sf::Time t_deltaTime)
{
	if (m_currentGameState == GameState::Author)
	{
		sf::Vector2f pos = m_authorText.getPosition();
		
		pos.x += 0.9;
		pos.y += -(float)std::cos(pos.x/19);
		
		m_authorText.setPosition(pos);
	}
	if (m_currentGameState == GameState::Licence)
	{
		sf::Vector2f pos = m_liscenceText.getPosition();
		m_logo.update(t_deltaTime);
		m_producerTextSp.update(t_deltaTime);
		pos.y++;
		m_liscenceText.setPosition(pos);

		if (m_logo.getSprite().getPosition().x < LICENCE_SCREEN)
		{
			m_liscenceText.setPosition(m_logo.getSprite().getPosition() + sf::Vector2f(20.0f, -20.0f));
			m_liscenceText.setRotation(m_logo.getSprite().getRotation());
		}
		else
		{
			m_liscenceText.setString(m_AND_ALSO);
		}
	}
	
	if (m_currentGameState == GameState::Producer)
	{
		m_producerTextSp.update(t_deltaTime);
		if (m_timer >= 0 && m_timer < 120)
		{
			m_timer++;
		}
		else if (m_timer >= 120)
		{
			m_producerText.rotate(-2);
			m_timer = 0;
		}
		if (m_timer == 30)
		{
			m_producerText.rotate(-2);
		}
		if (m_timer == 60)
		{
			m_producerText.rotate(2);
		}
		if (m_timer == 90)
		{
			m_producerText.rotate(2);
		}
	}

	if (m_logo.getSprite().getPosition().x >= LICENCE_SCREEN)
	{
		m_producerText.setPosition(m_logo.getSprite().getPosition());
	}
	if (m_currentGameState == GameState::Credits)
	{

		if (m_viking.m_pos.x > 3600 && m_viking.m_pos.x < 3601)
		{
			currentGroup++;
			m_timer = 0;
		}
		if (m_viking.m_pos.x > 3800 && m_viking.m_pos.x < 3801)
		{
			currentGroup++;
			m_timer = 0;
		}

		if (m_timer >= 0 && m_timer < 320)
		{
			m_timer++;

		}
		else if (m_timer >= 320)
		{
			m_names.setFillColor(sf::Color(0,0,0,255));
			m_title.setFillColor(sf::Color(0, 0, 0, 255));
		}
		if (m_timer == 80)
		{
			m_names.setFillColor(sf::Color(0, 0, 0, 50));
			m_title.setFillColor(sf::Color(0, 0, 0, 50));
		}
		if (m_timer == 160)
		{
			m_names.setFillColor(sf::Color(0, 0, 0, 100));
			m_title.setFillColor(sf::Color(0, 0, 0, 100));
		}
		if (m_timer == 240)
		{
			m_names.setFillColor(sf::Color(0, 0, 0, 200));
			m_title.setFillColor(sf::Color(0, 0, 0, 200));
		}
		else if(m_timer == 0)
		{
			m_names.setFillColor(sf::Color(0, 0, 0, 0));
			m_title.setFillColor(sf::Color(0, 0, 0, 0));
		}
	}
}


/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.setView(mainView);
	m_window.clear();
	m_window.draw(m_bg);
	
	if (m_currentGameState == GameState::Author)
	{
		m_window.draw(m_authorText);
	}
	if (m_currentGameState == GameState::Licence)
	{
		if (m_logo.getSprite().getPosition().x <= LICENCE_SCREEN)
		{
			m_window.draw(m_logo.getSprite());
		}
		m_window.draw(m_liscenceText);	
		m_window.draw(m_producerText);
	}
	if (m_currentGameState == GameState::Producer)
	{
		m_window.draw(m_producerText);
	}
	if (m_currentGameState == GameState::Splash )
	{
		m_window.draw(m_continueMsg);
		m_window.draw(m_producerText);
	}
	for (int i = 0; i < 50; i++)
	{
		fires[i].Draw(m_window);
	}
	if (m_currentGameState == GameState::Credits)
	{
		for (int i = 0; i < m_creditData.groups[currentGroup].m_peopleNames.size(); i++)
		{
			m_title.setString(m_creditData.groups[currentGroup].groupName + ":");
			m_names.setString(m_creditData.groups[currentGroup].m_peopleNames[i]);

			if (currentGroup == 0)
			{
				m_title.setPosition(3780, 360);
				m_names.setPosition(3800 , 400 + 40*i);
			}
			else if (currentGroup == 1)
			{
				m_title.setPosition(3980, 360);
				m_names.setPosition(4000, 400 + 40 * i);
			}
			else if (currentGroup == 2)
			{
				m_title.setPosition(4180, 360);
				m_names.setPosition(4200, 400 + 40 * i);
			}
			m_window.draw(m_names);
			m_window.draw(m_title);
		}
		
	}

	m_window.draw(m_cloud);
	m_window.draw(m_viking.getSprite());
	m_window.draw(m_boat.getSprite());
	m_window.display();
}

/// <summary>
/// load the font
/// </summary>
void Game::setupText()
{
	if (!m_font.loadFromFile("ASSETS\\FONTS\\Norse-Bold.otf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	m_authorText.setCharacterSize(40);
	m_authorText.setFont(m_font);
	m_authorText.setString(m_AUTHOR);
	m_authorText.setFillColor(sf::Color::Black);
	m_authorText.setPosition(sf::Vector2f(330, 70));
	m_authorText.setOrigin(50, 20);

	m_liscenceText.setCharacterSize(40);
	m_liscenceText.setString(m_LISCENCE);
	m_liscenceText.setFont(m_font);
	m_liscenceText.setFillColor(sf::Color::Black);
	m_liscenceText.setOrigin(50, 20);

	m_producerText.setCharacterSize(40);
	m_producerText.setString(m_PRODUCER);
	m_producerText.setFont(m_font);
	m_producerText.setFillColor(sf::Color::Black);
	m_producerText.setOrigin(180, 20);

	m_continueMsg.setCharacterSize(30);
	m_continueMsg.setString("Press Enter to\nContinue");
	m_continueMsg.setFont(m_font);
	m_continueMsg.setFillColor(sf::Color::Black);
	m_continueMsg.setPosition(sf::Vector2f(3230, 500));

	m_names.setCharacterSize(35);
	m_names.setFont(m_font);
	m_names.setFillColor(sf::Color::Black);

	
	m_title.setCharacterSize(40);
	m_title.setFont(m_font);
	m_title.setFillColor(sf::Color::Black);


}


