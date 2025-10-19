#include <iostream>
#include "LinkList.h"

//无参构造函数
template <typename DataType>
LinkList<DataType> :: LinkList( )
{
    first = new Node<DataType>;              //生成头结点
    first->next = nullptr;                  //头结点的指针域置空
}

//遍历操作
template <typename DataType>
void LinkList<DataType> :: PrintList( )
{
    Node<DataType> *p = first->next;         //工作指针p初始化
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;                         //工作指针p后移，注意不能写作p++
    }
    cout << endl;
}

//求单链表的长度
template <typename DataType>
int LinkList<DataType> :: Length( )
{
    Node<DataType> *p = first->next;        //工作指针p初始化为开始接点
    int count = 0;                         //累加器count初始化
    while (p !=nullptr)
    {
        p = p->next;
        count++;
    }
    return count;                         //注意count的初始化和返回值之间的关系
}

//按位查找
template <typename DataType>
DataType LinkList<DataType> :: Get(int i)
{
    Node<DataType> *p = first->next;        //工作指针p初始化
    int count = 1;                         //累加器count初始化
    while (p != nullptr && count < i)
    {
        p = p->next;                        //工作指针p后移
        count++;
    }
    if (p == nullptr) throw "查找位置错误";
    else return p->data;
}

//按值查找
template <typename DataType>
int LinkList<DataType> :: Locate(DataType x)
{
    Node<DataType> *p = first->next;        //工作指针p初始化
    int count = 1;                         //累加器count初始化
    while (p != nullptr)
    {
        if (p->data == x) return count;   //查找成功，结束函数并返回序号
        p = p->next;
        count++;
    }
    return 0;                              //退出循环表明查找失败
}

//插入操作
template <typename DataType>
void LinkList<DataType> :: Insert(int i, DataType x)
{
    Node<DataType> *p = first, *s = nullptr;   //工作指针p初始化
    int count = 0;
    while (p != nullptr && count < i - 1)     //查找第i – 1个结点
    {
        p = p->next;                            //工作指针p后移
        count++;
    }
    if (p == nullptr) throw "插入位置错误";   //没有找到第i-1个结点
    else {
        s = new Node<DataType>; s->data = x;    //申请结点s，数据域为x
        s->next = p->next; p->next = s;         //将结点s插入到结点p之后
    }
}

 //构造函数——建立单链表
template <typename DataType>
LinkList<DataType> :: LinkList(DataType a[ ], int n)
{
    first = new Node<DataType>; first->next = nullptr;     //初始化一个空链表
    for (int i = 0; i < n; i++)
    {
        Node<DataType> *s = nullptr;
        s = new Node<DataType>; s->data = a[i];
        s->next = first->next; first->next = s;   //将结点s插入到头结点之后
    }
}

//删除操作
template <typename DataType>
DataType LinkList<DataType> :: Delete(int i)
{
    DataType x;
    Node<DataType> *p = first, *q = nullptr;    //工作指针p指向头结点
    int count = 0;
    while (p != nullptr && count < i - 1)     //查找第i-1个结点
    {
        p = p->next;
        count++;
    }
    if (p == nullptr || p->next == nullptr)    //结点p不存在或p的后继结点不存在
        throw "删除位置错误";
    else {
        q = p->next; x = q->data;                //暂存被删结点
        p->next = q->next;                       //摘链
        delete q;
        return x;
    }
}

//析构函数——销毁单链表
template <typename DataType>
LinkList<DataType> :: ~LinkList( )
{
    Node<DataType> *p = first;
    while (first != nullptr)                   //释放单链表的每一个结点的存储空间
    {
        first = first->next;                     // first指向被释放结点的下一个结点
        delete p;
        p = first;                               //工作指针p后移
    }
}

