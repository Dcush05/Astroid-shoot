#include "healing.h"

void healing::draw(sf::RenderWindow& window)
{

	//window.draw(healingSprite);
    healingSprites_m.push_back(sf::Sprite(healingSprite));

    if (healingSpawner < spawnRand)
        healingSpawner++;

    if (healingSpawner >= spawnRand)
    {

        healingSprite.setPosition((rand() % int(window.getSize().x - healingSprite.getScale().x)), 0.f);
        healingSprites_m.push_back(sf::Sprite(healingSprite));
        healingSpawner = 0;
    }

    for (size_t i = 0; i < healingSprites_m.size(); i++)
    {


        healingSprite.move(0.f, 5.f);
        healingSprite.rotate(360);
        if (healingSprites_m[i].getPosition().y < window.getSize().y); {
            healingSprites_m.erase(healingSprites_m.begin() + i);

        }









    }
}
