#include "Spells.hpp"
#include "GameMaster.hpp"


Spells::Spells(Player *p)
{
	CooldownFireBall = 0;
	player = p;
}


Spells::~Spells() 
{

}

void Spells::Loop()
{
	SetFireBall();
	SetSlide();
}

void Spells::Render() 
{
	DrawSpell();
	GameMaster::GetGameData().window->draw(Spell);
}

bool Spells::collidesWith(CollisionObject* other)
{
	if (Player* player = dynamic_cast<Player*>(other)) {

		PlayerPos = player->cube.getPosition();
		PlayerRotation = player->cube.getRotation();
		PlayerBounds = player->cube.getGlobalBounds();
		if (Spell.getGlobalBounds().intersects(player->cube.getGlobalBounds())) 
		{
			return true;
		}


	}
	if (Enemies* enemy = dynamic_cast<Enemies*>(other)) 
	{
		if (Spell.getGlobalBounds().intersects(enemy->cube2.getGlobalBounds())) 
		{
			std::cout << "bam degats";
			return true;
		}
	}
	return false;
}

void Spells::handleCollision(CollisionObject* other)
{
	if (dynamic_cast<Enemies*>(other)) 
	{
		std::cout << "bam degats";
	}

	if (dynamic_cast<Player*>(other)) 
	{
		std::cout << "Casting";
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
			//this->Destroy();
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
	PlayerRapidity = player->playerSpeed;
	_Speed = PlayerRapidity * 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (canDash)
		{
			std::cout << "DASH";
			player->setPlayerSpeed(_Speed);
			canDash = false;
			DashReset = sf::Time::Zero;
		}
	}
	if (!canDash) 
	{
		std::cout << " PAS DASH";
		player->setPlayerSpeed(PlayerRapidity);
		DashReset += clock.restart();
		if (DashReset >= CooldownDash)
		{
			canDash = true;
		}
	}
}
