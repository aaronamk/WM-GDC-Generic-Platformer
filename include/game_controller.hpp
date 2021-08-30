#ifndef LOGIC_CONTROLLER_HPP
#define LOGIC_CONTROLLER_HPP


#include <list>
#include <memory>


class GameState;


/**
 * Main logic class that controls everything.
 */
class GameController {
public:
	/**
	 * Main method
	 */
	GameController(void) {};

	/**
	 * Main method
	 */
	GameController(std::shared_ptr<GameState> state) { this->setGameState(state); };

	/**
	 *
	 */
	std::shared_ptr<GameState> getGameState(void) const { return this->gameState; };

	/**
	 *
	 */
	void setGameState(std::shared_ptr<GameState> state) { this->gameState = state; };

	/**
	 * Resets game controller to default.
	 */
	void reset(void);

	/**
	 * @return pause state of the application
	 */
	const bool &isPaused(void) { return this->paused; };

	/**
	 * Play/pause the application.
	 */
	void togglePause(void) { this->paused = !this->paused; };

	/**
	 * @param state New pause state of the application
	 */
	void togglePause(bool state) { this->paused = state; };

	/**
	 * @return pause state of the application
	 */
	const bool &isInDialogMode(void) { return this->isInDialog; };

	/**
	 * Play/pause the application when in dialog.
	 */
	void toggleDialog(void) { this->isInDialog = !this->isInDialog; };

	/**
	 * @param state New pause state of the application while in dialog
	 */
	void toggleDialog(bool state) { this->isInDialog = state; };

	/**
	 *
	 */
	void update(void);


private:
	std::shared_ptr<GameState> gameState;
	bool paused = false;
	bool isInDialog = false;
};


#endif
