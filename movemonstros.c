// mover montros

pos move_monstro (ESTADO e,int i){
	int q;
	srand(NULL);
	q=rand () % 3;
	if (q=0){
		e.monstros[i].x+=1;
	}
	if (q=1){
		e.monstros[i].x+=1;
		e.monstros[i].y+=1;
	}
	if (q=2){
		e.monstros[i].x+=1;
		e.monstros[i].y+=-1;
	}
	if (q=3){
		e.monstros[i].y+=1;
	}
	if (q=4){
		e.monstros[i].y+=-1;
	}
	if (q=5){
		e.monstros[i].x+=-1;
	}
	if (q=6){
		e.monstros[i].x+=-1;
		e.monstros[i].y+=1;
	}
	if (q=7){
		e.monstros[i].x+=-1;
		e.monstros[i].y+=-1;
	}
}





Estado move_monstros (ESTADO e){
   for (i=0;i<10;i++){
   	 move_monstro(e);
   }
 
}

  




