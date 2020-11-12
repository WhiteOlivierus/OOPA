#include <iostream>

#include "Includes/NPC/BaseNPC.h"

#include "Includes/Races/Troll.h"
#include "Includes/Races/Elf.h"

#include "Includes/Jobs/Soldier.h"
#include "Includes/Jobs/Shaman.h"
#include "Includes/Jobs/Farmer.h"

int main(int, char **)
{
  INPC *npc = new BaseNPC();

  std::cout << "Client: I've got a npc component:" << std::endl;

  std::cout << "RESULT: " << npc->GetName();

  std::cout << std::endl;
  std::cout << std::endl;

  INPC *troll = new Troll(npc);
  INPC *trollElf = new Elf(troll);
  INPC *farmerTrollElf = new Farmer(trollElf);

  std::cout << "Client: Now I've got a decorated component:" << std::endl;

  std::cout << "RESULT: " << farmerTrollElf->GetName();

  std::cout << std::endl;

  delete npc;
  delete troll;
  delete trollElf;

  return 0;
}
