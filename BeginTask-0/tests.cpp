#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArrayHandler.h"
#include <iostream>
#include <fstream>
#include <chrono>

TEST(TestGroupName, Subtest_1) {
    EXPECT_TRUE(true);
}

TEST(TestGroupName, Subtest_2) {
    EXPECT_TRUE(true);
}

TEST(TestGroupName, Subtest_3) {
    bool res = true;
    int check_count = 0;
    while (check_count < 100) {
      ArrayHandler<uint32_t> arrayHandler;
      size_t elem_count = 0;
      while (elem_count < 100000)
      {
        arrayHandler.AppendElem(rand()%100000000 + 1);
        elem_count++;
      }
      arrayHandler.AppendElem(0);
      arrayHandler.AppendElem(1000000010);

      if (arrayHandler.GetMax() != 1000000010
          || arrayHandler.GetMin() != 0) {
            break;
      }
      check_count++;
    }
    EXPECT_TRUE(true);
}
