#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>
#include <iostream>
#include <conio.h>

using namespace cv;
using namespace std;

bool debug = true;

int WinMain(int argc, char **argv){
	Mat img;

	ifstream f;

	if (argc == 2){
		f.open(argv[1]);
	}
	else{
		f.open("plot.txt");
	}

	int configurationLines = 1;
	int sizex = 1, sizey = 1;
	Scalar color = Scalar::all(255);
	double radius = 5;
	double thickness = 1;
	bool defaultShow = true;

	string flag;
	int r, g, b, param, x, y, x1, x2, y1, y2;

	if (debug){
		if (f.good())
			cout << "File opened" << endl;
		else
			cout << "File not opened" << endl;
	}




	f >> sizex >> sizey;
	img = Mat(sizex, sizey, CV_8UC3, Scalar::all(0));
	if (debug)
		cout << "Size set to " << sizex << ", " << sizey << endl;


	while (f >> flag){
		if (debug)
			cout << "Instruction read : " << flag << endl;

		if (flag == "color"){
			f >> r >> g >> b;
			color = Scalar(b, g, r);

			if (debug)
				cout << "Color set to " << r << " " << g << " " << b << endl;
		}
		else if (flag == "radius"){
			f >> param;
			radius = param;

			if (debug)
				cout << "Radius set to " << param << endl;
		}
		else if (flag == "thick"){
			f >> param;

			if (debug)
				cout << "Thickness set to " << param << endl;

			thickness = param;
		}
		else if (flag == "dot"){
			f >> x >> y;

			if (debug)
				cout << "Drawing dot ( " << x << ", " << y << " )" << endl;

			circle(img, Point(x, y), radius, color, thickness);
		}
		else if (flag == "line"){
			f >> x1 >> y1 >> x2 >> y2;

			if (debug)
				cout << "Drawing line " << "( " << x1 << ", " << y1 << " ) to ( " << x2 << ", " << y2 << " )" << endl;

			line(img, Point(x1, y1), Point(x2, y2), color, thickness);
		}
		else if (flag == "wait"){
			f >> param;

			if (debug)
				cout << "Showing image for " << param << endl;

			imshow("PLOT", img);
			waitKey(param);
			defaultShow = false;
		}
		else if (flag == "clear"){
			f >> r >> g >> b;
			img = Scalar(b, g, r);

			if (debug)
				cout << "Image set to fill color " << r << " " << g << " " << b << endl;
		}
		else{
			cout << "Invalid Instruction" << endl;
		}
	}

	if (defaultShow){
		if (debug)
			cout << "defaultShow" << endl;

		imshow("PLOTTER", img);
		waitKey(0);
	}

	f.close();

	return 0;
}