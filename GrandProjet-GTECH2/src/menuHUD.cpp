#include "menuHUD.h"

//Initialisation of all elements
menuHUD::menuHUD()
{
    selectionBck.setFillColor(sf::Color(153, 89, 7, 200));
    selectionBck.setSize(sf::Vector2f(600, 600));

    menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);

    title.setFont(heartless);
    title.setString("Crusade of the Abyss");
    title.setCharacterSize(200);
    title.setFillColor(sf::Color(255, 255, 255, 255));   

    if (!font.loadFromFile("ressources/fonts/arial.ttf"));
    playtest.setFont(font);
    playtest.setCharacterSize(150);
    playtest.setFillColor(sf::Color(255, 255, 255, 255));

    playRect.setOutlineThickness(10);
    playRect.setOutlineColor(sf::Color::Red);
    playRect.setFillColor(sf::Color::Red);
}

menuHUD::~menuHUD()
{
}

//Background menu
void menuHUD::menuRender(sf::RenderWindow* win) {

    win->draw(menuBckSprite);
}

//Background for Option
void menuHUD::menuSelection(sf::RenderWindow* win)
{
    oldScreenSize = win->getSize();
    selectionBck.setOrigin(sf::Vector2f((selectionBck.getSize()) / 2.0f));
    screenSizeX = float(oldScreenSize.x);
    screenSizeY = float(oldScreenSize.y);

    selectionBck.setPosition(screenSizeX / 2.0f, screenSizeY / 2.0f);
    win->draw(selectionBck);
}

//Title of the game
void menuHUD::menuTitle(sf::RenderWindow* win)
{
    if (!this->heartless.loadFromFile("ressources/fonts/Heartless.ttf"))
    {
        std::cout << "Error TTF Title Font" << std::endl;
    }

    titleBounds = title.getLocalBounds();
    title.setOrigin(titleBounds.width / 2, titleBounds.height / 2);

    title.setPosition(screenSizeX / 2.0f, 100);
    win->draw(title);
}

//Text different Option
void menuHUD::menuTxt(sf::RenderWindow* win)
{
    play.begin();
    play.push_back(playtest);
    std::vector <sf::String> string;
    string = { "Play", "Option", "Quit" };
    for (i = 0; i < 3; i++)
    {       
        //Option text
        play[i].setString(string[i]);
        sf::FloatRect playbuttonBounds = play[i].getLocalBounds();
        play[i].setOrigin(playbuttonBounds.left + playbuttonBounds.width / 2, playbuttonBounds.top + playbuttonBounds.height / 2);
        play[i].setPosition(screenSizeX / 2.0f, (selectionBck.getPosition().y / 1.5) + i * 200);

        //Background rect
        playRect.setSize(sf::Vector2f(play[i].getGlobalBounds().width, play[i].getGlobalBounds().height));
        playBounds = play[i].getGlobalBounds();
        float x = playBounds.width / 2;
        float y = playBounds.height / 2;
        playRect.setOrigin(x, y);
        playRect.setPosition(play[i].getPosition());

        win->draw(playRect);
        win->draw(play[i]);

        play.push_back(playtest);


        sf::Vector2i mousePos = sf::Mouse::getPosition(*win);
        sf::Vector2f pointfloat(mousePos);

        //Detection selection + contain cursor mouse
        if (playBounds.contains(pointfloat)) {
            std::cout << "collision detected" << std::endl;
            if (detectedClick()) {
                std::cout << "clicked";
                switch (i)
                {
                case 0:
                    std::cout << "play" << std::endl;
                    /* sm.SetActiveScene(1);*/
                    break;
                case 1:
                    std::cout << "option" << std::endl;
                    break;
                case 2:
                    std::cout << "quit" << std::endl;
                    win->close();
                    break;
                default:
                    break;
                }              
            }
        }
    }
}

//Detection for Click
bool menuHUD::detectedClick() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return true;
    }
}