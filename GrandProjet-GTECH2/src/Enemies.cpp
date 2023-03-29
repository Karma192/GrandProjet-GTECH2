#include "Enemies.hpp"

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
    gameData = GetGameData();
    gameData.window->draw(playerSlime);
}

bool Enemies::collidesWith(CollisionObject* other)
{
    if (Player* player = dynamic_cast<Player*>(other)) {
        if (playerSlime.getGlobalBounds().intersects(player->playerSprite.getGlobalBounds())) {
            return true;
        }
    }

    return false;
}

void Enemies::handleCollision(CollisionObject* other)
{
    if (dynamic_cast<Player*>(other)) {
        std::cout << "dinguerie";
    }
}

void Enemies::DisplaySlime()
{
    animationSlime.InitAnimation("ressources/sprites/enemy/slime/slime_sprite_sheet.png", &playerSlime, 3.f, 32, 32);

    playerSlime.setPosition(sf::Vector2f(600, 350));
}

void Enemies::FollowTarget(bool)
{
    ////Radius for Aggro
    ////interval for aggro
    //sf::Clock clock;
    //float interval = 0.001f;
    //sf::Vector2f TargetPos = contextPlayer->cube.getPosition();
    //sf::Vector2f FollowPos = cube2.getPosition();
    //sf::Vector2f RelatPos = TargetPos - FollowPos;
    //float deltaLength = std::sqrt(RelatPos.x * RelatPos.x + RelatPos.y * RelatPos.y);
    //if (deltaLength > followRadius) {
    //    cube2.move(.005f * RelatPos);
    //}
    //clock.restart();

    //distance = std::sqrt((TargetPos.x - FollowPos.x) * (TargetPos.x - FollowPos.x) +
    //    (TargetPos.y - FollowPos.y) * (TargetPos.y - FollowPos.y));


    //if (distance <= 600 && follow)
    //{
    //    cube2.setFillColor(sf::Color::Blue);
    //    follow = true;
    //    cube2.move(.02f * RelatPos);
    //    //MoveBase(false);
    //}
    //else {
    //    cube2.setFillColor(sf::Color::Green);
    //}
}

//void Enemies::GetStunned()
//{
//    Player* contextPlayer;
//    sf::FloatRect rect = contextPlayer->hitboxTest.getGlobalBounds();
//    sf::FloatRect rect2 = cube2.getGlobalBounds();
//    if (contextPlayer->IsAttacking) {
//        if (IsDamaged(rect, rect2)) {
//            follow = false;
//            clock2.restart();
//        }
//    }
//    if (clock2.getElapsedTime().asSeconds() > 2.f) {
//        follow = true;
//    }
//}
