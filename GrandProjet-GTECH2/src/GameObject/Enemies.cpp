#include "Enemies.hpp"

Enemies::Enemies()
{
    SetSprite("sprites/player/adventurer-idle.png", sf::Vector2f(3.0f, 3.0f));
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
    GameMaster::GetInstance()->GetGameData().window->draw(*Sprite());
}

void Enemies::OnCollisionEnter(PhysicBody* other)
{
	std::cout << "Collision of " << GetName() <<" with a " << other->GetTag() << std::endl;

    if (other->CompareTag("Player"))
    {
        ennemieHP--;
        if (ennemieHP <= 0)
        {
            Destroy();
            //TODO DESTROY ENNEMIES
        }
	}
}

void Enemies::FollowTarget(bool)
{
    //Radius for Aggro
    //interval for aggro
    sf::Vector2f FollowPos = cube2.getPosition();
    sf::Vector2f RelatPos = TargetPos - FollowPos;
    distance = std::sqrt((TargetPos.x - FollowPos.x) * (TargetPos.x - FollowPos.x) +
        (TargetPos.y - FollowPos.y) * (TargetPos.y - FollowPos.y));


    if (distance <= 150)
    {
        follow = true;
        cube2.setFillColor(sf::Color::Blue);
        cube2.move(.02f * RelatPos);
    }
    else 
    {
        follow = false;
        cube2.setFillColor(sf::Color::Green);
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
