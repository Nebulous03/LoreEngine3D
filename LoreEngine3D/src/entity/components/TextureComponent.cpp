#include "TextureComponent.h"

TextureComponent::TextureComponent(Texture& texture) : Component(COMPONENT_TYPE_TEXTURE), _texture(&texture) {}

TextureComponent::~TextureComponent()
{
	delete _texture;
}

Texture* TextureComponent::getTexture()
{
	return _texture;
}
