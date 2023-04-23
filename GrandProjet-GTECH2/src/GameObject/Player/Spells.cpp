#include "Spells.hpp"
#include "../../Instance/GameMaster.hpp"
#include "Player.hpp"


/// Classe Mère Spells héritante de GameObject

void Spell::Reset()
{
	_isInit = false;
	_isActive = true;
	_destroyed = false;
	_lifeTime = _maxLifeTime;
	SetPosition(_player->Sprite().getPosition());
	Reinitialize();
}

/// Classe FireBall

FireBall::FireBall(sf::Vector2f pos)
{
	SetSprite("Default", sf::Vector2f(1, 1));
	SetID("FireBall", "Spell");
	SetPosition(pos);
	_cooldown = new Cooldown(500);
	SetLifeTime(500);
}

FireBall::~FireBall()
{
}

void FireBall::Loop()
{
	Sprite().move(_direction.x * _speed, _direction.y * _speed);
}

void FireBall::Render()
{
	GameMaster::Draw(Sprite());
}

void FireBall::OnCollisionEnter(PhysicBody* other)
{
	if (other->CompareTag("Enemy"))
	{
		_destroyed = true;
	}
}

void FireBall::SetDirection(sf::Vector2f dir)
{
	_direction = dir;
}

/// Classe Dash

Dash::Dash()
{
	SetID("Dash", "Spell");
	_cooldown = new Cooldown(200);
	SetLifeTime(15);
}

Dash::~Dash()
{
}

void Dash::OnActive()
{
	_player->AddSpeedModifier(_strenght);
}

void Dash::InactiveUpdate()
{
	_player->ResetSpeedModifier();
}

void Dash::SetStrenght(float strenght)
{
	_strenght = strenght;
}

/// Classe ThirdSpell

ThirdSpell::ThirdSpell()
{
	SetSprite("Default", sf::Vector2f(8, 8));
	SetID("AOE", "Spell");
	_cooldown = new Cooldown(300);
	SetLifeTime(30);
}

ThirdSpell::~ThirdSpell()
{
}

void ThirdSpell::Loop()
{
	SetPosition(_player->Sprite().getPosition());
}

void ThirdSpell::Render()
{
	GameMaster::Draw(Sprite());
}

void ThirdSpell::OnCollisionEnter(PhysicBody* other)
{
	if (other->CompareTag("Enemy"))
	{
		// Do a flip
	}
}

/// Classe SpellsManager

SpellsManager::SpellsManager(Player* p)
{
	_player = p;
	_fireBallSpell = new FireBall(_player->GetPlayerPosition());
	_spells.push_back(_fireBallSpell);
	_dashSpell = new Dash();
	_spells.push_back(_dashSpell);
	_thirdSpell = new ThirdSpell();
	_spells.push_back(_thirdSpell);

	for (auto spell : _spells)
	{
		spell->SetPlayer(_player);
	}

	_indexSpell = 0;
}

SpellsManager::~SpellsManager() 
{
	delete _fireBallSpell;
	delete _dashSpell;
	delete _thirdSpell;
	delete _player;
}

void SpellsManager::UpdateSpell()
{
	CastSpell();

	_fireBallSpell->SetDirection(_launchDirection);

	for (auto spell : _spells)
	{
		if (spell != nullptr)
		{
			spell->SpellUpdate();
		}
	}

	PurgeSpell();
}

void SpellsManager::PurgeSpell()
{
	for (auto spell : _spells)
	{
		if (spell != nullptr)
		{
			if (spell->IsDestroyed())
			{
				/*delete spell;
				spell = nullptr;*/
			}
		}
	}
}

void SpellsManager::SetLaunchDirection()
{
	_launchDirection = sf::Vector2f(std::cos(_player->GetPlayerAimDegree() * 3.14159265 / 180), 
		std::sin(_player->GetPlayerAimDegree() * 3.14159265 / 180));

}

void SpellsManager::CastSpell()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (!_shiftIsPressed)
		{
			_indexSpell = (_indexSpell + 1) % _spells.size();
		}
		std::cout << "Sort Actuel : \t" << _spells[_indexSpell]->GetName() << std::endl;
		_shiftIsPressed = true;
	}
	else {
		_shiftIsPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (!_spaceIsPressed)
		{
			_spells[_indexSpell]->Use();
		}
		_spaceIsPressed = true;
	}
	else {
		_spaceIsPressed = false;
	}
}
