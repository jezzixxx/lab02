# Lab01-ТиМП
## Плышевская К. ИУ8-23. Лабораторная работа по ТиМП №2
### Part 1
#### 0) Подготовка
Создала репозиторий на GitHub с названием lab02, лицензией MIT.    
Сгенерировала токен с правами repo.    
Инициализируем переменные:
```
export GITHUB_USERNAME=jezzixxx
export GITHUB_EMAIL=pkapav02@gmail.com
export GITHUB_TOKEN=<сгенирированный_токен>
```
Выбираем режим редактирования nano:    
`alias edit=nano`    
Записываем в файл ~/.config/hub (EOF — маркер окончания записи):
```
cat > ~/.config/hub <<EOF
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF
```
Записываем глобальные настройки (протокол, имя и почта пользователя):    
```
git config --global hub.protocol https
git config --global user.name ${GITHUB_USERNAME}
git config --global user.email ${GITHUB_EMAIL}
```
Создаём папку projects, внутри неё папку lab02:
```
mkdir projects
cd projects
mkdir lab02
cd lab02
```
#### 1) Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).
Создаём пустой репозиторий:    
`git init`    
Добавляем удалённый репозиторий:    
`git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git`
#### 2) Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.
Создаём пустой файл README.md:    
`touch README.md`    
Проверяем статус:    
`git status`    
Добавляем созданный файл:    
`git add README.md`    
Создаём коммит "added README.md":    
`git commit -m"added README.md"`    
Загружаем коммит в ветку master:    
`git push origin master`
#### 3) Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу Hello world на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.
Создаём файл hello_world.cpp в локальной копии репозитория:    
`touch hello_world.cpp`    
Записываем в него программу с плохим стилем кода:    
```
cat > hello_world.cpp <<EOF
 #include <iostream>
using namespace std;

int main(){
        cout<<"Hello, World"<<endl;
        return 0;
}
EOF
```
#### 4) Добавьте этот файл в локальную копию репозитория.
`git add hello_world.cpp`
#### 5) Закоммитьте изменения с осмысленным сообщением.
Создаём коммит с изменениями:    
`git commit -m"added hello_world.cpp"`    
Загружаем коммит в master:    
`git push origin master`
#### 6) Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.
Вносим изменения в файл:    
`sudo nano hello_world.cpp`    
Изменяем код на:
```
#include <iostream>
using namespace std;

int main(){
        cout<<"Input your name:";
        string name;
        cin>>name;
        cout<<"Hello world from "<<name<<endl;
        return 0;
}
```
Для сохранения: ctrl+o    
Проверяем имя файла, нажимаем Enter, закрываем через ctrl+x
#### 7) Закоммитьте новую версию программы. Почему не надо добавлять файл повторно `git add`?
Необходимо добавить новую версию hello_world.cpp, так как в ином случае в коммите не будет изменений. Поэтому используем:    
`git add hello_world.cpp`    
и создаём новый коммит:    
`git commit -m"changed hello_world.cpp"`
#### 8) Запуште изменения в удалёный репозиторий.
`git push origin master`    
#### 9) Проверьте, что история коммитов доступна в удалёный репозитории.
`git log`
### Part 2
#### 1) В локальной копии репозитория создайте локальную ветку `patch1`.
`git checkout -b patch1`
#### 2) Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.
Исправляем код в hello_world.cpp:    
`sudo nano hello_world.cpp`    
Новый код:    
```
#include <iostream>
#include <string>

int main(){
        std::cout<<"Input your name:";
        std::string name;
        std::cin>>name;
        std::cout<<"Hello world from "<<name<<std::endl;
        return 0;
}
```
#### 3) commit, push локальную ветку в удалённый репозиторий.
```
git add hello_world.cpp
git commit -m"fixed hello_world.cpp"
git push origin patch1
```
#### 4) Проверьте, что ветка patch1 доступна в удалёный репозитории.
`git branch`
#### 5) Создайте pull-request `patch1 -> master`.
На сайте GitHub
#### 6) В локальной копии в ветке `patch1` добавьте в исходный код комментарии.
Добавляем комментарии в hello_world.cpp:    
`sudo nano hello_world.cpp`    
Новый код:    
```
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
```
#### 7) commit, push.
```
git add hello_world.cpp
git commit -m"fixed hello_world.cpp with comments"
git push origin patch1
```
#### 8) Проверьте, что новые изменения есть в созданном на шаге 5 pull-request
Проверили, что на сайте GitHub в созданном pull отобразился новый коммит с внесёнными изменениями
#### 9) В удалённый репозитории выполните слияние PR patch1 -> master и удалите ветку patch1 в удаленном репозитории.
Слияние на сайте GitHub. Merge pull request    
Удаляем ветку на сайте
#### 10) Локально выполните pull.
`git pull origin master`
#### 11) С помощью команды git log просмотрите историю в локальной версии ветки master.
`git log`
#### 12) Удалите локальную ветку patch1.
`git branch -D patch1`
### Part 3
#### 1) Создайте новую локальную ветку `patch2`.
`git checkout -b patch2`
#### 2) Измените code style с помощью утилиты clang-format. Например, используя опцию `-style=Mozilla`.
Устанавливаем clang-format командой:    
`sudo apt install clang-format`    
Изменяем code style командой:    
`clang-format -style=Mozilla hello_world.cpp`
#### 3) commit, push, создайте pull-request `patch2 -> master`.
```
git add hello_world.cpp
git commit -m"hello_world.cpp with code style"
git push origin patch2
```
На сайте GitHub создаём pull request patch2 -> master
#### 4-5) Убедитесь, что в pull-request появились конфликтны.
Появились конфликты
#### 6) Для этого локально выполните pull + rebase (точную последовательность команд, следует узнать самостоятельно). Исправьте конфликты.
```
git pull --rebase origin master
//сообщение о конфликтах
git add hello_world.cpp
git rebase --continue
```
#### 7) Сделайте force push в ветку `patch2`.
`git push --force origin patch2`
#### 8) Убедитель, что в pull-request пропали конфликтны.
Конфликты пропали
#### 9) Вмержите pull-request patch2 -> master.
На GitHub merge patch2->master
