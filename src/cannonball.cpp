#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "cannonball.hpp"


Cannonball::Cannonball(b2Vec2 position, float damage) : Actor(position) {
    // set allegiance of cannonball to pirate (enemy) allegiance
	this->allegiance = Allegiance::PIRATE;

    // cannonball's default age is 0 on spawn
	this->age = 0;

	// fix shape to body
	this->shape.m_radius = this->RADIUS;
	this->bodyDef.type = b2_dynamicBody;
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.5f;
	this->fixtureDef.friction = 3.0f;

	// set drawable
	texture.loadFromFile("../resources/cannonball.png");
	this->sprite = sf::Sprite(texture, sf::IntRect(0,0,64,64));
	sprite.setScale(0.08,0.08);
	this->sprite.setOrigin(this->RADIUS * 14, this->RADIUS * 14);

	// set old drawable
	this->drawable.setOrigin(this->RADIUS, this->RADIUS);
	this->drawable.setFillColor(sf::Color::Blue);
	this->drawable.setRadius(this->RADIUS);
}

void Cannonball::update(const float &dt) {
    // increment cannon age on each update frame
	this->age++;

    // delete cannonballs that are of age 900
	if (this->age > 900) {
		this->room->removeActor(this->shared_from_this());
	}
}

void Cannonball::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->drawable.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	this->drawable.setRotation(-this->body->GetAngle() * 180 / M_PI);
	//window->draw(drawable);

	this->sprite.setPosition(this->getBody()->GetPosition().x,
	                        -this->getBody()->GetPosition().y);
	this->sprite.setRotation(-this->body->GetAngle() * 180 / M_PI);
	window->draw(sprite);
}
