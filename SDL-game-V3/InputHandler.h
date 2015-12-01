#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();

	//mouse
	//std::vector<bool> m_mouseButtonStates;
	/*
	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}
	*/


	//keyboard
	//Uint8* m_keystate;
	const Uint8* m_keystates;

	bool isKeyDown(SDL_Scancode key);

	/*
	//joystick
	void initialiseJoysticks();
	bool joysticksInitialised() {
		return m_bJoysticksInitialised;
	}
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	std::vector<std::vector<bool>> m_buttonStates;
	bool getButtonState(int joy, int buttonNumber)
	{
		return m_buttonStates[joy][buttonNumber];
	}
	*/

	// zbiorcze inputy w zaleznosci od kontrolera
	// private functions to handle different event types
	// handle keyboard events
	void onKeyDown();
	void onKeyUp();
	// handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);
	// handle joysticks events
	//void onJoystickAxisMove(SDL_Event& event);
	//void onJoystickButtonDown(SDL_Event& event);
	//void onJoystickButtonUp(SDL_Event& event);


	//z alien attack
	// mouse events
	bool getMouseButtonState(int buttonNumber) const;
	Vector2D* getMousePosition() const;

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

	//mouse
	//Vector2D* m_mousePosition;
	// mouse specific
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;

	/*
	//joystick
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;
	*/

};
typedef InputHandler TheInputHandler;