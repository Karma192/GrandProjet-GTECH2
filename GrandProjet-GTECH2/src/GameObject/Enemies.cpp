#include "Enemies.hpp"

Enemies::Enemies()
{
    SetSprite("Debug", sf::Vector2f(3.0f, 3.0f));
    SetPosition(sf::Vector2f(200, 200));
    SetID("Enemy1", "Enemy");
    this->ennemieHP = 10;
}

Enemies::~Enemies()
{

}

void Enemies::Loop() 
{
    //GetStunned();
    FollowTarget(follow);
}

void Enemies::Render() 
{
    GameMaster::Draw(Sprite());
}

void Enemies::OnCollisionEnter(PhysicBody* other)
{
    if (other->CompareTag("Player"))
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

void Enemies::FollowTarget(bool)
{
    //Radius for Aggro
    //interval for aggro
    sf::Vector2f FollowPos = Sprite().getPosition();
    sf::Vector2f RelatPos = TargetPos - FollowPos;
    distance = std::sqrt((TargetPos.x - FollowPos.x) * (TargetPos.x - FollowPos.x) +
        (TargetPos.y - FollowPos.y) * (TargetPos.y - FollowPos.y));


    if (distance <= 150)
    {
        follow = true;
        Sprite().move(.02f * RelatPos);
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
