#include <iostream>
#include <string>

int main(){
	//Выводим на экран запрос о вводе имени
	std::cout<<"Input your name:";
	//Создаём переменную name типа std::string
	std::string name;
	//Вводим с клавиатуры переменную name
	std::cin>>name;
	//Выводим на экран надпись "Hello world from @name", где name - введённое на предыдущем шаге имя
	std::cout<<"Hello world from "<<name<<std::endl;
	return 0;
}
