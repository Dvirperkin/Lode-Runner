#pragma once

#include "SpecialObject.h"

class Gift : public SpecialObject {

public:
    Gift() = default;
    Gift(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &);
    virtual void activate() = 0;

private:

};