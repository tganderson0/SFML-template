#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace components
{
  class Sprite
  {
    public:
      Sprite(std::shared_ptr<sf::Sprite> sprite) :
        m_sprite(sprite)
      {
      }

      auto get() { return m_sprite; }

    private:
      std::shared_ptr<sf::Sprite> m_sprite;
  };
}