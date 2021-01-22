#pragma once
#include "StaticObject.h"

class SpecialObject : public StaticObject{
public:
    //--------------------Constructor/Destructor Section--------------------
    SpecialObject(const sf::Vector2f & , enum Textures_t, const sf::Vector2i &);

    //--------------------Virtual Function Section--------------------
    virtual void activate() = 0;

private:
};