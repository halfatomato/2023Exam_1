//
// Created by qiuzhenxuan on 2023/11/27.
//

#ifndef CPPARRAYLIST__INT_ARRAY_LIST_H_
#define CPPARRAYLIST__INT_ARRAY_LIST_H_

#include <algorithm>
class int_array_list {
public:
  int_array_list() : int_array_list(2) {}

  explicit int_array_list(int capacity) {
    this->capacity = capacity;
    data = new int[capacity]{0};
    size = 0;
  }

  void set_capacity(int value) {
    int *new_data = new int[value]{0};
    size = std::min(size, value);
    for (int i = 0; i < size; i++) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    this->capacity = value;
  }

  int get_size() { return size; }

  void add(int value) {
    if (size == capacity) {
      set_capacity(capacity << 1);
    }
    data[size] = value;
    size++;
  }

  void removeAt(int index) {
    for (int i = index; i < size - 1; i++) {
      data[i] = data[i + 1];
    }
    size--;
    if (size <= capacity >> 2) {
      set_capacity(capacity >> 2);
    }
  }

  void remove(int value) {
    for (int i = 0; i < size; i++) {
      if (data[i] == value) {
        removeAt(i);
        break;
      }
    }
  }

  int get(int index) { return data[index]; }

private:
  int capacity;
  int size;
  int *data;
};

#endif // CPPARRAYLIST__INT_ARRAY_LIST_H_
