#pragma once
#include <iostream>
#include <cstring>
#include<string>
#include <fstream>




namespace MyExcel
{
	using namespace std;

	template<typename T>
	class Vector
	{
		T* data;
		int capacity;
		int length;

	public:

		typedef T value_type;

		Vector(int n = 10) : data(new T[n]), capacity(n), length(0) {};

		Vector(const Vector& other)
			: data(other.data), capacity(other.capacity), length(other.length)
		{
			for (int i = 0; i < length; i++)
			{
				data[i] = other.data[i];
			}
		}

		Vector(const Vector&& other)
			: data(other.data), capacity(other.capacity), length(other.length)
		{
			other.data = nullptr;
			other.capacity = 0;
			other.length = 0;
		}

		Vector& operator=(Vector& other)
		{
			if (this != &other) {
				delete[] data;

				data = new T[other.capacity];
				capacity = other.capacity;
				length = other.length;

				for (int i = 0; i < length; i++) {
					data[i] = other.data[i];
				}
			}
			return *this;
		}

		Vector& operator=(Vector&& other)
		{
			if (this != &other) {
				delete[] data;

				data = other.data;
				capacity = other.capacity;
				length = other.length;

				other.data = nullptr;
				other.capacity = 0;
				other.length = 0;
			}
			return *this;
		}


		void push_back(T s)
		{
			if (capacity <= length)
			{
				T* temp = new T[capacity * 2];

				for (int i = 0; i < length; i++)
				{
					temp[i] = std::move(data[i]);
				}

				delete[]data;

				data = temp;
				capacity *= 2;
			}

			data[length] = s;
			length++;


		}



		T& operator[] (int i) { return data[i]; }

		int size() { return length; }

		void remove(int x)
		{

			for (int i = x + 1; i < length; i++)
			{
				data[i - 1] = data[i];
			}

			length--;
		}

		~Vector()
		{
			if (data)
				delete[]data;
		}
	};



	template<>
	class Vector<bool>
	{
		unsigned int* data;
		int capacity;
		int length;

	public:

		typedef bool value_type;


		Vector(int n = 10) : data(new unsigned int [n/ 32 + 1]), capacity(n / 32 + 1), length(0) 
		{
			for (int i = 0; i < capacity; i++)
			{
				data[i] = 0;
			}
		};

		void push_back(bool s)
		{
			if (capacity * 32 <= length)
			{
				unsigned int* temp = new unsigned int[capacity * 2];

				for (int i = 0; i < capacity; i++)
				{
					temp[i] = data[i];
				}

				for (int i = capacity; i < capacity * 2; i++)
				{
					temp[i] = 0;
				}

				delete[]data;

				data = temp;
				capacity *= 2;
			}

			if (s)
			{
				data[length / 32] |= (1 << length % 32);
			}

			length++;
		}

		bool operator[] (int i) { return (data[i / 32] & (1 << (i % 32))) != 0; }

		int size() { return length; }

		void remove(int x)
		{

			for (int i = x + 1; i < length; i++)
			{
				int curr = i;
				int prev = i - 1;

				if ((data[curr / 32] & (1 << curr % 32)) == 1)
				{
					data[prev / 32] |= (1 << prev % 32);
				}
				else
				{
					unsigned int all_ones_except_prev = 0xFFFF;
					all_ones_except_prev ^= (1 << (prev % 32));
					data[prev / 32] &= all_ones_except_prev;
				}
			}

			length--;
		}

		~Vector()
		{
			if (data)
				delete[]data;
		}
	};

	class Stack
	{
		struct Node
		{
			Node* prev;
			std::string s;

			Node(Node* prev, std::string s) : prev(prev), s(s) {}
		};

		Node* current;
		Node start;

	public:
		Stack();

		// 최상단에 새로운 원소를 추가한다.
		void push(std::string s);

		// 최상단의 원소를 제거하고 반환한다.
		std::string pop();

		// 최상단의 원소를 반환한다. (제거 안함)
		std::string peek();

		// 스택이 비어있는지의 유무를 반환한다.
		bool is_empty();

		~Stack();
	};

	class NumStack {

		struct Node {
			Node* prev;
			double s;

			Node(Node* prev, double s) : prev(prev), s(s) {}
		};

		Node* current;
		Node start;

	public:
		NumStack();
		void push(double s);
		double pop();
		double peek();
		bool is_empty();

		~NumStack();
	};
}
