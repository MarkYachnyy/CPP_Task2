#pragma once
#include "../geometry/Utils.h"
#include "Invisible.h"

static Artifact *createRandomArtifact(Point &point) {
    int r = randInt(0, 3);
    return new Invisible(point.x, point.y);
}
