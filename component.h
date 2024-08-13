#ifndef COMPONENT_H
#define COMPONENT_H

#include<string>

class Component
{
public:
    virtual void Update(int deltaTime) = 0;
    virtual std::string GetComponentId() const = 0;
    virtual ~Component(){}
};

#endif // COMPONENT_H
