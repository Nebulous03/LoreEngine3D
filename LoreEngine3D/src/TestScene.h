#pragma once
#include "game\Scene.h"

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
	Mesh* _cubeMesh;
	Renderable* _cube;

	Timer _timer;

public:
	TestScene();
	~TestScene();
	void onLoad();
	void onUnload();
	void onTick();
	void onUpdate();
	void onRender();
};