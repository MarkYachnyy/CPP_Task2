#include "Direction.h"
#include "Point.h"

inline int normalizedInt(int a) {
    if (a > 0) {
        return 1;
    }
    if (a < 0) {
        return -1;
    }
    return 0;
}

inline Point* getIncrementPoint(Direction direction) {
    switch (direction) {
        case Direction::Up:{
            return new Point(0, -1);
        }
        case Direction::Right: {
            return new Point(1, 0);
        }
        case Direction::Down: {
            return new Point(0, 1);
        }
        case Direction::Left: {
            return new Point(-1, 0);
        }
        default: {
            return new Point(0, 0);
        }
    }
}

