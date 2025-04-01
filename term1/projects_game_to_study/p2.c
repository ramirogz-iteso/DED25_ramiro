#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_HP 100
#define MAX_NAME_LEN 50
#define MAX_MAGIC 3
#define CLEAR printf("\033[0;0H\033[2J");

typedef struct Player {
    char name[MAX_NAME_LEN];
    int hp;
    int DefendAct; //if is 1 the Player is using the defend function
    void (*magic[MAX_MAGIC])(void *both_players); // I declared the function pointer here !
    int Paralized;
    int Poisoned; // Its another flag that indicates if the player is poisoned or not
    int PDamage;
} Player;

//First the declaration of all the functions i will use in this program
void attack(Player *attacker, Player *defender);
void defend(Player *defender);
void Piro(void *both_players);
void Cura(void *both_players);
void Thunder(void *both_players);
void Octaslash(void *both_players);
void Bio(void *both_players);
void AppBio(Player *p);
void Status(Player *p1, Player *p2);
void TkT(Player *p1, Player *p2);
void GLoop(Player *p1, Player *p2);
void cpuTurn(Player *p1, Player *p2);
void AssingMagic(Player *p1);
void AssingMagicCPU(Player *p2);

int main(){
  srand(time(NULL));
  Player p1, p2;
  Player players[2] = {p1, p2};
  Player *ptrpl = players;

  //The initial config for the player (Human)
  printf("Introduce the name of your character: ");
  fgets(ptrpl->name, MAX_NAME_LEN, stdin);
  ptrpl->name[strcspn(ptrpl->name, "\n")] = '\0'; //This line replace the "\n" that fgets create with a "\0". 
  CLEAR;
  ptrpl->hp = MAX_HP;
  ptrpl->DefendAct = 0;
  ptrpl->Paralized = 0;
  ptrpl->Poisoned = 0;
  ptrpl->PDamage = 0;
  //The function that allows the player select the magic he/she wants to use
  AssingMagic(ptrpl);

  CLEAR;

  ptrpl++; //I move the pointer
  //The configuration of the second player
  printf("Who's gonna be your opponent: ");
  fgets(ptrpl->name, MAX_NAME_LEN, stdin);
  ptrpl->name[strcspn(ptrpl->name, "\n")] = '\0';
  CLEAR;
  ptrpl->hp = MAX_HP;
  ptrpl->DefendAct = 0;
  ptrpl->Paralized = 0;
  ptrpl->Poisoned = 0;
  ptrpl->PDamage = 0; 
  AssingMagicCPU(ptrpl); // <- The function that allows the CPU ""Choose" the materias he wants to use.

  CLEAR;
  ptrpl = players;

  Player *ptr1, *ptr2; // Creating new ptrs just to help doing the Gloop more easy.
  ptr1 = ptrpl;

  ptrpl++;

  ptr2 = ptrpl;

  GLoop(ptr1, ptr2); // The game Loop function... bassically the soul of the game. 
}

//Basic attack function
void attack(Player *attacker, Player *Defender){
    int dmg = 10;
    if(Defender->DefendAct){
      dmg /= 2;
      printf("%s is defending himself ! the damage is reduce by %d\n", Defender->name, dmg);
      Defender->DefendAct = 0;
    }

    Defender->hp -= dmg;
    if(Defender->hp < 0) Defender ->hp = 0;
    printf("%s attacked %s causing %d damage!", attacker->name, Defender->name, dmg);

    
}

// A heavy physical attack, that is classified like magic,
void Octaslash(void *both_players){
  Player **players = (Player **)both_players;
  Player *attacker = *players;
  Player *defender = *(players + 1);

  int dmg = 45;
  printf("%s just used Octaslash on %s! \n %s has been injured! \n", attacker->name, defender->name, defender->name);

  if(defender->DefendAct){
    dmg /= 2;
    printf("\n%s is defending himself ! the damage is reduce by %d\n", defender->name, dmg);
    defender->DefendAct = 0;
  }

  printf("Damage: %d\n", dmg);

  defender->hp -= dmg;
}
// The defending function, the only use of this is manage and modify the defending flag.
void defend(Player *defend){
  if(!defend->DefendAct){
    defend->DefendAct = 1;
    printf("\n%s is in defensive mode! all attacks will cause half of damage", defend->name);    
  }else{
    printf("\n%s is already defending himsel! use ohter thing...", defend->name);
  }
}
// A fire damage materia! 
void Piro(void *both_players){
  Player **players = (Player **)both_players;
  Player *attacker = *players;
  Player *defender = *(players + 1);

  int dmg = 30;
  printf("%s just used Piro on %s! \n %s it's in flames! \n Damage: %d", attacker->name, defender->name, defender->name, dmg);
  //If the defender action is on the damage will be reduced by the half. 
  if(defender->DefendAct){
    dmg /= 2;
    printf("\n%s is defending himself ! the damage is reduce by %d\n", defender->name, dmg);
    defender->DefendAct = 0; //It will reset the flag after use.
  }

  defender->hp -= dmg;
}
// This is the healing magic. And only affect one player. 
void Cura(void *both_players){
  Player **players = (Player **)both_players;
  Player *attacker = *players;

  int heal = 15;
  attacker->hp += heal;
  if(attacker->hp > MAX_HP){
    attacker->hp = MAX_HP;
  }
  printf("\n%s Regains %d points of life! ", attacker->name, heal);
}

// the fuction for the thunder materia.
void Thunder(void *both_players){
  Player **players = (Player **)both_players;
  Player *attacker = *players;
  Player *defender = *(players + 1);

  int dmg = 15;
  int parachance = rand() % 100; //This is a flag that i use to indicate the probabilites to get paralized
  printf("%s used Thunder on %s! \n %s it's in pain! \n", attacker->name, defender->name, defender->name);
  if(parachance < 20){ // A 20% of chance to get paralized
    defender->Paralized = 1; // Here i active the Paralized flag to indicate that this player will loose his/her turn
    printf("\n%s is paralized! %s will loose the next turn", defender->name, defender->name);
  }

  if(defender->DefendAct){
    dmg /= 2;
    printf("\n%s is defending himself ! the damage is reduce by %d\n", defender->name, dmg);
    defender->DefendAct = 0;
  }

  printf("Damage: %d", dmg);
  defender->hp -= dmg;
}

// This is the Poison function, like the other materias function it will work with just a array of void pointers.
void Bio(void *both_players){
  Player **players = (Player **)both_players;
  Player *attacker = *players;
  Player *defender = *(players + 1);

  int dmg = 15;
  int poisonedChance = rand() % 100; // This is the probabilities to get poisoned!

  printf("%s used Bio on %s! \n%s it's in pain! \nDamage: %d\n", attacker->name, defender->name, defender->name, dmg);

  // this is if the number is less than 95 and the defender is not poisoned.
  if (poisonedChance < 95 && defender->Poisoned == 0) {
      defender->Poisoned = 3; // The posion will lasts 2 turns
      defender->PDamage = 5; // The posion damage per turn
      printf("\n%s is poisoned! %s will lose life for the next 3 turns!\n", defender->name, defender->name);
  } else if (defender->Poisoned > 0) {
      printf("\n%s is already poisoned!\n", defender->name);
  }
  if (defender->DefendAct) {
      dmg /= 2;
      printf("\n%s is defending himself! The damage is reduced by %d\n", defender->name, dmg);
      defender->DefendAct = 0; // Reset the defense 
  }

  defender->hp -= dmg; // Applies the damage of the materia
}
//This is the function that applies the passive poison damage.
void AppBio(Player *p){
  if(p->Poisoned > 0){
    printf("\n%s suffers %d poison damage!\n", p->name, p->PDamage);
    p->hp -= p->PDamage;
    p->Poisoned -= 1; //This reduce the poison flag every time a turn occurs.
    if(p->Poisoned == 0){
      printf("\n%s is no longer poisoned!\n", p->name);
    }
  }
}

// The function that allow the player choose his materias 
void AssingMagic(Player *p1){
  int choice;

  printf("Choose your materias %s!\n", p1->name);
  printf("1. Piro\n");
  printf("2. Cura\n");
  printf("3. Thunder\n");
  printf("4. Octaslash\n");
  printf("5. Bio\n");

  for(int i = 0; i < MAX_MAGIC; i++){
    printf("Choose now ! (1-5): ");
    scanf("%d", &choice);
    getchar();
    switch (choice) // A switch to manage the materia selection.
    {
    case 1:
        *(p1->magic + i) = Piro;
        break;
    case 2: 
      *(p1->magic + i) = Cura;
      break;
    case 3: 
      *(p1->magic + i) = Thunder;
      break;
    case 4:
      *(p1->magic + i) = Octaslash;
      break;
    case 5: 
      *(p1->magic + i) = Bio;
      break;
    default:
      printf("Invalid Selection.... Try Again!\n");
      i--;
      break;
    }
  }
  CLEAR;
}

// The function that allows the CPU to "choose" the magic abilities.
void AssingMagicCPU(Player *p2){
  int RandIdex; 
  for(int i = 0; i < MAX_MAGIC; i++){
    RandIdex = rand() % MAX_MAGIC; //This is updated. Now the CPU can choose among the 5 materias.
    switch (RandIdex)
    {
      case 1:
      *(p2->magic + i) = Piro;
      break;
  case 2: 
    *(p2->magic + i) = Cura;
    break;
  case 3: 
    *(p2->magic + i) = Thunder;
    break;
  case 4:
    *(p2->magic + i) = Octaslash;
    break;
  case 5: 
    *(p2->magic + i) = Bio;
    break;
  default:
    printf("Invalid Selection.... Try Again!\n");
    i--;
    break;
    }
  }
}

// Take turn AKA Takata. Is the function that handles the human player turn.
void TkT(Player *p1, Player *p2){
  //First checks if the player is paralizes. If this is true then the turn will be skipped.
  if(p1->Paralized){
    printf("%s is paralized! he cant move!\n", p1->name);
    p1->Paralized = 0;
    return;
  }
  //Does the same with the poison, but this time it will call the function AppBio. That function deals the poison damage,
  if(p1 -> Poisoned > 0){
    AppBio(p1);
  }
  //This will reset the flag every begin of the turn.
  p1 ->DefendAct = 0;

  printf("%s turn!\n", p1->name);
  printf("1. Attack\n");
  printf("2. Defend\n");
  printf("3. Magic\n");
  int choice;
  do{ 
    printf("Choose your action: ");
    scanf("%d", &choice);
    getchar();

    if (choice < 1 || choice > 3){
      printf("Invalid option!");
    }
  } while (choice < 1 || choice > 3);
    switch (choice)
    {
    case 1:
      attack(p1,p2);
      break;
    case 2:
      defend(p1);
      break;
    case 3:
      CLEAR;
      printf("Choose your materia!\n");
      char * magics[] = {"Piro", "Cura", "Thunder", "Octaslash", "Bio"};
      for(int i = 0; i < MAX_MAGIC; i++){
        char *spellName = NULL; // the default or NULL value of the variable
        void (*currentSpell)(void *) = *(p1->magic + i); // This will allow to use pointer arithmetic
        //This allow to list all the materias in the screen.
        if (currentSpell == Piro) spellName = *(magics);
        else if (currentSpell == Cura) spellName = *(magics + 1);
        else if (currentSpell == Thunder) spellName = *(magics + 2);
        else if (currentSpell == Octaslash) spellName = *(magics + 3);
        else if (currentSpell == Bio) spellName = *(magics + 4);

        printf("%d. %s\n", i+1, spellName);
      }
      do{
        printf("Choose a Magic: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3){
            printf("Invalid option!");
        }
      }while (choice < 1 || choice > MAX_MAGIC);

      Player *both_players[2] = {p1, p2}; //This will pass only one array to all the magic functions.
      (*(*(p1->magic + (choice-1))))((void *)both_players); // With this the magics will work using arrays.
      break;
    }
}

//The function that handles the CPU turn.
void cpuTurn(Player *p1, Player *p2){
    if(p1->Paralized){
      printf("%s is paralized and can't move this turn!\n", p1->name);
      p1->Paralized = 0;
      return;  // It ends the whole function if the CPU is paralized
    }
    if(p1 -> Poisoned > 0){
      AppBio(p1);
    }

    p1->DefendAct = 0;
  
    int choice = rand() % 3 + 1; //This is the random int that "choose" the CPU next action.
    switch (choice) {
      case 1:
        printf("%s decided to attack!\n", p1->name);
        attack(p1, p2);
        break;
      case 2:
        printf("%s decided to defend!\n", p1->name);
        defend(p1);
        break;
      case 3:
        printf("%s is using magic!\n", p1->name);
        int magicChoice = rand() % MAX_MAGIC; // Choose a random magic
        Player *both_players[2] = {p1, p2};
        (*(p1->magic + magicChoice))((void *)both_players); // Call the function for the selected magic.
    }
  }
  

// Prints the status of both players
void Status(Player *p1, Player *p2){
  printf("\n==============================================\n");
  printf("%-15s ||   %-15s\n", p1->name, p2->name);
  printf("HP: %-3d/%-3d   ||   HP: %-3d/%-3d\n", p1->hp, MAX_HP, p2->hp, MAX_HP);

  if (p1->DefendAct || p2->DefendAct) {
    char p1Status[20] = " ";
    char p2Status[20] = " ";
    //Previously this function used ternary operators, but it was a little bit too confusing.... So i've changed it to the classic IF/ELSE 
    if (p1->DefendAct) {
        strcpy(p1Status, "Defending!");
    }
    if (p2->DefendAct) {
        strcpy(p2Status, "Defending!");
    }
    
    printf("%-15s ||   %-15s\n", p1Status, p2Status);
}
  if (p1->Paralized || p2->Paralized) {
    char p1Status[20] = " "; // I declared that the array will be empty, just to avoid trash content.
    char p2Status[20] = " ";
  
    if (p1->Paralized) {
    strcpy(p1Status, "Paralized!");
    }
    if (p2->Paralized) {
      strcpy(p2Status, "Paralized!");
    }
  
    printf("%-15s ||   %-15s\n", p1Status, p2Status);
  }
  if (p1->Poisoned || p2->Poisoned) {
    char p1Status[20] = " ";
    char p2Status[20] = " ";
  
  if (p1->Poisoned) {
    strcpy(p1Status, "Poisoned!");
  }
  if (p2->Poisoned) {
    strcpy(p2Status, "Poisoned!");
  }

  printf("==============================================\n");
  }
}


void GLoop(Player *p1, Player *p2){
  Player *current = p1;
  Player *opponent = p2;
      
  while (p1->hp > 0 && p2->hp > 0) {
    if (current->Poisoned > 0) {
      AppBio(current);  // Applies the poison to the human opponent
  }
    if (opponent->Poisoned > 0) {
      AppBio(opponent);  // Applies the poison to the opponent
    }

    Status(p1,p2);  
    if (current == p1) {
      TkT(current, opponent);
    } else {
      cpuTurn(current, opponent);
    } 
    printf("\nPress Enter to continue...\n");
    getchar();
    CLEAR; 
    // We change the turn
    Player *temp = current;
    current = opponent;
    opponent = temp;
  }
  // This is just the final message of the game, to indicate who wins.
  if(p1->hp <=0){
    printf("\n %s has been defeated %s is the absolute winner!\n", p1->name, p2->name);
  }else{
    printf("\n %s has been defeated %s is the absolute winner!\n", p2->name, p1->name);
  }
}