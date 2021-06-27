# Требования к приложению


Реализованный проект представляет из себя простую компьютерную игрув жанре Tower Defense: "Lonely turret". Игроку предлагается управление танком, с помо-щью которого он должен отбиваться от наступающих врагов, чтобы не дать им разрушитьбазу. Игровой цикл является бесконечным, поэтому игра заканчивается, когда противни-ки разрушают базу или главный герой погибает.Каждые 5 секунд наступает новый противник случайного типа. 

Каждые 10 минут характеристики врагов повышаются. Каждую минуту на карте появляется случайная руна,которую главный герой может подобрать.

###Типы появляющихся рун:###
1. здоровье для базы: повышает здоровье базы.
2. здоровье для героя: повышает здоровье героя.
3. увеличение урона героя: повышает урон главного героя.
4. монетка: повышает счётчик подобранных монеток.


###Типы появляющихся врагов:###


|тип             	|здоровье | урон  | скорость |способности    |
|-------------------|---------|-------|----------|---------------|
|"силач" |среднее |средний|средняя |нет |	     
| "летучая мышь"  |низкое  |низкий |высокая |нет | 		     
| "куча"|высокое |средний|низкая  |нет 	 	     
|"бык"|высокое |высокий|низкая  |останавливается |
|"грязевая капля"|низкое  |низкий |средняя |исчезает	     |
|"гриб"|средние |средний|низкая  |снижает урон  |


Использовалась графическая библиотека [SFML](https://www.sfml-dev.org/).
![](image/sfml.png)


###Игровое поле:####
<img src="game_process.png" width="900" height="600" />



###Пример включения учатка кода в документацию:###

~~~~~~~~~~~~~{.cpp}
#include<random>

int randomize_enemy_type(std::minstd_rand &simple_rand){

    int enemyType;

    enemyType=simple_rand()%6;

    return enemyType;
}
~~~~~~~~~~~~~