#pragma once

#include <unordered_map>
#include <memory>

using std::unordered_map;
using std::unique_ptr;
using std::make_pair;

#include "scene.h"
#include "scene_id.h"
#include "game_scene.h"

namespace SpaceShooter::Scenes
{
  class SceneHandler
  {
    public:
      void update();
      void draw();
      void switchTo(SceneId sceneId);
      void addScene(SceneId sceneId);
      unique_ptr<Scene> const getCurrentScene();

    private:
      unordered_map<SceneId, unique_ptr<Scene>> scenes; 
	    SceneId currentSceneId;

      bool sceneExists(SceneId sceneId);
      Scene createScene(SceneId sceneId);
  };
}