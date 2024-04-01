#include "scene_handler.h"

namespace SpaceShooter::Scenes
{
  void SceneHandler::update()
  {
    getCurrentScene()->update();
  }

  void SceneHandler::draw()
  {
    getCurrentScene()->draw();
  }

  void SceneHandler::switchTo(SceneId sceneId)
  {
    if(!sceneExists(sceneId)) return;

    currentSceneId = sceneId;
  }

  void SceneHandler::addScene(SceneId sceneId)
  {
    if(sceneExists(sceneId)) return;

    scenes.insert(make_pair(sceneId, createScene())); 
  }

  unique_ptr<Scene> SceneHandler::getCurrentScene()
  {
    return scenes.at(currentSceneId);
  }

  // private

  bool SceneHandler::sceneExists(SceneId sceneId)
  {
    return scenes.find(sceneId) != scenes.end();
  }

  Scene SceneHandler::createScene(SceneId sceneId)
  {
    //TODO: change to factory
    switch (sceneId)
    {
      case SceneId::mainMenu:
        //return new MainMenuScene();
      case SceneId::game:
        return new GameScene();
      case SceneId::gameOver:
        //return new GameOverScene();
    }
  }
}