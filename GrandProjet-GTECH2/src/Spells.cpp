#include "Spells.hpp"
#include "GameMaster.hpp"


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
	GameMaster::GetGameData().window->draw(Spell);
}

bool Spells::collidesWith(CollisionObject* other)
{
	if (Player* player = dynamic_cast<Player*>(other)) {

		playerCenter = Vector2f(player->cube.getPosition());
		mousePosWindow = Vector2f(Mouse::getPosition(*GameMaster::GetGameData().window));

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
	/*aimDir = mousePosWindow - playerCenter;
	aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

	float PI = 3.14159265f;
	float deg = atan2(aimDirNorm.y, aimDirNorm.x) * 180 / PI;
	player.setRotation(deg + 90);

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		b1.shape.setPosition(playerCenter);
		b1.currVelocity = aimDirNorm * b1.maxSpeed;

		bullets.push_back(Bullet(b1));
	}*/
}

void Spells::Launch(sf::Vector2f StartPos, sf::Vector2f LaunchDir) 
{
	/*position = StartPos;
	direction = LaunchDir;

	direction = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);

	launched = true;*/
}

void Spells::DrawSpell() 
{
	/*Spell.setRadius(10);
	Spell.setFillColor(sf::Color::Green);
	Spell.setPosition(position);
	Spell.setOrigin(Spell.getGlobalBounds().width / 2 , Spell.getGlobalBounds().height / 2);
	*/
}

void Spells::SetSlide() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {

	}
}
