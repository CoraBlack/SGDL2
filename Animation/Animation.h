#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include "./Frame.h"
class Animation{
public:
    Frame(std::string<Frame>frames);
    ~Frame();
 
    int AddFrame();
    
private:
    std::vector<Frame>frames;
};

#endif
