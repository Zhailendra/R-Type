/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** SoundLoader.cpp
*/

#include "SoundLoader.hpp"

sf::SoundBuffer rtype::SoundLoader::loadSoundBuffer(const std::string &filename) {
    sf::SoundBuffer soundBuffer;
    if (!soundBuffer.loadFromFile(filename)) {
        std::string errorMsg = "Failed to load sound from file: " + filename;
        throw rtype::ErrorHandler(errorMsg);
    }
    return soundBuffer;
}

std::shared_ptr<std::map<SoundType, sf::SoundBuffer>> rtype::SoundLoader::getSoundBuffers(
    std::shared_ptr<std::map<SoundType, sf::SoundBuffer>> soundBuffers_to_load
)
{
    static std::shared_ptr<std::map<SoundType, sf::SoundBuffer>> soundBuffers;
    if (soundBuffers_to_load != nullptr) {
        soundBuffers = soundBuffers_to_load;
    } else
        return soundBuffers;
    return nullptr;
}

void rtype::SoundLoader::loadAllSounds()
{
    std::shared_ptr<std::map<SoundType, sf::SoundBuffer>> soundBuffers = std::make_shared<std::map<SoundType, sf::SoundBuffer>>();

    for (auto &soundPath : soundPaths) {
        try {
            std::cout << "[DEBUG] Loading " << soundPath.second << std::endl;
            sf::SoundBuffer soundBuffer = loadSoundBuffer(soundPath.second);
            soundBuffers->insert(std::make_pair(soundPath.first, soundBuffer));
        } catch (const rtype::ErrorHandler &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
    }

    getSoundBuffers(soundBuffers);
}

void rtype::SoundLoader::playSound(SoundType soundType)
{
    auto soundBuffers = getSoundBuffers();

    if (soundBuffers->find(soundType) != soundBuffers->end()) {
        static sf::Sound sound; 
        sound.setBuffer(soundBuffers->at(soundType));
        sound.setVolume(50);
        sound.play();
    } else {
        std::cerr << "[ERROR] Sound type not found: " << static_cast<int>(soundType) << std::endl;
    }   
}