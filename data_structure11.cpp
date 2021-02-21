#include <iostream>
using namespace std;

#define QUE_LEN 100

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _lQueue
{
	Node* front;
	Node* rear;	
}LQueue;

typedef LQueue Queue;

void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

void QIsEmpty(Queue* pq)
{
	if (pq->front == NULL)
		return 1;
	else
		return 0;
}

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enquque(Queue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

void Dequeue(Queue* pq)
{
	Node* delNode;
	Data reData;

	if (QIsEmpty(pq))
	{
		cout << "큐 메모리 에러!\n";
		exit(-1);
	}

	delNode = pq->front;
	reData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return reData;
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		cout << "큐 메모리 에러!\n";
		exit(-1);
	}

	return pq->front->data;
}

int main()
{
	Queue q;
	QueueInit(&q);

	Enquque(&q, 1);
	Enquque(&q, 2);
	Enquque(&q, 3);
	Enquque(&q, 4);
	Enquque(&q, 5);

	while (!QIsEmpty(&q))
		cout << Dequeue(&q) << endl;

	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

