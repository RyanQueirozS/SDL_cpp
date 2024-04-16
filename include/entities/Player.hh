#pragma once

#include <SDL2/SDL.h>

#include "../../lib/utils/utils.hh"

//------------------------------------------------------------------------------

class Player {
   public:
    Vec2f velocity = {0, 0};
    Vec2f pos = {0, 0};

    bool colidedDown = false;
    bool colidedLeft = false;
    bool colidedRight = false;
    bool colidedUp = false;

    bool isAbovePlatform = false;

    // Dash
    bool isPreparingToDash = false;
    bool isDashing = false;
    float DashEnd;
    float whenNextDashAvailable;

    float preDashAnimationEnd;
    float preDashDurationInMs;

    float angleDash = 0;  // in angles
    //--

    Vec2i hitbox = {75, 75};

   public:
    static Player* GetPlayerInstace();

    // Vec2f* GetPlayerPos();  // not used
    void Move(const MoveOptions);
    void PrepareToDash(MoveOptions moveOpt, float startTick, SDL_Renderer* renderer, float* timeMultiplier);
    void Dash();

    Vec2i GetHitboxInfo();

   private:
    static Player* player;

    const Vec2f accelSpeed = {1, 250};  // may change during gameplay, I'll just use it as a const it for now

    // const SDL_Texture* StandingTexture;  // not used
    // const SDL_Texture* DuckingTexture;
    MoveOptions facing = RIGHT;
};

//------------------------------------------------------------------------------