#pragma once
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

class Dialogue
{
public:
	void dialogue(sf::RenderWindow* win, std::list<sf::String> textList, int characterSize);

	void dialogueStart(sf::RenderWindow* win);
	void textWriting(std::list<sf::String> text, int size);
	void dialogueFinished();

	void dialogueChoiceStart(sf::RenderWindow* win, int characterSize);



private:
	sf::Texture dialogueBoxTexture;
	sf::Sprite dialogueBox;

	sf::Texture dialogueChoiceBoxTexture;
	sf::Sprite dialogueChoiceBox;
	
	sf::Font policeDialogue;
	sf::Text dialogue;

};

