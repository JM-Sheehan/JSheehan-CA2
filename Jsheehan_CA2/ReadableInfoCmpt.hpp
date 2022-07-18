//
//  ReadableInfoCMPT.hpp
//  SimplisticComponentECS
//
//  Created by Denis Flynn on 17/11/2021.
//  Copyright � 2021 Denis Flynn. All rights reserved.
//

#ifndef ReadableInfoCMPT_hpp
#define ReadableInfoCMPT_hpp
#include <map>
#include <iostream>
using namespace std;
#include "Component.hpp"

class ReadableInfoCMPT : public Component
{
    ///This component could be used for debugging or for keeping readible info that we wish to store in our objects.
    ///One use case will be to keep a readable record of which components our object "own".
public:
    ReadableInfoCMPT();

    void addComponentDetails(std::string details);

    void printComponentDetails();

    void Update(float timeDelta) {

    }
private:

    std::map<int, std::string> _ComponentsAddedToObject;
    int _componentCount;
};

#endif /* ReadableInfoCMPT_hpp */
