#pragma once

#include "entities/Entity.hpp"

#include <chrono>
#if defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable : 4245) // Disable some compiler warnings that come from ctti
#endif
#include <ctti/type_id.hpp>
#if defined(_MSC_VER)
    #pragma warning(pop)
#endif
#include <initializer_list>
#include <unordered_set>

namespace systems
{
    class System
    {
      public:
        System(std::initializer_list<ctti::unnamed_type_id_t> list) :
            m_interests(list)
        {
        }

        virtual void addEntity(std::shared_ptr<entities::Entity> entity);
        virtual void removeEntity(decltype(entities::Entity().getId()) entityId);

        // The (void)elapsedTime is a technique to silence an unused parameter warning
        virtual void update(std::chrono::milliseconds elapsedTime) { (void)elapsedTime; }

      protected:
        entities::EntityMap m_entities;

      private:
        std::unordered_set<ctti::unnamed_type_id_t> m_interests;
        bool isInterested(entities::Entity* entity);
    };
}