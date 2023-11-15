#include "bird.h"

#include "Animation/animation.h"

namespace game
{
static Animation birdAnimation;
static int totalSprites = 2;

void moveBirdUp(Bird& bird);
void checkBirdHeightLimit(Bird& bird);
void updateBirdPos(Bird& bird);

void initBird(Bird& bird)
{
    bird.texture = LoadTexture("res/tempSpritesheet.png");
    bird.pos = { 120, 240 };
    bird.jumpForce = 250.f;
    bird.radius = 40.f;
    bird.gravity = 600.f;
    bird.velocity = 0.f;
    bird.flying = false;
    bird.color = WHITE;

    initAnimation(birdAnimation, static_cast<float>(bird.texture.width), static_cast<float>(bird.texture.height), 2);
}

void updateBird(Bird& bird)
{
    moveBirdUp(bird);
    checkBirdHeightLimit(bird);

    updateBirdPos(bird);
    bird.flying = false;

    updateAnimation(birdAnimation, static_cast<float>(bird.texture.width));
}

void drawBird(Bird bird)
{
    Rectangle dest = { bird.center.x, bird.center.y,
                         static_cast<float>(bird.texture.width / totalSprites), static_cast<float>(bird.texture.height) };
    Vector2 origin = { static_cast<float>(bird.texture.width / totalSprites / 2), 
                       static_cast<float>(bird.texture.height / 2) };

    DrawTexturePro(bird.texture, getFrameRect(birdAnimation), dest, origin, 0, bird.color);

#ifdef _DEBUG
    DrawCircleLines(static_cast<int>(bird.center.x), static_cast<int>(bird.center.y), bird.radius, RED);
#endif
}

void restartBird(Bird& bird)
{
    bird.pos = { 120, 240 };
}

void moveBirdUp(Bird& bird)
{
    if (IsKeyPressed(KEY_UP))
    {
        bird.velocity = -bird.jumpForce;
        bird.flying = true;
    }
}

void checkBirdHeightLimit(Bird& bird)
{
    if (bird.pos.y < 0) bird.pos.y = 0;
}

void updateBirdPos(Bird& bird)
{
    bird.velocity += bird.gravity * GetFrameTime();
    bird.pos.y += bird.velocity * GetFrameTime();

    bird.center.x = bird.pos.x + bird.radius;
    bird.center.y = bird.pos.y + bird.radius;
}

bool checkBirdTouchGround(Bird& bird, int screenHeight)
{
    return (bird.center.y > screenHeight);
}

void deinitBird(Bird& bird)
{
    UnloadTexture(bird.texture);
}
}