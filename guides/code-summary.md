# 新增代码汇总

> 提交作业时可直接复制此部分

## 一、顺序表新增代码

### 1. SeqList.h 新增函数声明

```cpp
void Reverse();    // 【新增功能】逆置操作，将线性表中的元素顺序反转
void Sort();       // 【新增功能】排序操作，对线性表进行升序排序（冒泡排序）
```

### 2. SeqList.cpp 新增逆置函数实现

```cpp
//【新增功能】逆置操作 - 将顺序表中的元素顺序反转
//算法思想：使用双指针法，从两端向中间交换元素
//时间复杂度：O(n/2) = O(n)，空间复杂度：O(1)
template <typename DataType>
void SeqList<DataType>::Reverse() {
    int left = 0;                             //左指针，指向数组起始位置
    int right = length - 1;                   //右指针，指向数组末尾位置
    DataType temp;                            //临时变量，用于交换
    
    //当左指针小于右指针时，继续交换
    while (left < right) {
        temp = data[left];                    //交换data[left]和data[right]
        data[left] = data[right];
        data[right] = temp;
        left++;                               //左指针右移
        right--;                              //右指针左移
    }
}
```

### 3. SeqList.cpp 新增排序函数实现

```cpp
//【新增功能】排序操作 - 使用冒泡排序对顺序表进行升序排序
//算法思想：重复遍历数组，比较相邻元素并交换，将最大元素"冒泡"到末尾
//时间复杂度：最坏O(n²)，最好O(n)（已排序情况），空间复杂度：O(1)
template <typename DataType>
void SeqList<DataType>::Sort() {
    bool swapped;                             //标志位，记录本轮是否发生交换
    DataType temp;
    
    //外层循环：控制排序的轮数（n-1轮）
    for (int i = 0; i < length - 1; i++) {
        swapped = false;                      //每轮开始前重置标志位
        
        //内层循环：进行相邻元素的比较和交换
        //每轮结束后，最大的元素会移动到未排序部分的末尾
        for (int j = 0; j < length - 1 - i; j++) {
            if (data[j] > data[j + 1]) {      //如果前一个元素大于后一个元素
                temp = data[j];               //交换这两个元素
                data[j] = data[j + 1];
                data[j + 1] = temp;
                swapped = true;               //标记发生了交换
            }
        }
        
        //优化：如果某一轮没有发生交换，说明数组已经有序，可以提前结束
        if (!swapped) break;
    }
}
```

### 4. SeqList_main.cpp 修改测试数据

```cpp
// 修改前：
int r[5] = {1, 2, 3, 4, 5}, i, x;

// 修改后：
int r[8] = {15, 3, 28, 9, 2, 28, 7, 12}, i, x;
```

### 5. SeqList_main.cpp 新增功能测试代码

```cpp
//【新增功能测试】测试逆置操作
cout << "\n========== 测试逆置功能 ==========" << endl;
cout << "逆置前的数据：";
L.PrintList();
L.Reverse();                                  //调用逆置函数
cout << "逆置后的数据：";
L.PrintList();

//【新增功能测试】测试排序操作
cout << "\n========== 测试排序功能 ==========" << endl;
cout << "排序前的数据：";
L.PrintList();
L.Sort();                                     //调用排序函数
cout << "排序后的数据（升序）：";
L.PrintList();

//【扩展测试】再次逆置，得到降序排列
cout << "\n========== 再次逆置得到降序 ==========" << endl;
L.Reverse();
cout << "降序排列的数据：";
L.PrintList();

cout << "\n程序执行完毕！" << endl;
```

---

## 二、单链表新增代码

### 1. LinkList.h 新增函数声明

```cpp
void Reverse();    // 【新增功能】逆置操作，将链表中的元素顺序反转
void Sort();       // 【新增功能】排序操作，对链表进行升序排序（选择排序）
```

### 2. LinkList.cpp 新增逆置函数实现

```cpp
//【新增功能】逆置操作 - 将单链表中的结点顺序反转
//算法思想：采用头插法，将原链表的结点依次摘下来插入到头结点之后
//时间复杂度：O(n)，空间复杂度：O(1)
//原理：遍历原链表，将每个结点从原位置摘下，插入到新链表的头部
template <typename DataType>
void LinkList<DataType>::Reverse() {
    Node<DataType>* p = first->next;          //p指向第一个数据结点
    Node<DataType>* q = nullptr;              //q用于暂存p的后继结点
    first->next = nullptr;                    //将头结点的next置空，准备重新构建链表
    
    //遍历原链表的所有结点
    while (p != nullptr) {
        q = p->next;                          //暂存p的后继结点
        p->next = first->next;                //将p结点插入到头结点之后（头插法）
        first->next = p;                      //更新头结点的next指针
        p = q;                                //p指向下一个待处理的结点
    }
}
```

### 3. LinkList.cpp 新增排序函数实现

```cpp
//【新增功能】排序操作 - 使用选择排序对单链表进行升序排序
//算法思想：对于每个位置，从后续未排序部分找到最小值，交换数据域（不改变指针）
//时间复杂度：O(n²)，空间复杂度：O(1)
//注意：这里采用交换数据域的方式，而不是调整指针，更简单易懂
template <typename DataType>
void LinkList<DataType>::Sort() {
    Node<DataType> *p, *q, *min;              //p为外层循环指针，q为内层循环指针，min记录最小值结点
    DataType temp;                            //用于交换数据的临时变量
    
    //外层循环：从第一个结点开始，依次确定每个位置的最小值
    p = first->next;
    while (p != nullptr) {
        min = p;                              //假设当前结点p为最小值结点
        q = p->next;                          //q从p的下一个结点开始
        
        //内层循环：在p后面的所有结点中查找最小值
        while (q != nullptr) {
            if (q->data < min->data)          //如果找到更小的值
                min = q;                      //更新最小值结点
            q = q->next;                      //继续向后查找
        }
        
        //如果最小值不是p自己，则交换p和min的数据域
        if (min != p) {
            temp = p->data;
            p->data = min->data;
            min->data = temp;
        }
        
        p = p->next;                          //外层循环指针后移
    }
}
```

### 4. LinkList_main.cpp 修改测试数据

```cpp
// 修改后：
int r[7] = {18, 5, 32, 11, 3, 32, 9}, i, x;
```

### 5. LinkList_main.cpp 新增功能测试代码

（与顺序表类似）

---

## 三、算法复杂度对比表

| 操作类型 | 顺序表算法 | 复杂度 | 单链表算法 | 复杂度 |
|---------|-----------|--------|-----------|--------|
| 逆置操作 | 双指针法 | O(n) | 头插法 | O(n) |
| 排序操作 | 冒泡排序 | O(n²) | 选择排序 | O(n²) |
| 空间开销 | - | O(1) | - | O(1) |

**说明：**
- 两种数据结构的逆置和排序时间复杂度相同
- 所有新增算法都是原地操作，额外空间开销 O(1)

---

## 四、测试数据说明

### 顺序表测试数据

```cpp
{15, 3, 28, 9, 2, 28, 7, 12}
```

**特点：**
- 8个元素（增加测试规模）
- 乱序排列（测试排序功能）
- 包含重复值28（测试算法对重复元素的处理）
- 数值范围较大（2-28）

### 单链表测试数据

```cpp
{18, 5, 32, 11, 3, 32, 9}
```

**特点：**
- 7个元素
- 乱序排列
- 包含重复值32
- 注意：由于构造函数使用头插法，实际存储顺序是逆序

---

**返回：** [作业提交指南](assignment-guide.md)  
[返回目录](../README.md)

