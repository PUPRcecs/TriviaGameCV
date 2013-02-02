/********************************************************************************************
Jonathan Torres Rodriguez 10612
Christian Santana Diaz 68918
Description: This program is a Trivia game that includes "OpenCV" libraries to load images. 
*///******************************************************************************************
#include <opencv2/core/core.hpp> //library
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h> //library to convert images to gray_scale
#include <opencv/highgui.h> //library to convert images to gray_scale
#include <iostream>//library for input and output
#include <ctime>// library for time(0) function
#include <string>// for string variable
#include <windows.h>// for Sleep(N)funcion
#include "Question.h"// header file
;using namespace std;
using namespace cv;
void error2();//error reporting prototype
int main()
{
	char sex;//for select avatar and genger
	Mat Iplayer1;//saves avatar image for player1
	Mat Iplayer2;//saves avatar image for player2
	Mat Itemp;// hold image of one avatar
	Mat Itemps;//hold image of one avatar
	Question trivia;// object to call the question
	string player1;//variable that holds the name of player1
	string player2;//variable that holds the name of player2
	int point1=0;// variable that holds the points of player1
	int point2=0;// variable that holds the points of player2
	int count=0;// counter to end loop of question
	char temp;// hold the number of question in char
	int temp2;// hold the number of question in int
	unsigned int seed=time(0);// uses time to generate random number
	srand(seed);// generates random number
	Mat image;// variable thats holds any image 
	Mat gray_image;//variable that holds the gray image 
	char question[10]={48,49, 50, 51, 52, 53, 54, 55, 56, 57};//array that holds the number of questions remaning and validates them
	system("title Trivia Game");//changes the name of the console
	//system("color");//change the color of console and text
	image = imread("Trivia.jpg", CV_LOAD_IMAGE_COLOR); // Reads the file name Trivia.jpg and loads in color mode
	if(!image.data ) // Checks for invalid input of image
	{
		cout << "Could not open or find the image" << endl ;//display to console
		system("pause");//pause the program
		return -1;
	}
	cvtColor( image, gray_image, CV_RGB2GRAY );//convert image into gray and asigns to gray_image
	imwrite( "Gray_Image.jpg", gray_image );//save gray_image as Gray_Image.jpg
	namedWindow( "Trivia", CV_WINDOW_AUTOSIZE );//rename and format windows
	namedWindow( "Gray Trivia", CV_WINDOW_AUTOSIZE );//format the console to display image
	imshow("Trivia", image );// shows image into the console 
	imshow( "Gray Trivia", gray_image );//display image to console
	waitKey(3000); // Wait for a key to be pressed
	destroyWindow("Trivia");//destroy console "named"
	destroyWindow("Gray Trivia");//destroy console "named"
	Sleep(2000);//stop the program for 2 seconds
	system("cls");//clean the console
	cout<<"\n\n\nPlayer1 name:";//ask for the name of player1
	cin>>player1;
	do{// start of loop to validate gender
		system("cls");
		cout<<"a.male\nb.female\nSelect your gender:";
		cin >> sex;
		if(sex!='a'&&sex!='b'&&sex!='c')
		{
			error2();//call function for error
		}
	}while(sex!='a'&&sex!='b'&&sex!='c');//end of gender validation
	system("cls");
	if(sex=='a')// if male is selected then
	{
		image= imread("men1.png",CV_LOAD_IMAGE_COLOR);//load image men1 in image as a color image
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar1",CV_WINDOW_NORMAL);//formatted the output console 
		Itemps= imread("men2.png",CV_LOAD_IMAGE_COLOR);//load image men2 in Itemps as a color image 
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar2",CV_WINDOW_NORMAL);//formatted the output console
		Itemp= imread("men3.png",CV_LOAD_IMAGE_COLOR);//load image men3 in Itemp as a color image
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar3",CV_WINDOW_NORMAL);//formatted the output console
		resizeWindow("Avatar3",300,216);//resize the console
		resizeWindow("Avatar2",300,216);//resize the console
		resizeWindow("Avatar1",300,216);//resize the console
		imshow("Avatar3",Itemp);//show image saved in Itemp in console
		imshow("Avatar2",Itemps);//show image saved in Itemps in console
		imshow("Avatar1",image);// show image saved in image in console
		waitKey(0);//pause until a key is pressed
		destroyWindow("Avatar3");//destroy console
		destroyWindow("Avatar2");//destroy console
		destroyWindow("Avatar1");//destroy console
		do{// start of loop to validate men avatar for player1
			system("cls");
			cout<<"a.avatar1\nb.avatar2\nc.avatar3\nselect avatar:";
			cin>> sex;
			if(sex!='a'&&sex!='b'&&sex!='c')
			{
				error2();//call function for error reporting
			}
		}while(sex!='a'&&sex!='b'&&sex!='c');//end of validation for mens avatar
		if(sex=='a')//if mens avatar1 is selected for player 1
		{
			Iplayer1=image;
		}else if(sex=='b')//if mens avatar2 is selected for player 1
			Iplayer1= Itemps;
		else{//if mens avatar3 is selected for player 1
			Iplayer1=Itemp;
		}
	}else{//if female gender is selected
		image= imread("woman1.png",CV_LOAD_IMAGE_COLOR);//load image woman1.png in image as a color image
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar1",CV_WINDOW_NORMAL);//format output console
		Itemps= imread("woman2.png",CV_LOAD_IMAGE_COLOR);//load image woman2.png in Itemps as a color image
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar2",CV_WINDOW_NORMAL);//format output console
		Itemp= imread("woman3.png",CV_LOAD_IMAGE_COLOR);// load image woman3.png in Itemp as a color image 
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar3",CV_WINDOW_NORMAL);// format output console
		resizeWindow("Avatar3",300,216);//resize the console
		resizeWindow("Avatar2",300,216);//resize the console
		resizeWindow("Avatar1",300,216);//resize the console
		imshow("Avatar3",Itemp);//show image to console
		imshow("Avatar2",Itemps);//show image to console
		imshow("Avatar1",image);//show image to console
		waitKey(0);//stop the program until a key is pressed
		destroyWindow("Avatar3");//destroy console
		destroyWindow("Avatar2");//destroy console
		destroyWindow("Avatar1");//destroy console
		do{//start loop to validate woman avatar selection for player1 
			system("cls");
			cout<<"a.avatar1\nb.avatar2\nc.avatar3\nselect avatar:";
			cin>> sex;
			if(sex!='a'&&sex!='b'&&sex!='c')
			{
				error2();//call function for error reporting
			}
		}while(sex!='a'&&sex!='b'&&sex!='c');//end of loop to validate avatar selection for player 1
		if(sex=='a')//if avatar1 is selected for player1
		{
			Iplayer1=image;
		}else if(sex=='b')//if avatar2 is selected for player1
			Iplayer1= Itemps;
		else{//if avatar3 is selected for player1
			Iplayer1=Itemp;
		}
	}//end of player1 selection
	system("cls");
	cout<<"\n\n\nPlayer2 name:";
	cin>>player2;
	do{//start of loop to validate gender for player2
		system("cls");
		cout<<"a.male\nb.female\nSelect your gender:";
		cin >> sex;
		if(sex!='a'&&sex!='b')
		{
			error2();//call function for error reporting
		}
	}while(sex!='a'&&sex!='b'&&sex!='c');//end of gender validation for player2
	system("cls");
	if(sex=='a') //if men is selected for player2
	{
		image= imread("men1.png",CV_LOAD_IMAGE_COLOR);
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar1",CV_WINDOW_NORMAL);
		Itemps= imread("men2.png",CV_LOAD_IMAGE_COLOR);
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar2",CV_WINDOW_NORMAL);
		Itemp= imread("men3.png",CV_LOAD_IMAGE_COLOR);
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar3",CV_WINDOW_NORMAL);
		resizeWindow("Avatar3",300,216);//resize the console
		resizeWindow("Avatar2",300,216);//resize the console
		resizeWindow("Avatar1",300,216);//resize the console
		imshow("Avatar3",Itemp);
		imshow("Avatar2",Itemps);
		imshow("Avatar1",image);
		waitKey(0);
		destroyWindow("Avatar3");
		destroyWindow("Avatar2");
		destroyWindow("Avatar1");
		do{//start of loop to validate men avatar for player2
			system("cls");
			cout<<"a.avatar1\nb.avatar2\nc.avatar3\nselect avatar:";
			cin>> sex;	
			if(sex!='a'&&sex!='b'&&sex!='c')
			{
				error2();//call function for error reporting
			}
		}while(sex!='a'&&sex!='b'&&sex!='c');//end of validate mend avatar for player2
		if(sex=='a')
		{
			Iplayer2=image;
		}else if(sex=='b')
			Iplayer2= Itemps;
		else{
			Iplayer2=Itemp;
		}
	}else{//if woman is selected for player2 
		image= imread("woman1.png",CV_LOAD_IMAGE_COLOR);
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar1",CV_WINDOW_NORMAL);
		Itemps= imread("woman2.png",CV_LOAD_IMAGE_COLOR);
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar2",CV_WINDOW_NORMAL);
		Itemp= imread("woman3.png",CV_LOAD_IMAGE_COLOR);
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow("Avatar3",CV_WINDOW_NORMAL);
		resizeWindow("Avatar3",300,216);
		resizeWindow("Avatar2",300,216);
		resizeWindow("Avatar1",300,216);
		imshow("Avatar3",Itemp);
		imshow("Avatar2",Itemps);
		imshow("Avatar1",image);
		waitKey(0);
		destroyWindow("Avatar3");
		destroyWindow("Avatar2");
		destroyWindow("Avatar1");
		do{//start of loop to validate woman avatar for player2
			system("cls");
			cout<<"a.avatar1\nb.avatar2\nc.avatar3\nselect avatar:";
			cin>> sex;	
			if(sex!='a'&&sex!='b'&&sex!='c')
			{
				error2();//call funcion for error reporting
			}
		}while(sex!='a'&&sex!='b'&&sex!='c');//end of loop to validate woman avatar for player2
		if(sex=='a')
		{
			Iplayer2=image;
		}else if(sex=='b')
			Iplayer2= Itemps;
		else{
			Iplayer2=Itemp;
		}
	}
	do{//start loop of the game
		do{//start loop to validate random question selection 
			temp2=(48+ rand() % 10);//generate random number in int 48-57 to say 0-9 in char
			temp=static_cast<char>(temp2);//convert number in char
		}while(question[temp2-48]== 'x');//end loop to validate random question selection
		/*********************************************************************************
		temp2=48+ran()%10 generate random number from 48 to 57 they are 0 to 9 in ASCII CODE
		and store in temp2
		temp=staic_cast<char>(temp2) convert number in temp2 to char and store in temp
		question[temp2-48] to temp2 rest 48 to convert the number store in temp2 to (0 to 9)
		*///******************************************************************************
		question[temp2-48]='x';// change the value in the array in the index[temp2-48] to x to elimited question
		namedWindow(player1,CV_WINDOW_NORMAL);
		resizeWindow(player1,300,216);
		imshow(player1,Iplayer1);//show avatar of the player1
		waitKey(0);
		destroyWindow(player1);
		system("cls");
		cout<<player1<<endl;
		if(trivia.preguntas(temp))//if and call funtion to load question from file, validate and return if is correct or incorrect
		{
			point1++;//if correct add 1 point to player1
			image= imread("Zebra.jpg",CV_LOAD_IMAGE_COLOR);
			if(!image.data ) // Check for invalid input
			{
				cout << "Could not open or find the image" << endl ;
				return -1;
			}
			namedWindow("Correct",CV_WINDOW_AUTOSIZE);
			imshow("Correct",image);//show image of correct
			waitKey(2000);
			destroyWindow("Correct");
			system("pause");
			system("cls");
		}
		else//if incorrect
		{
			image= imread("SadFace.jpg",CV_LOAD_IMAGE_COLOR);
			if(!image.data ) // Check for invalid input
			{
				cout << "Could not open or find the image" << endl ;
				return -1;
			}
			namedWindow("Incorrect",CV_WINDOW_AUTOSIZE);
			imshow("Incorrect",image);//show image of incorrect
			waitKey(2000);
			destroyWindow("Incorrect");
			system("pause");
			system("cls");
		}
		do{//start loop to validate random question selection
			temp2=(48+ rand() % 10);
			temp=static_cast<char>(temp2);
		}while(question[temp2-48]== 'x');
		/*********************************************************************************
		temp2=48+ran()%10 generate random number from 48 to 57 they are 0 to 9 in ASCII CODE
		and store in temp2
		temp=staic_cast<char>(temp2) convert number in temp2 to char and store in temp
		question[temp2-48] to temp2 rest 48 to convert the number store in temp2 to (0 to 9)
		*///******************************************************************************
		question[temp2-48]='x';// change the value in the array in the index[temp2-48] to x to elimited question
		namedWindow(player2,CV_WINDOW_NORMAL);
		resizeWindow(player2,300,216);
		imshow(player2,Iplayer2);//show avatar of player2
		waitKey(0);
		destroyWindow(player2);
		cout<<player2<<endl;
		if(trivia.preguntas(static_cast<char>(temp)))//if and call funtion to load question from file, validate and return if is correct or incorrect
		{
			point2++;//if correct add 1 point to player2
			image= imread("Zebra.jpg",CV_LOAD_IMAGE_COLOR);
			if(!image.data ) // Check for invalid input
			{
				cout << "Could not open or find the image" << endl ;
				return -1;
			}
			namedWindow("Correct",CV_WINDOW_AUTOSIZE);
			imshow("Correct",image);//show image of correct
			waitKey(2000);
			destroyWindow("Correct");
			system("pause");
			system("cls");
		}
		else//if incorrect
		{
			image= imread("SadFace.jpg",CV_LOAD_IMAGE_COLOR);
			if(!image.data ) // Check for invalid input
			{
				cout << "Could not open or find the image" << endl ;
				return -1;
			}
			namedWindow("Incorrect",CV_WINDOW_AUTOSIZE);
			imshow("Incorrect",image);//show image of incorrect
			waitKey(2000);
			destroyWindow("Incorrect");
			system("pause");
			system("cls");
		}
		count++;//update the counter to exit the loop 
		cout<<"Question remaining"<<endl;
		for(int i=0; i<10;i++)//loop for print the remaining question
		{
			cout<<question[i]<<",";
		}
		cout<<endl;
		system("pause");
		system("cls");
	}while(count<5);//end of loop of game
	cout<<player1<<" point:"<<point1<<endl;//print player1 point
	cout<<player2<<" point:"<<point2<<endl;//print player2 point
	if(point1>point2)//if player1 win
	{
		image= imread("winner.jpg",CV_LOAD_IMAGE_COLOR);
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow(player1,CV_WINDOW_AUTOSIZE);
		imshow(player1,image);//show image of win
		waitKey(2000);
		destroyWindow(player1);
		cout<<player1<< " is the winner\n" ;
	}
	else if(point2>point1)//if player2 win
	{
		image= imread("winner.jpg",CV_LOAD_IMAGE_COLOR);
		if(!image.data ) // Check for invalid input
		{
			cout << "Could not open or find the image" << endl ;
			return -1;
		}
		namedWindow(player2,CV_WINDOW_AUTOSIZE);
		imshow(player2,image);//show image of win
		waitKey(2000);
		destroyWindow(player2);
		cout<<player2<< " is the winner\n" ;
	}
	else//if a draw
	{
		cout<<"Draw\n";
	}
	system("pause");
	return 0;
}//end main
void error2()//display error reporting
{
	system("cls");
	system("color 74");
	cout <<endl;
	cout<<"                             *********************"<<endl;
	cout<<"                         *******               *******"<<endl;
	cout<<"                      ****                           ****"<<endl;
	cout<<"                   ***                                 ***"<<endl;
	cout<<"                  ***                                     ***"<<endl;
	cout<<"                 ***                                       ***"<<endl;
	cout<<"                ***                                         ***"<<endl;
	cout<<"               ***                                           ***"<<endl;
	cout<<"	      ***                                             ***"<<endl;
	cout<<"              **					       **"<<endl;
	cout<<"              **   *                                       *   **"<<endl;
	cout<<"              **  **                                       **  **"<<endl;
	cout<<"              **  **                                       **  **"<<endl;
	cout<<"              **  ***                                      **  **"<<endl;
	cout<<"              **   **                                     ***  **"<<endl;
	cout<<"              **   **                                     **   **"<<endl;
	cout<<"              ***   **                                    ***  **"<<endl;
	cout<<"               ***  **         ***           ***         **   **"<<endl;
	cout<<"                **  **   ***********       ************  **  **"<<endl;
	cout<<"                 ** **  ************       *************  ****"<<endl;
	cout<<"                  **** *************       *************  **"<<endl;
	cout<<"                   **   ***********         ***********   **"<<endl;
	cout<<"     *****         **   **********           **********   **         *****"<<endl;
	cout<<"     **  **        **    ********             ********     **       **  **"<<endl;
	cout<<"    **    **       **      *****     ** **      ****       **      **    **"<<endl;
	cout<<"    **     **      **               *** ***               **      **     **"<<endl;
	cout<<"   ***      ****   ***             **** ****              **   ****       **"<<endl;
	cout<<" ***           **** ***            **** ****            *** ****           ***"<<endl;
	cout<<" **               **********       **** ****        *********               **"<<endl;
	cout<<" ***********         **** ****     ***   ***     **** ****         ***********"<<endl;
	cout<<"          *****         ** ****                 **** **         *****"<<endl;
	cout<<"              *****     ****  **               *** ****      ****"<<endl;
	cout<<"                 *****   ** * **               ** * **   *****"<<endl;
	cout<<"                    ******* * *    *********  * * * ******"<<endl;
	cout<<"                        *** * *    * * * * *  * * * ***"<<endl;
	cout<<"                         **  ** **** * * * **** *** **"<<endl;
	cout<<"                      *****  ** *  * * * * *  * **  *****"<<endl;
	cout<<"                   ****  **    *** * * * * * ***    **  ****"<<endl;
	cout<<"                ****      **         ******        ***     *****"<<endl;
	cout<<"      ***********         ***                     ***          **********"<<endl;
	cout<<"      **               *******                   *******                ** "<<endl;
	cout<<"      ***           ****     ***               ***     ****            **"<<endl;
	cout<<"        **       ****          *****************          ****       *** "<<endl;
	cout<<"         **     ***                 *******                  ***    **"<<endl;
	cout<<"         **    **                                             ***   **"<<endl;
	cout<<"         ***  **                                               ***  **"<<endl;
	cout<<"          *****                                                 *****"<<endl;
	cout<<"\n\n\n\t\t\t     Invalid Data!!."<<endl;
	Sleep(2000);
	system("cls");
	system("color 09");	
}