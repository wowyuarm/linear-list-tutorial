/****************************************
    ��Ӧ�̲�2.6.2�ڣ���������ϻ�ʵ�� 
*****************************************/
#include <iostream>      //�������������
#include "LinkList.h"
#include "LinkList.cpp"

using namespace std;

int main( )
{
    int r[5] = {1, 2, 3, 4, 5}, i, x;
    LinkList<int> L{r, 5};
    cout << "��ǰ���Ա������Ϊ��";
    L.PrintList( );                                                //�����ǰ����1 2 3 4 5
    try
    {
        L.Insert(2, 8);                                            //�ڵ�2��λ�ò���ֵΪ8�Ľ��
        cout << "ִ�в������������Ϊ��";
        L.PrintList( );                                            //������������1 8 2 3 4 5
    } catch(char *str) {cout << str << endl;}
    cout << "��ǰ������ĳ���Ϊ��" << L.Length( ) << endl;        //�����������6
    cout << "��������ҵ�Ԫ��ֵ��";
    cin >> x;
    i = L.Locate(x);
    if (i > 0) cout << "Ԫ��" << x << "��λ��Ϊ��" << i << endl;
    else cout << "��������û��Ԫ��" << x << endl;
    try
    {
        cout << "������Ҫɾ���ڼ���Ԫ�أ�";
        cin >> i;
        x = L.Delete(i);                                           //ɾ����i��Ԫ��
        cout << "ɾ����Ԫ��ֵ��" << x << "��ִ��ɾ������������Ϊ��";
        L.PrintList( );                                            //���ɾ����ĵ�����
    } catch(char *str) {cout << str << endl;}
    return 0;
}
