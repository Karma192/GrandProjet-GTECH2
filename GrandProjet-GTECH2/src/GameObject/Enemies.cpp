#include "Enemies.hpp"

Enemies::Enemies(GameObject* tar)
{
    SetSprite("Default", sf::Vector2f(1.0f, 1.0f));
    SetPosition(sf::Vector2f(250, 250));
    SetID("Enemy1", "Enemy");
    _target = tar;
    this->ennemieHP = 10;
}

Enemies::~Enemies()
{
    delete _target;
}

void Enemies::Init()
{
    animationSlime.LoadAnimation("ressources/sprites/slime/slime_tilesheet.png", &Sprite(), 32, 32, 3.f);

    frameIndexIdle = { 0, 1, 2, 3 };
    frameIndexRun = { 7, 8, 9, 10, 11, 12 };
    frameIndexAttack = { 14, 15, 16, 17, 18, 19, 20 };
    frameIndexDie = { 27, 28, 29, 30, 31 };
}

void Enemies::Loop() 
{
    //GetStunned();
    FollowTarget();

    animationSlime.Animate(frameIndexIdle, 0.2f, true, false, 0);
}

void Enemies::Render() 
{
    GameMaster::Draw(Sprite());
}

void Enemies::OnCollisionEnter(PhysicBody* other)
{
    if (other->CompareTag("Spell"))
    {
		ennemieHP--;
        if (ennemieHP <= 0)
        {
			//Destroy(); ne fonctionne pas encore...
			Sprite().setPosition(-10000, 10000);
			//TODO DESTROY ENNEMIES
		}
	}
}

void Enemies::FollowTarget()
{
    TargetPos = _target->Sprite().getPosition();

    //Radius for Aggro
    //interval for aggro
    sf::Vector2f FollowPos = Sprite().getPosition();
    sf::Vector2f RelatPos = TargetPos - FollowPos;
    distance = std::sqrt((TargetPos.x - FollowPos.x) * (TargetPos.x - FollowPos.x) +
        (TargetPos.y - FollowPos.y) * (TargetPos.y - FollowPos.y));


    if (distance <= 250)
    {
        follow = true;
        Sprite().move(0.02f * RelatPos);
    }
    else 
    {
        follow = false;
    }
}

void Enemies::GetStunned()
{
    /*Player* contextPlayer;
    sf::FloatRect rect = contextPlayer->hitboxTest.getGlobalBounds();
    sf::FloatRect rect2 = cube2.getGlobalBounds();
    if (contextPlayer->IsAttacking) {
        if (IsDamaged(rect, rect2)) {
            follow = false;
            clock2.restart();
        }
    }
    if (clock2.getElapsedTime().asSeconds() > 2.f) {
        follow = true;
    }*/
}
