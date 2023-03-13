#include "FollowTarget.h"


FollowTarget::FollowTarget()
{
}

FollowTarget::~FollowTarget()
{
}

void FollowTarget::Loop() {
    AggroSystem();
}

void FollowTarget::AggroSystem() {

    FollowPos = contextEnemy->cube2.getPosition();
    TargetPos = contextPlayer->cube.getPosition();
    RelatPos = TargetPos - FollowPos;

    distance = std::sqrt((TargetPos.x - FollowPos.x) * (TargetPos.x - FollowPos.x) +
        (TargetPos.y - FollowPos.y) * (TargetPos.y - FollowPos.y));

    if (distance < 300)
    {
        follow = true;
        //cube2.setFillColor(sf::Color::Blue);
        contextEnemy->cube2.move(0.01f * RelatPos);
    }
}