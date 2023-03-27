#include "Spells.hpp"


Spells::Spells()
{
}


Spells::~Spells() 
{

}

void Spells::Loop()
{
	SetFireBall();
}

void Spells::Render() 
{
	gameData = GetGameData();
	gameData.window->draw(spell);
}

bool Spells::collidesWith(CollisionObject* other)
{
	if (Player* player = dynamic_cast<Player*>(other)) {
		PlayerPos = player->cube.getPosition();
		DrawSpell();
		playerRotation = player->cube.getRotation();
		if (spell.getGlobalBounds().intersects(player->cube.getGlobalBounds())) {
			return true;
		}
	}

	if (Enemies* enemy = dynamic_cast<Enemies*>(other)) {
		if (spell.getGlobalBounds().intersects(enemy->cube2.getGlobalBounds())) {
			return true;
		}
	}
	return false;
}

void Spells::handleCollision(CollisionObject* other)
{
	if (dynamic_cast<Player*>(other)) {

	}
	if (dynamic_cast<Enemies*>(other)) {
		std::cout << "bam degats";
	}
}

void Spells::SetFireBall() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		sf::Vector2f launchDirection(std::cos(playerRotation * 3.14159265 / 180),
			std::sin(playerRotation * 3.14159265 / 180));
		std::cout << launchDirection.x <<std::endl<<launchDirection.y;
		if (launchDirection == sf::Vector2f(0,-1)) {
			Launch(PlayerPos, sf::Vector2f(0,-10));
		}
		else
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
	spell.setOrigin(PlayerBounds.width / 2.0f, PlayerBounds.height / 2.0f);
}