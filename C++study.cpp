#pragma once
#include <iostream>
#include <cstring>
#include<string>
#include <fstream>
#include <windows.h>
#include "MyExcel.h"

#pragma execution_character_set( "utf-8" )

using namespace MyExcel;


std::ostream& operator<<(std::ostream& o, Table& t) {
	o << t.print_table();
	return o;

}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(NULL);
		std::cout.tie(NULL);

		SetConsoleOutputCP(CP_UTF8);

		//std::cout
		//	<< "테이블 (타입) (최대 행 크기) (최대 열 크기) 를 순서대로 입력해주세요"
		//	<< std::endl;
		//std::cout << "* 참고 * " << std::endl;
		//std::cout << "1 : 텍스트 테이블, 2 : CSV 테이블, 3 : HTML 테이블"
		//	<< std::endl;
		//
		//int type, max_row, max_col;
		//std::cin >> type >> max_row >> max_col;
		//MyExcel::Excel m(max_row, max_col, type - 1);
		//m.command_line();

		Vector<int> int_vec;
		int_vec.push_back(3);
		int_vec.push_back(2);

		std::cout << "-------- int vector ----------" << std::endl;
		std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
		std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

		Vector<std::string> str_vec;
		str_vec.push_back("hello");
		str_vec.push_back("world");
		std::cout << "-------- std::string vector -------" << std::endl;
		std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
		std::cout << "두번째 원소 : " << str_vec[1] << std::endl;

		Vector<bool> bool_vec;
		bool_vec.push_back(true);
		bool_vec.push_back(true);
		bool_vec.push_back(false);
		bool_vec.push_back(false);
		bool_vec.push_back(false);
		bool_vec.push_back(true);
		bool_vec.push_back(false);
		bool_vec.push_back(true);
		bool_vec.push_back(false);
		bool_vec.push_back(true);
		bool_vec.push_back(false);
		bool_vec.push_back(true);
		bool_vec.push_back(false);
		bool_vec.push_back(true);
		bool_vec.push_back(false);
		bool_vec.push_back(true);
		bool_vec.push_back(false);

		std::cout << "-------- bool vector ---------" << std::endl;
		for (int i = 0; i < bool_vec.size(); i++) {
			std::cout << bool_vec[i];
		}
		std::cout << std::endl;

		return 0;
	}

