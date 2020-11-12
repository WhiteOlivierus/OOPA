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

  std::cout << npc->Render() << std::endl;

  INPC *troll = new Troll(npc);
  INPC *trollElf = new Elf(troll);
  INPC *farmerTrollElf = new Farmer(trollElf);

  std::cout << farmerTrollElf->Render() << std::endl;

  delete npc;
  delete troll;
  delete trollElf;
  delete farmerTrollElf;

  return 0;
}
