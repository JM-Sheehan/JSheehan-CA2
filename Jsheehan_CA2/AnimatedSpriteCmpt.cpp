#include "AnimatedSpriteCmpt.hpp"

AnimatedSpriteCmpt::AnimatedSpriteCmpt(){}

AnimatedSpriteCmpt::AnimatedSpriteCmpt(const sf::Texture& texture, int frames =
    1, int frameSpeed = 0) :m_frameCount(frames), m_animationSpeed(frameSpeed)
{

    setTexture(texture); //since m_texture  is private member of parent class, will use utility function setTexture
}

bool AnimatedSpriteCmpt::SetSprite(sf::Texture& texture, int frames =
    1, int frameSpeed = 0)
{
    // Create a sprite from the loaded texture.
    m_sprite.setTexture(texture);

    // Set animation speed.
    m_animationSpeed = frameSpeed;

    // Store the number of frames.
    m_frameCount = frames;

    // Calculate frame dimensions.
    sf::Vector2u texSize = m_sprite.getTexture()->getSize();
    m_frameWidth = texSize.x / m_frameCount;
    m_frameHeight = texSize.y;

    // Check if animated or static.
    if (frames > 1)
    {
        // Set sprite as animated.
        m_isAnimated = true;

        // Set the texture rect of the first frame.
        m_sprite.setTextureRect(sf::IntRect(0, 0, m_frameWidth, m_frameHeight));
    }
    else
    {
        // Set sprite as non animated.
        m_isAnimated = false;
    }

    // Set the origin of the sprite.
    m_sprite.setOrigin(m_frameWidth / 2.f, m_frameHeight / 2.f);

    return true;

}

bool AnimatedSpriteCmpt::IsAnimated() { return m_isAnimated; }

void AnimatedSpriteCmpt::SetAnimated(bool isAnimated)
{
    m_isAnimated = isAnimated;

    if (isAnimated)
    {
        m_currentFrame = 0;
    }
    else
    {
        // set the texture rect of the first frame
        this->m_sprite.setTextureRect(sf::IntRect(0, 0, m_frameWidth, m_frameHeight));
    }
}

void AnimatedSpriteCmpt::Draw(sf::RenderWindow& window, float timeDelta)
{
    // check if the sprite is animated
    if (m_isAnimated)
    {
        // add the elapsed time since the last draw call to the aggregate
        m_timeDelta += timeDelta;

        // check if the frame should be updated
        if (m_timeDelta >= (1.f / m_animationSpeed))
        {
            NextFrame();
            m_timeDelta = 0;
        }
    }

    window.draw(m_sprite);
}

void AnimatedSpriteCmpt::NextFrame() {
    // check if we reached the last frame
    if (m_currentFrame == (m_frameCount - 1))
        m_currentFrame = 0;
    else
        m_currentFrame++;

    // update the texture rect
    m_sprite.setTextureRect(sf::IntRect(m_frameWidth * m_currentFrame, 0, m_frameWidth, m_frameHeight));
}

const int AnimatedSpriteCmpt::GetFrameCount() {
    return m_frameCount;
}