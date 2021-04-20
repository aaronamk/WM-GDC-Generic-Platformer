#include <list>
#include <memory>

#include "view.hpp"
#include "actor.hpp"
#include "ai_view.hpp"

AIView::AIView(std::shared_ptr<GameController> logic, std::shared_ptr<Actor> actor) : View(logic) {
	this->actor = actor;
	this->range = 30;
}

bool AIView::updateTarget(const Allegiance allegiance) {
    std::list<std::shared_ptr<Actor>> actors = this->logic->getCurrentRoom()->getActorList();
	for (std::shared_ptr<Actor> a : actors) {
		if (a->getAllegiance() == allegiance && a->isTargetable() && this->inRange(a)) {
			this->target = a;
			return true;
		}
	}
	this->target = NULL;
	return false;
}

bool AIView::inRange(std::shared_ptr<Actor> target) {
	b2Vec2 targetDist = target->getBody()->GetPosition() - this->actor->getBody()->GetPosition();
	return sqrt((pow(targetDist.x, 2) + pow(targetDist.y, 2))) <= this->range;
}
