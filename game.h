#pragma once
#include "const.h"
#include "SFML/Graphics.hpp"
#include "player.h"
#include "meteor.h"
#include <vector>
#include "splash.h"
#include <list>
#include "text.h"
#include "bonus.h"
#include "road.h"

class Game {
public:
	enum GameState { INTRO, PLAY, PAUSE, GAME_WIN , GAME_OVER };
	Game();
	void play();
private:
	void check_events();
	void update();
	void draw();
	void check_collisions();

	sf::RenderWindow window;
	Player player;
	GameState game_state = PLAY;
	//Win game_win;
	Splash game_over;
	Road road1, road2;
	std::vector<Meteor*> meteor_sprites;
	TextObj hp_text;
	sf::Clock clock;
	std::list<Bonus*> bonus_sprites;
};
