#include "player.h"


void player::drawPlayer(sf::RenderWindow& window)
{


	
	window.draw(playerSprite);

	// Draw the remaining heart sprites

	  // Draw the remaining heart sprites
	for (const auto& heart : health) {
		window.draw(heart);
	}

	

}

void player::movement(std::string direction)
{


	//player movement calculations based on the player accell and speed variables
	if (direction == "RIGHT") {
		playerSprite.move(playerSpeed += PLAYER_ACCELERATION, 0);
		//playerSprite.rotate(playerSpeed+=PLAYER_ACCELERATION);
		//playerSprite.rotate(playerAngle += rotationRate);
		//playerSprite.setRotation(0);
		if (playerSpeed > PLAYER_MAX_SPEED)
		{
			playerSpeed = PLAYER_MAX_SPEED;
		}
	}
	else if (direction == "LEFT") {
		playerSprite.move(playerSpeed -= PLAYER_ACCELERATION, 0);
		//playerSprite.rotate(playerSpeed-+PLAYER_ACCELERATION);
		//playerSprite.rotate(playerAngle -= rotationRate);
		//playerSprite.setRotation(180);
		if (playerSpeed < -PLAYER_MAX_SPEED) {
			playerSpeed = -PLAYER_MAX_SPEED;
		}
	}
	
	else {

		// Neither forward nor backward pressed
		if (playerSpeed < 0) {
			playerSpeed += PLAYER_ACCELERATION;
			if (playerSpeed >= 0) {
				playerSpeed = 0.0f;
			}
		}
		else {
			playerSpeed -= PLAYER_ACCELERATION;
			if (playerSpeed <= 0) {
				playerSpeed = 0.0f;
			}
		}


		if (direction == "UP") {
			playerSprite.move(0, playerSpeed -= PLAYER_ACCELERATION);
			//playerSprite.setRotation(360);
			playerGoingUp = true;
			//playerSprite.setTextureRect(sf::IntRect(16, 16, 31, 31));
			if (playerGoingUp = true) {
				std::cout << "UP\n";
			}
			if (playerSpeed < -PLAYER_MAX_SPEED) {
				playerSpeed = -PLAYER_MAX_SPEED;
			}
		}

		else if (direction == "DOWN") {
			playerSprite.move(0, playerSpeed += PLAYER_ACCELERATION);
			//playerSprite.setRotation(0);
			if (playerSpeed < PLAYER_MAX_SPEED)
				playerSpeed = PLAYER_MAX_SPEED;
		}
		if (playerSpeed < 0) {
			playerSpeed += PLAYER_ACCELERATION;
			if (playerSpeed >= 0) {
				playerSpeed = 0.0f;
			}
		}
		else {
			playerSpeed -= PLAYER_ACCELERATION;
			if (playerSpeed <= 0) {
				playerSpeed = 0.0f;
			}
		}
		playerCenter = playerSprite.getPosition();



		/*if (direction == "THRUST") {
			playerSprite.move(0, (playerSpeed -= PLAYER_ACCELERATION)*10); //THRUST FEATURE TO BE ADDED WORRY ON CHARACTERS NORMAL MOVEMENT ASSIGNED TO SHIFT
		}*/


	}
}

void player::takeDamage(int damage)
{
	//playerHealth -= damage; increments the damage
	maxHealth -= damage;
	// Remove a heart sprite from the array
	if (!health.empty()) {
		health.pop_back();
	}

	//int heartsToRemove = maxHearts / 1;
	


}


void player::heal(int healing)
{
	maxHealth += healing;

	// Make sure playerHealth doesn't exceed 3 hearts
	if (maxHealth > 3) {
		maxHealth = 3;
	}

	// Add a heart sprite to the array for each point of healing
	for (int i = 0; i < healing; ++i) {
		// Add a heart sprite to the 'health' array (assuming you have a way to do this)
		
		health.push_back(healthBar);

	}


}


