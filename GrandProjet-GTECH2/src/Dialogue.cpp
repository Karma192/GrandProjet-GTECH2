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
	dialogue.setFont(policeDialogue);
	dialogue.setCharacterSize(size);
	dialogue.setColor(sf::Color::White);

	dialogue.setPosition(dialogueBox.getPosition());

	for (int i = 0; i < textList.size(); i++) 
	{
		dialogue.setString("textList[i]");
	}

}

void Dialogue::dialogueFinished()
{
	if (!dialogueChoiceBoxTexture.loadFromFile("dialogue_layout.jpg"))
	{
		std::cout << "Error while loading dialogue_layout.jpg";
	}

	dialogueChoiceBox.setTexture(dialogueChoiceBoxTexture);
	dialogueChoiceBox.setPosition(sf::Vector2f(100, 250));
	dialogueChoiceBox.setScale(sf::Vector2f(0.25f, 1.f));
	win->draw(dialogueChoiceBox);
}
