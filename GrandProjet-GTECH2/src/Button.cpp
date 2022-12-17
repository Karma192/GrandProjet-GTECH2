#include "Button.hpp"

Button::Button() {

}

// Concstructor for rect button
Button::Button(int x, int y, int w, int h, sf::RenderWindow* win) {
	b_posx = x;
	b_posy = y;
	b_width = w;
	b_height = h;
	b_window = win;
	button = RECT;
}

// Concstructor for rect button with rotation
Button::Button(int x, int y, int w, int h, float angle, sf::RenderWindow* win) {
	b_posx = x;
	b_posy = y;
	b_width = w;
	b_height = h;
	b_angle = angle;
	b_window = win;
	button = RECT;
}

// Concstructor for rect button with rotation and specifics colors
Button::Button(int x, int y, int w, int h, float angle, int red, int green, int blue, int alpha, sf::RenderWindow* win) {
	b_posx = x;
	b_posy = y;
	b_width = w;
	b_height = h;
	b_angle = angle;
	c = sf::Color(red, green, blue, alpha);
	b_window = win;
	button = RECT;
}

// Concstructor for circle button
Button::Button(int x, int y, float radius, int red, int green, int blue, int alpha, sf::RenderWindow* win) {
	b_posx = x;
	b_posy = y;
	b_radius = radius;
	c = sf::Color(red, green, blue, alpha);
	b_window = win;
	button = CIRCLE;
}

// Constructor for convex button
Button::Button(int x, int y, int w, int h, int choice, int red, int green, int blue, int alpha, sf::RenderWindow* win) {
	b_posx = x;
	b_posy = y;
	b_width = w;
	b_height = h;
	b_choice = choice;
	c = sf::Color(red, green, blue, alpha);
	b_window = win;
	button = OTHER;
}

Button::~Button() {

}

void Button::ButtonLoop() {
	OnHover();
	IsClicking();
}

void Button::ButtonRender() {
	switch (button) {
	case RECT :
		DrawRectButton();
		break;
	case CIRCLE :
		DrawCircleButton();
		break;
	case OTHER :
		DrawOtherButton();
		break;
	default:
		break;
	}
}

// Function for detect on hover
bool Button::OnHover() {
	if (sf::Mouse::getPosition(*b_window).x < b_posx && sf::Mouse::getPosition(*b_window).x > (b_posx + b_width)) {
		if (sf::Mouse::getPosition(*b_window).y < b_posx && sf::Mouse::getPosition(*b_window).y >(b_posx + b_width)) {
			std::cout << "on hover !" << std::endl;
		}
	}
}

// Function for detect the click
bool Button::IsClicking() {
	if (OnHover()) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			return true;
		}
		return false;
	}
	else {
		return false;
	}
}

// Draw Rectangle Button
void Button::DrawRectButton() {
	b_rectangle.setPosition(b_posx, b_posy);
	b_rectangle.setSize(sf::Vector2f(b_width, b_height));
	b_rectangle.setFillColor(c);

	b_window->draw(b_rectangle);
}

// Draw Circle Button
void Button::DrawCircleButton() {
	b_sphere.setPosition(b_posx, b_posy);
	b_sphere.setRadius(b_radius);
	b_sphere.setFillColor(c);

	b_window->draw(b_sphere);
}

// Draw Other types of Button
void Button::DrawOtherButton() {
	switch (b_choice) {
	case DIAMOND :
		b_sphere.setPointCount(DIAMOND);
		b_sphere.setPosition(b_posx, b_posy);
		b_sphere.setRadius(b_radius);
		b_sphere.setFillColor(c);
		b_window->draw(b_sphere);
		break;
	case TRIANGLE :
		b_sphere.setPointCount(TRIANGLE);
		b_sphere.setPosition(b_posx, b_posy);
		b_sphere.setRadius(b_radius);
		b_sphere.setFillColor(c);
		b_window->draw(b_sphere);
		break;
	case HEXAGON :
		b_sphere.setPointCount(HEXAGON);
		b_sphere.setPosition(b_posx, b_posy);
		b_sphere.setRadius(b_radius);
		b_sphere.setFillColor(c);
		b_window->draw(b_sphere);
		break;
	default:
		break;
	}
}