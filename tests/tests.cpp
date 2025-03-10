#include "Snake.h"
#include "Point.h"
#include "Utils.h"
#include <cstdlib>
#include <gtest/gtest.h>

#include "Invisible.h"

TEST(SnakeTest, CreationTest1) {
    int x = randInt(-10, 10);
    int y = randInt(-10, 10);
    int l = randInt(2, 10);

    Snake snake1(std::vector<Point>{{x, y}, {x, y + l - 1}}, Direction::Up, 2);
    Snake snake2(Point(x, y), Direction::Up, l, 2);
    EXPECT_EQ(snake1, snake2);
}

TEST(SnakeTest, CreationTest2) {
    int x = randInt(-10, 10);
    int y = randInt(-10, 10);
    int l = randInt(2, 10);

    Snake snake1(std::vector<Point>{{x, y}, {x + l - 1, y}}, Direction::Left, 2);
    Snake snake2(Point(x, y), Direction::Left, l, 2);
    EXPECT_EQ(snake1, snake2);
}

TEST(SnakeTest, CreationTest3) {
    int x = randInt(-10, 10);
    int y = randInt(-10, 10);
    int l = randInt(2, 10);

    Snake snake1(std::vector<Point>{{x, y}, {x, y - l + 1}}, Direction::Down, 2);
    Snake snake2(Point(x, y), Direction::Down, l, 2);
    EXPECT_EQ(snake1, snake2);
}

TEST(SnakeTest, CreationTest4) {
    int x = randInt(-10, 10);
    int y = randInt(-10, 10);
    int l = randInt(2, 10);

    Snake snake1(std::vector<Point>{{x, y}, {x - l + 1, y}}, Direction::Right, 2);
    Snake snake2(Point(x, y), Direction::Right, l, 2);
    EXPECT_EQ(snake1, snake2);
}

TEST(SnakeTest, MoveTestSimple1) {
    int x = randInt(-10, 10);
    int y = randInt(-10, 10);
    int l = randInt(2, 10);

    Snake snake1(std::vector<Point>{{x, y}, {x - l + 1, y}}, Direction::Right, 2);
    snake1.move();
    Snake snake2(std::vector<Point>{{x + 1, y}, {x - l + 2, y}}, Direction::Right, 2, 1);
    EXPECT_EQ(snake1, snake2);
}


TEST(SnakeTest, MoveTestTailDisappear1) {
    int x = randInt(-10, 10);
    int y = randInt(-10, 10);
    int l = randInt(2, 10);

    Snake snake1(std::vector<Point>{{x, y}, {x, y + l - 1}, {x + 1, y + l - 1}}, Direction::Up, 5);
    Snake snake2(std::vector<Point>{{x, y - 1}, {x, y + l - 1}}, Direction::Up, 5, 4);
    snake1.move();
    EXPECT_EQ(snake1, snake2);
}

TEST(SnakeTest, MoveTestTailDisappear2) {
    int x = randInt(-10, 10);
    int y = randInt(-10, 10);
    int l = randInt(2, 10);

    Snake snake1(std::vector<Point>{{x, y}, {x + l - 1, y}, {x + l - 1, y + l - 1}, {x + l, y + l - 1}},
                 Direction::Left, 5);
    Snake snake2(std::vector<Point>{{x - 1, y}, {x + l - 1, y}, {x + l - 1, y + l - 1}}, Direction::Left, 5, 4);
    snake1.move();
    EXPECT_EQ(snake1, snake2);
}

TEST(SnakeTest, MoveTestTailDoesNotDisappear) {
    int x = randInt(-10, 10);
    int y = randInt(-10, 10);
    int l = randInt(2, 10);

    Snake snake1(std::vector<Point>{{x, y}, {x + l - 1, y}, {x + l - 1, y + l - 1}, {x + l + 1, y + l - 1}},
                 Direction::Left, 5);
    Snake snake2(std::vector<Point>{{x - 1, y}, {x + l - 1, y}, {x + l - 1, y + l - 1}, {x + l, y + l - 1}}, Direction::Left, 5, 4);
    snake1.move();
    EXPECT_EQ(snake1, snake2);
}

TEST(ArtifactTest, InvisibleTest) {
    int x = randInt(-10, 10);
    int y = randInt(-10, 10);
    int l = randInt(2, 10);

    Snake snake1(std::vector<Point>{{x, y}}, Direction::Left, 5, 5);
    Snake snake2(std::vector<Point>{{x, y}}, Direction::Left, 5,5);
    snake2.invisibleMoves = 20;
    Invisible i(1,1, 20);
    i.use(&snake1);

    EXPECT_EQ()
}

int main(int argc, char **argv) {
    srand(time(NULL));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
