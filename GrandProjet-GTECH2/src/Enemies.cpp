#include "Enemies.hpp"

Enemies::Enemies()
{
    Cube2Test();
    SetID("Enemy1", "Enemy");
    sf::FloatRect* hitbox = &cube2.getGlobalBounds();
    SetHitbox(hitbox);
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
    GameMaster::GetInstance()->GetGameData().window->draw(cube2);
}

void Enemies::OnCollisionEnter(PhysicBody* other)
{
    if (other->CompareTag("Player"))
    {
		std::cout << "Collision of " << GetName() <<" with player" << std::endl;
        ennemieHP--;
        std::cout << ennemieHP << std::endl;
        if (ennemieHP <= 0)
        {
            std::cout << "ennemi mort";
            cube2.setPosition(1800.f, 60.f);
            FollowTarget(false);
            Destroy();
            //TODO DESTROY ENNEMIES
        }
	}
    if (other->CompareTag("Enemy"))
    {
		std::cout << "Collision of " << GetName() << " with enemy" << std::endl;
	}
}

void Enemies::Cube2Test()
{
    cube2.setSize(sf::Vector2f(30.f, 30.f));
    cube2.setFillColor(sf::Color::Blue);
    cube2.setPosition(sf::Vector2f(800, 400));
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
