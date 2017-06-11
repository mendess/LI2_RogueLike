#ifndef __UI_MACROS_H__
#define __UI_MACROS_H__

/**
@file UIMacros.h
Definição de varias macros para usar ao gerar a interface
*/

/** \brief Lista das imagens do items */
#define ITEM_LIST				{"Empty",\
								 "Item_PotionHealth.png",\
								 "Item_PotionMana.png",\
								 "Item_ScrollRed.png",\
								 "Item_ScrollYellow.png",\
								 "Item_ScrollGreen.png",\
								 "Item_ScrollBlue.png",\
								 "Empty",\
								 "Empty",\
								 "Empty",\
								 "Item_SwordBronze.png",\
								 "Item_SwordIron.png",\
								 "Item_SwordSteel.png",\
								 "Item_SwordPalladium.png",\
								 "Item_ArmourBronze.png",\
								 "Item_ArmourIron.png",\
								 "Item_ArmourSteel.png",\
								 "Item_ArmourPalladium.png"}

/** \brief Largura do SVG */
#define SVG_WIDTH				800
/** \brief Altura do SVG */
#define SVG_HEIGHT				600
/** \brief Macro para abrir o SVG */
#define ABRIR_SVG				printf("<svg width=%d height=%d>\n",SVG_WIDTH,SVG_HEIGHT)
/** \brief Macro para fechar o SVG */
#define FECHAR_SVG				printf("</svg>\n")
/** \brief Macro com o caminho para as images */
#define IMAGE_PATH				"http://127.0.0.1/imagens/"
/** 
\brief Macro para imprimir uma imagem
@param X A coordenada X do canto superior esquerdo
@param Y A coordenada Y do canto superior esquerdo
@param WIDTH Largura da imagem
@param HEIGHT Altura da imagem
@param FICHEIRO Nome do ficheiro com a imagem
*/
#define IMAGEM(X,Y,WIDTH,HEIGHT,FICHEIRO)	printf("<image x=%d y=%d width=%d height=%d preserveAspectRatio=none xlink:href=%s%s />\n", \
												X, Y, WIDTH, HEIGHT, IMAGE_PATH, FICHEIRO)
/** 
\brief Macro para imprimir uma imagem formatada para ser uma peça do jogo
@param X A coordenada X do canto superior esquerdo
@param Y A coordenada Y do canto superior esquerdo
@param WIDTH Largura da imagem
@param HEIGHT Altura da imagem
@param FICHEIRO Nome do ficheiro com a imagem
*/
#define IMAGEM_FORMATED(X,Y,WIDTH,HEIGHT,FICHEIRO)	printf("<image x=%d y=%d width=%d height=%d preserveAspectRatio=none xlink:href=%s%s />\n", \
																(X+1)*TAM, (Y+1)*TAM, WIDTH, HEIGHT, IMAGE_PATH, FICHEIRO)

/**
\brief Macro para criar um quadrado
@param X A coordenada X do canto superior esquerdo
@param Y A coordenada Y do canto superior esquerdo
@param FILL A cor de preenchimento do quadrado
@param F_OPACITY Opacidade do preenchimento do quadrado
@param STROKE Cor do contorno do quadrado
@param S_OPACITY Opacidade do contorno do quadrado
@param SCALE A escala do quadrado
*/
#define SQUARE(X,Y,FILL,F_OPACITY,STROKE,S_OPACITY,SCALE)	printf("<rect x=%d y=%d width=%d height=%d style=fill:%s;fill-opacity:%f;stroke:%s;stroke-opacity:%f;stroke-width:5/></rect>\n", \
																		     X,   Y,   SCALE,    SCALE,         FILL,        F_OPACITY,   STROKE,          S_OPACITY)
/**
\brief Macro para criar um quadrado formatada param ser uma peça do jogo
@param X A coordenada X do canto superior esquerdo
@param Y A coordenada Y do canto superior esquerdo
@param FILL A cor de preenchimento do quadrado
@param F_OPACITY Opacidade do preenchimento do quadrado
@param STROKE Cor do contorno do quadrado
@param S_OPACITY Opacidade do contorno do quadrado
@param SCALE A escala do quadrado
*/
#define SQUARE_FORMATED(X,Y,FILL,F_OPACITY,STROKE,S_OPACITY,SCALE)	printf("<rect x=%d y=%d width=%d height=%d style=fill:%s;fill-opacity:%f;stroke:%s;stroke-opacity:%f;stroke-width:5/></rect>\n", \
																		    	 (X+1)*TAM,   (Y+1)*TAM,   SCALE,    SCALE,         FILL,        F_OPACITY,   STROKE,          S_OPACITY)
/**
\brief Macro para criar um circulo
@param X A coordenada X do centro
@param Y A coordenada Y do centro
@param RADIUS Raio do circulo
@param FILL A cor de preenchimento do quadrado
@param F_OPACITY Opacidade do preenchimento do quadrado
@param STROKE Cor do contorno do quadrado
@param S_OPACITY Opacidade do contorno do quadrado
@param SCALE A escala do quadrado
*/
#define CIRCLE(X,Y,RADIUS,FILL,F_OPACITY,STROKE,S_OPACITY,SCALE)	printf("<circle cx=%d cy=%d r=%d style=fill:%s;fill-opacity:%f;stroke:%s;stroke-opacity:%f;stroke-width:5/></circle>\n", \
																                X+SCALE/2,Y+SCALE/2,RADIUS,   FILL,      F_OPACITY,   STROKE,        S_OPACITY)
/**
\brief Macro para abrir um link
@param name Nome do jogador
@param action Ação do Link
*/
#define ABRIR_LINK(name,action)	printf("<a xlink:href=http://localhost/cgi-bin/roguel?%s,%s>\n",name,action)
/** \brief Macro para abrir um link para voltar para o primeiro menu */
#define ABRIR_RESET_LINK		printf("<a xlink:href=http://localhost/cgi-bin/roguel>\n")
/** \brief Macro para fechar um link */
#define FECHAR_LINK				printf("</a>\n")

#endif