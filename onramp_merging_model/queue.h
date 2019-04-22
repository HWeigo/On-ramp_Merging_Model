/*
* \file queue.h
* \brief 基于vector实现队列
*/

#ifndef __QUEUE_H
#define __QUEUE_H

#include "includes.h"

#define queueSize 10    //指定队列大小

/*
* \brief 压栈
* 将内容压入栈顶
* \param queue 队列参数
* \param element 压栈内容
*/
template <class T>
void push_QueueBack(vector<T> &queue, T element);

/*
* \brief 出栈（不删除）
* 仅返回栈顶内容，不删除
* \param queue 队列参数
* \return 返回栈顶内容
*/
template <class T>
T pop_QueueBack(vector<T> &queue);

/*
* \brief 显示
* \param queue 队列参数
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


