#pragma once

#include "Macro.h"

template <typename T>
class CListNode
{
	template <typename T>
	friend class CList;

private:
	CListNode()
	{
		m_pPrev = nullptr;
		m_pNext = nullptr;
	}
	~CListNode()
	{
	}

private:
	T	m_Data;
	CListNode<T>* m_pPrev;
	CListNode<T>* m_pNext;
};

template <typename T>
class CList
{
public:
	CList()
	{
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}
	~CList()
	{
		PNODE pDeleteNode = m_pBegin;

		while (pDeleteNode != nullptr)
		{
			PNODE pNextNode = pDeleteNode->m_pNext;
			delete pDeleteNode;
			pDeleteNode = pNextNode;
		}		
	}

private:
	typedef CListNode<T>	NODE;
	typedef CListNode<T>*	PNODE;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	int m_iSize;

public:
	void Push_Back(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		PNODE pPrevNode = m_pEnd->m_pPrev;

		pPrevNode->m_pNext = pNode;
		pNode->m_pPrev = pPrevNode;
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void Pop_Front()
	{
		if (Empty())
			assert(false);

		PNODE pDeleteNode = m_pBegin->m_pNext;
		PNODE pNextNode = pDeleteNode->m_pNext;

		m_pBegin->m_pNext = pNextNode;
		pNextNode->m_pPrev = m_pBegin;

		delete pDeleteNode;
		--m_iSize;
	}

	void Pop_Back()
	{
		if (Empty())
			assert(false);

		PNODE pDeleteNode = m_pEnd->m_pPrev;
		PNODE pPrevNode = pDeleteNode->m_pPrev;

		m_pEnd->m_pPrev = pPrevNode;
		pPrevNode->m_pNext = m_pEnd;

		delete pDeleteNode;
		--m_iSize;
	}

	T front()
	{
		if (Empty())
			assert(false);

		return m_pBegin->m_pNext->m_Data;
	}

	T back()
	{
		if (Empty())
			assert(false);

		return m_pEnd->m_pPrev->m_Data;
	}

	void clear()
	{
		if (Empty())
			return;

		PNODE pDeleteNode = nullptr;
		PNODE pNextNode = nullptr;
		
		while (pDeleteNode != m_pEnd)
		{
			pDeleteNode = m_pBegin->m_pNext;
			pNextNode = pDeleteNode->m_pNext;

			m_pBegin->m_pNext = pNextNode;
			pNextNode->m_pPrev = m_pBegin;

			delete pDeleteNode;
		}

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}

	bool Empty()	const
	{
		if (m_iSize == 0)
			return true;

		return false;
	}

	int Size()	const
	{
		return m_iSize;
	}
};

