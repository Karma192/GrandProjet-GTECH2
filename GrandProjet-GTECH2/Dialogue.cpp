#include "Dialogue.h"


void Dialogue::dialogue(sf::RenderWindow* win, std::list<sf::String> textList, int characterSize)
{
	dialogueStart(win);
	textWriting(textList, characterSize);
}

// Create the dialogue box
void Dialogue::dialogueStart(sf::RenderWindow* win)
{
	if (!dialogueBoxTexture.loadFromFile("dialogue_layout.jpg"))
	{
		std::cout << "Error while loading dialogue_layout.jpg";
	}

	dialogueBox.setTexture(dialogueBoxTexture);
	dialogueBox.setPosition(sf::Vector2f(10, 50));
	dialogueBox.setScale(sf::Vector2f(0.5f, 2.f));
	win->draw(dialogueBox);

}


// Import the dialogues in and write them
// (make use of a list of sf::String)
void Dialogue::textWriting(std::list<sf::String> textList, int size)
{
	texteEcrit.setFont(policeTexte);
	texteEcrit.setCharacterSize(size);
	texteEcrit.setColor(sf::Color::White);

	texteEcrit.setPosition(dialogueBox.getPosition());

	for (int i = 0; i < textList.size(); i++) 
	{
		texteEcrit.setString("textList[i]");
	}

}

void Dialogue::dialogueFinished()
{
}
