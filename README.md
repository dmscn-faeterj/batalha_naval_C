# Jogo Batalha Naval em C

### Trabalho para matéria de Algoritmos e Linguagem de Programação I 
##### _Prof.: Leonardo Vianna_



## Proposta do Trabalho

Inicialmente, cada um dos dois jogadores deve distribuir seus navios em um tabuleiro com 15 linhas e 15 colunas.

Concluída esta etapa, o jogo inicia-se com o primeiro participante informando as coordenadas (linha e coluna) de seu primeiro tiro. Se algum navio for atingido, o oponente deve dizer que tipo de embarcação foi alvejado e, então, o jogador inicial continua dando tiros enquanto estes atingirem alguma embarcação (ou seja, o oponente só jogará quando o tiro do primeiro atingir a água). 

O jogo termina assim que um dos jogadores atingir todos os navios (dando tiros em todas as suas partes) do oponente.

A frota de cada jogador é composta pelos seguintes navios:
* 1 porta-aviões: representado por 5 células
adjacentes no tabuleiro;
* 1 cruzador: 4 células adjacentes;
* 2 contra-torpedeiros: cada um ocupando 3
células adjacentes;
* 2 rebocadores: cada um ocupando 2
células adjacentes;
* 4 submarinos: uma única célula para cada.

Pede-se a implementação de um programa que simule o jogo Batalha Naval, observando os seguintes pontos: 

1. O programa deve manter duas matrizes 15x15, uma para cada jogador;
2. A execução deve ser iniciada com a leitura da distribuição de navios do primeiro jogador, seguida pela leitura do jogo do segundo participante. Em seguida, o jogo é iniciado com o primeiro jogador dando um tiro e termina quando um dos jogadores atingir todas as partes dos navios do seu oponente;
3. Utilizem matrizes de caracteres e preencham suas posições com um dos seguintes valores: A – água; P – porta- 0 aviões; C – cruzador; T – contra- torpedeiro; R – rebocador; S – submarino;
4. Cada navio pode ser disposto no tabuleiro horizontal ou verticalmente. Logo, para a inserção de cada navio (exceto o submarino que possui apenas uma posição), deve ser solicitada ao jogador a posição inicial (linha e coluna) e o sentido (vertical ou horizontal);
5. Atenção aos limites do tabuleiro (15x15). Por exemplo, se um jogador informar que deseja incluir um porta-aviões horizontalmente a partir da posição L4C13, não haverá espeço suficiente a partir da coluna 13 para incluir tal navio. Nesse caso, uma mensagem de erro deve ser gerada e novas coordenadas solicitadas ao usuário.

**OBS.:** O programa deve ser modularizado; ou seja, o problema deve ser decomposto em subproblemas e, para cada um destes, uma função deve ser implementada, recebendo e retornando os dados aplicáveis; 
