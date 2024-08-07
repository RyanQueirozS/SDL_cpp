#pragma once

#include "../Item.hh"

namespace Items {
class BowAndArrow : public Item::Item {
   public:
    inline BowAndArrow() : Item(ItemStats(1, 10, 10, 800, 1, 1)) {
        ID = ItemID::BOW_AND_ARROW;
        name = "Bow and Arrow";
        // atkType = Attack::AttackType::ARROW;
        // attackTypeAliveTime = 1000;
        itemStats.damage = 10;
        itemStats.armorPenetration = 10;
        itemStats.durability = 10;
        itemStats.weight = 1;
    }
};
}  // namespace Items
