# 第5章：高级算法实现

> 逆置与排序的完整解析

## 算法总览

| 数据结构 | 逆置算法 | 排序算法 | 时间复杂度 |
|---------|---------|---------|-----------|
| 顺序表 | 双指针法 | 冒泡排序 | O(n) / O(n²) |
| 单链表 | 头插法 | 选择排序 | O(n) / O(n²) |

---

## 5.1 顺序表逆置 - 双指针法

### 算法思想
从两端向中间，交换元素

### 代码
```cpp
void Reverse() {
    int left = 0, right = length - 1;
    DataType temp;
    while (left < right) {
        swap(data[left], data[right]);
        left++;
        right--;
    }
}
```

### 示例
```
{1, 3, 8, 9, 2} → {2, 9, 8, 3, 1}
```

---

## 5.2 顺序表排序 - 冒泡排序

### 算法思想
比较相邻元素，大的往后"冒泡"

### 优化版代码
```cpp
void Sort() {
    bool swapped;
    for (int i = 0; i < length - 1; i++) {
        swapped = false;
        for (int j = 0; j < length - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // 提前退出
    }
}
```

### 示例
```
{5, 2, 4, 1, 3} → {1, 2, 3, 4, 5}
```

---

## 5.3 单链表逆置 - 头插法

### 算法思想
将节点依次摘下，重新头插

### 代码
```cpp
void Reverse() {
    Node* p = first->next;
    Node* q = nullptr;
    first->next = nullptr;
    
    while (p != nullptr) {
        q = p->next;
        p->next = first->next;
        first->next = p;
        p = q;
    }
}
```

---

## 5.4 单链表排序 - 选择排序

### 算法思想
对每个位置，找后续最小值，交换数据域

### 代码
```cpp
void Sort() {
    Node *p, *q, *min;
    DataType temp;
    
    p = first->next;
    while (p != nullptr) {
        min = p;
        q = p->next;
        while (q != nullptr) {
            if (q->data < min->data)
                min = q;
            q = q->next;
        }
        if (min != p) {
            swap(p->data, min->data);
        }
        p = p->next;
    }
}
```

---

## 5.5 组合应用：降序排列

**方法：** 先升序排序，再逆置

```cpp
L.Sort();      // 升序：{1, 2, 3, 4, 5}
L.Reverse();   // 逆置：{5, 4, 3, 2, 1}
```

**时间复杂度：** O(n²) + O(n) = O(n²)

---

## 复杂度总结

| 操作 | 顺序表 | 单链表 | 说明 |
|------|--------|--------|------|
| 逆置 | O(n), O(1) | O(n), O(1) | 时间/空间 |
| 排序 | O(n²), O(1) | O(n²), O(1) | 冒泡/选择 |

---

**完整源码：** 查看 [src/](../../src/) 目录  
**下一章：** [第6章：综合应用与实战](06-comprehensive-practice.md)  
[返回目录](INDEX.md)

