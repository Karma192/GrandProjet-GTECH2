#include "menuHUD.h"

//Initialisation of all elements
menuHUD::menuHUD()
{
    selectionBck.setFillColor(sf::Color(144, 144, 144, 200));

    menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);

    if (!Antique.loadFromFile("ressources/fonts/Antique.ttf"));
    title.setFont(Antique);
    title.setString("Crusade of the Abyss");
    title.setCharacterSize(130);

    if (!font.loadFromFile("ressources/fonts/arial.ttf"));
    playFirstChoice.setFont(font);
    playFirstChoice.setCharacterSize(150);
    playFirstChoice.setFillColor(sf::Color(255, 255, 255, 255));

    playRect.setOutlineThickness(3);
    playRect.setOutlineColor(sf::Color::Black);
    playRect.setFillColor(sf::Color(130, 130, 130, 255));

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

    volumeTxt.setString("Volume :");
    volumeTxt.setFont(font);
    volumeTxt.setCharacterSize(40);

    languageTxt.setString("Langage :");
    languageTxt.setCharacterSize(40);
    languageTxt.setFont(font);

    languageOptionEN.setSize(sf::Vector2f(50, 50));
    languageOptionEN.setFillColor(sf::Color::Red);

    languageOptionFR.setSize(sf::Vector2f(50, 50));
    languageOptionFR.setFillColor(sf::Color::Red);

    play.begin();
    play.push_back(playFirstChoice); 
}

menuHUD::~menuHUD()
{

}

void menuHUD::Loop() 
{

}

void menuHUD::Render() 
{
    gameData = GetGameData();
    gameData.window->draw(menuBckSprite);
    menuSelection();
    menuTitle();
    if (optionOn)
    {
        menuTxt();
    }
    else 
    {
        Volume();
        GoBack();
        ChangeResolution();
        Language();
    }
}

bool menuHUD::collidesWith(CollisionObject* other)
{
    return false;
}

void menuHUD::handleCollision(CollisionObject* other)
{
}

void menuHUD::menuSelection()
{
    oldScreenSize = gameData.window->getSize();
    screenSizeX = float(oldScreenSize.x);
    screenSizeY = float(oldScreenSize.y);

    if (optionOn) {
        selectionBck.setSize(sf::Vector2f((40 * screenSizeX) / 100, 600));
    }
    else if (!optionOn) {
        selectionBck.setSize(sf::Vector2f((30 * screenSizeX) / 100, 400));
    }

    selectionBck.setOrigin(sf::Vector2f((selectionBck.getSize()) / 2.0f));
    selectionBck.setPosition(screenSizeX / 2.0f, screenSizeY / 2.0f);
    gameData.window->draw(selectionBck);
}

void menuHUD::menuTitle()
{
    if (!this->heartless.loadFromFile("ressources/fonts/Heartless.ttf"))
    {
        //std::cout << "Error TTF Title Font" << std::endl;
    }

    titleBounds = title.getLocalBounds();

    title.setPosition(screenSizeX / 2.0f - titleBounds.width / 2, 10);
    gameData.window->draw(title);
}

//Text different Option
void menuHUD::menuTxt()
{
    std::vector <sf::String> string;
    string = { "Play", "Option", "Quit" };
    for (i = 0; i < 3; i++)
    {      
        play[i].setString(string[i]);
        //Option text       
        sf::FloatRect playbuttonBounds = play[i].getLocalBounds();
        play[i].setOrigin(playbuttonBounds.left + playbuttonBounds.width / 2, playbuttonBounds.top + playbuttonBounds.height / 2);
        play[i].setPosition(screenSizeX / 2.0f, (selectionBck.getPosition().y / 1.5) + i * 190);

        //Background rect
        playRect.setSize(sf::Vector2f(play[i].getGlobalBounds().width, play[i].getGlobalBounds().height));
        playRect.setScale(1.10, 1.10);
        playBounds = play[i].getGlobalBounds();
        float x = playBounds.width / 2;
        float y = playBounds.height / 2;
        playRect.setOrigin(x, y);
        playRect.setPosition(play[i].getPosition());

        gameData.window->draw(playRect);
        gameData.window->draw(play[i]);

        play.push_back(playFirstChoice);


        mousePos = sf::Mouse::getPosition(*gameData.window);

        //Detection selection + contain cursor mouse
        if (playBounds.contains(sf::Vector2f(mousePos.x , mousePos.y))) {
            if (detectedClick()) {
                switch (i)
                {
                case 0:
                    SetActiveScene(LOBBY);
                    break;
                case 1:
                    optionOn = false;
                    break;
                case 2:
                    gameData.window->close();
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
void menuHUD::Volume() {
    volumeTxt.setOrigin(volumeTxt.getGlobalBounds().width / 2, volumeTxt.getGlobalBounds().height / 2);
    volumeTxt.setPosition(screenSizeX / 2.0f, (selectionBck.getPosition().y / 1.5));

    volume.setPosition(volumeTxt.getPosition().x - volume.getSize().x / 2, volumeTxt.getPosition().y + 40);

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
    gameData.window->draw(volumeTxtValue);
    gameData.window->draw(volumeTxt);
    gameData.window->draw(volume);
}

//Quit the option
void menuHUD::GoBack() {
    mousePos = sf::Mouse::getPosition(*gameData.window);
    returnbutton.setPosition(selectionBck.getPosition().x - selectionBck.getSize().x / 2, selectionBck.getPosition().y - selectionBck.getSize().y / 2);
    returnGlobalPos = returnbutton.getGlobalBounds();
    if (returnGlobalPos.contains(sf::Vector2f(mousePos.x, mousePos.y))) {
        if (detectedClick()) {
            optionOn = true;
        }
    }
    gameData.window->draw(returnbutton);
}


//Swap the screen resolution
void menuHUD::ChangeResolution() {
    screenTxt.setPosition(volume.getPosition().x, volume.getPosition().y + 50);
    gameData.window->draw(screenTxt);

    screenResLow.setPosition(volume.getPosition().x + volume.getSize().x - screenResLow.getSize().x, volume.getPosition().y +50);
    buttonChangeRect = screenResLow.getGlobalBounds();
    if (buttonChangeRect.contains(sf::Vector2f(mousePos.x, mousePos.y))) {
        if (detectedClick() && screenResLow.getFillColor() == sf::Color::Red) {
            gameData.window->create(sf::VideoMode(1600, 900), "Crusade Of The Abyss", sf::Style::Fullscreen);
            screenResLow.setFillColor(sf::Color::Blue);
        }
        else if (detectedClick() && screenResLow.getFillColor() == sf::Color::Blue) {
            gameData.window->create(sf::VideoMode(1920, 1080), "Crusade Of The Abyss", sf::Style::Fullscreen);
        }
    }
    gameData.window->draw(screenResLow);
}

//Change the language
void menuHUD::Language() {
    languageOptionEN.setPosition(volume.getPosition().x + volume.getSize().x - languageOptionEN.getSize().x, volume.getPosition().y + 125);

    languageOptionFR.setPosition(volume.getPosition().x + volume.getSize().x - languageOptionEN.getSize().x * 2 - 10, volume.getPosition().y + 125);

    languageTxt.setPosition(volume.getPosition().x, volume.getPosition().y + 125);

    gameData.window->draw(languageTxt);
    gameData.window->draw(languageOptionEN);
    gameData.window->draw(languageOptionFR);
}
