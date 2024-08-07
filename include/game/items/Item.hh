#pragma once

#include <SDL2/SDL_stdinc.h>

#include <string>

#include "../../../lib/utils/math_utils.hh"
#include "../entities/EntityAttributes.hh"

namespace Items {

struct ItemStats {
    ItemStats();
    ItemStats(float weight_, float damage_, float armorPenetration_, Uint32 cooldownInTicks_, int durability_, float chargeRate);  // TODO: create a factory
    ~ItemStats() = default;

    float weight;
    float damage;  // TODO: divide damage into different types, eg: piercing, bludgeoning...
    float armorPenetration;

    bool isUsable;
    Uint32 useCooldown;  // only used in usableItems

    Uint32 attackCooldownInTicks;  // I want to make everyItem have an attack animation, even if it's a simple one

    float chargeRate;  // rate it increases
    float chargeNow;   // rate it's at now

    int durability;
};

enum ItemID {
    BOW_AND_ARROW = 0,
    SHORTSWORD,
};

class Item {
   public:
    void Drop(Matrix2D<Item>* inventory);

    void ChargeAttack();
    void ReleaseAttack(EntityAttributes* entityAttribute, EntityAttributes::CombatAttributes* combatAttribute, float angle);

    ItemStats GetItemStats();

   protected:
    Item(ItemStats stats);
    ~Item() = default;

    std::string name;
    ItemID ID;

    ItemStats itemStats;
};

}  // namespace Items
