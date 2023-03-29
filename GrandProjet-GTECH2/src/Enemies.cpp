#include "Enemies.hpp"
#include "GameMaster.hpp"

Enemies::Enemies()
{
    DisplaySlime();
}

Enemies::~Enemies()
{

}

void Enemies::Loop() 
{
    //GetStunned();
    FollowTarget(follow);

    animationSlime.Animate(4, 7, 1, 1, 0.2f, false);
}

void Enemies::Render() 
{
    GameMaster::GetInstance()->GetGameData().window->draw(enemySlime);
}

bool Enemies::collidesWith(CollisionObject* other)
{
    if (Player* player = dynamic_cast<Player*>(other)) 
    {
        TargetPos = player->playerSprite.getPosition();
        if (enemySlime.getGlobalBounds().intersects(player->cube.getGlobalBounds())) 
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
        std::cout << ennemieHP << std::endl;
        if (ennemieHP <= 0)
        {
            std::cout << "ennemi mort";
            enemySlime.setPosition(1800.f, 60.f);
            FollowTarget(false);
            //TODO DESTROY ENNEMIES
        }
    }
}

void Enemies::DisplaySlime()
{
    animationSlime.InitAnimation("ressources/sprites/enemy/slime/slime_sprite_sheet.png", &enemySlime, 3.f, 32, 32);

    enemySlime.setPosition(sf::Vector2f(600, 350));
}

void Enemies::FollowTarget(bool)
{
    //Radius for Aggro
    //interval for aggro
    sf::Vector2f FollowPos = enemySlime.getPosition();
    sf::Vector2f RelatPos = TargetPos - FollowPos;
    distance = std::sqrt((TargetPos.x - FollowPos.x) * (TargetPos.x - FollowPos.x) +
        (TargetPos.y - FollowPos.y) * (TargetPos.y - FollowPos.y));


    if (distance <= 150)
    {
        follow = true;
        //cube2.setFillColor(sf::Color::Blue);
        enemySlime.move(.02f * RelatPos);
    }
    else 
    {
        follow = false;
        //cube2.setFillColor(sf::Color::Green);
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
