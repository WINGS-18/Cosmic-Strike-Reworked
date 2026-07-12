#include "game/Render.h"

namespace cs {

    Render::Render() {}

    Render& Render::getRenderer() {     //returns reference of it's own object
        static Render r;
        return r;
    }
}