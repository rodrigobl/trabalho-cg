class Terreno{
	
	public:
	//Limite da tela utilizada
	float limite;

	//largura e altura de cada tile do terreno
	float largura;
	float altura;
  float tipo;

  float pos_x;
  float pos_y;

  int cor;

	float escala;

  Terreno(){}

	Terreno(int s, InfoT t, float y, int i){

		limite = s;
    setDimensao(t.altura, t.largura);
    setPosicao(t.x, y);
    tipo = t.tipo;

    cor = i;

	}

  void setDimensao(float a, float l){
    altura = a;
    largura = l;
  }

  void setPosicao(float x, float y){

    pos_x = x;
    pos_y = y;

  }

  void movimentar(float velocidade){


    pos_y += velocidade;


    atualizar_desenho();
    glutPostRedisplay();

  }

	void atualizar_desenho(){

    /* Lado direito */
    glPushMatrix();

    glTranslatef(tipo*limite - pos_x, pos_y,0);
    desenhar();
    glPopMatrix();

    /* Lado esquerdo */
    glPushMatrix();

    glTranslatef(-(tipo*limite) + pos_x, pos_y,0);
    
    desenhar();
    glPopMatrix();

	}

  void resetar(InfoT t, float y){

    setDimensao(t.altura, t.largura);
    setPosicao(t.x, pos_y + y);
    tipo = t.tipo;

  }


	void desenhar(){

		int z_terreno = 0;

/*
    switch(cor){
      case 0:*/
		    glColor3ub(0,100,0);
      /*  break;

      case 1:
        glColor3ub(100,100,0);
        break;

      case 2:
        glColor3ub(0,100,100);
        break;

      case 3:
        glColor3ub(100,100,100);
        break;

      case 4:
        glColor3ub(100,0,0);
        break;

      case 5:
        glColor3ub(0,0,100);
        break;

      case 6:
        glColor3ub(100,0,100);
        break;

      case 7:
        glColor3ub(0,0,0);
        break;

		}*/

		glBegin(GL_POLYGON); 
		glVertex3f(-largura, (altura), z_terreno);
		glVertex3f(-largura,-(altura), z_terreno);
		glVertex3f( largura,-(altura), z_terreno);
		glVertex3f( largura, (altura), z_terreno);
		glEnd();

	}

	
};
