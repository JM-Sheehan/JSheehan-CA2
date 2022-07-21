#include "ReadableInfoCmpt.hpp"
ReadableInfoCMPT::ReadableInfoCMPT()
{
    _componentCount = 0;
    _ComponentsAddedToObject = {};

}

void ReadableInfoCMPT::addComponentDetails(std::string details)
{
    _ComponentsAddedToObject.emplace(_componentCount++, details);//++ after as I want the old value then update counter.
}

void ReadableInfoCMPT::printComponentDetails()
{
    for (int i = 0; i < _componentCount; i++)
        cout << _ComponentsAddedToObject[i] << " " << endl;
}