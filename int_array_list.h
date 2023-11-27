//
// Created by qiuzhenxuan on 2023/11/27.
//

#ifndef CPPARRAYLIST__INT_ARRAY_LIST_H_
#define CPPARRAYLIST__INT_ARRAY_LIST_H_

#include <algorithm>
class int_array_list {
public:
  //默认构造函数
  int_array_list() = default;

  //返回数组元素数量
  int get_size();

  //向数组尾添加元素
  void add(int value);

  //移除数组中指定位置的元素，并将后面的元素向前移动
  void removeAt(int index);

  //删除第一个出现的指定元素（如果存在），并将后面的元素向前移动
  void remove(int value);

  //返回数组中指定位置的元素
  int get(int index);
};

#endif // CPPARRAYLIST__INT_ARRAY_LIST_H_
