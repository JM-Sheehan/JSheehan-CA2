//
//  Object.hpp
//  SimplisticComponentECS
//
//  Created by Denis Flynn on 01/11/2021.
//  Copyright © 2021 Denis Flynn. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdarg> //added - for variadic args
#include "Component.hpp"

class Object
{
    //do nothing for the moment, except, add and remove components.

public:



    /**
        Variable parameter version.
        Note we are using Variadic templates here, see e.g. https://eli.thegreenplace.net/2014/variadic-templates-in-c/
     */

    template <typename T, typename... Args>
    std::shared_ptr<T> AttachComponent(Args... args);


    /**
        Gets our component
     */
    template <typename T>
    std::shared_ptr<T> GetComponent();

private:
    //A collection of all components the object has attached.
    std::vector<std::shared_ptr<Component>> m_components; //vector<Component*> m_component


};


#endif /* Object_hpp */
