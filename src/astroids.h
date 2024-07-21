#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <math.h>
#include <sstream> 
#include <vector>
#include "Global.h"
#include "SFML/Graphics.hpp"
#include <random>

using namespace sf;
class Speedastroids
{
	//POWER ASTROID

	//std::vector<sf::Sprite> astroids_m;

public:
	

	Sprite Speedastroid;
	int astroidSpawner = 0;
	std::vector<sf::Sprite> Speedastroids_m;
	int spawnRand = rand() % 10000+ 800;



       



	Speedastroids(std::string imgdirectory) {
		if (!SpeedastroidTexture.loadFromFile(imgdirectory)) {
			std::cout << "Error/n";


		}
		
		Speedastroid.setTexture(SpeedastroidTexture);
		Speedastroid.setTextureRect(IntRect(96, 32, 111, 51));
		Speedastroid.setScale(Vector2f(2, 2));
		//astroid.setPosition(Vector2f(Screenwidth / 2, Screenheight / 2));



		





		
		
			





	}
	void draw(sf::RenderWindow& window);
	void update(std::string direction);

	


private:
	Texture SpeedastroidTexture;



};

