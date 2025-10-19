#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

using namespace std;

//��������Ľ��ṹ����
template <typename DataType>
struct Node
{
    DataType data;              //������
    Node<DataType> *next;       //ָ����
};

//��������Ķ���
template <typename DataType>
class LinkList
{
    public:
        LinkList( );                      //�޲ι��캯��������ֻ��ͷ���Ŀ�����
        LinkList(DataType a[ ], int n);   //�вι��캯����������n��Ԫ�صĵ�����
        ~LinkList( );                     //��������
        int Length( );                    //������ĳ���
        DataType Get(int i);              //��λ���ҡ����ҵ�i������Ԫ��ֵ
        int Locate(DataType x);           //��ֵ���ҡ�����ֵΪx��Ԫ�����
        void Insert(int i, DataType x);   //�����������i��λ�ò���ֵΪx�Ľ��
        DataType Delete(int i);           //ɾ��������ɾ����i�����
        int Empty( );                     //�ж����Ա��Ƿ�Ϊ��
        void PrintList( );                //������������������������Ԫ��
    private:
        Node<DataType> *first;             //�������ͷָ��
};


#endif // LINKLIST_H_INCLUDED
