#pragma once

#include "../Item.hh"

namespace Items {
class BowAndArrow : public Item {
   public:
    inline BowAndArrow() {
        ID = ItemID::BOW_AND_ARROW;
        name = "Bow and Arrow";
        itemType = ItemType::SHORT_BOW;
        // atkType = Attack::AttackType::ARROW;
        // attackTypeAliveTime = 1000;
        damage = 10;
        armorPenetration = 10;
        durability = 10;
        invetoryWeight = 1;
    }
};
}  // namespace Items