 =======================================================================================
| README: 										|
| --------										|
| Written by: Sagi Arditti and Sergey Ovsiannikov					|
 =======================================================================================
===========================
1. Project: X Wing Fighter |
===========================

=================================
3. Explanation about the program:
=================================

 	The program will run a game of spaceships battles.
	The player control an X-Wings and is fighting againts hords of enemy Tie-Fighters and Bombers.
	The player can shot lasers and missile in order to take out the enemies, each kill will grant the player score points.
	Enemies will spawn randomaly and will seek out the player.
	The player starts at 100 hp and 3 lives, once all his lives are gone its game over.
	He can obtain more lives, missiles and faster lasers by collecting power ups who spawns randomly around the world.
	Will you be able to survive and win an endless war??
	May the Force be with you.

	Gameplay Video:	https://www.youtube.com/watch?v=tK365N5zY08

	* In order to run the project theres a need to install SFML from - www.sfml-dev.org

===========
4. Design:
===========
The world holds all the world's objects, astroids, a laser that got fired etc. 
The world will be in charge to update those objects and call thier move function,

The player will be able to control the x wing with the keyboard.
If a spaceship will die an explosion will be created in it place. 

All the buttons of the menu will inhirit from a base class named BaseButton.

The controller will run the game and will draw the world and the menu on the screen.

=================================
5. Explanation about each file:
=================================

AnimatedSprite.h\cpp
---------------------
Holds the AnimatedSprite class and the AnimatedSprite.h, 's functions.

Animation.h\cpp
----------------
Holds the Animation class and the Animation's functions.

BackgroundBlackHole.h\cpp
--------------------------
This holds the BackgroundBlackHole class and it's functions

BackgroundFog.h\cpp
--------------------
This holds the BackgroundFogclass and it's functions

BackgroundObj.h\cpp
--------------------
This holds the BackgroundObjclass and it's functions

BackgroundStar.h\cpp
---------------------
This holds the BackgroundStarclass and it's functions

Explosion.h\cpp
----------------
This holds the Explosion class and it's functions

GameObj.h\cpp
--------------
This holds the GameObj class and it's functions

Obstacle.h\cpp
---------------
This holds the Obstacle class and it's functions

ObstacleAsteroid.h\cpp
-----------------------
This holds the ObstacleAsteroid class and it's functions

ObstacleWreckage.h\cpp
-----------------------
This holds the ObstacleWreckage class and it's functions

PowerUp.h\cpp
--------------
This holds the PowerUp class and it's functions

PowerUpAmmo.h\cpp
------------------
This holds the PowerUpAmmo class and it's functions

PowerUpDelay.h\cpp
-------------------
This holds the PowerUpDelay class and it's functions

PowerUpLife.h\cpp
------------------
This holds the PowerUpLife class and it's functions

Spaceship.h\cpp
----------------
This holds the Spaceship class and it's functions

SpaceshipPlayer.h\cpp
----------------------
This holds the SpaceshipPlayer class and it's functions

SpaceshipEnemy.h\cpp
---------------------
This holds the SpaceshipEnemy class and it's functions

SpaceshipEnemySimple.h\cpp
---------------------------
This holds the SpaceshipEnemySimple class and it's functions

SpaceshipEnemyAdvanced.h\cpp
-----------------------------
This holds the SpaceshipEnemyAdvanced class and it's functions

SpaceshipEnemyBoss.h\cpp
-------------------------
This holds the SpaceshipEnemyBoss class and it's functions

Weapon.h\cpp
-------------
This holds the Weapon class and it's functions

WeaponHomingMissile.h\cpp
--------------------------
This holds the WeaponHomingMissile class and it's functions

WeaponLaser.h\cpp
-----------------
This holds the WeaponLaser class and it's functions

World.h\cpp
------------
This holds the World class and it's functions

BaseButton.h\cpp
-----------------
Holds the BaseButton class and the BaseButton's functions.
The basic button class the the others will inhirit from.

ButtonExit.h\cpp
-----------------
This holds the ButtonExit class and it's functions

ButtonHowToPlay.h\cpp
----------------------
This holds the ButtonHowToPlay class and it's functions

ButtonScoreTable.h\cpp
-----------------------
This holds the ButtonScoreTable class and it's functions

ButtonStartGame.h\cpp
----------------------
This holds the ButtonStartGame class and it's functions

Menu.h\cpp
-----------
Holds the Menu class and the Menu's functions.

Controller.h\cpp
-----------------
Holds the Controller class and the Controller's functions.

Main.cpp
---------
The main program, runs the checks and all the functions of the classes.

==============================================
6. Explanation about the classes and Structs:
==============================================

AnimatedSprite
---------------
a class of an animated sprite, switch the sprites automatically.

Animation
----------
control the animation of the sprites

BackgroundObj
--------------
the main class of all the background objects that are in the world.
all the background objects will inhirit from it.

BackgroundBlackHole
--------------------
a background object, black hole. holds a sprite and a sound. 
inhirit from BackgroundObj.

BackgroundFog.h\cpp
--------------------
a background object, fog. holds a sprite and a sound. 
inhirit from BackgroundObj.

BackgroundStar
---------------
a background object, star. holds a sprite and a sound. 
inhirit from BackgroundObj.

GameObj
--------
the main class of all the game objects.
all the game objects will inhirit from it.

Explosion
----------
The explosion class, holds an explosion sprite and a sound. 
inhirit from GameObj.

Obstacle
---------
the main obstacle class all the other obstacles will inhirit from it

ObstacleAsteroid
------------------
Asteroid that inhirit from Obstacle.

PowerUp
--------
The main power up class, all the power ups will inhirit from it.
inhirit from GameObj.

PowerUpAmmo
------------
a power up that gives missiles. inhirit from PowerUp.
inhirit from PowerUp

PowerUpDelay
-------------
a power up that gives laser speed. inhirit from PowerUp.
inhirit from PowerUp

PowerUpLife
------------
a power up that gives life. inhirit from PowerUp.
inhirit from PowerUp

Spaceship
----------
The main spaceship class, all the other spaceship will inhirit from it.
inhirit from GameObj.

SpaceshipPlayer
----------------
The player spaceship, got lives, score and a bool that tells if the player is dead or alive.
inhirit from Spaceship.

SpaceshipEnemy
---------------
The base class for enemy spaceships.
inhirit from Spaceship.

SpaceshipEnemySimple
---------------------
The stupid enemy spaceship.
inhirit from SpaceshipEnemy

SpaceshipEnemyAdvanced
-----------------------
The smart enemy spaceship
inhirit from SpaceshipEnemy

SpaceshipEnemyBoss
-------------------
The boss
inhirit from SpaceshipEnemy

Weapon
-------
The main weapon class, all the weapons inhirit from it

WeaponHomingMissile
---------------------
An homing missile that seek out the closest target.
inhirit from Weapon

WeaponLaser
-----------------
The main weapon, a laser with infinit ammo.
inhirit from Weapon

World
------
The game world, holds the background img or the worlds, and the objs that are on the world.

BaseButton
-----------
The basic button class the the others will inhirit from.

ButtonExit
-----------
an exit buttom
inhirit from BaseButton

ButtonHowToPlay
----------------
an how to play button
inhirit from BaseButton

ButtonScoreTable
-----------------
score table button
inhirit from BaseButton

ButtonStartGame
----------------
start game button
inhirit from BaseButton

Menu
-----
the menu class, holds the buttons and the menu backgorund img

