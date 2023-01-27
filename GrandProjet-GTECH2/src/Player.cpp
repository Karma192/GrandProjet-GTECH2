#include "Player.hpp"

Player::Player()
{
    playerSprite.setPosition(0, 0);
    ControllerInput();
}

Player::~Player() 
{

}

void Player::PlayerLoop() 
{
    playerEndurance();
    playerRegenEndurance();
    ControllerMove();
}

void Player::PlayerRender(sf::RenderWindow* win)
{
    playerUI(win);
    //win->draw(enduranceBarBack);
    win->draw(enduranceBar);
    win->draw(lifeBar);
    win->draw(playerUltiUI);
    win->draw(playerFirstSpell);
    win->draw(playerSecondSpell);
    win->draw(playerThirdSpell);
    win->draw(cube);
    setCamera(win);
}

void Player::playerEndurance()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && cd_Endurance >= 2 && endurancePlayer > 0)
    {
        endurancePlayer -= 0.1;
        std::cout << "Il te reste " << endurancePlayer << "de point d'endurance" << std::endl;
        enduranceBar.setScale(endurancePlayer / 100, 1);
    }
    if (endurancePlayer <= 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        std::cout << "Tu peux plus courir" << std::endl;
    }


}

void Player::playerRegenEndurance()
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && endurancePlayer <= 100)
    {
        endurancePlayer += 0.1;
        enduranceBar.setScale(endurancePlayer / 100, 1);
        std::cout << "REGEN ENDURANCE : " << endurancePlayer << std::endl;
    }

}

void Player::playerUI(sf::RenderWindow* win)
{
    enduranceBar.setSize(sf::Vector2f(300.f, 25.f));
    enduranceBar.setFillColor(sf::Color::Blue);
    sf::Vector2f enduranceBarV = win->mapPixelToCoords(sf::Vector2i(2, 830));
    enduranceBar.setPosition(enduranceBarV);

    /*enduranceBarBack.setSize(sf::Vector2f(300.f, 25.f));
    enduranceBarBack.setFillColor(sf::Color::Black);
    enduranceBarBack.setPosition(2, 2);*/

    lifeBar.setSize(sf::Vector2f(300.f, 25.f));
    lifeBar.setFillColor(sf::Color::Green);
    sf::Vector2f lifeBarV = win->mapPixelToCoords(sf::Vector2i(2, 800));
    lifeBar.setPosition(lifeBarV);

    playerUltiUI.setRadius(40);
    playerUltiUI.setFillColor(sf::Color::Transparent);
    playerUltiUI.setOutlineThickness(5);
    playerUltiUI.setOutlineColor(sf::Color::Yellow);
    sf::Vector2f playerUltiUIV = win->mapPixelToCoords(sf::Vector2i(30,880));
    playerUltiUI.setPosition(playerUltiUIV);

    playerFirstSpell.setRadius(20);
    playerFirstSpell.setFillColor(sf::Color::Transparent);
    playerFirstSpell.setOutlineThickness(5);
    playerFirstSpell.setOutlineColor(sf::Color::Green);
    sf::Vector2f PlayerFirstSpellV = win->mapPixelToCoords(sf::Vector2i(140, 920));
    playerFirstSpell.setPosition(PlayerFirstSpellV);

    playerSecondSpell.setRadius(20);
    playerSecondSpell.setFillColor(sf::Color::Transparent);
    playerSecondSpell.setOutlineThickness(5);
    playerSecondSpell.setOutlineColor(sf::Color::Green);
    sf::Vector2f playerSecondSpellV = win->mapPixelToCoords(sf::Vector2i(200, 920));
    playerSecondSpell.setPosition(playerSecondSpellV);

    playerThirdSpell.setRadius(20);
    playerThirdSpell.setFillColor(sf::Color::Transparent);
    playerThirdSpell.setOutlineThickness(5);
    playerThirdSpell.setOutlineColor(sf::Color::Green);
    sf::Vector2f playerThirdSpellV = win->mapPixelToCoords(sf::Vector2i(260, 920));
    playerThirdSpell.setPosition(playerThirdSpellV);
}

void  Player::ControllerInput()
{
    cube.setSize(sf::Vector2f(30.f, 30.f));
    cube.setFillColor(sf::Color::Red);
    cube.setPosition(sf::Vector2f(200, 200));
}

void Player::ControllerMove()
{
    float deadZone = 20.f;
    moveSpeed.x = (sf::Joystick::getAxisPosition(0, sf::Joystick::X));
    moveSpeed.y = (sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

    if (moveSpeed.x < -deadZone)
    {
        sf::Joystick::update();
        MovePlayer();
    }
    else if (moveSpeed.x > deadZone)
    {
        sf::Joystick::update();
        MovePlayer();
    }
    else if (moveSpeed.y < -deadZone)
    {
        sf::Joystick::update();
        MovePlayer();
    }
    else if (moveSpeed.x > deadZone)
    {
        sf::Joystick::update();
        MovePlayer();
    }
}

void Player::MovePlayer() {
    cube.move(moveSpeed.x / playerSpeed, moveSpeed.y / playerSpeed);
}

void Player::setCamera(sf::RenderWindow* win) {
    view = win->getDefaultView();
    view.setCenter(cube.getPosition());
    win->setView(view);
}

//Je test des trucs sur le Player, celà sera supprimé (Etienne)
//void Player::PlayerTest(sf::RenderWindow* win)
//{
//    playerTexture.loadFromFile("C:/Users/etien/Pictures/amongus.png");
//    if (!playerTexture.loadFromFile("C:/Users/etien/Pictures/amongus.png"))
//    {
//        std::cout << "y'a pas d'image" << std::endl;
//    }
//    playerSprite.setTexture(playerTexture);
//    win->draw(playerSprite);
//    std::cout << "player:" << playerSprite.getGlobalBounds().width << std::endl;
//}