
#define SEPARADOR "---------"
#define SEPARADOR2 "------------------------------------------------------------------"
/*A tabuleiro "tabuleiro" é utlizada 
para simular o tabuleiro do jogo da velha,
ou seja, cada posicao da tabuleiro [3][3] representa
uma posicao do tabuleiro.*/
int tabuleiro[3][3] = {
  { 0, 0, 0 },
  { 0, 0, 0 },
  { 0, 0, 0 }
};
int contadordevelhas = 0;
int contadordeganhadas1 = 0;
int contadordeganhadas2 = 0;
int contadordepartidas = 1;
//vai participar do funcionamento do switch
int ganhadorouvelha;
//Vai decidir se o jogo deu velha ou não.
int velha = 0;
//vai armazenar os valor da linha que o jogador escolher
int linha;
//vai armazenar os valor da coluna que o jogador escolher
int coluna;
//Vai decidir se há algum vencedor.
bool Havencedor = false;
//Vai decidir a vez dos jogadores
int JogadordaVez = 1;
//Vai armazenar a jogada do jogador da vez.
String jogada;
/* Função para pegar os dois primeiros dígitos de uma string
professor tive que pesquisar a maior parte dela, mas deu certo!*/

String Validajogada(const String& entrada) {
  String resultado;

  // Variável para controlar quantos dígitos foram encontrados
  int digitosEncontrados = 0;
  // Iterar através da entrada da string
  for (int i = 0; i < entrada.length(); i++) {
    char c = entrada.charAt(i);
    // confere se o caractere atual é um dígito
    if (isdigit(c)) {
      // Incrementa o contador de dígitos encontrados
      digitosEncontrados++;
      // Vê se é o primeiro ou terceiro digito
      if (digitosEncontrados == 1 || digitosEncontrados == 3) {
        resultado += c;
      }
      // Vê se já tem os digitos que precisamos na programação
      if (digitosEncontrados == 3) {
        break;
      }
    }
  }
  /*glossario: Documentação ARDUINO:
charAt: Acessa um caractere em uma determinada posição na String.
length: Retorna o comprimento da String, em caracteres. (Note que isso não inclui caracteres null no final da String.)
*/
  return resultado;
}
//função que vai imprimir o tabuleiro
void imprimirtabuleiro() {
  Serial.println("Tabuleiro:");
  Serial.println();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      Serial.print(tabuleiro[i][j]);
      if (j < 2) {
        Serial.print(" | ");
      }
    }
    Serial.println();
    if (i < 2) {
      Serial.println(SEPARADOR);
    }
  }
  Serial.println();
  Serial.print("Indique a posicao da sua peca, Jogador ");
  Serial.println(JogadordaVez);
}
// zera a matriz
void limpartabuleiro() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tabuleiro[i][j] = 0;
    }
  }
}

void setup() {
  Serial.begin(115200);

  limpartabuleiro();

  Serial.println();
  Serial.println("----------------");
  Serial.println("Jogador 1 comeca");
  Serial.println("----------------");
  Serial.println();
  
  Serial.print("Partida: ");
  Serial.println(contadordepartidas);
  Serial.println();

  imprimirtabuleiro();
}

void loop() {
  limpartabuleiro();
  // começa a variavel em zero para ir incrementando ela
  velha = 0;

  JogadordaVez = 1;

  Havencedor = false;
  // o do...while vai ver se já tem que da velha ou não

  do {
    if (Serial.available() > 0) {
      jogada = Serial.readString();

      if (jogada.length() > 3) {
        
        Serial.println(SEPARADOR2);
        Serial.println();
        Serial.print("Jogada invalida, tente jogar novamente jogador ");
        Serial.println(JogadordaVez);
        Serial.println();
        Serial.println(SEPARADOR2);
      } else if (jogada.length() < 3) {
        
        Serial.println(SEPARADOR2);
        Serial.println();
        Serial.print("Jogada invalida, tente jogar novamente jogador ");
        Serial.println(JogadordaVez);
        Serial.println();
        Serial.println(SEPARADOR2);
      } else if (jogada.substring(1, 2)!= " ") {
        
         Serial.println(SEPARADOR2);
        Serial.println();
        Serial.print("Jogada invalida, tente jogar novamente jogador ");
        Serial.println(JogadordaVez);
        Serial.println();
        Serial.println(SEPARADOR2);
       } else {
        if((jogada.indexOf("-") != -1) || (jogada.indexOf("+") != -1) || (jogada.indexOf(",") != -1) || (jogada.indexOf("!") != -1) || 
           (jogada.indexOf("@") != -1) || (jogada.indexOf("#") != -1) || (jogada.indexOf("$") != -1) || (jogada.indexOf("%") != -1) || 
           (jogada.indexOf("&") != -1) || (jogada.indexOf("*") != -1) || (jogada.indexOf("(") != -1) || (jogada.indexOf("§") != -1) || 
           (jogada.indexOf(")") != -1) || (jogada.indexOf("¢") != -1) || (jogada.indexOf("}") != -1) || (jogada.indexOf(";") != -1) || 
           (jogada.indexOf("=") != -1) || (jogada.indexOf("[") != -1) || (jogada.indexOf("]") != -1) || (jogada.indexOf("{") != -1) || 
           (jogada.indexOf(":") != -1) || (jogada.indexOf(".") != -1) || (jogada.indexOf("<") != -1) || (jogada.indexOf(">") != -1) ||
           (jogada.indexOf("`") != -1) || (jogada.indexOf("^") != -1) || (jogada.indexOf("~") != -1) || (jogada.indexOf("'") != -1) ||
           (jogada.indexOf("a") != -1) || (jogada.indexOf("b") != -1) || (jogada.indexOf("c") != -1) || (jogada.indexOf("d") != -1) ||
           (jogada.indexOf("e") != -1) || (jogada.indexOf("f") != -1) || (jogada.indexOf("g") != -1) || (jogada.indexOf("h") != -1) ||
           (jogada.indexOf("i") != -1) || (jogada.indexOf("j") != -1) || (jogada.indexOf("k") != -1) || (jogada.indexOf("l") != -1) ||
           (jogada.indexOf("m") != -1) || (jogada.indexOf("n") != -1) || (jogada.indexOf("o") != -1) || (jogada.indexOf("p") != -1) ||
           (jogada.indexOf("q") != -1) || (jogada.indexOf("r") != -1) || (jogada.indexOf("s") != -1) || (jogada.indexOf("t") != -1) ||
           (jogada.indexOf("u") != -1) || (jogada.indexOf("v") != -1) || (jogada.indexOf("w") != -1) || (jogada.indexOf("x") != -1) ||
           (jogada.indexOf("y") != -1) || (jogada.indexOf("z") != -1) || (jogada.indexOf("3") != -1) || (jogada.indexOf("4") != -1) ||
           (jogada.indexOf("5") != -1) || (jogada.indexOf("6") != -1) || (jogada.indexOf("7") != -1) || (jogada.indexOf("8") != -1) ||
           (jogada.indexOf("9") != -1)) {
           Serial.println(SEPARADOR2);
           Serial.println();
           Serial.print("Jogada invalida, tente jogar novamente jogador ");
           Serial.println(JogadordaVez);
           Serial.println();
           Serial.println(SEPARADOR2);
        } else {
          //tranforma byte em string e string em inteiro
          linha = Validajogada(jogada.substring(0, 1)).toInt();
          coluna = Validajogada(jogada.substring(2, 3)).toInt();
          //imprime a jogada
          Serial.println();
          Serial.println(SEPARADOR);
          Serial.print("Linha: ");
          Serial.println(linha);
          Serial.print("Coluna: ");
          Serial.println(coluna);
          Serial.println(SEPARADOR);
          Serial.println();
          //ve se o lugar na matriz está vazio
          if (tabuleiro[linha][coluna] == 0) {
            //troca o numero do jogador na matriz
            tabuleiro[linha][coluna] = JogadordaVez;
            //confere as posições ganhadoras na matriz
            if (((tabuleiro[0][0] == JogadordaVez && tabuleiro[0][1] == JogadordaVez && tabuleiro[0][2] == JogadordaVez) || 
                 (tabuleiro[1][0] == JogadordaVez && tabuleiro[1][1] == JogadordaVez && tabuleiro[1][2] == JogadordaVez) || 
                 (tabuleiro[2][0] == JogadordaVez && tabuleiro[2][1] == JogadordaVez && tabuleiro[2][2] == JogadordaVez)) || 
                 ((tabuleiro[0][0] == JogadordaVez && tabuleiro[1][0] == JogadordaVez && tabuleiro[2][0] == JogadordaVez) || 
                 (tabuleiro[0][1] == JogadordaVez && tabuleiro[1][1] == JogadordaVez && tabuleiro[2][1] == JogadordaVez) || 
                 (tabuleiro[0][2] == JogadordaVez && tabuleiro[1][2] == JogadordaVez && tabuleiro[2][2] == JogadordaVez)) ||
                 ((tabuleiro[0][0] == JogadordaVez && tabuleiro[1][1] == JogadordaVez && tabuleiro[2][2] == JogadordaVez) ||
                 (tabuleiro[0][2] == JogadordaVez && tabuleiro[1][1] == JogadordaVez && tabuleiro[2][0] == JogadordaVez))) {
              Havencedor = true;
              ganhadorouvelha = 1;
              
            } else if (JogadordaVez == 1) {
              JogadordaVez = 2;
            } else {
              JogadordaVez = 1;
            }
            //incrementa a velha
            velha++;
          } else {
            Serial.println(SEPARADOR2);
            Serial.println();
            Serial.print("Voce colocou a peca numa posicao ja ocupada Jogador ");
            Serial.print(JogadordaVez);
            Serial.println(" ,Tente novamente.");
            Serial.println();
            Serial.println(SEPARADOR2);
            Serial.println();
          }

          imprimirtabuleiro();
     }
    }
   }
  } while (!Havencedor && velha < 9);
  // confere se tem velha ou não
  if (!Havencedor) {
    ganhadorouvelha = 2;
  }
  //solta as mensagens de velha e ganhador
  switch (ganhadorouvelha) {
    case 1:
      contadordepartidas++;
      if (JogadordaVez == 1){
        contadordeganhadas1++;
      } else {
        contadordeganhadas2++;
      }
      Serial.print("Parabens, Jogador ");
      Serial.println(JogadordaVez);
      Serial.println();
      Serial.println("Novo jogo");
      Serial.println();
      Serial.print("Velhas: ");
      Serial.println(contadordevelhas);
      Serial.println();
      Serial.print("Partidas ganhas do jogador 1: ");
      Serial.println(contadordeganhadas1);
      Serial.println();
      Serial.print("Partidas ganhas do jogador 2: ");
      Serial.println(contadordeganhadas2);
      Serial.println();
      Serial.print("Partida: ");
      Serial.println(contadordepartidas);
      Serial.println();
      Serial.println("----------------");
      Serial.println("Jogador 1 comeca");
      Serial.println("----------------");
      Serial.println();
      limpartabuleiro();
      JogadordaVez = 1;
      imprimirtabuleiro();
      break;
    case 2:
      contadordepartidas++;
      contadordevelhas++;
      Serial.println("Velha!");
      Serial.println();
      Serial.println("Novo jogo");
      Serial.println();
      Serial.print("Velhas: ");
      Serial.println(contadordevelhas);
      Serial.println();
      Serial.print("Partidas ganhas do jogador 1: ");
      Serial.println(contadordeganhadas1);
      Serial.println();
      Serial.print("Partidas ganhas do jogador 2: ");
      Serial.println(contadordeganhadas2);
      Serial.println();
      Serial.println("----------------");
      Serial.println("Jogador 1 comeca");
      Serial.println("----------------");
      Serial.println();
      limpartabuleiro();
      JogadordaVez = 1;
      imprimirtabuleiro();
      break;
  }
}