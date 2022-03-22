#include <gtest/gtest.h>

#include <vector>

// ======================================================================
// bowlingScore
//
// (normally one would want to separate the implemenation on of the
// function / class from its tests, but to start its easiest to have it
// all together.

int bowlingScore(const std::vector<int>& rolls)
{
  int score = 0;
  int i = 0;
  for (int frame = 0; frame < 10; frame++) {
    score += rolls[i] + rolls[i + 1];
    i += 2;
  }
  return score;
}

// ======================================================================
// Tests

TEST(Bowling, AllZeros)
{
  std::vector<int> rolls = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };
  EXPECT_EQ(rolls.size(), 20);
  EXPECT_EQ(bowlingScore(rolls), 0);
}

TEST(Bowling, RegularGame)
{
  std::vector<int> rolls = {
    0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6,
  };
  EXPECT_EQ(rolls.size(), 20);
  EXPECT_EQ(bowlingScore(rolls), 14);
}
