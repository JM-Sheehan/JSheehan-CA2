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

class AICmpt : Component {
	public:
		void Update(float timeDelta);
		void UpdatePathfinding(TileMap& level, sf::Vector2f playerPosition);
	private:
};

#endif /* AICmpt_hpp */
