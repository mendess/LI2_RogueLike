#ifndef ___JOGO_H___
#define ___JOGO_H___

//#define BOSS
#define ANTICHEAT

#include "estrutura.h"
#include "actionMap.h"
#ifdef ANTICHEAT
#include "antiCheat.h"
#endif
#include "levelMaker.h"
#include "calcularCombate.h"
#include "IA/IA.h"
#include "shop.h"
#include "score.h"
#include "items.h"
#include "html/htmlMaster.h"

#define FILEPATH	"/var/www/html/files/"

/*
--gold
GoldCoins
--potion
HealthPotion    1
ManaPotion      2
--scroll
ScrollFire      3  - Vermelho
ScrollLightning 4  - Amarelo
ScrollTeleport  5  - Azul
ScrollHealing   6  - Pink
--weapon
SwordBronze     10 - Castanho
SwordIron       11 - Cinzento Escuro
SwordSteel      12 - Cinzento Claro
SwordPalladium  13 - Inventa para ai
--armour
ArmourBronze    14 - Castanho
ArmourIron      15 - Cinzento Escuro
ArmourSteel     16 - Cinzento Claro
ArmourPalladium 17 - Inventa para ai
*/

/**
\brief Calcula um novo estado conforme a ação que esteja no estado que recebe
@param e Estado do jogo
*/
ESTADO calcularNovaEstado(ESTADO e);
/**
\brief Lê o estado de um ficheiro
Converte o estado que estava em hexadecimal no ficheiro para uma struct ESTADO e muda a action conforme a que está na QUERY_STRING
@param args QUERY_STRING
@param gamestateFile Apontador para um ficheiro com o estado
*/
ESTADO ler_estado (char *args);
/**
\brief Escreve o estado no ficheiro
@param e EStado do jogo
*/
void escrever_estado(ESTADO e);
/**
\brief Corre o jogo.
Cria um novo jogo se estiver a começar ou faz "update" ao estado conforme o que o jogador fez.
*/
ESTADO runGame();

void keepLog(ESTADO e);

#endif
