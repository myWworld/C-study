#pragma once
#include <iostream>
#include <cstring>
#include<string>
#include "datastructure.h"

namespace MyExcel
{
	class Table;

	class Excel
	{
		Table* current_table;

	public:

		Excel(int max_row, int max_col, int choice);

		int parse_user_input(string s);
		void command_line();
	};

	class Cell
	{
	protected:

		Table* table;
		int x, y;

	public:

		virtual string stringify() = 0;
		virtual int to_numeric() = 0;

		Cell(int x, int y, Table* table);
	};

	class StringCell : public Cell {
		string data;

	public:
		string stringify();
		int to_numeric();

		StringCell(string data, int x, int y, Table* t);
	};

	class NumberCell : public Cell {

		int data;

	public:
		string stringify();
		int to_numeric();

		NumberCell(int data, int x, int y, Table* t);
	};

	class DateCell : public Cell {

		time_t data;

	public:
		string stringify();
		int to_numeric();

		DateCell(string s, int x, int y, Table* t);
	};

	class ExprCell : public Cell
	{
		string data;
		string* parsed_expr;

		Vector<string> exp_vec;

		int predecence(char c);

		void parse_expression();

	public:

		ExprCell(string data, int x, int y, Table* t);
		string stringify();
		int to_numeric();
	};

	class Table
	{
	protected:

		int max_row_size, max_col_size;

		Cell*** data_table;

	public:

		Table(int  max_row_size, int max_col_size);

		~Table();

		void reg_cell(Cell* c, int row, int col);

		int to_numeric(const string& s);
		int to_numeric(int row, int col);

		string stringify(const string& s);
		string stringify(int row, int col);

		virtual std::string print_table() = 0;
	};


	class TextTable : public Table
	{
		string repeat_char(int n, char c);
		string col_num_to_str(int n);

	public:
		std::string print_table() override;

		TextTable(int row, int col);

	};

	class HtmlTable : public Table
	{
	public:
		HtmlTable(int row, int col);

		string print_table()override;
	};

	class CSVTable : public Table
	{
	public:
		CSVTable(int row, int col);

		string print_table()override;
	};



}

