/****************************************
    ��Ӧ�̲�2.6.1�ڣ�˳�����ϻ�ʵ�� 
*****************************************/
#include <iostream>
#include "SeqList.h"
#include "SeqList.cpp"

using namespace std;

int main( )
{
    int r[5] = {1, 2, 3, 4, 5}, i, x;
    SeqList<int> L{r, 5};                          //��������5��Ԫ�ص�˳���
    cout << "��ǰ���Ա������Ϊ��";
    L.PrintList( );                                //�����ǰ���Ա�1 2 3 4 5
    try
    {
        L.Insert(2, 8);                            //�ڵ�2��λ�ò���ֵΪ8��Ԫ��
        cout << "ִ�в������������Ϊ��";
        L.PrintList( );                            //������������Ա�1 8 2 3 4 5
    } catch(char *str) {cout << str << endl;}
    cout << "��ǰ���Ա�ĳ���Ϊ��" << L.Length( ) << endl;    //������Ա�ĳ���6
    cout << "��������ҵ�Ԫ��ֵ��";
    cin >> x;
    i = L.Locate(x);
    if (0 == i)
        cout << "����ʧ��" << endl;
    else
        cout << "Ԫ��" << x << "��λ��Ϊ��" << i << endl;
    try
    {
        cout << "��������ҵڼ���Ԫ��ֵ��";
        cin >> i;
        cout << "��" << i << "��Ԫ��ֵ��" << L.Get(i) << endl;
    } catch(char *str){
        cout << str << endl;
    }
    try
   {
        cout << "������Ҫɾ���ڼ���Ԫ�أ�";
        cin >> i;
        x = L.Delete(i);                                       //ɾ����i��Ԫ��
        cout << "ɾ����Ԫ����" << x <<"��ɾ��������Ϊ��";
        L.PrintList( );                                        //���ɾ��������Ա�
    } catch(char *str){
       cout << str << endl;
    }
    return 0;
}
