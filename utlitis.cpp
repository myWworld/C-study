#pragma once
#include "datastructure.h"

namespace MyExcel
{

	

	Stack::Stack():start(NULL, 0) { current = &start; }

	// 최상단에 새로운 원소를 추가한다.
	void Stack::push(std::string s)
	{

		Node* n = new Node(current, s);
		current = n;
	}

	// 최상단의 원소를 제거하고 반환한다.
	std::string Stack::pop()
	{
		if (current == &start) return "";


		std::string s = current->s;
		Node* temp = current;
		current = current->prev;

		delete temp;
		return s;

	}

	// 최상단의 원소를 반환한다. (제거 안함)
	std::string Stack::peek()
	{
		return current->s;
	}

	// 스택이 비어있는지의 유무를 반환한다.
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

