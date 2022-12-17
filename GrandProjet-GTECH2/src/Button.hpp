#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameMaster.hpp"

class Button {
public :
	Button();
	Button(int x, int y, int w, int h, sf::RenderWindow* win);
	Button(int x, int y, int w, int h, float angle, sf::RenderWindow* win);
	Button(int x, int y, int w, int h, float angle, int red, int green, int blue, int alpha, sf::RenderWindow* win);
	Button(int x, int y, float radius, int red, int green, int blue, int alpha, sf::RenderWindow* win);
	Button(int x, int y, int w, int h, int choice, int red, int green, int blue, int alpha, sf::RenderWindow* win);
	virtual ~Button();

	void ButtonLoop();
	void ButtonRender();

private :
	sf::RenderWindow* b_window;
	sf::Color c;
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

	int b_width, b_height, b_posx, b_posy;
	float b_angle;
	int b_red, b_green, b_blue, b_alpha;

	bool OnHover();
	bool IsClicking();

	void DrawRectButton();
	void DrawCircleButton();
	void DrawOtherButton();
};