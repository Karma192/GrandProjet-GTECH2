#include "Spells.hpp"


Spells::Spells()
{
	CooldownFireBall = 0;
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
	DrawSpell();
	gameData = GetGameData();
	gameData.window->draw(Spell);
}

bool Spells::collidesWith(CollisionObject* other)
{
	if (Player* player = dynamic_cast<Player*>(other)) {

		PlayerPos = player->cube.getPosition();
		PlayerRotation = player->cube.getRotation();
		PlayerBounds = player->cube.getLocalBounds();

		//Endurance = player->playerEndurance();

		if (Spell.getGlobalBounds().intersects(player->cube.getGlobalBounds())) {
			return true;
		}
	}

	if (Enemies* enemy = dynamic_cast<Enemies*>(other)) {
		if (Spell.getGlobalBounds().intersects(enemy->cube2.getGlobalBounds())) {
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
		if (CooldownFireBall <= 0) {
			CooldownFireBall = MaxCooldownFireBall;
			sf::Vector2f launchDirection(std::cos(PlayerRotation * 3.14159265 / 180),
				std::sin(PlayerRotation * 3.14159265 / 180));
			Launch(PlayerPos, launchDirection);
		}
	}
	CooldownFireBall--;
	if (launched) {
		position += direction * speed;
	}
	if (isLaunched()) {
		if (Spell.getPosition().x < 0 || Spell.getPosition().x > 1920 ||
			Spell.getPosition().y < 0 || Spell.getPosition().y > 1080) {
			this->Destroy();
		}
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
	Spell.setRadius(10);
	Spell.setFillColor(sf::Color::Green);
	Spell.setPosition(position);
	Spell.setOrigin(PlayerBounds.width / 2.0f, PlayerBounds.height / 2.0f);
}

void Spells::SetSlide() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {

	}
}
