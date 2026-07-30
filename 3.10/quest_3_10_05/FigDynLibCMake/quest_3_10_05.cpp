#include <iostream>
#include <string>
#include "class_Figure.h"
#include "class_Triangle.h"
#include "class_PR_triangle.h"
#include "class_RB_triangle.h"
#include "class_RS_triangle.h"
#include "class_Quadrilateral.h"
#include "class_PR_q.h"
#include "class_Romb.h"
#include "class_Square.h"
#include "class_Parallelogramm.h"

using namespace std;

void print_info(Figure* fig)
{
	fig->get_name();
	fig->get_sides();
	fig->get_angles();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Triangle tr(10, 20, 30, 50, 60, 70);
	PR_triangle pr_tr(10, 20, 30, 50, 60);
	RB_triangle rb_tr(10, 20, 50, 60);
	RS_triangle rs_tr(30, 60);
	print_info(&tr);
	print_info(&pr_tr);
	print_info(&rb_tr);
	print_info(&rs_tr);

	Quadrilateral quad(10, 20, 30, 40, 50, 60, 70, 80);
	PR_q pr_q(10, 20);
	Square sq(20);
	Romb r(30, 30, 40);
	Parallelogramm paralm(20, 30, 30, 40);
	print_info(&quad);
	print_info(&pr_q);
	print_info(&sq);
	print_info(&r);
	print_info(&paralm);


	return 0;
}