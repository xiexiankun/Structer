#define _CRT_SECURE_NO_WARNINGS 
#include<vector>
#include<iostream>
using namespace std;
template<class T>
class BitMap
{
public:
	BitMap()//无参数的拷贝构造
		:_size(0)
	{}
	BitMap(size_t size)//有个数的拷贝构造
		:_size(0)
	{
		_array.resize((size>>5)+1);//一个整数4个字节32个二进制位  这里求的是开辟了多少个字节
	}
	void Set(size_t num)
	{
		//把第0字节1位置置为1
		size_t index = num >> 5;//字节位置
		size_t n = num % 32;
		//_array[0]表示0至31；_array[index]=00000000 00000000 00000000 00000000
		_array[index] |= (1 << n);//写入1后得到00000000 00000000 000000000 000000010
	}
	void Reset(size_t num)
	{
		size_t index = num >> 5;
		size_t n = num % 32;
		_array[index] &= ~(1 << n);
	}
	bool Test(size_t num)
	{
		size_t index = num >> 5;
		size_t n = num % 32;
		return _array[index] & (1 << n);
	}
public:
	vector<size_t> _array;
	size_t _size;
};
void Test()
{
	BitMap<size_t> bm(66);
	bm.Set(1);
	bm.Set(34);
	bm.Set(4);
	cout << "1?" << bm.Test(1) << endl;
	cout << "34?" << bm.Test(34) << endl;
	cout << "4?" << bm.Test(4) << endl;

	bm.Reset(34);
	cout << "1?" << bm.Test(1)<<endl;
	cout << "34?" << bm.Test(34) << endl;
	cout << "4?" << bm.Test(4) << endl;

}
int main()
{
	Test();
	system("pause");
	return 0;
}