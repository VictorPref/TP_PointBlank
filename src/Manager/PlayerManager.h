//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_PLAYERMANAGER_H
#define TP_POINTBLANK_PLAYERMANAGER_H

#include "../Player/Player.h"
#include "vector"
#include "../GameObject/Component/Vector3.h"

class PlayerManager {

    std::vector<Player> playerManager;
    static PlayerManager* instance;

public:
    static PlayerManager* getInstance();
    void CreatePlayer(std::vector<Vector3> spawnPos);
    void getPlayer(int id);
    void drawPlayers();
    void drawPlayer(int id);
    void UpdateAllPlayers();

};


#endif //TP_POINTBLANK_PLAYERMANAGER_H
