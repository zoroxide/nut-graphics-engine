#include "nut/src/Engine.h"

int main() {
    Engine e; // object from the engine
    e.render("nut/resources/models/bunny.obj"); // render a model, in this case this is the stanford bunny example :)
    return 0;
}
