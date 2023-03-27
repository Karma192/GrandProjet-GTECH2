#include "Spells.hpp"


Spells::Spells()
{
	speed = 5;
	launched = false;
	DrawSpell();
}


Spells::~Spells() 
{

}

void Spells::Loop()
{
}

void Spells::Render() 
{
	gameData = GetGameData();
	gameData.window->draw(spell);
}

void Spells::SetFireBall(Player& player) 
{
	sf::Vector2f yes = player.cube.getPosition();
	std::cout << yes.x << yes.y << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		sf::Vector2f PlayerPos = player.cube.getPosition();
		float playerRotation = player.cube.getRotation() * 3.14159265 / 180;

		sf::Vector2f launchDirection(std::cos(playerRotation), std::sin(playerRotation));
		Launch(PlayerPos, launchDirection);
	}
	Update();
}

void Spells::Update() 
{
	if (launched) {
		position += direction * speed;
	}
}

void Spells::Launch(sf::Vector2f StartPos, sf::Vector2f LaunchDir) 
{
	position = StartPos;
	direction = LaunchDir;

	direction = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);

	launched = true;
}

void Spells::DrawSpell() 
{
	spell.setRadius(10);
	spell.setFillColor(sf::Color::Green);
	spell.setPosition(position);
}