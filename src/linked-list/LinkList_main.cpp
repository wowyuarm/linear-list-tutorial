/****************************************
    对应教材2.6.2节，单链表的上机实现 
*****************************************/
#include <iostream>      //引入输入输出流
#include "LinkList.h"
#include "LinkList.cpp"

using namespace std;

int main( )
{
    int r[5] = {1, 2, 3, 4, 5}, i, x;
    LinkList<int> L{r, 5};
    cout << "当前线性表的数据为：";
    L.PrintList( );                                                //输出当前链表1 2 3 4 5
    try
    {
        L.Insert(2, 8);                                            //在第2个位置插入值为8的结点
        cout << "执行插入操作后数据为：";
        L.PrintList( );                                            //输出插入后链表1 8 2 3 4 5
    } catch(char *str) {cout << str << endl;}
    cout << "当前单链表的长度为：" << L.Length( ) << endl;        //输出单链表长度6
    cout << "请输入查找的元素值：";
    cin >> x;
    i = L.Locate(x);
    if (i > 0) cout << "元素" << x << "的位置为：" << i << endl;
    else cout << "单链表中没有元素" << x << endl;
    try
    {
        cout << "请输入要删除第几个元素：";
        cin >> i;
        x = L.Delete(i);                                           //删除第i个元素
        cout << "删除的元素值是" << x << "，执行删除操作后数据为：";
        L.PrintList( );                                            //输出删除后的单链表
    } catch(char *str) {cout << str << endl;}
    return 0;
}
