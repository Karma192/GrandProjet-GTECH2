#include "Enemies.hpp"
#include "GameMaster.hpp"

Enemies::Enemies()
{
    Cube2Test();
    this->ennemieHP = 10;
}

Enemies::~Enemies()
{

}

void Enemies::Loop() 
{
    //GetStunned();
    FollowTarget(follow);

    animationSlime.Animate(frameIndexIdle, 0.2f, true, false, 0);
}

void Enemies::Render() 
{
    GameMaster::GetInstance()->GetGameData().window->draw(cube2);
}

bool Enemies::collidesWith(CollisionObject* other)
{
    if (Player* player = dynamic_cast<Player*>(other)) 
    {
        TargetPos = player->cube.getPosition();
        if (cube2.getGlobalBounds().intersects(player->hitboxTest.getGlobalBounds())) 
        {
            return true;
        }
    }
    if (Spells* spells = dynamic_cast<Spells*>(other))
    {
        int enemyDamage = spells->GetThirdSpellDamage();

        if (cube2.getGlobalBounds().intersects(spells->_hitboxThirdSpell.getGlobalBounds()))
        {
            return true;
        }
    }


    return false;
}

void Enemies::handleCollision(CollisionObject* other)
{
    if (dynamic_cast<Player*>(other)) 
    {
        ennemieHP--;
        if (ennemieHP <= 0)
        {
            std::cout << "ennemi mort";
            cube2.setPosition(1800.f, 60.f);
            FollowTarget(false);
            //TODO DESTROY ENNEMIES
        }
    }
    if (dynamic_cast<Spells*>(other))
    {
        ennemieHP--;
        if (ennemieHP <= 0)
        {
            std::cout << "ennemi mort";
            cube2.setPosition(1800.f, 60.f);
            FollowTarget(false);
            //TODO DESTROY ENNEMIES
        }
    }
}

void Enemies::Cube2Test()
{
    animationSlime.LoadAnimation("ressources/sprites/slime/slime_tilesheet.png", &cube2, 32, 32, 3.f);

    frameIndexIdle = { 0, 1, 2, 3 };
    frameIndexRun = { 7, 8, 9, 10, 11, 12 };
    frameIndexAttack = { 14, 15, 16, 17, 18, 19, 20 };
    frameIndexDie = { 27, 28, 29, 30, 31 };

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
        cube2.move(.02f * RelatPos);
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
