#include "Spells.hpp"
#include "../../Instance/GameMaster.hpp"


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
	SetDash();

}

void Spells::Render() 
{
	DrawSpell();
	GameMaster::GetGameData().window->draw(Spell);
	ThirdSpell();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		GameMaster::GetInstance()->GetGameData().window->draw(_hitboxThirdSpell);
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

void Spells::SetDash() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (_canDash)
		{
			_canDash = false;
			_asDash = true;
			DashReset = sf::Time::Zero;
			DashReset += clock.restart();
		}
	}	

	if (clock.getElapsedTime().asSeconds() > 0.2f)
	{
		_asDash = false;
	}

	if (!_canDash)
	{
		if (clock.getElapsedTime().asSeconds() > 3.f)
		{
			_canDash = true;
		}
	}
}

void Spells::ThirdSpell()
{
	_hitboxThirdSpell.setRadius(80.f);
	_hitboxThirdSpell.setFillColor(sf::Color::Blue);
	_hitboxThirdSpell.setOrigin(_hitboxThirdSpell.getGlobalBounds().width/ 2.0f,
		_hitboxThirdSpell.getGlobalBounds().height / 2.0f);
	_hitboxThirdSpell.setPosition(PlayerPos);
}
