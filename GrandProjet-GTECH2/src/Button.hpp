#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameMaster.hpp"

class Button {
public:
	Button();
	Button(float x, float y, int w, int h, sf::RenderWindow* win);
	Button(float x, float y, int w, int h, float angle, sf::RenderWindow* win);
	Button(float x, float y, int w, int h, float angle, int red, int green, int blue, int alpha, sf::RenderWindow* win);
	Button(float x, float y, float radius, int red, int green, int blue, int alpha, sf::RenderWindow* win);
	Button(float x, float y, int w, int h, int choice, int red, int green, int blue, int alpha, sf::RenderWindow* win);
	virtual ~Button();

	void ButtonLoop();
	void ButtonRender();

private:
	sf::RenderWindow* b_window;
	sf::Color b_color;
	sf::CircleShape b_sphere;
	sf::RectangleShape b_rectangle;

	int button;
	enum {
		RECT = 0,
		CIRCLE = 1,
		OTHER = 2,
	};

	float b_radius;

	int b_choice;

	float  b_posx, b_posy;
	int b_width, b_height;
	float b_angle;

	bool OnHover();
	bool IsClicking();

	void DrawRectButton();
	void DrawCircleButton();
	void DrawOtherButton();
};