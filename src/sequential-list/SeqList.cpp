template <typename DataType>
SeqList<DataType> :: SeqList(DataType a[ ], int n)
{
    if (n > MaxSize) throw "参数非法";
    for (int i = 0; i < n; i++)
        data[i] = a[i];
    length = n;
}

template <typename DataType>
void SeqList<DataType> :: PrintList( )
{
    for (int i = 0; i < length; i++)
        cout << data[i] << " ";                //依次输出线性表的元素值
    cout << endl;
 }

template <typename DataType>
DataType SeqList<DataType> :: Get(int i)
{
    if (i < 1 && i > length) throw "查找位置非法";
    else return data[i - 1];
}


template <typename DataType>
int SeqList<DataType> :: Locate(DataType x)
{
    for (int i = 0; i < length; i++)
      if (data[i] == x) return i+1;            //返回其序号i+1
    return 0;                                  //退出循环，说明查找失败
}

template <typename DataType>
void SeqList<DataType> :: Insert(int i, DataType x)
{
    if (length == MaxSize) throw "上溢";
    if (i < 1 || i > length + 1) throw "插入位置错误";
    for (int j = length; j >= i; j--)
        data[j] = data[j - 1];                 //第j个元素存在数组下标为j-1处
    data[i - 1] = x;
    length++;
}

template <typename DataType>
DataType SeqList<DataType> :: Delete(int i)
{
    DataType x;
    if (length == 0) throw "下溢";
    if (i < 1 || i > length) throw "删除位置错误";
    x = data[i - 1];                          //取出位置i的元素
    for (int j = i; j < length; j++)
        data[j - 1] = data[j];                //此处j已经是元素所在的数组下标
    length--;
    return x;
}

