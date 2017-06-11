#include "IA.h"
/**
@file IAdragon.h
Movimentos e ataques do dragão
*/
/**
\brief retira dano ao jogador se este estiver dentro de um cone
@param e Estado do jogo
@returns estado do jogo depois de ter sido tirada vida ao jogador
pelo cone de fogo
*/
ESTADO fireCone0 (ESTADO e);
/**
\brief dá dano ao jogador numa area 2 por 8 abaixo do dragão e atira-o
3 casas para trás ou contra a parte de baixo do mapa
@param e Estado do jogo
@returns estado do jogo depois de ter sido tirada vida ao jogador
pelo ataque de asas do dragão
*/
ESTADO wing_attack0 (ESTADO e);
/**
\brief se o jogador estiver em cima do lugar onde uma bola de fogo aterra perde vida
@param e Estado do jogo
@returns estado do jogo depois de ter sido tirada vida ao jogador pelas bolas de fogo
*/
ESTADO fireball_damage (ESTADO e);
/**
\brief o dragão escolhe de 8 a 16 bolas de fogo e atira-as para o mapa
@param e Estado do jogo
@returns estado do jogo depois de terem sido escolhidas as posições das bolas de fogo
*/
ESTADO fireball_attack0 (ESTADO e);
/**
\brief move o dragão no mapa dependendo dos ataques que ele tem ou da distancia ao jogador
@param e Estado do jogo
@return estado do jogo depois do dragão se ter movido
*/
ESTADO dragon_movement0 (ESTADO e);
/**
\brief coordena se o dragão muda de cima para baixo no mapa, se escolhe um ataque e se move ou se o executa.
@param e Estado do jogo
@returns o estado do jogo depois do dragão ter executado a sua estratégia. se o jogador estiver ao seu lado este voa para a parte de baixo do mapa
*/
ESTADO estrat_dragon0 (ESTADO e);
/**
\brief retira dano ao jogador se este estiver dentro de um cone invertido
@param e Estado do jogo
@returns estado do jogo depois de ter sido tirada vida ao jogador pelo cone de fogo invertido
*/
ESTADO fireCone1(ESTADO e);
/**
\brief dá dano ao jogador numa area 2 por 8 acima do dragão e atira-o 3 casas para trás ou contra a parte de cima do mapa
@param e Estado do jogo
@returns estado do jogo depois de ter sido tirada vida ao jogador pelo ataque de asas do dragão
*/
ESTADO wing_attack1 (ESTADO e);
/**
\brief se o jogador estiver em cima do lugar onde uma bola de fogo aterra perde vida
@param e Estado do jogo
@returns estado do jogo depois de terem sido escolhidas as posições das bolas de fogo
*/
ESTADO fireball_attack1 (ESTADO e);
/**
\brief move o dragão no mapa dependendo dos ataques que ele tem ou da distancia ao jogador
@param e Estado do jogo
@return estado do jogo depois do dragão se ter movido
*/
ESTADO dragon_movement1 (ESTADO e);
/**
\brief coordena se o dragão muda de baixo para cima no mapa, se escolhe um ataque e se move ou se o executa.
@param e Estado do jogo
@returns o estado do jogo depois do dragão ter executado a sua estratégia. Se o jogador estiver ao lado dele o drãgão voa para a parte de cima do mapa
*/
ESTADO estrat_dragon1 (ESTADO e);