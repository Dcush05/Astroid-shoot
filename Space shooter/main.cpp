#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include <string>


#include "player.h"
#include "Global.h"
#include "astroids.h"
#include "fps.h"
#include "Animation.h"
#include "healing.h"




int main() {
    sf::RenderWindow window(sf::VideoMode(Screenwidth, Screenheight), "My window");
    sf::View view(Vector2f(0, 0), sf::Vector2f(Screenwidth, Screenheight));
    window.setFramerateLimit(60);
    float deltaTime = 0.0f;
    Clock clock;
    float ShootTimer = 0.f;
    float spawnInterval = 0.f;
    float spawnTimer = 2.f;
    int score = 10;
    int highScore = 0; //high schore variable

    //opens the file and gets whatever the highscore is from that file
     std::ifstream highScoreFile("data/score.dat");
     if (highScoreFile.is_open()) {
         highScoreFile >> highScore;
         highScoreFile.close();
     }

    
    

    //framerate
    FPS fps;
    sf::Text fpsNum;
    sf::Font font;
    font.loadFromFile("Assets/pixel.ttf");
    fpsNum.setFont(font);
    fpsNum.setCharacterSize(25);
    fpsNum.setFillColor(sf::Color::Black);
    fpsNum.setPosition(0, 0);

    //scoretext
    sf::Text scoreText;
    scoreText.setFont(font);

    scoreText.setString("Score: 0");

    scoreText.setCharacterSize(24);
    scoreText.setPosition(0, 650);
    scoreText.setFillColor(Color::Black);
    //high score
    sf::Text highscoreText;
    highscoreText.setFont(font);
    highscoreText.setString("High score: 0 ");
    highscoreText.setCharacterSize(10);
    highscoreText.setPosition(0, 680);
    highscoreText.setFillColor(sf::Color::Black);



    //points



    //TODO: -MOVEMENT AND ROTATION -> -> -SHOOTING -> -ASTROID SPAWNING -> *-DYING TO ASTROIDS -> CAMERA(X)-> -POINT SYSTEM -> -AWARD SYSTEM(HIGH SCORE AND MORE POWER ITEMS) -> END GAME (BOSS ONCE YOU HIT A CERTAIN SCORE)->? LEVELS (BACKGROUND) ->
    //GO BACK TO THRUST AT SOME POINT HAVE AN FUEL SYSTEM FOR YOUR THRUST
    //MAKE WHATEVER THE HELL THE BACKGROUND SCROLLING IS BETTER :D (DONE)
    //properly add a dying system
    //add Animation
    //change the score.dat file pushing shipping to github
    //fix healing system



    //Game assets
    player ship("Assets/ship.png");
    Animation animation(&ship.playerTexture, sf::Vector2u(8, 8), 3.f); //animation the floating value messes with 5he times between ever framee
    


    ship.playerGoingUp = false;
    Speedastroids power("Assets/Astroid.png");
    healing healing("Assets/Astroid.png");
    
    sf::Texture healastroidTexture;
    if (!healastroidTexture.loadFromFile("Assets/astroid.png")) {
        std::cout << "Error/n";



    }





    Texture bulletTexture;
    if (!bulletTexture.loadFromFile("Assets/bullet.png"))
    {
        std::cout << "Load failed" << '\n';
        system("pause");

    }

    sf::Sprite bullet;
    bullet.setTexture(bulletTexture);
    bullet.setTextureRect(IntRect(0, 0, 16, 16));
    bullet.setScale(Vector2f(2, 2));
    int bulletdmg = 5;

    std::vector<sf::Sprite> bullets;
    bullets.push_back(sf::Sprite(bullet));
    Animation animation1 (&bulletTexture, sf::Vector2u(16, 16), 0.2f);



    //enemy class:
    Texture enemyTexture;
    if (!enemyTexture.loadFromFile("Assets/Astroid.png"))
    {
        std::cout << "Load failed" << '\n';

        system("pause");
    }

    Sprite enemy;
    enemy.setTexture(enemyTexture);
    enemy.setTextureRect(IntRect(0, 0, 15, 15));
    enemy.setScale(Vector2f(2, 2));
    std::vector<Sprite> enemies;   
    enemies.push_back(Sprite(enemy));   //converting the enemysprite into a vector
    int enemyDamage = 1;
    
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Assets/background.png")) {
        // Handle error loading texture
        std::cout << "Load failed" << '\n';

        system("pause");
    }
    
    // Create a sprite for the background
    sf::Sprite background(backgroundTexture);

    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
           
            deltaTime = clock.restart().asSeconds();
            if (score > highScore) {
                highScore = score;
                std::ofstream highScoreFile("data/score.dat");
                if (highScoreFile.is_open()) {
                    highScoreFile << highScore;
                    highScoreFile.close();
                }
            }
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)

                window.close();

        }

        //updating the framerate to print onto the window
        fps.update();
        std::ostringstream ss;
        ss << fps.getFPS();
        fpsNum.setString(ss.str());
        

        //movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            ship.movement("RIGHT");
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            ship.movement("LEFT");
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            ship.movement("UP");

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            ship.movement("DOWN");




        //Shooting logic

        if (ShootTimer < 10)
            ShootTimer++;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ShootTimer >= 10) //shoot
        {
            

            bullet.setPosition(ship.playerCenter);
            bullets.push_back(Sprite(bullet));
            std::cout << "Shoot\n";
            ShootTimer = 0;
           
        }
        for (size_t i = 0; i < bullets.size(); i++)
        {



            bullets[i].move(0, -5);

            if (bullets[i].getPosition().y <= 0)
                bullets.erase(bullets.begin() + i);


        }


        //enemy logic
        spawnTimer += deltaTime;


       if (spawnTimer >= spawnInterval)
             spawnTimer++;

        if (spawnTimer >= 15)
        {

            enemy.setPosition((rand() % int(window.getSize().x - enemy.getScale().x)), 0.f);
            enemies.push_back(Sprite(enemy));
            // Reset the spawn timer
            spawnTimer = 0.0f;

            
        }

        for (size_t i = 0; i < enemies.size(); i++)
        {


            enemies[i].move(0.f, 5.f);
            enemies[i].rotate(2);

            if (enemies[i].getPosition().y > window.getSize().y - 20)
                enemies.erase(enemies.begin() + i);

        }


        //Collision for power up astroids
        //logic for power up astroids
        if (!power.Speedastroids_m.empty() && !bullets.empty())
        {
            for (size_t i = 0; i < bullets.size(); i++)
            {

                for (size_t k = 0; k < power.Speedastroids_m.size(); k++)
                {

                    if (bullets[i].getGlobalBounds().intersects(power.Speedastroids_m[k].getGlobalBounds()))
                    {


                        bullets.erase(bullets.begin() + i);
                         ship.PLAYER_ACCELERATION = ship.PLAYER_ACCELERATION + 5;
                        if (ship.PLAYER_ACCELERATION > 10)
                        {
                            ship.PLAYER_ACCELERATION = 1;

                        }
                        power.Speedastroids_m.erase(power.Speedastroids_m.begin() + k);
                      
                        break; //breaks the loop
                    }
                }
            }
        }
        //bullet colision for healing
        if (!healing.healingSprites_m.empty() && !bullets.empty()) {
            for (size_t i = 0; i < bullets.size(); i++) {

                for (size_t k = 0; k < healing.healingSprites_m.size(); k++) {

                    if (bullets[i].getGlobalBounds().intersects(healing.healingSprites_m[k].getGlobalBounds())) {

                        ship.heal(healing.healingAmount);
                        bullets.erase(bullets.begin() + i);
                       // ship.playerHealth = ship.playerHealth + healing.heal; //doesnt work find fix plz
                        healing.healingSprites_m.erase(healing.healingSprites_m.begin() + k);
                        
                        //std::cout << ship.playerHealth << '\n'; 

                        break;


                    }



                }





            }




        }

        //Collision for enemy bad stupid astroids

        
        //bullet collision
        if (!enemies.empty() && !bullets.empty())
        {
            for (size_t i = 0; i < bullets.size(); i++)
            {

                for (size_t k = 0; k < enemies.size(); k++)
                {

                    if (bullets[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
                    {
                        

                        score = score + 10;
                        scoreText.setString("Score: " + std::to_string(score));
                        bullets.erase(bullets.begin() + i);
                        enemies.erase(enemies.begin() + k);
                        std::cout << "ROCK DESTROYED\n";
                       


                        



                        


                        
                        
                        break; //breaks the loop
                    }
                }
            }
        }
        //Collision with astroid 
        for (size_t y = 0; y < enemies.size(); y++){
            if(ship.playerSprite.getGlobalBounds().intersects(enemies[y].getGlobalBounds())){
            enemies.erase(enemies.begin() + y);
            std::cout << "SHIP HIT\n";

            ship.takeDamage(enemyDamage);

          // std::cout << "Health: " << ship.playerHealth << '\n';
            //ship.playerSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

               }

        }
        
        if (ship.maxHealth<=0) {

           // ship.playerHealth = 3; //touch up on this
            //ship.takeDamage(enemyDamage);
            
              exit(EXIT_SUCCESS); //temporary will show game score after
            

        }
        
        
        
       
        // Wrap the player around the screen
        if (ship.playerSprite.getPosition().x > window.getSize().x) {
            ship.playerSprite.setPosition(-ship.playerSprite.getScale().x, ship.playerSprite.getPosition().y);
        }
        else if (ship.playerSprite.getPosition().x < -ship.playerSprite.getScale().x) {
            ship.playerSprite.setPosition(window.getSize().x, ship.playerSprite.getPosition().y);
        } 
        if (ship.playerSprite.getPosition().y > window.getSize().y) {
            ship.playerSprite.setPosition(ship.playerSprite.getPosition().x, -ship.playerSprite.getScale().y);
        }
        else if (ship.playerSprite.getPosition().y < -ship.playerSprite.getScale().y) {
            ship.playerSprite.setPosition(ship.playerSprite.getPosition().x, window.getSize().y);
        }

        //highscore to window
        highscoreText.setString("High Score: " + std::to_string(highScore));


        
        ship.playerSprite.setTextureRect(animation.uvRect);
        animation.Update(0, deltaTime);
        window.clear();
        window.draw(background);
        ship.drawPlayer(window);
        for (size_t i = 0; i < enemies.size(); i++)
        {

            window.draw(enemies[i]);



        }
        
        for (size_t i = 0; i < power.Speedastroids_m.size(); i++)
        {

            window.draw(power.Speedastroids_m[i]);



        }
        power.draw(window);
 
        for (size_t i = 0; i < bullets.size(); i++)
        {

            window.draw(bullets[i]);



        }
        for (size_t i = 0; i < healing.healingSprites_m.size(); i++) {
            window.draw(healing.healingSprites_m[i]);


        }

        
        healing.draw(window);
        window.draw(fpsNum); //draws the fps
        window.draw(scoreText);
        window.draw(highscoreText);

        window.display();
    }


	return 0;
}