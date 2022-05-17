#include <iostream>

enum class Division
{
    UNDEFINED = -1,
    ASSASIN,
    MEDIC,
    MAGE,
    TANK,
};

enum class Combat
{
    UNKNOWN = -1,
    RANGE,
    MELEE,
    BOTH
};

struct Hero
{
    char* name;
    Division division;
    Combat combat;
};

void chooseDivision(Hero& hero)
{
    int divisionNum;
    std::cout << "Press the subsequent number to choose your division:\n";
    std::cout << "Assasin 0 || Medic 1 || Mage 2 || Tank 3\n";
    std::cin >> divisionNum;
    
    switch (divisionNum)
    {
    case 0:
        hero.division = Division::ASSASIN;
        break;
    case 1:
        hero.division = Division::MEDIC;
        break;
    case 2:
        hero.division = Division::MAGE;
        break;
    case 3:
        hero.division = Division::TANK;
        break;
    default:
        hero.division = Division::UNDEFINED;
        break;
    }
}

void chooseCombat(Hero& hero)
{
    int combatNum;
    std::cout << "Press the subsequent number to choose your combat style:\n";
    std::cout << "Range 0 || Melee 1 || Both 2\n";
    std::cin >> combatNum;

    switch (combatNum)
    {
    case 0:
        hero.combat = Combat::RANGE;
        break;
    case 1:
        hero.combat = Combat::MELEE;
        break;
    case 2:
        hero.combat = Combat::BOTH;
        break;
    default:
        hero.combat = Combat::UNKNOWN;
        break;
    }
}

void initializeHero(Hero& hero, const int nameLength)
{
    hero.name = new char[nameLength + 1];
    hero.name[nameLength] = '\0';
    for (int i = 0; i < nameLength; i++)
        std::cin >> hero.name[i];
    chooseDivision(hero);
    chooseCombat(hero);
}

void printHeroDivision(const Hero& hero)
{
    switch (hero.division)
    {
    case Division::ASSASIN:
        std::cout << "assasin.\n";
        break;
    case Division::MEDIC:
        std::cout << "medic.\n";
        break;
    case Division::MAGE:
        std::cout << "mage.\n";
        break;
    case Division::TANK:
        std::cout << "tank.\n";
        break;
    default:
        std::cout << "undefined.\n";
        break;
    }
}

void printHeroCombat(const Hero& hero)
{
    switch (hero.combat)
    {
    case Combat::RANGE:
        std::cout << "range.\n";
        break;
    case Combat::MELEE:
        std::cout << "melee.\n";
        break;
    case Combat::BOTH:
        std::cout << "both.\n";
        break;
    default:
        std::cout << "unknown.\n";
        break;
    }
}

void printHeroStats(const Hero& hero)
{
    std::cout << "Your hero's name is " << hero.name << '\n';

    std::cout << hero.name << "'s division is ";
    printHeroDivision(hero);

    std::cout << hero.name << "'s combat style is ";
    printHeroCombat(hero);
}

int main()
{
    int heroNameLength;
    std::cout << "How long is the hero's name?\n";
    std::cin >> heroNameLength;

    Hero hero;
    initializeHero(hero, heroNameLength);
    printHeroStats(hero);

    delete[] hero.name;
    return 0;
}
