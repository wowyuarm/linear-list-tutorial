# 第3章：顺序表完整实现

> 从零开始，一步步实现顺序表

## 本章学习目标

1. 理解顺序表的存储结构
2. 实现顺序表的基本操作
3. 掌握每个操作的算法思想
4. 学会分析算法的复杂度

---

## 第一部分：顺序表的设计思想

### 3.1 顺序表的物理结构

#### 核心思想

用数组存储线性表，元素在内存中连续存放

#### 形象比喻

**顺序表 = 教室里的座位**
- 座位是连续排列的
- 每个座位有编号（0,1,2,3...）
- 可以直接通过编号找到座位

#### 内存布局

```
逻辑结构：(10, 20, 30, 40, 50)

物理结构：
下标    0      1      2      3      4      5 ...  99
地址  1000   1004   1008   1012   1016   1020 ... 1396
值     10     20     30     40     50    未用  ... 未用
       ↑                                  ↑
      data[0]                          data[5]

length = 5（当前元素个数）
MaxSize = 100（最大容量）
```

---

### 3.2 顺序表的类定义

#### 完整的头文件 SeqList.h

```cpp
#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED

using namespace std;

const int MaxSize = 100;    // 最大容量

template <typename DataType>
class SeqList {
public:
    SeqList();                           // 无参构造函数
    SeqList(DataType a[], int n);        // 有参构造函数
    ~SeqList() {};                       // 析构函数
    int Length() { return length; };     // 返回长度
    DataType Get(int i);                 // 按位查找
    int Locate(DataType x);              // 按值查找
    void Insert(int i, DataType x);      // 插入
    DataType Delete(int i);              // 删除
    int Empty();                         // 判空
    void PrintList();                    // 打印
    void Reverse();                      // 逆置
    void Sort();                         // 排序
    
private:
    DataType data[MaxSize];
    int length;
};

#endif
```

---

## 第二部分：构造函数的实现

### 3.3 无参构造函数

```cpp
template <typename DataType>
SeqList<DataType>::SeqList() {
    length = 0;    // 初始长度为0
}
```

**使用示例：**
```cpp
SeqList<int> L;           // 创建空表
cout << L.Length();       // 输出：0
```

---

### 3.4 有参构造函数

```cpp
template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {
    // 步骤1：检查参数合法性
    if (n > MaxSize) {
        throw "参数非法";
    }
    
    // 步骤2：复制元素
    for (int i = 0; i < n; i++) {
        data[i] = a[i];
    }
    
    // 步骤3：设置长度
    length = n;
}
```

**时间复杂度：** O(n)

---

## 第三部分：基本操作的实现

### 3.5 打印操作（PrintList）

```cpp
template <typename DataType>
void SeqList<DataType>::PrintList() {
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
```

**时间复杂度：** O(n)

---

### 3.6 按位查找（Get）

```cpp
template <typename DataType>
DataType SeqList<DataType>::Get(int i) {
    // 检查位置是否合法
    if (i < 1 || i > length) {
        throw "查找位置非法";
    }
    
    // 返回第i个元素
    return data[i - 1];    // 注意：i-1
}
```

**关键点：**
- 逻辑位置从1开始
- 数组下标从0开始
- 第i个元素 → data[i-1]

**时间复杂度：** O(1)

---

### 3.7 按值查找（Locate）

```cpp
template <typename DataType>
int SeqList<DataType>::Locate(DataType x) {
    // 遍历数组
    for (int i = 0; i < length; i++) {
        if (data[i] == x) {
            return i + 1;    // 找到了，返回位置
        }
    }
    return 0;                // 返回0表示查找失败
}
```

**时间复杂度：** O(n)

---

### 3.8 插入操作（Insert）⭐ 重点难点

#### 算法思想

1. 检查是否已满
2. 检查位置是否合法
3. **从后往前**移动元素
4. 在第i个位置放入x
5. 长度加1

#### 详细图解

```
原顺序表：{10, 20, 30, 40, 50}
位置：      1   2   3   4   5

任务：在第3个位置插入8

步骤1：从后往前移动
j=5: data[5] = data[4]  → 50后移
j=4: data[4] = data[3]  → 40后移
j=3: data[3] = data[2]  → 30后移

步骤2：插入8
data[2] = 8

结果：{10, 20, 8, 30, 40, 50}
```

#### 代码实现

```cpp
template <typename DataType>
void SeqList<DataType>::Insert(int i, DataType x) {
    if (length == MaxSize) throw "上溢";
    if (i < 1 || i > length + 1) throw "插入位置错误";
    
    // 从后往前移动元素
    for (int j = length; j >= i; j--) {
        data[j] = data[j - 1];
    }
    
    data[i - 1] = x;
    length++;
}
```

**为什么从后往前移？**  
避免覆盖未移动的元素！

**时间复杂度：** O(n)

---

### 3.9 删除操作（Delete）⭐ 重点难点

#### 算法思想

1. 检查表是否为空
2. 检查位置是否合法
3. 保存第i个元素的值
4. **从前往后**移动元素
5. 长度减1
6. 返回被删除的值

#### 详细图解

```
原顺序表：{10, 20, 30, 40, 50}
位置：      1   2   3   4   5

任务：删除第3个位置的元素

步骤1：保存值
x = data[2] = 30

步骤2：从前往后移动
j=3: data[2] = data[3]  → 40前移（覆盖30）
j=4: data[3] = data[4]  → 50前移

结果：{10, 20, 40, 50}
```

#### 代码实现

```cpp
template <typename DataType>
DataType SeqList<DataType>::Delete(int i) {
    DataType x;
    if (length == 0) throw "下溢";
    if (i < 1 || i > length) throw "删除位置错误";
    
    x = data[i - 1];
    
    // 从前往后移动元素
    for (int j = i; j < length; j++) {
        data[j - 1] = data[j];
    }
    
    length--;
    return x;
}
```

**时间复杂度：** O(n)

---

## 第四部分：高级操作

### 3.10 逆置操作（Reverse）

#### 算法思想：双指针法

```cpp
template <typename DataType>
void SeqList<DataType>::Reverse() {
    int left = 0;
    int right = length - 1;
    DataType temp;
    
    while (left < right) {
        // 交换data[left]和data[right]
        temp = data[left];
        data[left] = data[right];
        data[right] = temp;
        
        left++;
        right--;
    }
}
```

**示例：**
```
原数组：{1, 3, 8, 9, 2}
逆置后：{2, 9, 8, 3, 1}
```

**时间复杂度：** O(n)  
**空间复杂度：** O(1)

---

### 3.11 排序操作（Sort）- 冒泡排序

#### 算法思想

重复遍历数组，比较相邻元素并交换，最大元素"冒泡"到末尾

#### 代码实现（优化版）

```cpp
template <typename DataType>
void SeqList<DataType>::Sort() {
    bool swapped;
    DataType temp;
    
    for (int i = 0; i < length - 1; i++) {
        swapped = false;
        
        for (int j = 0; j < length - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                swapped = true;
            }
        }
        
        // 优化：如果没有交换，提前退出
        if (!swapped) break;
    }
}
```

**示例：**
```
原数组：{5, 2, 4, 1, 3}
排序后：{1, 2, 3, 4, 5}
```

**时间复杂度：**
- 最好：O(n)（已排序）
- 最坏：O(n²)
- 平均：O(n²)

**空间复杂度：** O(1)

---

## 第五部分：完整代码汇总

### 完整的 SeqList.cpp

查看源码：[src/sequential-list/SeqList.cpp](../../src/sequential-list/SeqList.cpp)

### 完整的 SeqList_main.cpp

查看源码：[src/sequential-list/SeqList_main.cpp](../../src/sequential-list/SeqList_main.cpp)

---

## 第3章小结

### 核心知识点

✅ 顺序表用数组存储，元素连续  
✅ length记录元素个数，MaxSize限制容量  
✅ 位置从1开始，下标从0开始  
✅ **插入**：从后往前移动元素  
✅ **删除**：从前往后移动元素  
✅ 访问：O(1)，插入删除：O(n)  

### 操作总结表

| 操作 | 时间复杂度 | 关键点 |
|------|-----------|--------|
| 构造函数 | O(n) | 复制n个元素 |
| 按位查找 | O(1) | 直接访问 |
| 按值查找 | O(n) | 遍历查找 |
| 插入 | O(n) | 移动元素 |
| 删除 | O(n) | 移动元素 |
| 逆置 | O(n) | 双指针法 |
| 排序 | O(n²) | 冒泡排序 |

---

## 练习题

### 练习1：实现判空函数

```cpp
template <typename DataType>
int SeqList<DataType>::Empty() {
    // 请实现：如果为空返回1，否则返回0
}
```

### 练习2：手动模拟

原表：`{5, 10, 15, 20}`  
执行：`Insert(2, 8)`  
画出每一步的变化

### 练习3：思考题

为什么插入要从后往前移动，删除要从前往后移动？  
如果反过来会怎样？

**答案在第4章末尾**

---

**下一章：** [第4章：单链表完整实现](04-linked-list.md) - 理解指针，掌握链式存储

[返回目录](../README.md)

