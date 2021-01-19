#pragma once
#include "StaticObject.h"

class SpecialObject : public StaticObject{
public:
    SpecialObject(const sf::Vector2f & , enum Textures_t, const sf::Vector2i &);

    virtual void activate() = 0;

private:
};