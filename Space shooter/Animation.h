#pragma once
#include "SFML/Graphics.hpp"
#include <chrono>
class Animation
{

public:

	sf::IntRect uvRect;
	
	Animation(sf::Texture* texture, sf::Vector2u imagecount, float switchTime);
	~Animation();



	void Update(int row, float deltaTime);







	









private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float totalTime;
	float switchTime;







};

