#include "Vec2.h"

Vec2::Vec2()
{    
}

Vec2::Vec2(float xin, float yin)
    : x(xin), y(yin)
{
    
}

bool Vec2::operator == (const Vec2& rhs) const
{
    return false;
}

bool Vec2::operator != (const Vec2& rhs) const
{
    return false;
}



Vec2 Vec2::operator + (const Vec2& rhs) const
{
    return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator - (const Vec2& rhs) const
{
    return Vec2(0, 0);
}

Vec2 Vec2::operator / (const float val) const
{
    return Vec2(0, 0);
}

Vec2 Vec2::operator * (const float val) const
{
    return Vec2(0, 0);
}



Vec2 Vec2::operator += (const Vec2& rhs) const
{
    return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator -= (const Vec2& rhs) const
{
    return Vec2(0, 0);
}

Vec2 Vec2::operator /= (const float val) const
{
    return Vec2(0, 0);
}

Vec2 Vec2::operator *= (const float val) const
{
    return Vec2(0, 0);
}


float Vec2::dist(const float val) const
{
    return 0.0f;
}