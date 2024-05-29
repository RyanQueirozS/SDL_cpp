#include "../../include/entities/Camera.hh"

//------------------------------------------------------------------------------

Camera* Camera::instance = new Camera;

Camera* Camera::GetCameraInstance() { return instance; }

Vector2<float> Camera::pos = {0, 0};

void Camera::FollowPlayer(Vector2<float> posPlayer, float delta, Vector2<int> cameraInfo,
                          Vector2<int> hitboxPlayer, float timeMultiplier, const bool& isPaused) {
    if (isPaused) return;
    playerOffset.x = posPlayer.x - pos.x - float(cameraInfo.x) / 2.0f + float(hitboxPlayer.x) / 2.0f;
    playerOffset.y = posPlayer.y - pos.y - float(cameraInfo.y) / 1.5f + float(hitboxPlayer.y) / 1.5f;

    vel.y *= (1 - delta) * timeMultiplier;  // case beingMoved
    vel.x *= (1 - delta) * timeMultiplier;
    if (!isBeingMoved) {
        vel.y = playerOffset.y * 0.1f * (1.0f - delta) * timeMultiplier;
        vel.x = playerOffset.x * 0.1f * (1.0f - delta) * timeMultiplier;
    }

    pos.y += vel.y;
    pos.x += vel.x;
    isBeingMoved = false;
}

void Camera::Move(Direction direction, const bool& isPaused) {
    if (isPaused) return;
    cameraMovementSpeed = {maxPlayerOffset.x / 2, maxPlayerOffset.y / 8};  // Values to make it smoother
    isBeingMoved = true;
    switch (direction) {
        case UP: {
            if (playerOffset.y < float(maxPlayerOffset.y)) {
                vel.y -= float(cameraMovementSpeed.y);
            }
            break;
        }
        case DOWN: {
            if (playerOffset.y < float(maxPlayerOffset.y)) {
                vel.y += float(cameraMovementSpeed.y);
            }
            break;
        }
        case LEFT: {
            if (playerOffset.x > float(minPlayerOffset.x)) {
                vel.x -= float(cameraMovementSpeed.x);
            }
            break;
        }
        case RIGHT: {
            if (playerOffset.x < float(maxPlayerOffset.x)) {
                vel.x += float(cameraMovementSpeed.x);
            }
            break;
        }
    }
}

Vector2<float> Camera::GetCameraPos() { return pos; }
