#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define CLEAR printf("\033[0;0H\033[2J");
#define random1to5 (rand() % 5)
#define random1to3 (rand() % 3)
#define AITURN *turn == 1
#define MYTURN *turn == 0
#define random1to2 (rand() % 2)
#define downDefense (turn == 0) ? (aiTeam->is_nowDefending = 0) : (myTeam->is_nowDefending = 0); //printf("Defense downed"); getchar();
typedef void (*magAttFuncPtr) (void *[]);

typedef struct
{
    char name[15];
    char pokeName[15];
    int HP;
    char * magNames[5];
    int is_nowDefending;
    int is_nowCharging;
    void * actions;
    magAttFuncPtr magicPtr[3];
}Pokemon;
 
//Originally this was setted-up for 5 pokemons, 11  attacks and have multiple pokemons in a team , but for time issues,
//2 pokemon and 5 attacks are fully playable, so this code is easy to escalate and bring more pokemons and magic
// attacks.

//There is a void *ptr[] used throughout the code, it holds all the relevant pointers

//All functions that recieve the void *ptr[] needs to do the following:
/*
    //Gett all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];
*/
//Convert all pointers holded inside the array to their specific and used ones

//There are thing could be optimized, like holding strings in the struct so prints can be just one line instead of one for each, user and cpu

void winningScreen(void *[], int);//Winning Screen
void menu();//Just the starting menu print
void pokemonConstructor(Pokemon *,void*[],char*[]);//An initialization for all 5 pokemons and their attr.
void chooseTeam(Pokemon *, Pokemon *, void *[], char *[]);//Player #1 (human) choosing and giving a Pokemon 
                                                        //  its Name and selecting which 3 functions out of the possible 5 
                                                        //  will be loaded to his Pokemon.
void Attack(void *[]);//Basic attack function that deals 10 dmg
void Defend(void *[]);//Basic defense function that reduces in half the damage done
void Magic(void *[]);//This is where the magic attacks coordinate, recieves a ptr, then exctracts all data from the void ptr,
                    //then, the magic attacks names (inside a pokemon struct) are shown to the player, who is given to choose one,
                    //with the election made, the function is called via a Function pointer holded inside the pokemon struct.
                    //Every magic attack has his unique logic inside.
int midturn_pokemonCheck(void *[]);//Used between turns to check if someone has already win
void printPlay(void *[]);//Shows the "Chessboard" to the user
void playTurn(void *[]);//Where all the playing logistic gets done, basically, recives all data from void *ptr[], then determine whose turn it is,
                        //then call the function electionCatch(), recieve an election and with a switch case, calling the function user wants
int electionCatch(void *[]);//Prints the options user has, depending on data recieved by void *ptr[], its recursive for handling missinputs

//void chooseMagic(Pokemon *, Pokemon *); I was thinking separating the choosing magic part from choose team part but didnt, it'll be useful for recursion

//Magic attacks, recive void *ptr[], then each one makes his unique thing
//Finished are 1 to 5
//other ones are for future implementation
void QuickAttack(void *[]);
void Slash(void *[]);
void Crimson_Storm(void *[]);
void IronBash(void *[]);
void FlashCannon(void *[]);
void Blizzard(void *[]);
void IcyWind(void *[]);
void FlyingPress(void *[]);
void HighJumpKick(void *[]);
void LeafStorm(void *[]);
void Recover(void *[]);


int flipCoin();//Rand % 2
void printPoke(Pokemon *);//Printing func to debug
void enterTo();//Getchar function to stall the printing




int main()
{
    srand(time(NULL));
    Pokemon poke[5];
    //This arrays are this way because first I wanted to give every pokemon the
    //Quick Attack movement and then 2 related attacks, but requirement was to 
    //be chosen by user
    void * maAtt[]={QuickAttack,Slash,Crimson_Storm,
                    IronBash,FlashCannon,
                    QuickAttack,Blizzard,IcyWind,
                    QuickAttack,FlyingPress,HighJumpKick,
                    QuickAttack,LeafStorm,Recover};
    char *magAttName[]={"Quick Attack", "Slash", "Crimson Storm",       
                        "Iron Bash", "Flash Cannon",
                        "Quick Attack", "Blizzard", "Icy Wind",
                        "Quick Attack", "Flying Press", "High Jump Kick", 
                        "Quick Attack","Leaf Storm", "Recover"};
    Pokemon myTeam[1];
    Pokemon aiTeam[1];
    pokemonConstructor(poke,maAtt,magAttName);
    menu();
    chooseTeam(poke, myTeam,maAtt,magAttName);
    //Play
        //Random assign enemy pokemon
    *aiTeam = poke[random1to2];
    int turn = 0;
    int win = -1;
    int * turnPtr = &turn;
    void *vPtr[] = {myTeam,aiTeam,turnPtr};
    //printPoke(myTeam);
    while(win==-1)
    {
        playTurn(vPtr);
        win = midturn_pokemonCheck(vPtr);
    }
    winningScreen(vPtr, win);
}

void winningScreen(void * ptr[], int win)
{
    //Getting all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];

    if(win== 0)
    {
        printf("\n==============================\n");
        printf("       |   YOU WIN   |      \n");
        printf("==============================\n");
        printf("1-Your %s\t%s\n",myTeam->pokeName,myTeam->name);
        printf("2-Rival's %s\t\n",aiTeam->pokeName);
        printf("==============================\n");
    }
    else
    {
        printf("\n==============================\n");
        printf("      |   YOU LOOSE   |      \n");
        printf("==============================\n");
        printf("\t\t\t1-Rival's %s\t\n",aiTeam->pokeName);
        printf("\t\t\t2-Your %s\t%s\n",myTeam->pokeName,myTeam->name);
        printf("==============================\n");
    }
}

void menu()
{
    int i;
    printf("\n==============================\n");
    printf("       | POKE BATTLE |      \n");
    printf("==============================\n");
    printf("        1. Start Game         \n");
    printf("        2. Exit               \n");
    printf("==============================\n");
    printf("    Choose an option: ");
    scanf("%d",&i);
    CLEAR
    if(i==2) exit(0);
}

void pokemonConstructor(Pokemon * poke, void *Funcptr[], char *Cptr[])
{
    Pokemon * ptr = poke;
    char *pokeNames[] = {"Charizard", "Melmetal","Abomasnow","Hawlucha","Celebi"};
    int pokeHP[] = {180,140,140,120,130};
    void * actions[] = {Attack,Defend,Magic};

    int ind = 0;
    for(int i = 0; i<5; i++)
    {
        strcpy(ptr[i].pokeName, pokeNames[i]);
        ptr[i].HP = pokeHP[i];
        ptr[i].actions = actions;
        ptr[i].is_nowCharging = 0;
        ptr[i].is_nowDefending = 0;
        for(int z = 0; z<3; z++,ind++)
        {
            ptr[i].magicPtr[z] = Funcptr[ind];
            ptr[i].magNames[z] = Cptr[ind];
        }
    } 
}

void chooseTeam(Pokemon * poke, Pokemon * myTeam, void *Funcptr[], char *Cptr[])
{
    /*
    Funcptr is magic functions
    Cptr is an array of strings with the magic functions name
    */
    int election;
    printf("\nAvailable Pokemon:\n");
    for(int i = 0; i<2; i++) printf("Pokemon[%d]: %s, HP: %d\n",i+1,poke[i].pokeName, poke[i].HP);
    printf("Please choose a Pokemon (1-2)\n");
    scanf("%d",&election);
    if(election<=0 || election>=6)
    {
        printf("Number out of bounds (1-2) Try again\n");
        chooseTeam(poke,myTeam,Funcptr,Cptr);
        return;
    }
    *myTeam = poke[election-1];
    CLEAR
    election = 0;
    printf("Would you like to give %s a name?\n1- Yes\n2- No\n",myTeam->pokeName);
    scanf("%d",&election);
    CLEAR
    if(election == 1) 
    {
        getchar();
        char str[16];
        printf("Enter your buddy's name (3-15 letters): ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0;
        strcpy(myTeam->name, str);
        CLEAR
        printf("Great! Your buddy is now called %s\n", myTeam->name);
    }
    else printf("Let's move on\n");
    enterTo();
    CLEAR
    printf("Choose 3 moves for %s:\n", myTeam->name);
    for (int i = 0; i < 5; i++)
    {
        printf("%d. %s\n", i + 1, Cptr[i]);
    }

    int selected[3] = {-1, -1, -1};
    election = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("Select move %d: ", i + 1);
        scanf("%d", &election);

        while (election < 1 || election > 5 || selected[0] == election - 1 || selected[1] == election - 1)
        {
            printf("Invalid or duplicate choice. Try again: ");
            scanf("%d", &election);
        }
        selected[i] = election - 1;
        myTeam->magicPtr[i] = Funcptr[selected[i]];
        myTeam->magNames[i] = Cptr[selected[i]];
    }

    printf("\n%s is ready for battle!\n", myTeam->pokeName);
    enterTo();
    CLEAR
}

void Attack(void * ptr[])
{
    //Getting all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];

    if(*turn==0)
    {
                printf("\nYour %s is attacking Rival's %s!",myTeam->name,aiTeam->pokeName);
        if(aiTeam->is_nowDefending == 1)
        {
            printf("\n%s realized a great defensive move and has only receieved 5 damage\n"
                    ,aiTeam->pokeName);
            aiTeam->HP -= 5;
            aiTeam->is_nowDefending = 0;
        }  
        else
        {
            printf("\n%s has recieved 10 damage\n",aiTeam->pokeName);
            aiTeam->HP -= 10;
        }
        myTeam->is_nowDefending = 0;
    }
    else
    {
        printf("\nRival's %s is attacking your %s!",aiTeam->pokeName,myTeam->name);
        if(myTeam->is_nowDefending == 1)
        {
            printf("\n%s realized a great defensive move and has only receieved 5 damage\n"
                ,myTeam->name);
            myTeam->HP -= 5;
            myTeam->is_nowDefending = 0;
        }   
        else
        {
            printf("\n%s has recieved 10 damage\n",myTeam->name);
            myTeam->HP -= 10;
        }
        aiTeam->is_nowDefending = 0;
    } 
}

void Defend(void * ptr[])
{
    //Getting all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];
    if(*turn == 0)
    {
        printf("%s is preparing a defensive move!\n",myTeam->name);
        myTeam->is_nowDefending = 1;
    }
    else
    {
        printf("%s is preparing a defensive move!\n",aiTeam->pokeName);
        aiTeam->is_nowDefending = 1;
    }
}

void Magic(void * ptr[])
{
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];
    int election;

    if(MYTURN)
    {
        printf("Magic Attacks for %s:\n", myTeam->name);
        for (int i = 0; i < 3; i++)
        {
            printf("%d. %s\n", i + 1, myTeam->magNames[i]);
        }
        printf("Choose: \n");
        scanf("%d",&election);
        printf("%s uses %s\n",myTeam->name,myTeam->magNames[election-1]);
        myTeam->magicPtr[election-1](ptr);
    }
    else
    {
        if(AITURN)
        {
            printf("Rival is using a magic attack\nRival is taking a decision");
            for(int i = 0; i<3 ; i++)
            {
                sleep(1);
                printf(".");
            }
            printf("\n");
        }
        election = random1to3;
        printf("%s uses %s\n",aiTeam->pokeName,aiTeam->magNames[election]);
        aiTeam->magicPtr[election](ptr);
    }
    downDefense
}

int midturn_pokemonCheck(void * ptr[])
{
        //Getting all pointers back
        Pokemon *myTeam = (Pokemon *)ptr[0];
        Pokemon *aiTeam = (Pokemon *)ptr[1];
        int *turn = (int *)ptr[2];

        if(aiTeam->HP <= 0) return 0;
        if(myTeam->HP <= 0) return 1;
        else return -1;
}

void printPlay(void * ptr[])
{   
    //Getting all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];

    printf((*turn == 0) ? "YOUR TURN\n" : "RIVAL TURN\n");

    //printf("%d",*turn);

    printf("  Rival Pokemon: %s\n",aiTeam->pokeName);
    printf("  HP: %d\n", aiTeam->HP);
    printf("  Defending: %s\n", aiTeam->is_nowDefending ? "Yes" : "No");
    printf("  Charging turns: %d\n", aiTeam->is_nowCharging);
    printf("---------------------------------------\n");

    printf("  Your Pokemon: %s\n",myTeam->pokeName);
    printf("  Name: %s\n", myTeam->name);
    printf("  HP: %d\n", myTeam->HP);
    printf("  Defending: %s\n", myTeam->is_nowDefending ? "Yes" : "No");
    printf("  Charging turns: %d\n", myTeam->is_nowCharging);
    printf("=======================================\n");

    if(AITURN)
    {
        printf("Rival is taking a decision");
        for(int i = 0; i<3 ; i++)
        {
            sleep(1);
            printf(".");
        }
        printf("\n");
    }
}

void playTurn(void * ptr[])
{
    //Getting all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];
    int election;

    printPlay(ptr);

    if(*turn == 0)
    {
        if(myTeam->is_nowCharging >= 1)
        {

            election = electionCatch(ptr);
        }
        else
        {
            election = electionCatch(ptr);
        }
    }
    else
    {
        if(aiTeam->is_nowCharging >= 1)
        {
            printf("Rival's %s is now charging his next move\nCan't use Magic moves\n",aiTeam->pokeName);
            aiTeam->is_nowCharging -= (aiTeam->is_nowCharging >= 1) ? 1 : 0;
            election = (rand() % 2) + 1;
        }
        else
        {
            election = (rand() % 3) + 1;
        }
    }
        
    switch (election)
    {
    case 1:
        //printf("Before: MyDefending=%d, AiDefending=%d\n",myTeam->is_nowDefending, aiTeam->is_nowDefending);
        Attack(ptr);
        *turn = (*turn == 0) ? 1 : 0;
        //printf("After: MyDefending=%d, AiDefending=%d\n",myTeam->is_nowDefending, aiTeam->is_nowDefending);
        enterTo();
        break;
    case 2:
        //printf("Before: MyDefending=%d, AiDefending=%d\n",myTeam->is_nowDefending, aiTeam->is_nowDefending);
        downDefense
        Defend(ptr);
        *turn = (*turn == 0) ? 1 : 0;
        //printf("After: MyDefending=%d, AiDefending=%d\n",myTeam->is_nowDefending, aiTeam->is_nowDefending);
        enterTo();
        break;
    case 3:
        Magic(ptr);
        *turn = (*turn == 0) ? 1 : 0;
        enterTo();
        break;
    case 4:
        //resting, charging, sleeping, etc.
        *turn = (*turn == 0) ? 1 : 0;
        break;
    default:
        printf("Try again, (try between 1 to 3)");
        playTurn(ptr);
        break;
    }
    CLEAR
}

int electionCatch(void * ptr[])
{
    //Getting all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];
    int election;

    if(myTeam->is_nowCharging >= 1)
    {
        printf("Your %s is now charging his next move\nCan't use Magic moves",myTeam->name);
        myTeam->is_nowCharging -= (myTeam->is_nowCharging >= 1) ? 1 : 0;
        printf("  Choose an action:\n");
        printf("  1. Attack\n");
        printf("  2. Defend\n");
        printf("=======================================\n");
        printf("Your choice: ");
        scanf("%d",&election);
        election = (election < 1 || election > 2) ? electionCatch(ptr) : election;
        return election;
    }
    else
    {
        printf("  Choose an action:\n");
        printf("  1. Attack\n");
        printf("  2. Defend\n");
        printf("  3. Magic\n");
        printf("=======================================\n");
        printf("Your choice: ");
        scanf("%d",&election);
        election = (election < 1 || election > 3) ? electionCatch(ptr) : election;
        return election;
    }
}

void QuickAttack(void *ptr[])
{
    //Getting all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];

    printf("Quick Attack deals 20 HP to opponent's Pokemon and doesnt have to rest or charge\n");
    if(MYTURN)
    {
        aiTeam->HP -= (aiTeam->is_nowDefending == 1) ? 10 : 20;
        printf((aiTeam->is_nowDefending == 1) ? "%s has recieved 10 damage":
                                                 "%s has recieved 20 damage",aiTeam->pokeName);
    }
    else
    {
        myTeam->HP -= (myTeam->is_nowDefending) ? 10 : 20;
        printf((myTeam->is_nowDefending == 1) ? "%s has recieved 10 damage":
                                                "%s has recieved 20 damage",myTeam->name );
    }
}

void Slash(void *ptr[])
{
    //Getting all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];

    printf("Slash deals 100 HP to opponent's Pokemon,\nbut after that your Pokemon can't use any magic "
            "for 3 turns\n");
    if(MYTURN)
    {
        aiTeam->HP -= (aiTeam->is_nowDefending == 1) ? 50 : 100;
        printf((aiTeam->is_nowDefending == 1) ? "%s has recieved 50 damage":
                                                 "%s has recieved 100 damage",aiTeam->pokeName );
        myTeam->is_nowCharging = 3;
    }
    else
    {
        myTeam->HP -= (myTeam->is_nowDefending) ? 50 : 100;
        printf((myTeam->is_nowDefending == 1) ? "%s has recieved 50 damage":
                                                "%s has recieved 100 damage",myTeam->name );
        aiTeam->is_nowCharging = 3;
    }
}
void Crimson_Storm(void *ptr[])
{
    //Getting all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];

    printf("Crimson Storm deals 60 HP to opponent's Pokemon but after attacking,\n your Pokemon "
            "can't  use any magic for 2 turns\n"
            "After using Crimson Storm, flip a coin\n"
            "if lands head, your Charizard will not be needing any rest\n");
    if(MYTURN)
    {
        aiTeam->HP -= (aiTeam->is_nowDefending == 1) ? 30 : 60;
        printf((aiTeam->is_nowDefending == 1) ? "%s has recieved 30 damage\n":
                                                 "%s has recieved 60 damage\n",aiTeam->pokeName );
        int HrT = flipCoin();
        printf((HrT == 0) ? "Head" : "Tail"); 
        myTeam->is_nowCharging = (HrT == 0) ? 0 : 2;
    }
    else
    {
        myTeam->HP -= (myTeam->is_nowDefending) ? 30 : 60;
        printf((myTeam->is_nowDefending == 1) ? "%s has recieved 30 damage\n":
                                                "%s has recieved 60 damage\n",myTeam->name );
        int HrT = flipCoin();
        printf((HrT == 0) ? "Head" : "Tail");                                 
        aiTeam->is_nowCharging = (HrT == 0) ? 0 : 2;
    }
}

void IronBash(void *ptr[]) 
{
    //Getting all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];

    printf("Iron Bash deals 80 HP to opponent's Pokemon,\nbut after that your Pokemon can't use any magic "
            "for 2 turns\n");
    if(MYTURN)
    {
        aiTeam->HP -= (aiTeam->is_nowDefending == 1) ? 40 : 80;
        printf((aiTeam->is_nowDefending == 1) ? "%s has recieved 40 damage":
                                                    "%s has recieved 80 damage",aiTeam->pokeName );
        myTeam->is_nowCharging = 2;
    }
    else
    {
        myTeam->HP -= (myTeam->is_nowDefending) ? 40 : 80;
        printf((myTeam->is_nowDefending == 1) ? "%s has recieved 40 damage":
                                                "%s has recieved 80 damage",myTeam->name );
        aiTeam->is_nowCharging = 2;
    }
}

void FlashCannon(void *ptr[]) 
{
    //Getting all pointers back
    Pokemon *myTeam = (Pokemon *)ptr[0];
    Pokemon *aiTeam = (Pokemon *)ptr[1];
    int *turn = (int *)ptr[2];

    printf("Flash Cannon deals 40 HP to opponent's Pokemon but after attacking,\n your Pokemon "
            "can't  use any magic for 1 turns\n"
            "After using Flash Cannon, flip a coin\n"
            "if lands head, your Rival's Pokemon will need to rest his eyes for 1 turn\n");
    if(MYTURN)
    {
        aiTeam->HP -= (aiTeam->is_nowDefending == 1) ? 20 : 40;
        printf((aiTeam->is_nowDefending == 1) ? "%s has recieved 20 damage\n":
                                                    "%s has recieved 40 damage\n",aiTeam->pokeName );
        myTeam->is_nowCharging = 1;
        int HrT = flipCoin();
        printf((HrT == 0) ? "Head" : "Tail"); 
        aiTeam->is_nowCharging += (HrT == 0) ? 1 : 0;
    }
    else
    {
        myTeam->HP -= (myTeam->is_nowDefending) ? 20 : 40;
        printf((myTeam->is_nowDefending == 1) ? "%s has recieved 20 damage\n":
                                                "%s has recieved 40 damage\n",myTeam->name );
        aiTeam->is_nowCharging = 1;
        int HrT = flipCoin();
        printf((HrT == 0) ? "Head" : "Tail");                                 
        myTeam->is_nowCharging += (HrT == 0) ? 1 : 0;
    }
}

void Blizzard(void *ptr[]) {
    printf("Blizzard\n");
}

void IcyWind(void *ptr[]) {
    printf("IcyWind\n");
}

void FlyingPress(void *ptr[]) {
    printf("FlyingPress\n");
}

void HighJumpKick(void *ptr[]) {
    printf("HighJumpKick\n");
}

void LeafStorm(void *ptr[]) {
    printf("LeafStorm\n");
}

void Recover(void *ptr[]) {
    printf("Recover\n");
}

void printPoke(Pokemon *poke) 
{
    // Print general details about the Pokemon
    printf("Pokemon Name: %s\n", poke->name);
    printf("HP: %d\n", poke->HP);
    printf("Defending: %s\n", poke->is_nowDefending ? "Yes" : "No");
    printf("Charging: %s\n", poke->is_nowCharging ? "Yes" : "No");

    // Print magic names
    printf("Magic Attacks:\n");
    for (int i = 0; i < 3; i++) {
        if (poke->magNames[i] != NULL) {
            printf("  %d. %s\n", i + 1, poke->magNames[i]);
        }
    }

    // Print the magic function pointers (checking for NULL if needed)
    printf("Magic Function Pointers:\n");
    for (int i = 0; i < 3; i++) {
        if (poke->magicPtr[i] != NULL) {
            printf("  Magic %d: Function address %d\n", i + 1, poke->magicPtr[i]);
        }
    }
}

int flipCoin()
{
    printf("Flipping");
    for(int i = 0; i<3 ; i++)
    {
        sleep(1);
        printf(".");
    }
    printf("\n");
    return rand() % 2;
}

void enterTo()
{
    printf("\n\nPress Enter to continue...");
    while (getchar() != '\n');
    getchar();

}