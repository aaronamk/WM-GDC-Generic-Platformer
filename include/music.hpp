#include <SFML/Audio.hpp>
#include <iostream>

/* Manages all of the music for the game. Will most likely put Sound Effects in a different file. */
class Sounds{
    public:
        Sounds(std::string musicPath);
        ~Sounds();
        void playTrack();
        void stopTrack();
        void pauseTrack();

    private:
        sf::Music music;
        //keep track of what is being played to stop/pause as necessary
        /*
        Add Sound effects in the game by using this method:
        sf::SoundBuffer [SOUND_EFFECT_NAME];
        sf::Sound [SOUND_EFFECT_NAME];
        */
};
