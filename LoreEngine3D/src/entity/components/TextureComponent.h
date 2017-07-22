#pragma once
#include "../Component.h"
#include "../../graphics/textures/Texture.h"

#define COMPONENT_TYPE_TEXTURE 3

class TextureComponent : public Component
{
protected:
	Texture* _texture;
public:
	TextureComponent(Texture& texture);
	~TextureComponent();

	Texture* getTexture();
};