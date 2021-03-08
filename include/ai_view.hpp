#ifndef AI_VIEW_HPP
#define AI_VIEW_HPP


#include <list>
#include <memory>

#include "logic_controller.hpp"
#include "view.hpp"
#include "character.hpp"


class AIView : public View {
public:
	AIView(std::shared_ptr<LogicController> logic, std::shared_ptr<Actor> actor);

	/**
	 * Checks if specified target is in range of AI
	 * @return if target is out of range
	 * @param target Target to be checked
	 */
	virtual bool inRange(std::shared_ptr<Actor> target);

	/**
	 * Update target if no target or if target out of range
	 * @param allegiance the allegiance that the target should be
	 * @return True if found a target, false if not
	 */
	bool updateTarget(const Allegiance allegiance);

	/**
	 * Attacks the current target
	 */
	//void attack();

	virtual void update(const float &dt);


protected:
	int range;
	std::shared_ptr<Actor> actor;
	std::shared_ptr<LogicController> logic;
	std::shared_ptr<Actor> target;
};


#endif
