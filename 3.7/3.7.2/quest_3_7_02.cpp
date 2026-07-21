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
#include "fig_error_class.h"

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
	try
	{
		Triangle tr(1, 2, 3, 90, 60, 30);
		print_info(&tr);
		PR_triangle pr_tr(1, 2, 3, 30, 60);
		print_info(&pr_tr);
		RB_triangle rb_tr(1, 2, 30, 120);
		print_info(&rb_tr);
		RS_triangle rs_tr(1, 60);
		print_info(&rs_tr);

		Quadrilateral quad(1, 2, 3, 4, 80, 30, 80, 170);
		print_info(&quad);
		PR_q pr_q(1, 2);
		print_info(&pr_q);
		Square sq(1);
		print_info(&sq);
		Romb r(1, 60, 50);
		print_info(&r);
		Parallelogramm paralm(1, 2, 60, 50);
		print_info(&paralm);
	}
	catch (fig_error& ex)
	{
		cout << ex.what();
	}
	
	return 0;
}