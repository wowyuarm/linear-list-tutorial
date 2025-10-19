/****************************************
    对应教材2.6.1节，顺序表的上机实现 
*****************************************/
#include <iostream>
#include "SeqList.h"
#include "SeqList.cpp"

using namespace std;

int main( )
{
    int r[5] = {1, 2, 3, 4, 5}, i, x;
    SeqList<int> L{r, 5};                          //建立具有5个元素的顺序表
    cout << "当前线性表的数据为：";
    L.PrintList( );                                //输出当前线性表1 2 3 4 5
    try
    {
        L.Insert(2, 8);                            //在第2个位置插入值为8的元素
        cout << "执行插入操作后数据为：";
        L.PrintList( );                            //输出插入后的线性表1 8 2 3 4 5
    } catch(char *str) {cout << str << endl;}
    cout << "当前线性表的长度为：" << L.Length( ) << endl;    //输出线性表的长度6
    cout << "请输入查找的元素值：";
    cin >> x;
    i = L.Locate(x);
    if (0 == i)
        cout << "查找失败" << endl;
    else
        cout << "元素" << x << "的位置为：" << i << endl;
    try
    {
        cout << "请输入查找第几个元素值：";
        cin >> i;
        cout << "第" << i << "个元素值是" << L.Get(i) << endl;
    } catch(char *str){
        cout << str << endl;
    }
    try
   {
        cout << "请输入要删除第几个元素：";
        cin >> i;
        x = L.Delete(i);                                       //删除第i个元素
        cout << "删除的元素是" << x <<"，删除后数据为：";
        L.PrintList( );                                        //输出删除后的线性表
    } catch(char *str){
       cout << str << endl;
    }
    return 0;
}
