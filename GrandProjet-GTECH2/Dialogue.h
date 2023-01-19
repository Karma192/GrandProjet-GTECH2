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



private:
	sf::Texture dialogueBoxTexture;
	sf::Sprite dialogueBox;
	
	sf::Font policeTexte;
	sf::Text texteEcrit;

};

