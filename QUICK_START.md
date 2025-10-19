# 快速开始指南

## 🎯 5分钟快速入门

### 第1步：克隆或下载项目

```bash
git clone https://github.com/yourusername/linear-list-tutorial.git
cd linear-list-tutorial
```

或者直接下载 ZIP 文件解压。

### 第2步：选择你的学习路径

#### 路径A：我想直接运行代码 💻

```bash
# 编译顺序表
cd src/sequential-list
g++ -std=c++11 -o SeqList SeqList_main.cpp
./SeqList

# 编译单链表
cd ../linked-list
g++ -std=c++11 -o LinkList LinkList_main.cpp
./LinkList
```

或使用 DEV C++：
1. 打开 `SeqList_main.cpp` 或 `LinkList_main.cpp`
2. 按 F11 编译运行

详见：[DEV C++ 使用指南](guides/dev-cpp-guide.md)

#### 路径B：我想系统学习 📚

**零基础：**
1. [第1章：C++ 基础知识](docs/01-cpp-basics.md)
2. [第2章：数据结构基础](docs/02-data-structure-basics.md)
3. 继续后续章节...

**有基础：**
- 直接从 [第3章：顺序表实现](docs/03-sequential-list.md) 开始

完整目录：[教程索引](docs/INDEX.md)

#### 路径C：我要完成作业 📝

1. 快速浏览前2章，了解基础
2. 学习第3-5章，理解实现
3. 运行代码，截图保存结果
4. 参考 [作业提交指南](guides/assignment-guide.md)
5. 查看 [新增代码汇总](guides/code-summary.md)

---

## 📂 项目结构速览

```
linear-list-tutorial/
├── docs/           ← 📚 6章完整教程
├── src/            ← 💻 可运行的源代码
├── guides/         ← 📖 实用指南（作业、编译等）
└── README.md       ← 项目主页
```

---

## 🎓 学习建议

1. **边学边做** - 不要只看不动手
2. **画图辅助** - 特别是指针操作
3. **做练习题** - 每章末尾都有
4. **使用费曼学习法** - 讲给别人听

---

## 💡 核心概念速查

### 顺序表
- **特点**：连续存储，随机访问快
- **操作**：插入O(n)，删除O(n)，访问O(1)
- **逆置**：双指针法
- **排序**：冒泡排序

### 单链表
- **特点**：分散存储，动态灵活
- **操作**：插入O(1)，删除O(1)，访问O(n)
- **逆置**：头插法
- **排序**：选择排序

---

## 🐛 遇到问题？

1. **编译错误**
   - 检查是否支持 C++11：加 `-std=c++11`
   - 确保 `.h` `.cpp` `_main.cpp` 在同一目录

2. **运行错误**
   - 查看 [DEV C++ 使用指南](guides/dev-cpp-guide.md)
   - 查看第6章：综合应用与实战

3. **其他问题**
   - 提交 GitHub Issue
   - 查看文档中的"常见问题"部分

---

## ⭐ 收藏和分享

如果这个项目对你有帮助：
- ⭐ 给项目加星
- 🔗 分享给同学
- 🐛 报告问题
- 💡 提出建议

---

**现在就开始学习吧！** → [教程目录](docs/INDEX.md)

[返回主页](README.md)

