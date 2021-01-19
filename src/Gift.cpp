#include "Gift.h"

Gift::Gift(const sf::Vector2f &location, enum Textures_t gift, const sf::Vector2i & stageSize)
    : SpecialObject(location , gift, stageSize){
}