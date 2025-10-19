template <typename DataType>
SeqList<DataType> :: SeqList(DataType a[ ], int n)
{
    if (n > MaxSize) throw "�����Ƿ�";
    for (int i = 0; i < n; i++)
        data[i] = a[i];
    length = n;
}

template <typename DataType>
void SeqList<DataType> :: PrintList( )
{
    for (int i = 0; i < length; i++)
        cout << data[i] << " ";                //����������Ա��Ԫ��ֵ
    cout << endl;
 }

template <typename DataType>
DataType SeqList<DataType> :: Get(int i)
{
    if (i < 1 && i > length) throw "����λ�÷Ƿ�";
    else return data[i - 1];
}


template <typename DataType>
int SeqList<DataType> :: Locate(DataType x)
{
    for (int i = 0; i < length; i++)
      if (data[i] == x) return i+1;            //���������i+1
    return 0;                                  //�˳�ѭ����˵������ʧ��
}

template <typename DataType>
void SeqList<DataType> :: Insert(int i, DataType x)
{
    if (length == MaxSize) throw "����";
    if (i < 1 || i > length + 1) throw "����λ�ô���";
    for (int j = length; j >= i; j--)
        data[j] = data[j - 1];                 //��j��Ԫ�ش��������±�Ϊj-1��
    data[i - 1] = x;
    length++;
}

template <typename DataType>
DataType SeqList<DataType> :: Delete(int i)
{
    DataType x;
    if (length == 0) throw "����";
    if (i < 1 || i > length) throw "ɾ��λ�ô���";
    x = data[i - 1];                          //ȡ��λ��i��Ԫ��
    for (int j = i; j < length; j++)
        data[j - 1] = data[j];                //�˴�j�Ѿ���Ԫ�����ڵ������±�
    length--;
    return x;
}

