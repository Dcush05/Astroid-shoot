#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <math.h>
#include <sstream> 
#include <vector>
#include "Animation.h"
//#include "Global.h"




using namespace sf;



class player
{



public:
	Sprite playerSprite;
	Texture playerTexture;
	sf::Clock clock;
	float velocity;
	float PLAYER_MAX_SPEED = 6.f;
	float PLAYER_ACCELERATION = 1.f;
	float playerSpeed = 3.0f;
	double rotationRate = 4 * M_PI / 180;
	float playerAngle = 1 * M_PI / 180;
	sf::Vector2f playerCenter;
	int shootTimer = 0;
	bool isAlive = true;
	std::vector<sf::Sprite> ship;
	bool playerGoingUp = false;
	sf::Vector2f playerPosition;
	//Animation idle;
	float deltaTime = 0.f;

	
	int maxHealth = 3; //the amount of hearts shown on screen





	player(std::string imgdirectory ) {
		if (!playerTexture.loadFromFile(imgdirectory)) {
			std::cout << "Error/n";


		}
		//std::cout << "Health: " << playerHealth << '\n';

		//Animation
		//sf::IntRect Animation(0,0,16,16);
		sf::Vector2u textureSize = playerTexture.getSize();
		textureSize.x /= 8;
		textureSize.y /= 8;
		playerPosition.x = 630;
		playerPosition.y = 600;
	

		playerSprite.setTexture(playerTexture);
		playerSprite.setTextureRect(sf::IntRect(0, 0, 15, 15));
		//playerSprite.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y)); //(0,0,16,16)
		// playerSprite.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
		 //playerSprite.setTextureRect(sf::IntRect(0,0,16,16));
		playerSprite.setPosition(Vector2f(playerPosition));
		playerSprite.getGlobalBounds();
		playerSprite.setScale(Vector2f(2.5, 2.5));
		playerCenter = Vector2f(playerSprite.getPosition().x, (playerSprite.getPosition().y));


		
		

		//health bar texture
		if (!healthBarTexture.loadFromFile("Assets/health.png")) {
			// Handle error
		}
		for (int i = 0; i < maxHealth; ++i){
		healthBar.setTexture(healthBarTexture);
		healthBar.setTextureRect(sf::IntRect(0, 0, 16, 16));
		healthBar.setPosition(10+i*healthBar.getGlobalBounds().width, 630);
		health.push_back(healthBar);
	}
		
	}

		void drawPlayer(sf::RenderWindow & window);
		void movement(std::string direction);
		void takeDamage(int damage);
		void heal(int heal);

private:
	
	//Sprite health;
	sf::Sprite healthBar;
	sf::Texture healthBarTexture;
	std::vector<sf::Sprite> health; 
	

	

};
