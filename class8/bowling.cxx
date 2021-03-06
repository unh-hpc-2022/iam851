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
    if (rolls[i] == 10) {
      // strike: add 10 for this frame + the number of pins in the next two
      // rolls
      score += 10 + rolls[i + 1] + rolls[i + 2];
      i += 1;
    } else if (rolls[i] + rolls[i + 1] == 10) {
      // spare: add 10 for this frame + the number of pins in the next roll
      score += 10 + rolls[i + 2];
      i += 2;
    } else {
      score += rolls[i] + rolls[i + 1];
      i += 2;
    }
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

TEST(Bowling, Spare)
{
  std::vector<int> rolls = {
    7, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };
  EXPECT_EQ(rolls.size(), 20);
  EXPECT_EQ(bowlingScore(rolls), 14 + 6);
}

TEST(Bowling, MoreSpares)
{
  std::vector<int> rolls = {
    1, 2, 7, 3, 4, 2, 0, 0, 0, 0, 4, 6, 2, 8, 5, 2, 0, 0, 0, 0,
  };
  EXPECT_EQ(rolls.size(), 20);
  EXPECT_EQ(bowlingScore(rolls), 3 + 14 + 6 + 12 + 15 + 7);
}

TEST(Bowling, Strike)
{
  std::vector<int> rolls = {
    10, 7, 3, 4, 2, 0, 0, 0, 0, 4, 6, 2, 8, 5, 2, 0, 0, 0, 0,
  };
  EXPECT_EQ(rolls.size(), 19);
  EXPECT_EQ(bowlingScore(rolls), 20 + 14 + 6 + 12 + 15 + 7);
}

TEST(Bowling, PerfectGame)
{
  std::vector<int> rolls = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  EXPECT_EQ(rolls.size(), 12);
  EXPECT_EQ(bowlingScore(rolls), 300);
}
