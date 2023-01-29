#include "menuHUD.h"

//Initialisation of all elements
menuHUD::menuHUD()
{
    selectionBck.setFillColor(sf::Color(153, 89, 7, 200));

    menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);

    title.setFont(heartless);
    title.setString("Crusade of the Abyss");
    title.setCharacterSize((screenSizeX * 80)/100);
    title.setCharacterSize(200);
    title.setFillColor(sf::Color(255, 255, 255, 255));   

    if (!font.loadFromFile("ressources/fonts/arial.ttf"));
    playFirstChoice.setFont(font);
    playFirstChoice.setCharacterSize(150);
    playFirstChoice.setFillColor(sf::Color(255, 255, 255, 255));

    playRect.setOutlineThickness(10);
    playRect.setOutlineColor(sf::Color::Red);
    playRect.setFillColor(sf::Color::Red);

    volume.setSize(sf::Vector2f(300, 25.f));
    volume.setFillColor(sf::Color::Blue);

    returnbutton.setSize(sf::Vector2f(50, 50));
    returnbutton.setFillColor(sf::Color::Red);

    screenResLow.setSize(sf::Vector2f(50, 50));
    screenResLow.setFillColor(sf::Color::Red);

    screenTxt.setString("1600*900 :");
    screenTxt.setCharacterSize(40);
    screenTxt.setFont(font);

    volumeTxtValue.setCharacterSize(40);

    play.begin();
    play.push_back(playFirstChoice);
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
    screenSizeX = float(oldScreenSize.x);
    screenSizeY = float(oldScreenSize.y);

    if (once) {
        selectionBck.setSize(sf::Vector2f((40 * screenSizeX) / 100, 600));
    }
    else if (!once) {
        selectionBck.setSize(sf::Vector2f((30 * screenSizeX) / 100, 400));
    }

    selectionBck.setOrigin(sf::Vector2f((selectionBck.getSize()) / 2.0f));
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

    title.setPosition(screenSizeX / 2.0f - titleBounds.width / 2, 10);
    win->draw(title);
}

//Text different Option
void menuHUD::menuTxt(sf::RenderWindow* win)
{
    std::vector <sf::String> string;
    string = { "Play", "Option", "Quit" };
    for (i = 0; i < 3; i++)
    {      
        play[i].setString(string[i]);
        //Option text       
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

        play.push_back(playFirstChoice);


        mousePos = sf::Mouse::getPosition(*win);

        //Detection selection + contain cursor mouse
        if (playBounds.contains(sf::Vector2f(mousePos.x , mousePos.y))) {
            if (detectedClick()) {
                switch (i)
                {
                case 0:
                    /* sm.SetActiveScene(1);*/
                    break;
                case 1:
                    once = false;
                    break;
                case 2:
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

//The bar for the volume
void menuHUD::Volume(sf::RenderWindow* win) {

    volumeTxt.setString("Volume :");
    volumeTxt.setFont(font);
    volumeTxt.setOrigin(volumeTxt.getGlobalBounds().width / 2, volumeTxt.getGlobalBounds().height / 2);
    volumeTxt.setCharacterSize(40);
    volumeTxt.setPosition(screenSizeX / 2.0f, (selectionBck.getPosition().y / 1.5));

    volume.setPosition(screenSizeX / 2.0f - volume.getSize().x / 2, (selectionBck.getPosition().y - 130));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && newVol >= 1) {
        newVol -= 1;
        volume.setScale(newVol /100, 1);
    }

    float scaleFactor = volume.getScale().x;
    scaleFactor *= 100.0f;
    std::string scaleFactorTxt = std::to_string(scaleFactor);
    scaleFactorTxt.erase(3, 9);
    volumeTxtValue.setString(scaleFactorTxt);
    volumeTxtValue.setPosition(volume.getPosition().x + volume.getSize().x, volume.getPosition().y - volume.getSize().y /2);
    volumeTxtValue.setFont(font);
    win->draw(volumeTxtValue);
    win->draw(volumeTxt);
    win->draw(volume);
}

//Quit the option
void menuHUD::GoBack(sf::RenderWindow* win) {
    mousePos = sf::Mouse::getPosition(*win);
    returnbutton.setPosition(selectionBck.getPosition().x - selectionBck.getSize().x / 2, selectionBck.getPosition().y - selectionBck.getSize().y / 2);
    returnGlobalPos = returnbutton.getGlobalBounds();
    if (returnGlobalPos.contains(sf::Vector2f(mousePos.x, mousePos.y))) {
        if (detectedClick()) {
            once = true;
        }
    }
    win->draw(returnbutton);
}

void menuHUD::ChangeResolution(sf::RenderWindow* win) {
    screenTxt.setPosition(volume.getPosition().x, volume.getPosition().y + 50);
    win->draw(screenTxt);

    screenResLow.setPosition(volume.getPosition().x + volume.getSize().x - screenResLow.getSize().x, volume.getPosition().y +50);
    buttonChangeRect = screenResLow.getGlobalBounds();
    if (buttonChangeRect.contains(sf::Vector2f(mousePos.x, mousePos.y))) {
        if (detectedClick()) {
            win->create(sf::VideoMode(1600, 900), "Crusade Of The Abyss", sf::Style::Fullscreen);
            screenResLow.setFillColor(sf::Color::Blue);
        }
    }
    win->draw(screenResLow);
}

void menuHUD::Language(sf::RenderWindow* win) {
    languageTxt.setString("Langage :");
    languageTxt.setCharacterSize(40);
    languageTxt.setFont(font);

    languageOptionEN.setSize(sf::Vector2f(50,50));
    languageOptionEN.setFillColor(sf::Color::Red);
    languageOptionEN.setPosition(volume.getPosition().x + volume.getSize().x - languageOptionEN.getSize().x, volume.getPosition().y + 125);

    languageOptionFR.setSize(sf::Vector2f(50, 50));
    languageOptionFR.setFillColor(sf::Color::Red);
    languageOptionFR.setPosition(volume.getPosition().x + volume.getSize().x - languageOptionEN.getSize().x * 2 - 10, volume.getPosition().y + 125);

    languageTxt.setPosition(volume.getPosition().x, volume.getPosition().y + 125);

    win->draw(languageTxt);
    win->draw(languageOptionEN);
    win->draw(languageOptionFR);
}