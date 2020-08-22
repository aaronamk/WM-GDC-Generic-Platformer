#include "master_logic.hpp"
#include "master_view.hpp"

#include "actor.hpp"
#include "room.hpp"
#include "exit.hpp"
#include "platform.hpp"
#include "pari.hpp"


void MasterLogic::init(std::shared_ptr<MasterView> view) {
	this->view = view;
}


void MasterLogic::startDemo(void) {
	// Create room
	this->roomList.push_front(Room());
	this->currentRoom = this->roomList.begin();

	std::shared_ptr<Platform> ground = std::make_shared<Platform>(0, -100, 20000);
	this->currentRoom->addActor(ground);

	// Add pari
	std::shared_ptr<Pari> pari = std::make_shared<Pari>(300,335);
	this->currentRoom->addActor(pari);
	this->view->addView(pari);

	// Add Platform
	std::shared_ptr<Platform> platform1 = std::make_shared<Platform>(300, 400, 200);
	this->currentRoom->addActor(platform1);

	// Add Another Platform
	std::shared_ptr<Platform> platform2 = std::make_shared<Platform>(700, 400, 200);
	this->currentRoom->addActor(platform2);
}


void MasterLogic::startMenu(void) {

}


void MasterLogic::reset(void) {
	this->roomList.clear();
	this->currentRoom->reset();
}


void MasterLogic::checkCollisions(void) {
	// create list of all dependent actors beforehand for improved performance (hopefully)
	std::list<std::shared_ptr<Actor>> physicalActors;
	for (std::shared_ptr<Actor> actor : this->currentRoom->getActorList()) {
		if (actor->isPhysical()) physicalActors.push_back(actor);
	}

	// check actor collisions
	for (std::shared_ptr<Actor> actor : this->currentRoom->getActorList()) {

		// respond based on actor's state
		switch (actor->getState()) {
			case ActorState::INDEPENDENT :
				continue; // skip independent actors
			case ActorState::GROUNDED :
				for (std::shared_ptr<Actor> physicalActor : this->currentRoom->getActorList()) {
					if (actor->collidesSquare(*physicalActor)) break; //still grounded
				}
				actor->setState(ActorState::AIRBORNE);
				break;
			case ActorState::AIRBORNE :
				break;
		}
	}
}


void MasterLogic::update(const float &dt) {
	if (!this->paused) {
		// Update all actors in the actor list
		if (this->currentRoom->getActorList().size() > 0) {
			for (std::shared_ptr<Actor> actor : this->currentRoom->getActorList()) actor->update(dt);
			this->checkCollisions();
		}
	}
}
