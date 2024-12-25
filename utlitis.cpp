#pragma once
#include "datastructure.h"

namespace MyExcel
{

	

	Stack::Stack():start(NULL, 0) { current = &start; }

	// �ֻ�ܿ� ���ο� ���Ҹ� �߰��Ѵ�.
	void Stack::push(std::string s)
	{

		Node* n = new Node(current, s);
		current = n;
	}

	// �ֻ���� ���Ҹ� �����ϰ� ��ȯ�Ѵ�.
	std::string Stack::pop()
	{
		if (current == &start) return "";


		std::string s = current->s;
		Node* temp = current;
		current = current->prev;

		delete temp;
		return s;

	}

	// �ֻ���� ���Ҹ� ��ȯ�Ѵ�. (���� ����)
	std::string Stack::peek()
	{
		return current->s;
	}

	// ������ ����ִ����� ������ ��ȯ�Ѵ�.
	bool Stack::is_empty()
	{
		if (current == &start)
			return true;

		return false;
	}

	Stack::~Stack()
	{
		while (current != &start)
		{
			Node* temp = current;
			current = current->prev;

			delete temp;
		}
	}

	NumStack::NumStack() : start(NULL, 0) { current = &start; }
	void NumStack::push(double s) {
		Node* n = new Node(current, s);
		current = n;
	}
	double NumStack::pop() {
		if (current == &start) return 0;

		double s = current->s;
		Node* prev = current;
		current = current->prev;

		// Delete popped node
		delete prev;
		return s;
	}
	double NumStack::peek() { return current->s; }
	bool NumStack::is_empty() {
		if (current == &start) return true;
		return false;
	}
	NumStack::~NumStack() {
		while (current != &start) {
			Node* prev = current;
			current = current->prev;
			delete prev;
		}
	}
}

