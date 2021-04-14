#include<raylib.h>

#define MAX_FRAME_SPEED 15
#define MIN_FRAME_SPEED 1
#define SCREEN_WIDTH 800 //largura da tela
#define SCREEN_HEIGHT 300 //altura da tela

int main()
{
    //Variaveis
    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 8;

    int JogadorX = 400.0f; //posicao de spawn X do jogador
    int JogadorY = 200.0f; //posicao de spawn Y do jogador
    int moveX = 4; //velocidade de movimento do jogador no eixo x
    int moveY = 4; //velocidade de movimento do jogador no eixo x

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Castle os RaylibStein"); //inicializa a janela do jogo
    Vector2 position = {JogadorX, JogadorY}; //vetor posicao do jogador
    Texture2D Jogador = LoadTexture("Jogador.png"); //carrega o sprite do jogador

    Rectangle frameRec = {0.0f, 0.0f, (float)Jogador.width/11 , (float)Jogador.height/3};

    SetTargetFPS(60); //seta para que o jogo rode a 60 frames

    while(!WindowShouldClose())
    {
        framesCounter++; //contador para mudar o sprite do jogador

        if(IsKeyDown(KEY_RIGHT)) //caso a seta da direita seja pressionada
        {
            position.x += moveX; //incrementa posicao x do jogador
            if (framesCounter>=60/framesSpeed)
            {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 1) //faz o loop da animacao do jogador para a direita
                    currentFrame = 0;
                frameRec.x = (float)currentFrame*(float)Jogador.width/5;
            }
        }

        if(IsKeyDown(KEY_LEFT)) //caso a seta da esquerda seja pressionada
        {
            position.x -= moveX; //decrementa a posicao x do jogador
            if (framesCounter>=60/framesSpeed)
            {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 3) //faz o loop da animacao do jogador para a esquerda
                    currentFrame = 2;
                frameRec.x = (float)currentFrame*(float)Jogador.width/5;
            }
        }

        if(IsKeyDown(KEY_UP)) //caso a seta de cima seja pressionada
        {
            position.y -= moveY;
            if (framesCounter>=60/framesSpeed)
            {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 1) //faz o loop da animacao do jogador para cima
                    currentFrame = 0;
                frameRec.y = (float)currentFrame*(float)Jogador.height;
            }
        }

        if(IsKeyDown(KEY_DOWN)) //caso a seta de baixo seja pressionada
        {
            position.y += moveY;
            if (framesCounter>=60/framesSpeed)
            {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 1) //faz o loop da animacao do jogador para baixo
                    currentFrame = 0;
                frameRec.y = (float)currentFrame*(float)Jogador.height;
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE); //cor do fundo

        DrawTextureRec(Jogador, frameRec, position, WHITE); //desenha o jogador na tela

        EndDrawing();
    }

    UnloadTexture(Jogador); //da unload na textura do jogador

    CloseWindow();

    return 0;
}
