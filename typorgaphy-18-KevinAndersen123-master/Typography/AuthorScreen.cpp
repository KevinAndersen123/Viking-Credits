#include "AuthorScreen.h"




AuthorScreen::AuthorScreen(Game & t_game, sf::Font t_font):
	m_game{t_game},
	m_font{t_font},
	m_animationState{AnimationState::Appear}	
{
	m_madeByMessage.setFont(m_font);
	m_madeByMessage.setFillColor(sf::Color::Red);
	m_madeByMessage.setPosition(100.0f, 100.0f);
	m_madeByMessage.setString(First_MESSAGE);	// "handmade by pete
	m_rotate.rotate(-m_rotationOffset, 1000.0f, 1000.0f); // set text up in anticlockwise position to start
}

AuthorScreen::~AuthorScreen()
{
}


/// <summary>
/// where animation is done at start rotate text into place
/// wait till 2 seconds
/// change phrase leaving word Pete in place
/// slide sentance out tot he left
/// </summary>
/// <param name="t_deltaTime">frame time</param>
void AuthorScreen::update(sf::Time t_deltaTime)
{
	m_cumulativeTime += t_deltaTime;
	if (m_animationState == AnimationState::Appear)
	{		
		if (m_cumulativeTime.asMilliseconds() < m_keyFrameLevel)
		{
			m_rotate.rotate(m_rotationIncrement, 1000.0f, 1000.0f);
		}
	}
	if (m_cumulativeTime.asMilliseconds() > m_keyFrameLevel && m_animationState == AnimationState::Appear)
	{
		m_animationState = AnimationState::None;
	}
	if (m_cumulativeTime.asMilliseconds() > m_keyframeLeave && m_animationState == AnimationState::None)
	{
		m_animationState = AnimationState::Disappear;
		m_madeByMessage.setString(FIRST_MESSAGE_STUB); // "handmade by <space>"
		float offset = m_madeByMessage.getGlobalBounds().width;
		m_madeByMessage.setPosition(m_madeByMessage.getPosition() + sf::Vector2f{ offset, 0.0f });
		m_madeByMessage.setString(SECOND_MESSAGE); // "Pete is cool"
		
	}
	if (m_cumulativeTime.asMilliseconds() > m_keyframeExit)
	{
		m_game.m_currentGameState = GameState::Exit;
		m_animationState = AnimationState::Appear;
	}
	if (m_animationState == AnimationState::Disappear)
	{
		m_exitSpeed += m_slideAmount ;		
		m_rotate.translate(static_cast<float>(m_exitSpeed), 0.0f);
	}

}

/// <summary>
/// render to t_window
/// </summary>
/// <param name="t_window"></param>
void AuthorScreen::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Blue);
	t_window.draw(m_madeByMessage,m_rotate);
	t_window.display();
}

/// <summary>
/// set the speed of the animation
/// </summary>
/// <param name="t_scale">speed 1 - 10</param>
void AuthorScreen::setAnimationSpeed(int t_scale)
{
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	m_keyFrameLevel = t_scale * 100;
	m_keyframeLeave = m_keyFrameLevel + 3000;
	m_keyframeExit = m_keyframeLeave + t_scale * 200;
	m_rotationIncrement = (m_rotationOffset / m_keyFrameLevel)  * (timePerFrame.asMilliseconds() +1) ;
	m_slideAmount =  m_madeByMessage.getPosition().x / m_keyFrameLevel* (timePerFrame.asMilliseconds());
}
