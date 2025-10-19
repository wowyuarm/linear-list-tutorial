#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

using namespace std;

//将单链表的结点结构定义
template <typename DataType>
struct Node
{
    DataType data;              //数据域
    Node<DataType> *next;       //指针域
};

//单链表类的定义
template <typename DataType>
class LinkList
{
    public:
        LinkList( );                      //无参构造函数，建立只有头结点的空链表
        LinkList(DataType a[ ], int n);   //有参构造函数，建立有n个元素的单链表
        ~LinkList( );                     //析构函数
        int Length( );                    //求单链表的长度
        DataType Get(int i);              //按位查找。查找第i个结点的元素值
        int Locate(DataType x);           //按值查找。查找值为x的元素序号
        void Insert(int i, DataType x);   //插入操作，第i个位置插入值为x的结点
        DataType Delete(int i);           //删除操作，删除第i个结点
        int Empty( );                     //判断线性表是否为空
        void PrintList( );                //遍历操作，按序号依次输出各元素
    private:
        Node<DataType> *first;             //单链表的头指针
};


#endif // LINKLIST_H_INCLUDED
