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

	Triangle tr(1, 2, 3, 1, 2, 3);
	PR_triangle pr_tr(1, 2, 3, 1, 2);
	RB_triangle rb_tr(1, 2, 1, 2);
	RS_triangle rs_tr(1, 60);
	print_info(&tr);
	print_info(&pr_tr);
	print_info(&rb_tr);
	print_info(&rs_tr);

	Quadrilateral quad(1, 2, 3, 4, 1, 2, 3, 4);
	PR_q pr_q(1, 2);
	Square sq(1);
	Romb r(1, 60, 50);
	Parallelogramm paralm(1, 2, 60, 50);
	print_info(&quad);
	print_info(&pr_q);
	print_info(&sq);
	print_info(&r);
	print_info(&paralm);


	return 0;
}