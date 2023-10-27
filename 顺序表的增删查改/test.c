#include"SeqList.h"

void TestSeqList1(SL* seq)
{
	SeqListInit(seq);
}
void TestSeqList2(SL* seq)
{
	SeqListPushBack(seq, 2);
	SeqListPushBack(seq, 3);
	SeqListPushBack(seq, 4);
	SeqListPushBack(seq, 5);
	SeqListPrint(seq);
}
void TestSeqList3(SL* seq)
{
	SeqListPushFront(seq, 6);
	SeqListPushFront(seq, 7);
	SeqListPushFront(seq, 10);
	SeqListPrint(seq);
}
void TestSeqList4(SL* seq)
{
	SeqListPopBack(seq);
	SeqListPrint(seq);
}
void TestSeqList5(SL* seq)
{
	SeqListPopFront(seq);
	SeqListPrint(seq);
}
void TestSeqList6(SL* seq)
{
	SeqListInsert(seq, 2);
}
void TestSeqList7(SL* seq)
{
	SeqListModify(seq, 2);
	SeqListPrint(seq);
}
void TestSeqList8(SL* seq)
{
	SeqListSort(seq);
	SeqListPrint(seq);
}
int main()
{
	SL sq;
	TestSeqList1(&sq);
	TestSeqList2(&sq);
	TestSeqList3(&sq);
	TestSeqList4(&sq);
	TestSeqList5(&sq);
	TestSeqList6(&sq);
	TestSeqList7(&sq);
	TestSeqList8(&sq);
	return 0;
}
