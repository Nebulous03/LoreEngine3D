#pragma once
#include "game\Scene.h"
#include "math\Math.h"
#include "graphics\Camera.h"
#include "graphics\Shader.h"
#include "graphics\Renderer.h"
#include "graphics\SceneLayer.h"
#include "utils\OBJLoader.h"
#include "logic\Input.h"
#include "utils\Timer.h"

class TestScene : public Scene {

private:
	Camera* _camera;
	Shader* _colorShader;
	BasicRenderer* _renderer;
	SceneLayer* _layer;

	Entity* cubeEntity;

	Timer _timer;

public:
	TestScene();
	~TestScene();
	void onLoad(Game& game) override;
	void onUnload(Game& game) override;
	void onTick(Game& game, double delta) override;
	void onUpdate(Game& game, double delta) override;
	void onRender() override;
};