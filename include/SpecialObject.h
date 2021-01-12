#pragma once
#include "StaticObject.h"

class SpecialObject : public StaticObject{
public:
    SpecialObject() = default;
    SpecialObject(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &);

    virtual void activate() = 0;

private:

};