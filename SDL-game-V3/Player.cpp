#pragma once
#include "Player.h"
#include "LoaderParams.h"
#include <SDL.h>
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Vector2D.h"




Player::Player(const LoaderParams* pParams) :	SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

//version without input

//void Player::update()
//{
	/*
	m_x += 1; // version without vectors
	m_position.setX(m_position.getX() + 1);  //version with vector2D
	m_position.setY(m_position.getY() - 1); //version with vector2D
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	*/

	//version with velocity update
//	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	//m_velocity.setX(1); // dodaje stala wartos predkosci
//	m_acceleration.setX(0.01); //tutaj nie dziala bo kszaczy sie konstruktor bo wielkosc accelaration nie jest zainicjowana
//	SDLGameObject::update();
	//version with velocity update END
//}
//version without input END

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}

void Player::clean()
{
}


//input pod joystick na razie
void Player::handleInput()
{
	//myszka test inputu
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}

	//keyboard
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}


	//mouse position, animation go after the coursor
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;

	// mouse fallow the mouse, b³êdy kszaczy sie 
	//Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	//m_velocity = (*vec - m_position) / 100;


	//joystick
	/*
	if (TheInputHandler::Instance()->joysticksInitialised())
	{
		if (TheInputHandler::Instance()->xvalue(0, 1) > 0 ||
			TheInputHandler::Instance()->xvalue(0, 1) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,
				1));
		}
		if (TheInputHandler::Instance()->yvalue(0, 1) > 0 ||
			TheInputHandler::Instance()->yvalue(0, 1) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,
				1));
		}
		if (TheInputHandler::Instance()->xvalue(0, 2) > 0 ||
			TheInputHandler::Instance()->xvalue(0, 2) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,
				2));
		}
		if (TheInputHandler::Instance()->yvalue(0, 2) > 0 ||
			TheInputHandler::Instance()->yvalue(0, 2) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,
				2));
		}
	}
	*/
}