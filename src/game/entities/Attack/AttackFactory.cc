#include "../../../../include/game/entities/Attack/AttackFactory.hh"

#include "../../../../include/game/entities/Attack/Weapons/Melee.hh"
#include "../../../../include/game/entities/Attack/Weapons/Ranged.hh"

namespace Attacks {
AttackFactory::AttackFactory() {
    RegisterAll();
}

AttackFactory AttackFactory::instance = AttackFactory();
AttackFactory& AttackFactory::Instance() { return instance; }

void AttackFactory::CreateAttack(AttackType atkType, Items::ItemStats itemStats, EntityAttributes* entity, float angle) {
    attackFactoryMap::iterator it = attackCreators.find(atkType);
    if (it != attackCreators.end()) {
        it->second(itemStats, entity, angle);
    }
}

void AttackFactory::RegisterAll() {
    instance.RegisterAttack(AttackType::ARROW_PROJECTILE, [](Items::ItemStats itemStats_, EntityAttributes* creature_, float angle_) {
        WoodenArrow::Create(itemStats_, creature_, angle_);
    });
    instance.RegisterAttack(AttackType::SWORD_SLASH, [](Items::ItemStats itemStats_, EntityAttributes* creature_, float angle_) {
        ShortSwordSwing::Create(itemStats_, creature_, angle_);
    });
}

void AttackFactory::RegisterAttack(AttackType atkType, std::function<void(Items::ItemStats, EntityAttributes*, float)> constructor) {
    attackCreators.emplace(atkType, constructor);
}
}  // namespace Attacks
