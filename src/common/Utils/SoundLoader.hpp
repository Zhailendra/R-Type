#ifndef SOUNDLOADER_HPP
#define SOUNDLOADER_HPP

#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include <map>
#include "../../client/ErrorHandler.hpp"
#include "Path.hpp"

namespace rtype {
    class SoundLoader {
    private:
        static sf::SoundBuffer loadSoundBuffer(const std::string& filename);
    public:
        static void loadAllSounds();
        static std::shared_ptr<std::map<SoundType, sf::SoundBuffer>> getSoundBuffers(std::shared_ptr<std::map<SoundType, sf::SoundBuffer>> soundBuffers_to_load = nullptr);
        static void playSound(SoundType soundType);
    };
}

#endif // SOUNDLOADER_HPP
