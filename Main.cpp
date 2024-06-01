/*

In this game you will control a goblin fortress.
You will start out with little and will have to make the decision to mine for resources or to gather berries ect.
The end goal of the game will be to conquer all of the other kingdoms.
To be able to conquer a kingdom you will have to have enough goblins and enough weapNarmor. This will also take food for the goblins to take for war.
Even then goblins will still die,
The kingdoms will go to war with you eventually.

*/


#include <iostream>
#include <random>

void lose(void);
void printStats(bool dead=false);
void updateForts(void);
void printForts(void);

class Fort {

public:
    int villagers;
    std::string name;
    bool conquered = false;
    Fort(int villagers, std::string name);

    void fight(void);

};

Fort forts[5] = {Fort(45, "Winchester"), Fort(100, "Hollownest"), Fort(150, "Lake Town"), Fort(300, "Dale"), Fort(500, "Rivendell")};

std::string input; // Input from the player after each tick.
long long temp; // Various temporary variables.
long choiceCount = 0; // Goes up whenever a choice is made that will take up time.
bool choiceMade = false; // Will turn true when a choice is made that will take up time.

// Stocks
long long meals = 60;
long long oreChunks = 0;
long long weapNarmor = 0; // Weapons and armor

// Stats
long long population = 15;
int conqueredForts = 0;


int main(void) {

    std::cout << "\nWelcome to Goblin Fortress.\nIn this game your main goal is to conquer all of the other fortresses without being conquered or destroyed yourself.\nIn the process of conquering fortresses, you will need to make sure your Goblins have enough food to live, among other things :).\n";
    std::cout << "\nFor each choice you make time goes by. As time goes by the enemy forts grow stronger and food dwindles. Be ready for anything.\n";
    std::cout << "Strike and Conquer!\n";
    std::cout << "\nEnter help for... help.\n\n";

    // Loop
    while (true) {

        choiceMade = false;
        std::getline(std::cin, input);  

        // HELP
        if (input == "help" || input == "Help" || input == "h") {
            std::cout << "\nList of Commands:\n\n" <<
            "c / conquer: Shows you a list of fortresses to conquer.\n" <<
            "g / Gather: Sends your goblins to gather food from the wilderness.\n" <<
            "m / Mine: Goblins will mine ore chunks for forging.\n" <<
            "f / Forge: Your goblins will forge sets of weapons and armor for themselves.\n" <<
            "s / Stats: Shows you stats about your fortress.\n" <<
            "Exit: Exits the game.\n\n" <<
            "To conquer a fort enter conquer then the number of the fort.\n\n";
        }
        // MAP
        else if (input == "conquer" || input == "conquer" || input == "c") {
            printForts();
        }
        // GATHER
        else if (input == "Gather" || input == "gather" || input == "g") {
            temp += (population*2) + ((choiceCount%3) - (choiceCount/2)); // Resources around the fort decrease over time.
            if (temp < 4) temp = 4;
            meals += temp;
            std::cout << "\nYour goblins were able to gather " << temp << " meals. : You now have " << meals-population << " meals.\n";
            temp = (population/16)-(weapNarmor/5);
            population -= temp;
            if (temp >2)
                std::cout << "However, " << temp << " were eaten by the beasts of the wilderness.\n\n";
            else if (temp == 1)
                std::cout << "However, a single goblin was eaten by the beasts of the wilderness.\n\n";
            else
                std::cout << "\n";
            choiceMade = true;
        }
        // MINE
        else if (input == "Mine" || input == "mine" || input == "m") {
            temp = (choiceCount%3) + (population/8);
            temp == 0 ? temp = 1 : temp = temp; // Makes sure you at least get one ore chunk.
            oreChunks += temp;
            if (temp > 1)
                std::cout << "\nYour goblins were able to mine out " << temp << " ore chunks.\n";
            else 
                std::cout << "\nYour goblins were able to mine out a single ore chunk.\n";
            temp = population/20;
            if ((temp % 3) + (choiceCount % 3) == 0)
                temp = 0;
            population -= temp;
            if (temp == 1)
                std::cout << "However, a single goblin died in the mines.\n\n";
            else if (temp > 2)
                std::cout << "However, " << temp << " goblins died in the mines.\n\n";
            else
                std::cout << "\n";
            choiceMade = true;
        }
        // FORGE
        else if (input == "Forge" || input == "forge" || input == "f") {
            if (oreChunks > 0) {
                temp = (choiceCount%5) + (population/8);
                temp == 0 ? temp = 1 : temp = temp; // Makes sure you at least get one.
                if (temp > oreChunks)
                    temp = oreChunks; 
                weapNarmor += temp;
                oreChunks -= temp;
                std::cout << "\nYour goblins forged " << temp << " sets of weapons and armor.\n\n"; 
                choiceMade = true;
            }
            else 
                std::cout << "\nYou don't have enough ore chunks to forge weapons and armor.\n\n";
        }
        // STATS
        else if (input == "Stats" || input == "stats" || input == "s") {
            printStats();
        }

        // THE FORTS
        else if (input == "conquer1" || input == "conquer1" || input == "c1") {
            if (!forts[0].conquered) {
                forts[0].fight();
                choiceMade = true;
            }
            else
                std::cout << "This fort has already been conquered.\n";
        }
        else if (input == "conquer2" || input == "conquer2" || input == "c2") {
            if (!forts[1].conquered) {
                forts[1].fight();
                choiceMade = true;
            }
            else
                std::cout << "This fort has already been conquered.\n";
        }
        else if (input == "conquer3" || input == "conquer3" || input == "c3") {
            if (!forts[2].conquered) {
                forts[2].fight();
                choiceMade = true;
            }
            else
                std::cout << "This fort has already been conquered.\n";
        }
        else if (input == "conquer4" || input == "conquer4" || input == "c4") {
            if (!forts[3].conquered) {
                forts[3].fight();
                choiceMade = true;
            }
            else
                std::cout << "This fort has already been conquered.\n";
        }
        else if (input == "conquer5" || input == "conquer5" || input == "c5") {
            if (!forts[4].conquered) {
                forts[4].fight();
                choiceMade = true;
            }
            else
                std::cout << "This fort has already been conquered.\n";
        }

        else if (input == "Exit" || input == "exit") {
            break;
        }
        else {
            std::cout << "Input not valid.\n\n";
        }


        if (choiceMade) {
            choiceCount++;

            // Invasion Time
            if (choiceCount%(13-(conqueredForts*3)) == 0) { // The more you conquer, the more likely you are to be invaded due to alliances.
                if (population < 7) // You die no matter what if you have too little goblins
                    population = 0;
                temp = population-(weapNarmor/2);
                if (population > 20)
                    temp -= population/12;
                population -= temp;
                if (population <= 0 && weapNarmor == 0)
                    std::cout << "You were invaded and all your goblins were killed due to lack of preparation.\n\n";
                else if (population <= 0)
                    std::cout << "You were invaded and all your goblins were killed.\n\n";
                else if (temp > 0)
                    std::cout << "You were invaded by another fortress and lost " << temp << " goblins.\n\n";
                else
                    std::cout << "You were invaded by another fortress but didn't lose any goblins.\n\n";
            }

            // Meal Time
            if (meals >= population)
                meals -= population;
            else {
                population = meals;
                meals = 0;
                std::cout << "Goblins have died from lack of sustenance.\n\n";
            }

            // Migrant Time
            if (choiceCount%5 == 0) {
                temp = (population/3)+(meals/45)+(weapNarmor/15)+conqueredForts*10;
                temp == 0 ? population += 2 : population += temp; // Will add two goblin to the population if none decide to come.
                std::cout << temp << " Goblins decided to migrate to your fortress.\n\n";
            }

            // Pre-starvation check
            if (meals < population)
                std::cout << "On the next choice your goblins could die from lack of sustenance.\n\n";

            updateForts();
        }


        // Loss Check
        if (population <= 0)
            lose();

        // Win Check
        if (conqueredForts >= 5) {
            std::cout << "You've done it! You've conquered all the other fortresses and taken them for your own!\n\nYour Stats:\n";
            printStats(true);
            break;
        }
    }

    return 0;
}





void lose(void) {
    std::cout << "All of your goblins have died.\n\nYour Stats:\n";
    printStats(true);
    exit(0);
}

void printStats(bool dead) {
    if (!dead)
        std::cout <<
        "\nPopulation: " << population <<
        "\nForts conquered: " << conqueredForts <<
        "\nChoices Made: " << choiceCount <<
        "\n\nMeals: " << meals <<
        "\nOre Chunks: " << oreChunks <<
        "\nWeapons and Armor: " << weapNarmor <<
        "\n\n";
    else
        std::cout <<
        "\nForts conquered: " << conqueredForts <<
        "\nChoices Made: " << choiceCount <<
        "\n\nMeals: " << meals <<
        "\nOre Chunks: " << oreChunks <<
        "\nWeapons and Armor: " << weapNarmor <<
        "\n\n";
}


void Fort::fight(void) {
        temp = (this->villagers+(choiceCount%15))-weapNarmor;
        if (temp < 0 ) temp = 0;
        population -= temp;
        if (population > 0) {
            std::cout << "You conquered " << this->name << " successfully.\n";
            if (temp)
                std::cout << "However, " << temp << " of your own goblins have perished in war.\n\n";
            else
                std::cout << "\n";
            conqueredForts++;
            this->conquered = true;
        }
        else {
            std::cout << "You were unsuccessful in defeating " << this->name << ".\n\n";
            lose();
        }
    }

Fort::Fort(int villagers, std::string name) {
    this->villagers = villagers;
    this->name = name;
};

void printForts(void) {
    int i = 0;
    for (Fort f : forts) {
        i++;
        if (!f.conquered)
            std::cout << "\n" << i << ". " << f.name << " - " << f.villagers << "\n";
    }
    std::cout << "\n";
}

void updateForts(void) {
    for (int i=0; i<5; i++)
        forts[i].villagers++;
}