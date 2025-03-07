#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CLEAR printf("\033[0;0H\033[2J");
#define TRUE 1
#define FALSE 0

typedef void (*magic) (void*);
typedef struct Pokemon {
char name[20];
int HP;
int Defend; //Check if it is 1, to receive 50% less dmg
magic Equipped_magic[3]; 
char magic_name[3][20]; //This is an array that contain the name of the three equipped spells.
int Burn; //A '1' status means the Pokemon is on fire.
} Pokemon;

void Begin_game(Pokemon *);
void Print_player(Pokemon *);
int check_turn(Pokemon *);
void set_roles_and_play(Pokemon *, int*);
void play(void *);
void play_CPU(void *);
void attack(Pokemon * , Pokemon *);
void defend(Pokemon *);
void burn_check(Pokemon *);
int magic_select(Pokemon* , int, int );


void Energy_burst(void *);
void Cleanse(void *);
void Ignition(void *);
void Heal(void *);
void Hyper_Beam(void *);

int main()
{
    srand(time(NULL));

    Pokemon Player;
    Pokemon CPU;
    Pokemon Players[2] = {Player, CPU}; //Will contain Player at [0] and CPU at [1]
    Pokemon * ptr = Players;
    int in_turn = 0; //This variable manages turns. A zero value means Player's turn, one means CPU's
    int * turn_manager = &in_turn;
    Begin_game(Players);

    while(Players[0].HP > 0 && Players[1].HP > 0)
    {
        Print_player(Players);
        set_roles_and_play(Players, turn_manager);
        burn_check(Players);
        printf("Press ENTER to continue...");
        getchar(); 
        CLEAR
    }
    if(in_turn == 0)
    {
        printf("Greninja wins!\n");
    }
    else
    {
        printf("%s wins!\n", Players[0].name);
    }


}

void Begin_game(Pokemon * Set)
{
    //Player
    printf("Enter the name of your Pokemon: ");
    fgets(Set->name, 20, stdin);
    Set->name[strcspn(Set->name, "\n")] = '\0';
    Set->HP = 100;
    Set->Defend = FALSE;
    Set->Burn = FALSE;
    printf("Select 3 magic spells:\n");
    printf("\t1 - Energy burst: Deals 20 damage. 20%% chance of stunning an enemy.\n");
    printf("\t2 - Cleanse. Removes negative effects.\n");
    printf("\t3 - Ignition. Deal 15 damage points, and set the target on fire for three turns. Burning enemies will receive 5 damage each turn.\n");
    printf("\t4 - Heal. Heal 15 HP.\n");
    printf("\t5 - Hyper Beam. Deals 1 damage + 50%% of targets missing HP\n");

    int selection;
    int Taken_spells[3] = {-1,-1,-1}; //This array serves as validation, so  the player can't take the same magic twice. 
    int z = 0;                          //Initialized in -1 values because the magics correspond to numbers 0 - 4
    while(z < 3)
    {
        
        printf("Spell slot %d: ", z+1);
        int ret = scanf("%d", &selection);
        int Error = FALSE;
        for(int y= 0;y< 3; y++)
        {
            if(Taken_spells[y] == selection) //Check the values of the Taken_spells array, to see if the spell is already taken.
            {   
                Error = TRUE;
            }
        }
        if(Error != TRUE)
        {
            magic_select(Set, selection - 1 , z); //Since the player and the CPU share the magic select function, and the CPU's values start at 0, the players 
            Taken_spells[z] = selection;            //values are passed with a -1, to make them zero based.
            z++;
        }
        else
        {
            printf("Magic already selected!\n");
        }
    }
    

    //CPU
    Set++;
    strcpy(Set->name, "Greninja");
    Set->HP = 100;
    Set->Defend = FALSE;
    Set->Burn = FALSE;
    z = 0;
    Taken_spells[0] = -1; //Reset the array
    Taken_spells[1] = -1;
    Taken_spells[2] = -1;
    while(z < 3)
    {
        int selection = rand() % 5;
        int Error = FALSE;
        for(int y= 0;y< 3; y++)
        {
            if(Taken_spells[y] == selection)
            {   
                Error = TRUE;
            }
        }
        if(Error != TRUE)
        {
            magic_select(Set, selection, z);
            Taken_spells[z] = selection;
            z++;
        }
    }
    CLEAR
}
int magic_select(Pokemon* Pkm, int selection, int iteration)
{   
    switch (selection)
        {
        case 0:
            Pkm->Equipped_magic[iteration] = Energy_burst;
            strcpy(Pkm->magic_name[iteration], "Energy Burst");
            break;
        case 1:
            Pkm->Equipped_magic[iteration] = Cleanse;
            strcpy(Pkm->magic_name[iteration], "Cleanse");
            break;
        case 2:
            Pkm->Equipped_magic[iteration] = Ignition;
            strcpy(Pkm->magic_name[iteration], "Ignition");
            break;
        case 3:
            Pkm->Equipped_magic[iteration] = Heal;
            strcpy(Pkm->magic_name[iteration], "Heal");
            break;
        case 4:
            Pkm->Equipped_magic[iteration] = Hyper_Beam;
            strcpy(Pkm->magic_name[iteration], "Hyper Beam");
            break;
        default:
            break;
        }
}
void print_magic(Pokemon * pkm)
{
    printf("Equipped spells:\n");
    printf("\t1 - %s\n", pkm->magic_name[0]);
    printf("\t2 - %s\n", pkm->magic_name[1]);
    printf("\t3 - %s\n", pkm->magic_name[2]);
}

void Print_player(Pokemon * ptr)
{
    Pokemon * P = ptr;
    ptr++; 
    Pokemon * C = ptr;
    printf("Name: %s ================================================ Name: %-20s\n", P->name, C->name);
    printf("HP:   %-4d    ================================================ HP:   %-4d\n", P->HP, C->HP);
    printf("Defend: %-4d  ================================================ Defend: %-4d\n", P->Defend, C->Defend);
    printf("Burn:   %-4d  ================================================ Burn:   %-4d\n", P->Burn, C->Burn);

}


void set_roles_and_play(Pokemon * Characters, int * turn) //This pointer checks the value of the in_turn variable
{

    Pokemon * Player = Characters;
    Characters++;
    Pokemon * CPU = Characters;
    void * Kit[3] = {Player, CPU, turn};
    
    if(*turn == 0)
    {
        *turn = 1; //Changes in_turn to one (next turn CPU)
        play(Kit);
    }
    else
    {   
        *turn = 0; //Changes in_turn to zero (next turn Player)
        play_CPU(Kit);
    }
}

void play(void * Data) //Function that allows the player to play. It has more text and options than the CPU
{
    int action;
    void ** Kit = (void **)Data;
    Pokemon * Attacker = Kit[0]; //Since it's the player's turn, attacker is the one passed in the first position, and defender the Pokemon in the second one (CPU)
    Pokemon * Defender = Kit[1];
    printf("It's %s's turn. Choose an action!\n", Attacker->name);
    printf("\t1 - Attack. Deals 10 dmg.\n");
    printf("\t2 - Defend. Receive half damage of next attack.\n");
    printf("\t3 - Cast spell. Choose one of your three magic spells and use it.\n");
    printf("Your selection -> ");
    int ret = scanf("%d", &action);
    getchar();
    //printf("Selected %d", action); //For debug
    int selected_magic;
    switch (action)
    {
    case 1:
        attack(Attacker, Defender);
        break;
    case 2: 
        defend(Attacker); 
        break;
    case 3:
        print_magic(Attacker);
        printf("Choose a spell to cast! -> ");
        int ret = scanf("%d", &selected_magic);
        Attacker->Equipped_magic[selected_magic -1](Data); //Minus one to account for zero based array.
        getchar();
        break;
    default:
        break;
    }
}

void play_CPU(void * Data) //Play function for the CPU. Calculates random values, and displays info messages
{
    void ** Kit = (void **)Data;
    Pokemon * Defender = Kit[0];
    Pokemon * Attacker = Kit[1];
    printf("It's %s's turn.\n", Attacker->name);
    int action = rand() % 3; //Random generated number between 0 -Attack, 1 - Defend and 2 - Magic
    switch (action)
    {
    case 0:
        attack(Attacker, Defender);
        break;
    case 1:
        defend(Attacker); 
        break;
    case 2:
        print_magic(Attacker);
        action = rand() % 3;
        Attacker->Equipped_magic[action](Data);
        break;
    default:
        break;
    }
}

void attack(Pokemon * Attacker, Pokemon * Defender)
{
    if(Defender->Defend == TRUE)
    {
        printf("%s hits %s. However, %s was prepared, so it receives only 5 damage points!\n", Attacker->name, Defender->name, Defender->name);
        Defender->HP = Defender->HP - 5;
        Defender->Defend = 0;
    }
    else
    {
        printf("%s hits %s, inflicting 10 damage points.\n", Attacker->name, Defender->name);
        Defender->HP = Defender->HP - 10;
    }
}

void defend(Pokemon * Attacker)
{
    printf("%s switches to a defensive stand. He will receive 50%% less damage from next attack!\n", Attacker->name);
    Attacker->Defend = 1;
}

//Magic attacks
void Energy_burst(void * Characters) //Attack that does 20 dmg and has a stun chance of 20%
{
    void ** Kit = (void **)Characters;
    Pokemon * Attacker = NULL;
    Pokemon * Defender = NULL;
    int * turn = Kit[2];
    if(*turn == 1)
    {
        Attacker = Kit[0];   
        Defender = Kit[1]; 
        if(Defender->Defend == FALSE)
        {
            printf("%s creates a ball of energy and throws it at %s, inflicting 20 damage points!\n", Attacker->name, Defender->name);
            Defender->HP = Defender->HP - 20;
        }
        else
        {
            printf("%s gathers energy and unleashes it onto %s. %s jumps in the air, nearly dodging the attack and receiving 10 damage points!\n", Attacker->name, Defender->name, Defender->name);
            Defender->HP = Defender->HP - 10;
            Defender->Defend = FALSE;
        }
        int stun_chance = rand() % 5;
        if(stun_chance == 0)
            {   
                    *turn = 0; //This is what causes the CPU to miss its turn, because its sets the variable turn to the player value (0)
                    printf("Oh no! %s is stunned! It loosses one turn.", Defender->name);
                    
            } 
    }
    else
    {
        Defender = Kit[0];
        Attacker = Kit[1];
        if(Defender->Defend == FALSE)
        {
            printf("%s creates a ball of energy and throws it at %s, inflicting 20 damage points!\n", Attacker->name, Defender->name);
            Defender->HP = Defender->HP - 20;
        }
        else
        {
            printf("%s gathers energy and unleashes it onto %s. %s jumps in the air, nearly dodging the attack and receiving 10 damage points!\n", Attacker->name, Defender->name, Defender->name);
            Defender->HP = Defender->HP - 10;
            Defender->Defend = FALSE;
        }
        int stun_chance = rand() % 5;
        if(stun_chance == 0)
            {   
                    *turn = 1; //Causes the player to miss its turn.
                    printf("Oh no! %s is stunned! It loosses one turn.\n", Defender->name);
            } 
    }
    
}

void Cleanse(void * Characters)  //Removes negative effects, such as Burn
{
    void ** Kit = (void **)Characters;
    Pokemon * Attacker = NULL;
    int * turn = Kit[2];
    if(*turn == 1) //Determines who is the attacker (the one casting the spell)
    {
        Attacker = Kit[0];   
    }
    else
    {
        Attacker = Kit[1];
    }
    printf("%s concentrates and casts Purification, removing negative effects.\n", Attacker->name);
    Attacker->Burn = FALSE; //Set burn to 0, removing the effect.
}

void Ignition(void * Characters) //Deals 15 dmg points. The target will burn for three turns, loosing 5 HP each time
{
    void ** Kit = (void **)Characters;
    Pokemon * Attacker = NULL;
    Pokemon * Defender = NULL;
    int * turn = Kit[2];
    if(*turn == 1)//If it is the player turns, set attacker to player's Pokemon, and Defender to CPU
    {
        Attacker = Kit[0];   
        Defender = Kit[1];   
    }
    else//Defender is the player's Pokemon, CPU is the attacker.
    {
        Defender = Kit[0];
        Attacker = Kit[1];
    }
    if(Defender->Defend == FALSE)
    {
        printf("%s conjures a pilar of flames that deals 15 damage and sets %s on fire for three turns.\n", Attacker->name, Defender->name);
        Defender->HP = Defender->HP - 15;
    }
    else
    {
        printf("%s conjures a pilar of flames, which %s nearly dodges. %s receives 7 damage and sets %s on fire for three turns.\n", Attacker->name, Defender->name, Defender->name);
        Defender->HP = Defender->HP - 7;
        Defender->Defend = FALSE;
    }
    Defender->Burn = 3; //Set burn to 3. The value will go down each turn (check burn_check function).
}

void Heal(void * Characters) //Heals the caster for 20 HP
{
    void ** Kit = (void **)Characters;
    Pokemon * Attacker = NULL;
    int * turn = Kit[2];
    if(*turn == 1)
    {
        Attacker = Kit[0];   
    }
    else
    {
        Attacker = Kit[1];
    }
    printf("%s focuses. It channels energy into its body, mending wounds and restoring 15 HP!\n", Attacker->name);
    Attacker->HP = Attacker->HP + 15;
    if(Attacker->HP > 100) //Assures no Pokemon can get more HP than its max.
        Attacker->HP = 100;
}

void Hyper_Beam(void * Characters) //Execute. Deals 1 damage + 50% of targets missing HP. The less HP a Pokemon has, the more effective it is.
{

    void ** Kit = (void **)Characters;
    Pokemon * Attacker = NULL;
    Pokemon * Defender = NULL;
    int * turn = Kit[2];
    if(*turn == 1)
    {
        
        Attacker = Kit[0];   
        Defender = Kit[1];   
    }
    else
    {
        
        Defender = Kit[0];
        Attacker = Kit[1];
    }
    int missing_HP = 100 - Defender->HP; //Calculates target's missing HP.
    int dmg = 1 + (missing_HP / 2); 

    if(Defender->Defend == FALSE)
    {
        if(dmg == 0)//This is in case the ability is used on a Pokemon that has full health. Since the dmg would be zero, sets it to 1.
        {
            dmg = 1;
        }
        printf("%s channels a massive energy beam, and prepares to anihilate %s with it. %s gets hit and receives %d damage points!\n", Attacker->name, Defender->name,Defender->name, dmg);
        Defender->HP = Defender->HP - dmg;
    }
    else
    {
        dmg = dmg / 2; //If the Pokemon is defending, receives half the damage.
        if(dmg == 0)//This is in case the ability is used on a Pokemon that has full health. Since the dmg would be zero, sets it to 1.
        {
            dmg = 1;
        }
        printf("%s releases a devastating attack, but %s was prepared, and only receives %d damage points!\n", Attacker->name, Defender->name, dmg);
        Defender->HP = Defender->HP - dmg;
        Defender->Defend = FALSE;
    }

}

void burn_check(Pokemon * Pkm) //Checks Burn status on BOTH Pokemons. If anyone is burning, looses 5 HP.
{
    if(Pkm->Burn > 0) //Checks Player's Pokemon
    {
        printf("%s is burning and looses 5 HP!\n", Pkm->name);
        Pkm->HP = Pkm->HP - 5;
        Pkm->Burn--; //Decreses burn counter by 1, since it lasts three turns.
    }
    Pkm++; //Moves to check CPU's Pokemon
    if(Pkm->Burn > 0)
    {
        printf("%s is burning and looses 5 HP!\n", Pkm->name);
        Pkm->HP = Pkm->HP - 5;
        Pkm->Burn--; 
    }
}

