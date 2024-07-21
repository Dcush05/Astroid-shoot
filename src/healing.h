#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <random>
class healing
{



public:
	sf::Sprite healingSprite;
	std::vector<sf::Sprite> healingSprites_m;
	int healingSpawner = 0;
	int spawnRand = rand() % 1000 + 100; //adjust
	int healingAmount = 1;



	healing(std::string imgDirectory) {


		if (!healingTexture.loadFromFile(imgDirectory)) {
			std::cout << "Error/n";

		}


		healingSprite.setTexture(healingTexture);
		healingSprite.setTextureRect(sf::IntRect(31, 47, 48, 64));
		healingSprite.setScale(2, 2);







	}
	void draw(sf::RenderWindow& window);



private:

	sf::Texture healingTexture;


};

