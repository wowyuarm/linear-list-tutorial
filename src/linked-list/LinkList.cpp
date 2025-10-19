#include <iostream>
#include "LinkList.h"

//�޲ι��캯��
template <typename DataType>
LinkList<DataType> :: LinkList( )
{
    first = new Node<DataType>;              //����ͷ���
    first->next = nullptr;                  //ͷ����ָ�����ÿ�
}

//��������
template <typename DataType>
void LinkList<DataType> :: PrintList( )
{
    Node<DataType> *p = first->next;         //����ָ��p��ʼ��
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;                         //����ָ��p���ƣ�ע�ⲻ��д��p++
    }
    cout << endl;
}

//������ĳ���
template <typename DataType>
int LinkList<DataType> :: Length( )
{
    Node<DataType> *p = first->next;        //����ָ��p��ʼ��Ϊ��ʼ�ӵ�
    int count = 0;                         //�ۼ���count��ʼ��
    while (p !=nullptr)
    {
        p = p->next;
        count++;
    }
    return count;                         //ע��count�ĳ�ʼ���ͷ���ֵ֮��Ĺ�ϵ
}

//��λ����
template <typename DataType>
DataType LinkList<DataType> :: Get(int i)
{
    Node<DataType> *p = first->next;        //����ָ��p��ʼ��
    int count = 1;                         //�ۼ���count��ʼ��
    while (p != nullptr && count < i)
    {
        p = p->next;                        //����ָ��p����
        count++;
    }
    if (p == nullptr) throw "����λ�ô���";
    else return p->data;
}

//��ֵ����
template <typename DataType>
int LinkList<DataType> :: Locate(DataType x)
{
    Node<DataType> *p = first->next;        //����ָ��p��ʼ��
    int count = 1;                         //�ۼ���count��ʼ��
    while (p != nullptr)
    {
        if (p->data == x) return count;   //���ҳɹ��������������������
        p = p->next;
        count++;
    }
    return 0;                              //�˳�ѭ����������ʧ��
}

//�������
template <typename DataType>
void LinkList<DataType> :: Insert(int i, DataType x)
{
    Node<DataType> *p = first, *s = nullptr;   //����ָ��p��ʼ��
    int count = 0;
    while (p != nullptr && count < i - 1)     //���ҵ�i �C 1�����
    {
        p = p->next;                            //����ָ��p����
        count++;
    }
    if (p == nullptr) throw "����λ�ô���";   //û���ҵ���i-1�����
    else {
        s = new Node<DataType>; s->data = x;    //������s��������Ϊx
        s->next = p->next; p->next = s;         //�����s���뵽���p֮��
    }
}

 //���캯����������������
template <typename DataType>
LinkList<DataType> :: LinkList(DataType a[ ], int n)
{
    first = new Node<DataType>; first->next = nullptr;     //��ʼ��һ��������
    for (int i = 0; i < n; i++)
    {
        Node<DataType> *s = nullptr;
        s = new Node<DataType>; s->data = a[i];
        s->next = first->next; first->next = s;   //�����s���뵽ͷ���֮��
    }
}

//ɾ������
template <typename DataType>
DataType LinkList<DataType> :: Delete(int i)
{
    DataType x;
    Node<DataType> *p = first, *q = nullptr;    //����ָ��pָ��ͷ���
    int count = 0;
    while (p != nullptr && count < i - 1)     //���ҵ�i-1�����
    {
        p = p->next;
        count++;
    }
    if (p == nullptr || p->next == nullptr)    //���p�����ڻ�p�ĺ�̽�㲻����
        throw "ɾ��λ�ô���";
    else {
        q = p->next; x = q->data;                //�ݴ汻ɾ���
        p->next = q->next;                       //ժ��
        delete q;
        return x;
    }
}

//���������������ٵ�����
template <typename DataType>
LinkList<DataType> :: ~LinkList( )
{
    Node<DataType> *p = first;
    while (first != nullptr)                   //�ͷŵ������ÿһ�����Ĵ洢�ռ�
    {
        first = first->next;                     // firstָ���ͷŽ�����һ�����
        delete p;
        p = first;                               //����ָ��p����
    }
}

