#version 330 core

out vec4 gl_FragColor;

in vec4 _color;
in vec2 _texCoord;

uniform sampler2D _texture;

void main()
{
	gl_FragColor = texture(_texture, _texCoord) * vec4(1.0, 1.0, 1.0, 1.0); //_color;
}
