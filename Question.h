#ifndef Question_H
#define	Question_H
#include <string>
using namespace std;

class Question
{
private:
	string pregunta;
	string uno;
	string dos;
	string tres;
	string cuatro;
	bool validation(char a);
	void error();
	char answer;
public:
	Question();
	bool preguntas(char q);
	bool answers(char a);
}
#endif