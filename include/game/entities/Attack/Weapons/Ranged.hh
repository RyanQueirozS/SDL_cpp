#pragma once

#include "../../../items/Item.hh"
#include "../../Entity.hh"
#include "../Attack.hh"

namespace Attacks {
class WoodenArrow : public Arrow {
   public:
    inline static void Create(Items::ItemStats itemStats_, Entity* entityOrigin_, float angle_) {
        std::shared_ptr<WoodenArrow> atk(new WoodenArrow());
        atk->Init(itemStats_, entityOrigin_, angle_, entityOrigin_->GetPos(), Vec2<float>{30.f, 10.f}, Vec2<float>{400, 400});
        Entity::PushToEntityVector(atk);
    }

    inline ~WoodenArrow() = default;

   private:
    inline WoodenArrow() = default;
};
}  // namespace Attacks
