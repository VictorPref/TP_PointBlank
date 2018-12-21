//
// Created by prefo on 2018-12-17.
//

#include "PlayerManager.h"

PlayerManager* PlayerManager::instance = nullptr;
PlayerManager* PlayerManager::getInstance()
{
    if (!instance)
    {
        instance = new PlayerManager();
    }
    
    return instance;
}
void PlayerManager::UpdateAllPlayers(std::vector<GameObject*> level) {
    for(Player* p : playerManager)
    {
        p->Update(level);
    }
}

void PlayerManager::CreatePlayer(std::vector<Vector3> spawnPos) {

    for(int i = 0 ; i < spawnPos.size();i++){
        Player* p = new Player(spawnPos[i],Vector3(10,10,10),Vector3(0,0,0),Vector3(130,120,80),i);
        SDL_Joystick* gGameController = SDL_JoystickOpen( i );

        if( gGameController == NULL )
        {
            printf( "Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError() );
        }else {
            p->setController(gGameController);
        }
        playerManager.push_back(p);

    }

}

void PlayerManager::getPlayer(int id) {

}

void PlayerManager::drawPlayers() {

    for(int i = 0 ; i <playerManager.size();i++){
        playerManager[i]->draw();
    }
}



void PlayerManager::drawPlayer(int id) {
    playerManager[id]->draw();
}

void PlayerManager::DrawUIPlayers() {

    for(int i = 0 ; i <playerManager.size();i++){
        playerManager[i]->getUi()->DrawUI(playerManager[i]->getHealth());
    }
}

void PlayerManager::DrawUIPlayer( int id) {

    playerManager[id]->getUi()->DrawUI(playerManager[id]->getHealth());
}

void PlayerManager::UpdatePlayer(int id, std::vector<GameObject *> level) {
    playerManager[id]->Update(level);
}
