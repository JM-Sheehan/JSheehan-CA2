//
//  AnimatedSpriteCmpt.hpp
//  SimplisticComponentECS
//
//  Created by Denis Flynn on 14/11/2021.
//  Copyright © 2021 Denis Flynn. All rights reserved.
//

#ifndef AnimatedSpriteCmpt_hpp
#define AnimatedSpriteCmpt_hpp

#include "SpriteCmpt.hpp"
#include <string>
class AnimatedSpriteCmpt : public SpriteCmpt
{
public:
    AnimatedSpriteCmpt();
    AnimatedSpriteCmpt(const sf::Texture& ,int , int);

    bool SetSprite(sf::Texture& , int, int);
    
    bool IsAnimated();

    void SetAnimated(bool);

    void Draw(sf::RenderWindow&, float);

    void NextFrame();
    

    // Gets the frame count of the object.
    const int  GetFrameCount();

private:
    bool m_isAnimated;
    int m_animationSpeed;
    int m_frameCount;
    int m_currentFrame;
    int m_frameWidth;
    int m_frameHeight;

};

#endif /* AnimatedSpriteCmpt_hpp */
