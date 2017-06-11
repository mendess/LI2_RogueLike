#ifndef ___UI_MASTER_H___
#define ___UI_MASTER_H___

/**
@file UIMaster.h
Definição das funções que controlam a interface
*/

#include "../estrutura.h"

#include "UI0Form.h"
#include "UI1Menu.h"
#include "UI2CharSelect.h"
#include "UI4ScoreBoard.h"
#include "UI5Playing.h"
#include "UI6Shop.h"

/** \brief Imprime o header do UI */
void print_header();
/** \brief Imprime o footer do UI */
void print_footer();
/**
\brief Função mestra que imprime toda a interfaçe 
@param e Estado do Jogo
*/
void imprime(ESTADO e);

#endif
