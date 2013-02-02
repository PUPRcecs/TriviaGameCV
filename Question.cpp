
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "Question.h"
;using namespace std;


Question::Question()
{
	pregunta="/0";
	uno="/0";
	dos="/0";
	tres="/0";
	cuatro="/0";
	answer='/0';
}
bool Question::preguntas(char q)
{
	
	char a;
	string archivo;
	ifstream inputFile;
	char name[6];
	name[0]= q;
	name[1]= '.';
	name[2]= 't';
	name[3]= 'x';
	name[4]= 't';
	name[5]='\0';
	cout<<"Question #"<<q<<endl;
	archivo= name;
	inputFile.open(archivo.c_str());
	getline(inputFile, pregunta);
	getline(inputFile, uno); 
	getline(inputFile, dos);
	getline(inputFile, tres);
	getline(inputFile, cuatro);
	inputFile>>answer; 
	inputFile.close();
	do{
		cout<<pregunta<<endl;
		cout<<uno<<endl;
		cout<<dos<<endl;
		cout<<tres<<endl;
		cout<<cuatro<<endl;
		cout<<"Your answer:";
		cin>>a;
	}
	while(this->validation(a));
	return this->answers(a);
}
bool Question::validation(char a)
{
	if( a!='a' && a!='d'&& a!='c' && a!='b')
	{
		error();
		return true;
	}
	else
	{
		return false;
	}

}
bool Question::answers(char a)
{
	if(a == this->answer)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Question::error()
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
	system("color 59");	
}
