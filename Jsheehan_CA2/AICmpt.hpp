//
//  AICmpt.hpp
//  SimplisticComponentECS
//
//  Created by Denis Flynn on 03/11/2021.
//  Copyright © 2021 Denis Flynn. All rights reserved.
//

#ifndef AICmpt_hpp
#define AICmpt_hpp
#include "Component.hpp"
#include "TileMap.hpp"

void Update(float timeDelta);
void UpdatePathfinding(TileMap& level, sf::Vector2f playerPosition);
#endif /* AICmpt_hpp */
