#include "const.h"
#include "meteor.h"

std::string Meteor::meteor_file_names[] =
{ "" };

Meteor::Meteor() {
	size_t type = rand() % 1;
	texture.loadFromFile(IMAGES_FOLDER +
		Meteor::meteor_file_names[type]);
	sprite.setTexture(texture);
	spawn();
}
void Meteor::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
void Meteor::update() {
	sprite.move(speedx, speedy);
	if (sprite.getPosition().x < 0.f - getWidth() ||
		sprite.getPosition().x > WINDOW_WIDTH ||
		sprite.getPosition().y > WINDOW_HEIGHT
		)
	{
		spawn();
	}
}
size_t Meteor::getWidth() { return sprite.getLocalBounds().width; }
size_t Meteor::getHeight() { return sprite.getLocalBounds().height; }
sf::FloatRect Meteor::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Meteor::getPosition() { return sprite.getPosition(); }
void Meteor::spawn() {
	float startx = rand() % (static_cast<size_t>(WINDOW_WIDTH) - getWidth() + 1);
	float starty = rand() % (static_cast<size_t>(WINDOW_HEIGHT) + 1) - WINDOW_HEIGHT;
	sprite.setPosition(startx, starty);
	speedx = 0;
	speedy = 3;
}
sf::Vector2f Meteor::getCenter() {
	return sf::Vector2f
	(
		sprite.getPosition().x + getWidth() / 2.0,
		sprite.getPosition().y + getHeight() / 2.0
	);
}