#pragma once
#include "Componet.h"

class Texture2D;
class Actor;
class Transform2D;

class Sprite :
    public Componet
{
public:

    /// <param name="texture">sets the sprites image to be this texture</param>
    /// <param name="name">the name of the component instance</param>
    Sprite(Texture2D* texture, const char* name = "SpriteComponet");

    /// <param name="texture">the path the textures load</param>
    /// <param name="name">the name of the component instance</param>
    Sprite(const char* path, const char* name = "SpriteComponet");
    ~Sprite() override;

    int getWidth() { return m_width; }
    int getHight() { return m_height; }

    void draw() override;

private:
    Texture2D* m_texture;
    int m_width;
    int m_height;
};