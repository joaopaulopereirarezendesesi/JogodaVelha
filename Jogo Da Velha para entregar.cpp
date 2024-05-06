#define SEPARADOR "---------"
  
/*A tabuleiro "tabuleiro" é utlizada 
para simular o tabuleiro do jogo da velha,
ou seja, cada posicao da tabuleiro [3][3] representa
uma posicao do tabuleiro.*/
int tabuleiro[3][3] = {
{ 0, 0, 0 },
{ 0, 0, 0 },
{ 0, 0, 0 }
};
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
void imprimirtabuleiro(){
  Serial.println("Tabuleiro:");
  Serial.println();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      Serial.print(tabuleiro[i][j]);
      if(j<2) {
        Serial.print(" | ");
      }
    }
    Serial.println();
    if(i<2){
      Serial.println(SEPARADOR);
    }
  }
  Serial.println();
  Serial.print("Indique a posicao da sua peca, Jogador ");
  Serial.println(JogadordaVez);
}
// zera a matriz
void limpartabuleiro(){
  for (int i = 0; i < 3; i++){
   for (int j = 0; j < 3; j++) {
      tabuleiro[i][j]= 0;
    }
  }
}

void setup(){
  Serial.begin(115200);

   limpartabuleiro();
  
   Serial.println();
   Serial.println("----------------");
   Serial.println("Jogador 1 comeca");
   Serial.println("----------------");
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
      
      if(jogada.length() > 3){
        Serial.println();
        Serial.print("Jogada invalida, tente jogar novamente jogador ");
        Serial.println(JogadordaVez);
        Serial.println();
        } else if (jogada.length() < 3) {
          Serial.println();
          Serial.print("Jogada invalida, tente jogar novamente jogador ");
          Serial.println(JogadordaVez);
          Serial.println();
          } else {
              if ((jogada.indexOf("-") || jogada.indexOf("+") || jogada.indexOf(",") || jogada.indexOf("!") ||
                   jogada.indexOf("@") || jogada.indexOf("#") || jogada.indexOf("$") || jogada.indexOf("%") ||
                   jogada.indexOf("¨") || jogada.indexOf("&") || jogada.indexOf("*") || jogada.indexOf("(") ||
                   jogada.indexOf(")") || jogada.indexOf("¹") || jogada.indexOf("²") || jogada.indexOf("³") ||
                   jogada.indexOf("£") || jogada.indexOf("¢") || jogada.indexOf("¬") || jogada.indexOf("§") ||
                   jogada.indexOf("=") || jogada.indexOf("[") || jogada.indexOf("]") || jogada.indexOf("{") ||
                   jogada.indexOf("}") || jogada.indexOf("ª") || jogada.indexOf("º") || jogada.indexOf(";") ||
                   jogada.indexOf(":") || jogada.indexOf(".") || jogada.indexOf("<") || jogada.indexOf(">") ||
                   jogada.indexOf("?") || jogada.indexOf("/") || jogada.indexOf("|") || jogada.indexOf("°") ||
                   jogada.indexOf("´") || jogada.indexOf("`") || jogada.indexOf("^") || jogada.indexOf("~") ||
                   jogada.indexOf("'")) >= 0){
              Serial.println();
              Serial.print("Jogada invalida, tente jogar novamente jogador ");
              Serial.println(JogadordaVez);
              Serial.println();
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
        if ((tabuleiro[0][0] == JogadordaVez && tabuleiro[0][1] == JogadordaVez && tabuleiro[0][2] == JogadordaVez) ||
            (tabuleiro[1][0] == JogadordaVez && tabuleiro[1][1] == JogadordaVez && tabuleiro[1][2] == JogadordaVez) ||
            (tabuleiro[2][0] == JogadordaVez && tabuleiro[2][1] == JogadordaVez && tabuleiro[2][2] == JogadordaVez)) {
          Havencedor = true;
          ganhadorouvelha = 1;
        } else if ((tabuleiro[0][0] == JogadordaVez && tabuleiro[1][0] == JogadordaVez && tabuleiro[2][0] == JogadordaVez) ||
                   (tabuleiro[0][1] == JogadordaVez && tabuleiro[1][1] == JogadordaVez && tabuleiro[2][1] == JogadordaVez) ||
                   (tabuleiro[0][2] == JogadordaVez && tabuleiro[1][2] == JogadordaVez && tabuleiro[2][2] == JogadordaVez)) {
          Havencedor = true;
          ganhadorouvelha = 1;
        } else if ((tabuleiro[0][0] == JogadordaVez && tabuleiro[1][1] == JogadordaVez && tabuleiro[2][2] == JogadordaVez) ||
                   (tabuleiro[0][2] == JogadordaVez && tabuleiro[1][1] == JogadordaVez && tabuleiro[2][0] == JogadordaVez)) {
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
        Serial.print("Voce colocou a peca numa posicao ja ocupada Jogador ");
        Serial.print(JogadordaVez);
        Serial.println(" ,Tente novamente.");
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
      Serial.print("Parabens, Jogador ");
      Serial.println(JogadordaVez);
      Serial.println();
      Serial.println("Novo jogo");
      Serial.println();
      Serial.println("----------------");
      Serial.println("Jogador 1 comeca");
      Serial.println("----------------");
      break;
    case 2:
      Serial.println("Velha!");
      Serial.println();
      Serial.println("Novo jogo");
      Serial.println();
      Serial.println("----------------");
      Serial.println("Jogador 1 comeca");
      Serial.println("----------------");
      break;
  }
}