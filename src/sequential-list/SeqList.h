#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED

using namespace std;
//˳�����ඨ��
const int MaxSize = 100;                 //100ֻ��ʾ���Ե����ݣ�����ʵ��������嶨��
template <typename DataType>            //����ģ����SeqList
class SeqList
{
    public:
       SeqList( );                        //�޲ι��캯���������յ�˳���
       SeqList(DataType a[ ], int n);     //�вι��캯������������Ϊn��˳���
       ~SeqList( ){};                     //��������
       int Length( ){return length ;};   //�����Ա�ĳ���
       DataType Get(int i);               //��λ���ң����ҵ�i��Ԫ�ص�ֵ
       int Locate(DataType x );           //��ֵ���ң�����ֵΪx��Ԫ�����
       void Insert(int i, DataType x);   //����������ڵ�i��λ�ò���ֵΪx��Ԫ��
       DataType Delete(int i);            //ɾ��������ɾ����i��Ԫ��
       int Empty( );                      //�ж����Ա��Ƿ�Ϊ��
       void PrintList( );                 //������������������������Ԫ��
    private:
       DataType data[MaxSize];            //�������Ԫ�ص�����
       int length;                        //���Ա�ĳ���
};


#endif // SEQLIST_H_INCLUDED
