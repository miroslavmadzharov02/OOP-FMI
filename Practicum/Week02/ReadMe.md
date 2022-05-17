##  Задачи
 
**Задача 1**: Напишете програма, която отпечатва собствения си код.

**Задача 2**: Напишете функция, която приема име на съществуващ файл и име и копира съдържанието на същестуващия файл в нов файл.

**Задача 3**: Напишете програма,  която чете comma-separated values (**CSV**) файл със студенти **със следните 4 полета**: Първо име, Фамилно име, Имейл, Факултетен номер.
1.  Със стартирането на програмата потребителят да въвежда име на файл, който да бъде зареден в паметта.
2.  Напишете функция, която след зареждане на файла да отпечатва на **стандартния изход** информация за студента при подаден **факултетен номер**.
3.  Напишете функция, която **по подаден факултетен номер и низ**, променя email-a на студента, който има дадения факултетен номер, с подадения низ.
4.  Напишете функцията , която приема низ (име на файл) и запазва студентите в същия формат (**CSV**). Т.е. при повторно пускане на програмата да може да прочете новия генериран файл.

Да се реализира прост интерфейс, с който да се извикват написаните фунцкии през конзолата:

**Пример** (входът от потребителя започва с '>'):

 ```
Open file: 
>students.csv
File successfully opened!
>print 80000
Name = Stefan Velkov, Email: stefan@yahoo.com, FN: 80000
>edit 80000 stecho@abv.bg
>print 80000
Name = Krum Velkov, Email: stecho@abv.bg, FN: 80000
>save students2.csv
file students2.csv successfully saved!
```