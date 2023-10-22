#include "astroids.h"

void Speedastroids::draw(sf::RenderWindow& window)
{
    Speedastroids_m.push_back(sf::Sprite(Speedastroid));

    if (astroidSpawner < spawnRand)
        astroidSpawner++;

    if (astroidSpawner >= spawnRand)
    {

        Speedastroid.setPosition((rand() % int(window.getSize().x - Speedastroid.getScale().x)), 0.f);
        Speedastroids_m.push_back(Sprite(Speedastroid));
        astroidSpawner = 0;
    }

    for (size_t i = 0; i < Speedastroids_m.size(); i++)
    {


        Speedastroid.move(0.f, 5.f);
        Speedastroid.rotate(360);
        if (Speedastroids_m[i].getPosition().y < window.getSize().y); {
            Speedastroids_m.erase(Speedastroids_m.begin() + i);

        }







    }
}

