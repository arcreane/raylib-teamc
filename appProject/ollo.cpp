#include "ollo.h"

ollo::ollo()
{
	cells[0] = Vec2{ 1,1 }; // terf dlisr col 1
	cells[1] = Vec2{ 2,1 }; // li lfo9  col 2
	cells[2] = Vec2{ 2,2 }; // li f center col 2
	cells[3] = Vec2{ 3,2 }; // li f limn col 3
	//i = 1;
}

void ollo::Turn()
{

	printf("i == %d\n", i);

	switch (i) {
	case 1:
		cells[0].setY(cells[0].getY() + 1);
		break;
	case 2:
		cells[0].setY(cells[0].getY() + 1);
		cells[0].setX(cells[0].getX() + 1);
		break;
	case 3:
		cells[1].setX(cells[1].getX() - 1);
		cells[1].setY(cells[1].getY() + 1);
		break;
	case 4:
		cells[3].setX(cells[3].getX() - 1);
		cells[3].setY(cells[3].getY() - 1);
		break;
	case 5:
		cells[3].setX(cells[3].getX() + 1);
		cells[3].setY(cells[3].getY() + 1);
		cells[1].setX(cells[1].getX() + 1);
		cells[1].setY(cells[1].getY() - 1);
		cells[0].setY(cells[0].getY() - 1);
		cells[0].setX(cells[0].getX() - 1);
		i = 1;
		break;
	}

	//if (i == 1) {
	//	cells[0].setY(cells[0].getY() + 1);
	//	//	/* 0 1          1
	//	//	     2 3  =>  0 2 3 */
	//}
	//else if (i == 2) {
	//	cells[0].setY(cells[0].getY() + 1);
	//	cells[0].setX(cells[0].getX() + 1);
	//	//	//	//		/*   1        1
	//	//	//	//		   0 2 3  ==> 2 3
	//	//	//	//					  0    */
	//}
	//else if (i == 3) {
	//	printf("HASH");
	//	cells[1].setX(cells[1].getX() - 1);
	//	cells[1].setY(cells[1].getY() + 1);
	//	//		/*   1
	//	//		     2 3 ==>  1 2 3
	//	//			 0          0    */
	//}
	//else if (i == 4) {
	//	cells[3].setX(cells[3].getX() - 1);
	//	cells[3].setY(cells[3].getY() - 1);
	//	//		/*                3
	//	//		    1 2 3  ==>  1 2
 //		//	          0           0  */
	//}
	//else if (i == 5) {
	//	cells[3].setX(cells[3].getX() + 1);
	//	cells[3].setY(cells[3].getY() + 1);
	//	cells[1].setX(cells[1].getX() + 1);
	//	cells[1].setY(cells[1].getY() - 1);
	//	cells[0].setY(cells[0].getY() - 2);
	//	cells[0].setX(cells[0].getX() - 1);
	//	//		/*        3       0 1
	//	//		        1 2  ==>    2 3
	//	//	              0            */
	//	i = 1;
	//}

	i++;
	printf("i == %d\n", i);
	
	//if (cells[0].getY() != cells[2].getY()) { // 3 != 2
	//	/* 0 1          1
	//	     2 3  =>  0 2 3 */
	//	printf("1>>>>>>>>>>>>>>>>>>>[0]%d\n", cells[0].getY());
	//	printf("1>>>>>>>>>>>>>>>>>>>[2]%d\n", cells[2].getY());
	//	cells[0].setY(cells[0].getY() + 1);
	//	printf("1>>>>>>>>>>>>>>>>>>>[0]%d\n", cells[0].getY());
	//	printf("1>>>>>>>>>>>>>>>>>>>[2]%d\n", cells[2].getY());
	//}
	//else if (cells[0].getY() == cells[2].getY()) { // cells[0] = Vec2{ 1,2 };
	//	printf("2>>>>>>>>>>>>>>>>>>>[0]%d\n", cells[0].getY());
	//	printf("2>>>>>>>>>>>>>>>>>>>[2]%d\n", cells[2].getY());
	//	//	//		/*   1        1
	//	//	//		   0 2 3  ==> 2 3
	//	//	//					  0    */
	//	cells[0].setY(cells[0].getY() + 1);
	//	cells[0].setX(cells[0].getX() + 1);
	//	printf("2>>>>>>>>>>>>>>>>>>>[0]%d\n", cells[0].getY());
	//	printf("2>>>>>>>>>>>>>>>>>>>[2]%d\n", cells[2].getY());
	//} // cells[0] = Vec2{ 2,3 };


	//if (cells[0].getY() != cells[2].getY()) {
	//	cells[0].setY(cells[0].getY() + 1);
	//	cells[0].setX(cells[0].getX() + 1);
	//	//		/*  0        0
	//	//		   000  ==>	 00
	//	//					 0*/
	//}
	//else
	//if (cells[0].getX()) {
	//	cells[0].setY(cells[0].getY() + 1);
	//	cells[0].setX(cells[0].getX() + 1);
	//	cells[1].setY(cells[1].getY() + 1);
	//	cells[1].setX(cells[1].getX() + 1);
	//	cells[3].setY(cells[3].getY() + 1);
	//	cells[3].setX(cells[3].getX() + 1);
	//}

	


	/*if (cells[0].getY() != cells§[2].getY()) {
		printf("1>>>>>>>>>>>>>>>>>>>[0]%d\n", cells[0].getY());
		printf("1>>>>>>>>>>>>>>>>>>>[2]%d\n", cells[2].getY());
		cells[0].setY(cells[0].getY() + 2);
		cells[0].setX(cells[0].getX() + 1);
		cells[1].setY(cells[1].getY() + 1);
		cells[1].setX(cells[1].getX() + 1);
		cells[3].setY(cells[3].getY() + 1);
		cells[3].setX(cells[3].getX() + 1);
		printf("1>>>>>>>>>>>>>>>>>>>[0]%d\n", cells[0].getY());
		printf("1>>>>>>>>>>>>>>>>>>>[2]%d\n", cells[2].getY());
	}
	else {
		printf("2>>>>>>>>>>>>>>>>>>>[0]%d\n", cells[0].getY());
		printf("2>>>>>>>>>>>>>>>>>>>[2]%d\n", cells[2].getY());
		cells[0].setY(cells[0].getY() + 2);
		cells[0].setX(cells[0].getX() + 2);
		cells[1].setY(cells[1].getY() + 1);
		cells[1].setX(cells[1].getX() + 1);
		cells[3].setY(cells[3].getY() + 1);
		cells[3].setX(cells[3].getX() + 1);
		printf("2>>>>>>>>>>>>>>>>>>>[0]%d\n", cells[0].getY());
		printf("2>>>>>>>>>>>>>>>>>>>[2]%d\n", cells[2].getY());
	}*/
	

	//if (cells[2].getX() - cells[3].getX() == 0) {
	//	if (cells[2].getY() - cells[3].getY() > 0) {
	//		/*  0        0
	//		   000  ==>	 00
	//					 0*/
	//		cells[0].setX(cells[0].getX() - 2);
	//		cells[0].setY(cells[0].getY() + 2);
	//		cells[1].setX(cells[1].getX() - 1);
	//		cells[1].setY(cells[1].getY() + 1);
	//		cells[3].setX(cells[3].getX() + 1);
	//		cells[3].setY(cells[3].getY() + 1);
	//	}
	//	else
	//	{
	//		/* 000       0
	//			 0  ==>  0
	//					00*/
	//		cells[0].setX(cells[0].getX() + 2);
	//		cells[0].setY(cells[0].getY() - 2);
	//		cells[1].setX(cells[1].getX() + 1);
	//		cells[1].setY(cells[1].getY() - 1);
	//		cells[3].setX(cells[3].getX() - 1);
	//		cells[3].setY(cells[3].getY() - 1);
	//	}
	//}
	//else
	//{
	//	if (cells[2].getX() - cells[3].getX() > 0) {
	//		int i;
	//		switch (cells[2].getX())
	//		{
	//		case(9):
	//			i = -2;
	//			break;
	//		default:
	//			i = 0;
	//			break;
	//		}
	//		cells[0].setX(cells[0].getX() + 2 + i);
	//		cells[0].setY(cells[0].getY() + 2);
	//		cells[1].setX(cells[1].getX() + 1 + i);
	//		cells[1].setY(cells[1].getY() + 1);

	//		cells[3].setX(cells[3].getX() + 1 + i);
	//		cells[3].setY(cells[3].getY() - 1);
	//		cells[2].setX(cells[2].getX() + i);
	//	}
	//	else
	//	{
	//		int i;
	//		switch (cells[2].getX())
	//		{
	//		case(0):
	//			i = 2;
	//			break;
	//		default:
	//			i = 0;
	//			break;
	//		}
	//		cells[0].setX(cells[0].getX() - 2 + i);
	//		cells[0].setY(cells[0].getY() - 2);
	//		cells[1].setX(cells[1].getX() - 1 + i);
	//		cells[1].setY(cells[1].getY() - 1);

	//		cells[3].setX(cells[3].getX() - 1 + i);
	//		cells[3].setY(cells[3].getY() + 1);
	//		cells[2].setX(cells[2].getX() + i);
	//	}
	//}
}
