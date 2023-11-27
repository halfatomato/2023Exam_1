//
// Created by qiuzhenxuan on 2023/11/27.
//
#include "../int_array_list.h"
#include "gtest/gtest.h"
#include <random>

// Demonstrate some basic assertions.
TEST(IntArrayListTest, Features) {
  int min = INT_MIN, max = INT_MAX;
  std::random_device seed;
  std::ranlux48 engine(seed());
  std::uniform_int_distribution<> distrib(min, max);

  auto v = new std::vector<int>();
  auto list = new int_array_list();

  for (int i = 0; i < (1 << 8); i++) {
    int value = distrib(engine);
    v->push_back(value);
    list->add(value);
  }
  EXPECT_EQ(v->size(), list->get_size());
  for (int i = 0; i < v->size(); i++) {
    EXPECT_EQ(v->at(i), list->get(i));
  }

  for (int i = 0; i < (1 << 6); ++i) {
    int index = abs(distrib(engine)) % (int)v->size();
    v->erase(v->begin() + index);
    list->removeAt(index);
  }
  EXPECT_EQ(v->size(), list->get_size());
  for (int i = 0; i < v->size(); i++) {
    EXPECT_EQ(v->at(i), list->get(i));
  }

  for (int i = 0; i < (1 << 6); ++i) {
    int index = abs(distrib(engine)) % (int)v->size();
    v->erase(std::remove(v->begin(), v->end(), v->at(index)));
    list->remove(list->get(index));
  }
  EXPECT_EQ(v->size(), list->get_size());
  for (int i = 0; i < v->size(); i++) {
    EXPECT_EQ(v->at(i), list->get(i));
  }
}
