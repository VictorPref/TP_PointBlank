//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_PLAYERMANAGER_H
#define TP_POINTBLANK_PLAYERMANAGER_H

#include "../Player/Player.h"
#include "vector"

class PlayerManager {

    std::vector<Player> playerManager;

public:

    void UpdateAllPlayers();

};


#endif //TP_POINTBLANK_PLAYERMANAGER_H
