#ifndef CHARACTER_H
#define CHARACTER_H


#include <memory>
#include <box2d/box2d.h>

#include "actor.hpp"

/*
* The parent class for all movable characters
*/
class Character : public Actor, public std::enable_shared_from_this<Character> {
	protected:
		float acceleration;
		float jumpImpulse;
		float maxSpeed;
		int maxHealth;
		float health;


	public:
		Character(float x, float y);

		virtual void damage(float d);

		void heal(int healAmount);

		void setHealth(double health) { this->health = health; };

		const int getHealth(void) const { return this->health; };

		void setMaxHealth(double health) { this->maxHealth = health; };

		const int getMaxHealth(void) const { return this->maxHealth; };

		void jump(void);

		void goLeft(void);

		void goRight(void);

		void update(const float &dt) override;
};


#endif
