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
#include <stdio.h>
#include <stdlib.h>
#define max_capacity 10

struct list
{
    int size;
    int capacity;
    int* arr;
};

int main()
{
   struct list* a = (struct list*)malloc(sizeof(struct list));
   a->arr = (int*)malloc(sizeof(int) * max_capacity);
   a->size = 0;
   a->capacity = max_capacity;
  return 0;
}

  //返回数组元素数量
 int get_size(struct list* a)
{
    return a->size;
}
  //向数组尾添加元素
  void add(struct list* a,int value)
{
  if(a->size < capacity)
  {
    a->arr[a->size] = value;
    a->size++;
  }
  if(a->size >= capacity)
  {
    int* ptr = (int*)realloc(a->arr,sizeof(int) * (a->capacity+1));
    if(ptr != NULL)
    {
       a->arr = ptr;
       a->arr[a->size+1] = value;
       a->size++;
       a->capacity++;
    }
    if(ptr == NULL)
    {
        printf("空间申请失败");
    }
  }
}

  //移除数组中指定位置的元素，并将后面的元素向前移动
  void removeAt(struct list* a , int index)
{
   if(index<0 || index >a->size)
   {
    printf("输入错误");
   }
   else
   {int i = index;
   for(i;i<a->size;i++)
   {
    a->arr[i] = a->arr[i+1];
   }
   a->size--;
   }

}
  //删除第一个出现的指定元素（如果存在），并将后面的元素向前移动
 void my_remove(struct list* a,int value)
{
   int left = 0;
   int right = a->size-1;
   while(left<=right)
   {
    int mid = (a->arr[left]+a->arr[right])/2;
    if(a->arr[mid]<value)
    {
        left++;
    }
    else if(a->arr[mid]>value)
    {
        right--;
    }
    else if(a->arr[mid]=value)
    {
      int i = mid;
      for(i;i<a->size-1;i++)
      {
        a->arr[i] = a->arr[i+1];
      }
      a->size--;
    }
    else
    {
        printf("找不到指定数");
    }
   }
}

  //返回数组中指定位置的元素
 int get(struct list* a,int index)
{
  return a->arr[index]; 
}



#endif // CPPARRAYLIST__INT_ARRAY_LIST_H_
