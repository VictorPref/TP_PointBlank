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



void PlayerManager::UpdateAllPlayers() {

}

void PlayerManager::CreatePlayer(std::vector<Vector3> spawnPos) {

}

void PlayerManager::getPlayer(int id) {

}

void PlayerManager::drawPlayers() {

}

void PlayerManager::drawPlayer(int id) {

}
