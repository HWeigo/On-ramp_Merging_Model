/*
* \file queue.h
* \brief ����vectorʵ�ֶ���
*/

#ifndef __QUEUE_H
#define __QUEUE_H

#include "includes.h"

#define queueSize 10    //ָ�����д�С

/*
* \brief ѹջ
* ������ѹ��ջ��
* \param queue ���в���
* \param element ѹջ����
*/
template <class T>
void push_QueueBack(vector<T> &queue, T element);

/*
* \brief ��ջ����ɾ����
* ������ջ�����ݣ���ɾ��
* \param queue ���в���
* \return ����ջ������
*/
template <class T>
T pop_QueueBack(vector<T> &queue);

/*
* \brief ��ʾ
* \param queue ���в���
*/
template <class T>
void showQueue(vector<T> queue);

/**********************************/
template <class T>
void push_QueueBack(vector<T> &queue, T element)
{

	if (queue.size() == queueSize)
	{
		for (int i = 0; i < queueSize - 1; i++)
		{
			queue[i] = queue[i + 1];
		}
		queue[queueSize - 1] = element;
	}
	else
	{
		queue.push_back(element);
	}
}

template <class T>
T pop_QueueBack(vector<T> &queue)
{
	return queue[queue.size() - 1];
}

template <class T>
void showQueue(vector<T> queue)
{
	for (int i = 0; i < queue.size(); i++)
	{
		cout << queue[i] << ' ';
	}
	cout << endl;
}


#endif // !__QUEUE_H


