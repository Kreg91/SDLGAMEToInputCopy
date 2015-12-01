#pragma once
#include <SDL.h>
#include "Game.h"

#include <SDL_joystick.h>
#include <SDL_mixer.h>
#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;
/*
InputHandler::InputHandler()
{
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
	
}
*/
InputHandler::InputHandler() : m_keystates(0), m_mousePosition(new Vector2D(0, 0))
{
	// create button states for the mouse
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}

//initialize joystick
/*
void InputHandler::initialiseJoysticks()
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}
	if (SDL_NumJoysticks() > 0)
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			if (SDL_JoystickOpened(i) == 1)
			{
				m_joysticks.push_back(joy);
			}
			else
			{
				std::cout << SDL_GetError();
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialised = true;
		std::cout << "Initialised " << m_joysticks.size() << "joystick(s)";
	}
	else
	{
		m_bJoysticksInitialised = false;
	}

	//joy buttons
	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		SDL_Joystick* joy = SDL_JoystickOpen(i);
		if (SDL_JoystickOpened(i))
		{
			m_joysticks.push_back(joy);
			m_joystickValues.push_back(std::make_pair(new
				Vector2D(0, 0), new Vector2D(0, 0)));
			std::vector<bool> tempButtons;
			for (int j = 0; j < SDL_JoystickNumButtons(joy); j++)
			{
				tempButtons.push_back(false);
			}
			m_buttonStates.push_back(tempButtons);
		}
	}

}
*/
void InputHandler::clean()
{



	/*
	//joystick
	if (m_bJoysticksInitialised)
	{
		for (unsigned int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
	*/
}

void InputHandler::update()
{
	//keyboard
	//umiescilem w oddzielnych funkcjach t¹ wazna zmienn¹
	//m_keystates = SDL_GetKeyboardState(0);

	/*
	//general event
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			TheGame::Instance()->quit();
		}
	}
	*/
	//zbiorcze podsumowanie
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
	//	case SDL_JOYAXISMOTION:
		//	onJoystickAxisMove(event);
			//break;
		//case SDL_JOYBUTTONDOWN:
			//onJoystickButtonDown(event);
			//break;
		//case SDL_JOYBUTTONUP:
			//onJoystickButtonUp(event);
			//break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}

	
	
	//tutaj dodawaj eventy Inputu, sa one pozniej odtwarzane w klasie Game w funkcji events
	//wrzucilem to do funkcji zewnetrznych ponizej
	/*
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			m_mouseButtonStates[LEFT] = true;
		}
		if (event.button.button == SDL_BUTTON_MIDDLE)
		{
			m_mouseButtonStates[MIDDLE] = true;
		}
		if (event.button.button == SDL_BUTTON_RIGHT)
		{
			m_mouseButtonStates[RIGHT] = true;
		}
	}
	if (event.type == SDL_MOUSEBUTTONUP)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			m_mouseButtonStates[LEFT] = false;
		}
		if (event.button.button == SDL_BUTTON_MIDDLE)
		{
			m_mouseButtonStates[MIDDLE] = false;
		}
		if (event.button.button == SDL_BUTTON_RIGHT)
		{
			m_mouseButtonStates[RIGHT] = false;
		}
	}
	*/

	//mouse axis events, kszaczy sie nie uzywaj tego
	/*
	if (event.type == SDL_MOUSEMOTION)
	{
		m_mousePosition->setX(event.motion.x);
		m_mousePosition->setY(event.motion.y);
	}
	*/

	//zbiorcze podsumowanie


}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0)
	{
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void InputHandler::onMouseButtonDown(SDL_Event &event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = true;
	}

	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = true;
	}

	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event &event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = false;
	}

	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = false;
	}

	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = false;
	}
}
void InputHandler::onMouseMove(SDL_Event &event)
{
	m_mousePosition->setX(event.motion.x);
	m_mousePosition->setY(event.motion.y);
}

void InputHandler::onKeyDown()
{
	m_keystates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
	m_keystates = SDL_GetKeyboardState(0);
}

//mouse
bool InputHandler::getMouseButtonState(int buttonNumber) const
{
	return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition() const
{
	return m_mousePosition;
}

