/*
=====================================
  A BUSCA DO AMULETO SAGRADO
  RPG em Linguagem C
  
  Sistema de Pontuacao:
  - Cada rota tem uma virtude
  - Escolhas certas dao pontos
  - No final, ranking baseado nos pontos
=====================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========== VARIAVEIS GLOBAIS ==========

// Pontuacao por virtude
int pontosCompaixao = 0;    // Floresta
int pontosAstúcia = 0;      // Pantano (escrevi sem acento pra nao dar erro)
int pontosSabedoria = 0;    // Caverna

// Controle de itens importantes (0 = nao tem, 1 = tem)
int temMithril = 0;
int temEscamaDragao = 0;
int dragaoFilhoteSalvo = 0;
int dragaoFilhoteMorto = 0;

// Controle da rota escolhida
char rotaEscolhida[20];

// ========== FUNCOES AUXILIARES ==========

// Limpa a tela (funciona em Windows e Linux)
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Pausa o jogo ate o jogador apertar ENTER
void pausar() {
    printf("\n\nPressione ENTER para continuar...");
    while(getchar() != '\n');  // Limpa o buffer
    getchar();                 // Espera o ENTER
}

// Mostra os pontos atuais (para debug, pode comentar depois)
void mostrarPontos() {
    printf("\n[DEBUG - Pontos Atuais]");
    printf("\nCompaixao: %d | Astucia: %d | Sabedoria: %d\n", 
           pontosCompaixao, pontosAstúcia, pontosSabedoria);
}

// ========== DECLARACAO DAS FUNCOES ==========
// (Declarar antes para o compilador saber que existem)

void menu();
void introducao();
void escolhaRota();

// Floresta
void rotaFloresta();
void eventoGoblinFada();
void eventoElfaGlacify();
void eventoNinfaFloresta();

// Pantano
void rotaPantano();
void eventoCelaBruxa();
void eventoLagartoFulzard();
void eventoCobraPantano();

// Caverna
void rotaCaverna();
void eventoDragaoFilhote();
void eventoAnaoEgnar();
void eventoDrakeAnciao();

// Castelo
void castelo();
void eventoGargulaCharadas();
void eventoArmadurasDancarinas();
void eventoMimicoDiario();
void confrontoFinalAnimata();

// Finais
void calcularRanking();

// ========== FUNCAO PRINCIPAL ==========

int main() {
    menu();
    return 0;
}

// ========== MENU INICIAL ==========

void menu() {
    int escolha;
    
    limparTela();
    printf("=====================================\n");
    printf("  A BUSCA DO AMULETO SAGRADO\n");
    printf("=====================================\n\n");
    
    printf("1 - Iniciar Jogo\n");
    printf("2 - Sobre o Jogo\n");
    printf("3 - Sair\n\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    
    if (escolha == 1) {
        introducao();
    } else if (escolha == 2) {
        limparTela();
        printf("\n=== SOBRE O JOGO ===\n\n");
        printf("Um RPG de escolhas onde suas decisoes importam.\n");
        printf("Tres caminhos, tres virtudes, multiplos finais.\n");
        printf("Descubra a verdade sobre os herois do passado.\n\n");
        pausar();
        menu();
    } else {
        printf("\nObrigado por jogar!\n");
        exit(0);
    }
}

// ========== INTRODUCAO ==========

void introducao() {
    limparTela();
    printf("\n=== INTRODUCAO ===\n\n");
    
    printf("Ao acordar, voce sai da sua casa e avista um senhor idoso.\n");
    printf("Ele se chama Kenshi, e parece preocupado.\n\n");
    pausar();
    
    printf("Kenshi: \"Preciso da sua ajuda, jovem aventureiro.\"\n");
    printf("\"Ha um tempo atras, havia uma maga renomada chamada Animata.\"\n");
    printf("\"Ela fazia parte de um grupo de herois lendarios.\"\n\n");
    pausar();
    
    printf("\"Eles protegiam nosso reino... ate que algo terrivel aconteceu.\"\n");
    printf("\"O lider deles, Damian, morreu em batalha.\"\n");
    printf("\"Animata enlouqueceu de dor e roubou o amuleto sagrado.\"\n");
    printf("\"Agora ela se trancou no castelo.\"\n\n");
    pausar();
    
    printf("\"Preciso que voce recupere o amuleto e... talvez... salve ela.\"\n\n");
    printf("Kenshi te entrega uma mochila com suprimentos e uma espada.\n");
    printf("Ele limpa uma lagrima: \"Se cuide... Confio em voce.\"\n\n");
    pausar();
    
    escolhaRota();
}

// ========== ESCOLHA DA ROTA ==========

void escolhaRota() {
    int escolha;
    
    limparTela();
    printf("\n=== ESCOLHA SEU CAMINHO ===\n\n");
    
    printf("Kenshi: \"Ha tres caminhos para o castelo.\"\n\n");
    
    printf("1 - FLORESTA\n");
    printf("   'O caminho da vida e da harmonia.'\n");
    printf("   'Aqui, a COMPAIXAO e testada.'\n\n");
    
    printf("2 - PANTANO\n");
    printf("   'O caminho dos desafios e armadilhas.'\n");
    printf("   'Aqui, a ASTUCIA e testada.'\n\n");
    
    printf("3 - CAVERNA\n");
    printf("   'O caminho do conhecimento e verdade.'\n");
    printf("   'Aqui, a SABEDORIA e testada.'\n\n");
    
    printf("Sua escolha: ");
    scanf("%d", &escolha);
    
    // Salva a rota escolhida
    if (escolha == 1) {
        strcpy(rotaEscolhida, "Floresta");
        rotaFloresta();
    } else if (escolha == 2) {
        strcpy(rotaEscolhida, "Pantano");
        rotaPantano();
    } else if (escolha == 3) {
        strcpy(rotaEscolhida, "Caverna");
        rotaCaverna();
    } else {
        printf("\nEscolha invalida! Indo pela Floresta...\n");
        pausar();
        strcpy(rotaEscolhida, "Floresta");
        rotaFloresta();
    }
}

// ========================================
//          ROTA 1: FLORESTA
// ========================================

void rotaFloresta() {
    limparTela();
    printf("\n=== FLORESTA ===\n\n");
    printf("Voce entra na floresta densa.\n");
    printf("A luz do sol atravessa as folhas criando um ambiente magico.\n");
    printf("Voce sente paz... mas tambem vigilancia.\n\n");
    pausar();
    
    // Tres eventos da floresta
    eventoGoblinFada();
    eventoElfaGlacify();
    eventoNinfaFloresta();
    
    // Apos completar a floresta, vai para o castelo
    castelo();
}

// ---------- EVENTO 1: GOBLIN E FADA ----------

void eventoGoblinFada() {
    int escolha1, escolha2;
    
    limparTela();
    printf("\n=== EVENTO 1: ENCONTRO NA FLORESTA ===\n\n");
    
    printf("Voce avista um brilho estranho no arbusto.\n");
    printf("Ao se aproximar, ouve grunidos.\n");
    printf("Voce se esconde atras de uma arvore e observa:\n\n");
    printf("Um GOBLIN esta tentando comer uma FADA!\n");
    printf("A fada grita pedindo ajuda!\n\n");
    pausar();
    
    printf("O que voce faz?\n");
    printf("1 - Atacar o goblin (violencia direta)\n");
    printf("2 - Procurar algo ao redor (preparacao)\n");
    printf("3 - Interagir com o goblin (comunicacao)\n");
    printf("Escolha: ");
    scanf("%d", &escolha1);
    
    // ===== ESCOLHA 1: ATACAR =====
    if (escolha1 == 1) {
        limparTela();
        printf("\nVoce pega sua espada e avanca!\n");
        printf("O goblin se assusta e solta a fada!\n");
        printf("Voce o persegue e...\n\n");
        
        printf("O que voce faz?\n");
        printf("1 - Deixar ele fugir (misericordia)\n");
        printf("2 - Correr atras e atacar (justica)\n");
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            printf("\nVoce deixa o goblin fugir assustado.\n");
            printf("A fada agradece: 'Obrigada por nao matar ele!'\n");
            printf("Ela danca ao seu redor e voce se sente revigorado.\n");
            pontosCompaixao += 2;  // +2 pontos por misericordia
        } else {
            printf("\nVoce persegue e derrota o goblin.\n");
            printf("A fada agradece, mas parece triste: 'Ele era so um bebe...'\n");
            pontosCompaixao += 0;  // 0 pontos - violencia desnecessaria
        }
        
    // ===== ESCOLHA 2: PROCURAR AO REDOR =====
    } else if (escolha1 == 2) {
        limparTela();
        printf("\nVoce procura ao redor cuidadosamente...\n");
        printf("Voce encontra:\n\n");
        
        printf("1 - Pedras no chao\n");
        printf("2 - Cristal brilhante\n");
        printf("3 - Frutas vermelhas\n");
        printf("O que voce pega? ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            // PEDRAS
            printf("\nVoce pega uma pedra e arremessa no goblin!\n");
            printf("Acerta! Ele solta a fada e foge.\n");
            printf("A fada agradece e te abencoa.\n");
            pontosCompaixao += 1;  // +1 ponto - resolveu sem matar
            
        } else if (escolha2 == 2) {
            // CRISTAL
            printf("\nVoce pega o cristal brilhante e o mostra!\n");
            printf("O goblin esquece a fada e corre atras do cristal!\n");
            printf("Ele pega o cristal e sai pulando feliz.\n");
            printf("A fada ri: 'Goblins adoram coisas brilhantes!'\n");
            printf("Ela danca em volta de voce e te abencoa.\n");
            pontosCompaixao += 3;  // +3 pontos - solucao criativa e pacifica
            
        } else {
            // FRUTAS
            printf("\nVoce pega as frutas e joga para o goblin!\n");
            printf("Ele pega as frutas e comeca a comer feliz.\n");
            printf("Ele solta a fada e te agradece!\n");
            printf("A fada: 'Ele so estava com fome! Obrigada por entender!'\n");
            printf("Ela te abencoa com po magico.\n");
            pontosCompaixao += 3;  // +3 pontos - empatia maxima
        }
        
    // ===== ESCOLHA 3: INTERAGIR =====
    } else if (escolha1 == 3) {
        limparTela();
        printf("\nVoce se aproxima com as maos levantadas.\n");
        printf("O goblin te ve e fica na defensiva, segurando a fada.\n\n");
        
        printf("O que voce faz?\n");
        printf("1 - Gritar com ele (intimidacao)\n");
        printf("2 - Fazer mimica (comunicacao)\n");
        printf("3 - Dar comida da mochila (empatia)\n");
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            // GRITAR
            printf("\nVoce grita alto!\n");
            printf("O goblin se assusta muito e comeca a correr!\n");
            printf("Ele deixa a fada cair no caminho.\n");
            printf("A fada agradece, um pouco abalada pelo susto.\n");
            pontosCompaixao += 1;  // +1 ponto - funcionou mas foi agressivo
            
        } else if (escolha2 == 2) {
            // MIMICA
            printf("\nVoce comeca a fazer mimica!\n");
            printf("Voce aponta para a fada, depois para o ceu.\n");
            printf("Voce faz cara de triste, depois de feliz.\n");
            printf("O goblin te olha confuso...\n");
            printf("De repente ele entende e ri muito!\n");
            printf("Ele solta a fada, ainda rindo, e vai embora feliz.\n");
            printf("A fada: 'Voce e muito engracado! E gentil!'\n");
            pontosCompaixao += 3;  // +3 pontos - criatividade e empatia
            
        } else {
            // DAR COMIDA
            printf("\nVoce pega carne seca da mochila e oferece.\n");
            printf("O goblin cheira... e seus olhos brilham!\n");
            printf("Ele solta a fada e pega a comida.\n");
            printf("Ele come feliz e te segue um pouco, agradecido.\n");
            printf("A fada: 'Ele so tinha fome! Voce tem um bom coracao!'\n");
            pontosCompaixao += 4;  // +4 pontos - maxima empatia (sacrificou comida)
        }
    }
    
    pausar();
    printf("\n[COMPAIXAO: +%d pontos neste evento]\n", pontosCompaixao);
    pausar();
}

// ---------- EVENTO 2: ELFA GLACIFY ----------

void eventoElfaGlacify() {
    int escolha1, escolha2;
    
    limparTela();
    printf("\n=== EVENTO 2: RIO E CACHOEIRA ===\n\n");
    
    printf("Voce continua pela floresta ate encontrar um rio cristalino.\n");
    printf("Seguindo o rio, voce chega a uma bela cachoeira.\n\n");
    printf("Do lado direito, uma ELFA NEGRA medita em posicao de lotus.\n");
    printf("Do lado esquerdo, uma ESPADA LONGA esta cravada no chao.\n");
    printf("A cachoeira cai forte no centro.\n\n");
    pausar();
    
    printf("O que voce faz?\n");
    printf("1 - Pegar a espada (acao impulsiva)\n");
    printf("2 - Conversar com a elfa (respeito)\n");
    printf("3 - Entrar na cachoeira (purificacao)\n");
    printf("Escolha: ");
    scanf("%d", &escolha1);
    
    // ===== ESCOLHA 1: PEGAR ESPADA =====
    if (escolha1 == 1) {
        limparTela();
        printf("\nVoce se aproxima da espada.\n");
        printf("E linda, antiga, coberta de vinhas.\n");
        printf("Voce puxa... e ela sai facilmente!\n");
        printf("Um brilho azul emana dela!\n");
        printf("Voce se sente como um heroi escolhido!\n\n");
        printf("De repente... tudo ao seu redor CONGELA!\n");
        printf("Voce esta preso em gelo!\n\n");
        pausar();
        
        printf("A elfa abre os olhos e se aproxima.\n");
        printf("Ela pega a espada de suas maos congeladas.\n");
        printf("Com um gesto, o gelo derrete.\n\n");
        printf("Elfa: 'Por que pegou sem pedir?'\n\n");
        
        printf("O que voce responde?\n");
        printf("1 - Pedir desculpas humildemente\n");
        printf("2 - Se justificar\n");
        printf("3 - Ficar em silencio\n");
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            // DESCULPAS
            printf("\nVoce: 'Me desculpe, agi por impulso. Foi errado.'\n");
            printf("Elfa sorri: 'Poucos admitem erros. Isso e compaixao por si mesmo.'\n");
            printf("'Aceitar falhas e o primeiro passo para crescer.'\n");
            pontosCompaixao += 2;  // +2 por humildade
            
        } else if (escolha2 == 2) {
            // JUSTIFICAR
            printf("\nVoce: 'Pensei que era uma espada perdida...'\n");
            printf("Elfa balanca a cabeca: 'Justificar erros nao os apaga.'\n");
            printf("'Mas ao menos voce tenta entender. Isso e algo.'\n");
            pontosCompaixao += 1;  // +1 por tentar
            
        } else {
            // SILENCIO
            printf("\nVoce fica em silencio, refletindo sobre seu erro.\n");
            printf("Elfa: 'O silencio tambem e resposta.'\n");
            printf("'Voce reflete. Isso e sabio.'\n");
            pontosCompaixao += 2;  // +2 por reflexao
        }
        
        printf("\nElfa: 'Meu nome e Glacify. Ja fui guerreira.'\n");
        printf("'Conheci um paladino chamado Damian...'\n");
        printf("'Ele me ensinou que errar nao e o fim.'\n");
        printf("'Espero que sua jornada termine melhor que a dele.'\n");
        
    // ===== ESCOLHA 2: CONVERSAR =====
    } else if (escolha1 == 2) {
        limparTela();
        printf("\nVoce se aproxima respeitosamente da elfa.\n");
        printf("Ela abre os olhos lentamente.\n");
        printf("O vento balanca seus cabelos prateados.\n");
        printf("Ela te cumprimenta com um aceno.\n\n");
        printf("Elfa: 'Ola, viajante. O que te traz aqui?'\n");
        printf("Voce conta sobre sua missao.\n\n");
        pausar();
        
        printf("Ela suspira: 'Animata... conheci ela.'\n");
        printf("'Eramos parte do mesmo grupo.'\n");
        printf("'Eu sou Glacify.'\n\n");
        
        printf("O que voce pergunta?\n");
        printf("1 - Treinar com ela\n");
        printf("2 - Perguntar sobre Damian\n");
        printf("3 - Perguntar sobre a espada\n");
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            // TREINAR
            printf("\nGlacify sorri: 'Faz tempo que nao luto!'\n");
            printf("Voces treinam a tarde toda.\n");
            printf("Ela e incrivelmente rapida e precisa.\n");
            printf("Voce aprende muito com ela.\n");
            printf("Glacify: 'Obrigada. Voce me lembrou porque eu lutava.'\n");
            printf("'Para proteger, nao para destruir.'\n");
            pontosCompaixao += 3;  // +3 por conexao e aprendizado
            
        } else if (escolha2 == 2) {
            // DAMIAN
            printf("\nGlacify: 'Damian... ele era nosso lider.'\n");
            printf("'Sempre sabia o que dizer.'\n");
            printf("'Ele me ensinou a ter confianca em mim mesma.'\n");
            printf("'Eu tinha medo de errar... de machucar alguem.'\n");
            printf("'Ele disse: Voce ja falha ao nao tentar.'\n");
            printf("'Levei isso comigo.'\n");
            pontosCompaixao += 2;  // +2 por empatia e curiosidade
            
        } else {
            // ESPADA
            printf("\nGlacify olha para a espada: 'Era de Damian.'\n");
            printf("'Deixei aqui como lembranca... e como teste.'\n");
            printf("'Quem pega sem perguntar, nao e digno.'\n");
            printf("'Voce perguntou. Isso diz muito.'\n");
            pontosCompaixao += 2;  // +2 por respeito
        }
        
        printf("\nGlacify: 'Va com cuidado. Animata sofre... mas e perigosa.'\n");
        
    // ===== ESCOLHA 3: CACHOEIRA =====
    } else {
        limparTela();
        printf("\nVoce decide entrar na cachoeira.\n");
        printf("Tira sua armadura e espada.\n");
        printf("A agua e gelada, mas revigorante.\n");
        printf("Voce se sente limpo... internamente.\n\n");
        pausar();
        
        printf("Ao sair, a elfa esta te observando.\n");
        printf("Ela sorri: 'Poucos escolhem a purificacao.'\n");
        printf("'A maioria escolhe o poder.' (aponta para a espada)\n");
        printf("'Meu nome e Glacify.'\n\n");
        
        printf("O que voce faz?\n");
        printf("1 - Agradecer a cachoeira (gratidao)\n");
        printf("2 - Perguntar se ela cuida do lugar\n");
        printf("3 - Meditar com ela\n");
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            printf("\nVoce agradece em voz alta a cachoeira.\n");
            printf("Glacify: 'Gratidao e uma virtude rara.'\n");
            printf("'Que a floresta te proteja.'\n");
            pontosCompaixao += 2;
            
        } else if (escolha2 == 2) {
            printf("\nGlacify: 'Sim, cuido. E minha penitencia.'\n");
            printf("'Falhei em proteger alguem importante.'\n");
            printf("'Agora protejo este lugar sagrado.'\n");
            pontosCompaixao += 2;
            
        } else {
            printf("\nVoce se senta ao lado dela e medita.\n");
            printf("O silencio e confortavel.\n");
            printf("Glacify: 'Presenca e um presente raro.'\n");
            printf("'Obrigada.'\n");
            pontosCompaixao += 3;  // +3 por presenca plena
        }
    }
    
    pausar();
    printf("\n[COMPAIXAO TOTAL: %d pontos]\n", pontosCompaixao);
    pausar();
}

// ---------- EVENTO 3: NINFA DA FLORESTA ----------

void eventoNinfaFloresta() {
    limparTela();
    printf("\n=== EVENTO 3: A NINFA DA FLORESTA ===\n\n");
    
    printf("Ao continuar seu caminho, uma nevoa magica surge.\n");
    printf("Uma figura eterea aparece entre as arvores.\n");
    printf("E uma NINFA - a guardia da floresta.\n\n");
    pausar();
    
    printf("Ninfa: 'Voce atravessou minha floresta...'\n");
    printf("'Vi como tratou os pequenos e os antigos.'\n");
    printf("'Agora... julgo seu coracao.'\n\n");
    pausar();
    
    // JULGAMENTO BASEADO NOS PONTOS
    printf("\n--- JULGAMENTO DA FLORESTA ---\n\n");
    
    if (pontosCompaixao >= 8) {
        // ALTA COMPAIXAO
        printf("Ninfa: 'Seu coracao e puro.'\n");
        printf("'Voce protegeu sem destruir.'\n");
        printf("'Compreendeu sem julgar.'\n");
        printf("'A floresta te ABENCOA!'\n\n");
        printf("Uma luz verde te envolve.\n");
        printf("Voce se sente completamente curado e protegido.\n");
        printf("[BENCAO: Protecao da Natureza - sera util no castelo]\n");
        pontosCompaixao += 5;  // Bonus de 5 pontos
        
    } else if (pontosCompaixao >= 4) {
        // MEDIA COMPAIXAO
        printf("Ninfa: 'Voce fez o necessario.'\n");
        printf("'Nem heroi, nem vilao.'\n");
        printf("'A floresta te ACEITA.'\n\n");
        printf("Uma brisa suave te envolve.\n");
        printf("Voce se sente parcialmente curado.\n");
        pontosCompaixao += 2;  // Bonus de 2 pontos
        
    } else {
        // BAIXA COMPAIXAO
        printf("Ninfa: 'Voce deixou dor por onde passou.'\n");
        printf("'Escolheu forca sobre gentileza.'\n");
        printf("'A floresta... LEMBRA.'\n\n");
        printf("Espinhos brotam ao seu redor.\n");
        printf("Voce sente uma marca de desaprovacao.\n");
        printf("[MALDICAO: A natureza nao te ajudara]\n");
        pontosCompaixao += 0;  // Sem bonus
    }
    
    pausar();
    printf("\n--- FLORESTA COMPLETA ---");
    printf("\nPONTOS DE COMPAIXAO FINAIS: %d\n", pontosCompaixao);
    pausar();
}

// ========================================
//          ROTA 2: PANTANO
// ========================================

void rotaPantano() {
    limparTela();
    printf("\n=== PANTANO ===\n\n");
    printf("Voce entra no pantano lodoso.\n");
    printf("O cheiro e forte, o terreno e traicoeiro.\n");
    printf("Voce precisa de astucia para sobreviver aqui.\n\n");
    pausar();
    
    // Tres eventos do pantano
    eventoCelaBruxa();
    eventoLagartoFulzard();
    eventoCobraPantano();
    
    // Apos completar o pantano, vai para o castelo
    castelo();
}

// ---------- EVENTO 1: CELA E BRUXA ----------

void eventoCelaBruxa() {
    int escolha1, escolha2;
    
    limparTela();
    printf("\n=== EVENTO 1: RUINAS AMALDICOADAS ===\n\n");
    
    printf("Voce encontra uma construcao antiga em ruinas.\n");
    printf("Parece abandonada, mas algo parece errado...\n");
    printf("Ao entrar, voce ve runas brilhantes no chao.\n\n");
    pausar();
    
    printf("O que voce faz?\n");
    printf("1 - Investigar as runas (cuidado)\n");
    printf("2 - Andar pelas paredes (cautela)\n");
    printf("3 - Andar direto pelo centro (confianca)\n");
    printf("Escolha: ");
    scanf("%d", &escolha1);
    
    // ===== ESCOLHA 1: INVESTIGAR =====
    if (escolha1 == 1) {
        limparTela();
        printf("\nVoce se abaixa e examina as runas cuidadosamente.\n");
        printf("Sao runas de aprisionamento!\n");
        printf("Voce percebe que e uma ARMADILHA!\n\n");
        
        printf("O que voce faz?\n");
        printf("1 - Contornar as runas (astucia)\n");
        printf("2 - Tentar desarmar (arriscado)\n");
        printf("3 - Pisar sabendo o risco (confianca)\n");
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            // CONTORNAR
            printf("\nVoce contorna as runas com cuidado!\n");
            printf("Consegue passar sem ativar a armadilha!\n");
            pontosAstúcia += 3;  // +3 por astucia maxima
            printf("Mais a frente, voce encontra uma bruxa ferida.\n");
            
        } else if (escolha2 == 2) {
            // DESARMAR
            printf("\nVoce tenta desarmar a magia...\n");
            printf("As runas piscam... e SE ATIVAM!\n");
            printf("Voce e preso em uma CELA MAGICA!\n");
            pontosAstúcia += 1;  // +1 por tentar
            printf("Depois de um tempo, uma bruxa aparece e te liberta.\n");
            
        } else {
            // PISAR
            printf("\nVoce pisa nas runas sabendo o risco.\n");
            printf("A armadilha SE ATIVA!\n");
            printf("Voce e preso em uma CELA MAGICA!\n");
            pontosAstúcia += 0;  // 0 pontos - imprudente
            printf("Depois de um tempo, uma bruxa aparece e te liberta.\n");
        }
        
    // ===== ESCOLHA 2: PAREDES =====
    } else if (escolha1 == 2) {
        limparTela();
        printf("\nVoce decide andar pelas paredes, evitando o centro.\n");
        printf("Uma pedra solta cede sob seu pe!\n");
        printf("OUTRA ARMADILHA!\n\n");
        
        printf("O que voce faz?\n");
        printf("1 - Rolar para frente (agilidade)\n");
        printf("2 - Se proteger com o braco (defesa)\n");
        printf("3 - Correr (panico)\n");
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            printf("\nVoce rola rapido para frente!\n");
            printf("Evita a maioria da armadilha!\n");
            pontosAstúcia += 2;  // +2 por reflexo
            printf("Mas tropeça em outra armadilha... e e preso!\n");
            printf("Uma bruxa aparece e te liberta.\n");
            
        } else if (escolha2 == 2) {
            printf("\nVoce levanta o braco para se proteger!\n");
            printf("A armadilha te acerta, mas nao e fatal!\n");
            pontosAstúcia += 1;  // +1 por defesa
            printf("Voce cai em uma rede e fica preso.\n");
            printf("Uma bruxa aparece e te liberta.\n");
            
        } else {
            printf("\nVoce corre em panico!\n");
            printf("Pisa em TODAS as armadilhas!\n");
            pontosAstúcia += 0;  // 0 pontos - panico
            printf("Voce e preso em uma cela magica.\n");
            printf("Uma bruxa aparece e te liberta.\n");
        }
        
    // ===== ESCOLHA 3: DIRETO =====
    } else {
        limparTela();
        printf("\nVoce anda direto pelo centro, confiante.\n");
        printf("ERRO! As runas se ativam!\n");
        printf("Voce e preso em uma CELA MAGICA!\n");
        pontosAstúcia += 0;  // 0 pontos - sem cautela
        printf("\nDepois de um tempo, uma bruxa aparece e te liberta.\n");
    }
    
    pausar();
    
    // CONTINUACAO - BRUXA
    limparTela();
    printf("\n--- ENCONTRO COM A BRUXA ---\n\n");
    printf("Bruxa: 'Desculpe pelas armadilhas... protegem minha casa.'\n");
    printf("'Voce parece saudavel. Preciso de ajuda.'\n");
    printf("'Um SLIME roubou um ingrediente raro meu.'\n");
    printf("'Pode recupera-lo para mim?'\n\n");
    pausar();
    
    printf("Voces caminham juntos ate encontrar o SLIME.\n");
    printf("Ele esta saltitando, com algo brilhando dentro dele.\n\n");
    
    printf("O que voce faz?\n");
    printf("1 - Atacar o slime (forca)\n");
    printf("2 - Modo furtivo (agilidade)\n");
    printf("3 - Interagir com o slime (criatividade)\n");
    printf("Escolha: ");
    scanf("%d", &escolha1);
    
    if (escolha1 == 1) {
        // ATACAR
        printf("\nVoce investe com a espada!\n");
        printf("Perfura o slime! Ele se desmancha!\n");
        printf("A pedra voa no ar... voce pega!\n");
        printf("Bruxa: 'Eficiente... mas um pouco brutal.'\n");
        pontosAstúcia += 1;  // +1 funcional mas bruto
        
    } else if (escolha1 == 2) {
        // FURTIVO
        printf("\nVoce se esconde no mato...\n");
        printf("Espera o momento certo...\n");
        printf("PULA em cima do slime!\n");
        printf("Ele se assusta e cospe a pedra!\n");
        printf("Voce pega no ar!\n");
        printf("Bruxa: 'Impressionante! Rapido e esperto!'\n");
        pontosAstúcia += 3;  // +3 astucia perfeita
        
    } else {
        // INTERAGIR
        printf("\nVoce se aproxima devagar do slime...\n");
        printf("Ele para e te olha curioso.\n");
        printf("Voce... comeca a fazer COCEGA nele?!\n");
        printf("O slime TREME e cospe a pedra!\n");
        printf("Ele comeca a te seguir, parecendo feliz!\n");
        printf("Bruxa: 'Incrivel! Nunca vi ninguem fazer amizade com um slime!'\n");
        pontosAstúcia += 4;  // +4 criatividade maxima
    }
    
    pausar();
    
    printf("\n--- DE VOLTA NA CASA DA BRUXA ---\n\n");
    printf("Bruxa joga a pedra no caldeirao.\n");
    printf("Ela prepara uma pocao e toma um pouco.\n");
    printf("Sua postura melhora, suas feridas curam!\n\n");
    printf("Ela enche dois frascos e te da um.\n");
    printf("Bruxa: 'Obrigada, aventureiro. Tome, vai precisar.'\n");
    printf("Voce bebe a pocao e se sente revigorado!\n\n");
    
    pausar();
    printf("\n[ASTUCIA TOTAL: %d pontos]\n", pontosAstúcia);
    pausar();
}

// ---------- EVENTO 2: LAGARTO FULZARD ----------

void eventoLagartoFulzard() {
    int escolha1, escolha2;
    
    limparTela();
    printf("\n=== EVENTO 2: O GUERREIRO LAGARTO ===\n\n");
    
    printf("Continuando pelo pantano, voce ve uma figura estranha.\n");
    printf("Um LAGARTO HUMANOIDE esta sentado em uma pedra.\n");
    printf("Ele olha para o horizonte, parecendo distraido.\n\n");
    pausar();
    
    printf("O que voce faz?\n");
    printf("1 - Cumprimentar alto (chamar atencao)\n");
    printf("2 - Aproximar em silencio (respeito)\n");
    printf("3 - Observar a distancia (cautela)\n");
    printf("Escolha: ");
    scanf("%d", &escolha1);
    
    // ===== ESCOLHA 1: CUMPRIMENTAR ALTO =====
    if (escolha1 == 1) {
        limparTela();
        printf("\nVoce: 'Ola! Bom dia!'\n");
        printf("O lagarto se assusta e cai da pedra!\n");
        printf("Lagarto: 'AH! Voce me assustou!'\n");
        printf("Ele se levanta rindo: 'Eu me distraio facil...'\n\n");
        pausar();
        
        printf("Lagarto: 'Meu nome e Fulzard. Quem e voce?'\n");
        printf("Voce conta sobre sua missao.\n");
        printf("Fulzard: 'Animata? Conheci ela...'\n");
        printf("'Quero te testar. Topas?'\n\n");
        
        printf("Teste: Acertar 3 alvos sem se distrair.\n");
        printf("O que voce faz?\n");
        printf("1 - Aceitar focado (determinacao)\n");
        printf("2 - Aceitar mas conversar durante (casual)\n");
        printf("3 - Recusar educadamente\n");
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            printf("\nVoce foca completamente na tarefa.\n");
            printf("Fulzard faz barulhos para distrair, mas voce ignora.\n");
            printf("ACERTA os 3 alvos!\n");
            printf("Fulzard: 'Impressionante! Voce tem FOCO.'\n");
            printf("'Damian me ensinou isso... voce me lembra ele.'\n");
            pontosAstúcia += 3;  // +3 foco total
            
        } else if (escolha2 == 2) {
            printf("\nVoce tenta atirar enquanto conversa.\n");
            printf("Acerta 2 alvos, erra 1.\n");
            printf("Fulzard: 'Quase! Mas se distrair pode custar caro.'\n");
            pontosAstúcia += 2;  // +2 esforco
            
        } else {
            printf("\nVoce: 'Prefiro nao, obrigado.'\n");
            printf("Fulzard: 'Sem problemas! Cada um tem seu jeito.'\n");
            pontosAstúcia += 1;  // +1 por honestidade
        }
        
    // ===== ESCOLHA 2: SILENCIO =====
    } else if (escolha1 == 2) {
        limparTela();
        printf("\nVoce se aproxima em silencio, respeitoso.\n");
        printf("O lagarto vira e sorri: 'Voce e bom... eu era pessimo nisso.'\n");
        printf("Lagarto: 'Meu nome e Fulzard.'\n\n");
        pausar();
        
        printf("Fulzard: 'Conheci um paladino chamado Damian.'\n");
        printf("'Ele me ensinou a ter FOCO... a me importar.'\n");
        printf("'Antes, eu era distraido, nao ligava pra nada.'\n");
        printf("'Ele me mostrou que se importar dói... mas vale a pena.'\n\n");
        
        printf("O que voce faz?\n");
        printf("1 - Perguntar mais sobre Damian\n");
        printf("2 - Perguntar por que ele esta aqui\n");
        printf("3 - Apenas ouvir em silencio\n");
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            printf("\nFulzard: 'Ele era nosso lider... e amigo.'\n");
            printf("'Quando ele morreu, eu perdi o foco de novo.'\n");
            printf("'Agora tento honrar o que ele me ensinou.'\n");
            pontosAstúcia += 2;  // +2 empatia
            
        } else if (escolha2 == 2) {
            printf("\nFulzard: 'Estou aqui guardando memorias.'\n");
            printf("'Este pantano... lutamos aqui uma vez.'\n");
            printf("'Eu me distraí e quase morri.'\n");
            printf("'Damian me salvou. Nunca esqueci.'\n");
            pontosAstúcia += 2;  // +2 curiosidade
            
        } else {
            printf("\nVoce apenas escuta, respeitoso.\n");
            printf("Fulzard sorri: 'Obrigado por ouvir.'\n");
            printf("'Faz tempo que nao falo sobre isso.'\n");
            pontosAstúcia += 3;  // +3 presenca
        }
        
    // ===== ESCOLHA 3: OBSERVAR =====
    } else {
        limparTela();
        printf("\nVoce observa de longe.\n");
        printf("O lagarto vira: 'Sei que esta ai. Pode vir.'\n");
        printf("Ele sorri: 'Paranoia e boa. Eu tinha pouca.'\n");
        printf("Lagarto: 'Meu nome e Fulzard.'\n\n");
        pausar();
        
        printf("Fulzard: 'Quer cacar comigo?'\n");
        printf("'Tem uma presa por aqui.'\n\n");
        
        printf("O que voce decide?\n");
        printf("1 - Aceitar liderar (confianca)\n");
        printf("2 - Deixar ele liderar (humildade)\n");
        printf("3 - Cacar cada um de um lado\n");
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            printf("\nVoce lidera a cacada.\n");
            printf("Fulzard te segue com atencao.\n");
            printf("Voces capturam a presa com sucesso!\n");
            printf("Fulzard: 'Voce e um bom lider!'\n");
            pontosAstúcia += 3;  // +3 lideranca
            
        } else if (escolha2 == 2) {
            printf("\nVoce deixa Fulzard liderar.\n");
            printf("Ele fica surpreso: 'Serio? Obrigado!'\n");
            printf("Ele lidera bem, focado.\n");
            printf("Fulzard: 'Fazia tempo que nao confiavam em mim.'\n");
            pontosAstúcia += 3;  // +3 confianca
            
        } else {
            printf("\nVoces se separam.\n");
            printf("Voce perde a presa por falta de coordenacao.\n");
            printf("Fulzard: 'Sozinho e mais dificil, ne?'\n");
            pontosAstúcia += 1;  // +1 independencia
        }
    }
    
    pausar();
    
    printf("\n--- DESPEDIDA ---\n\n");
    printf("Fulzard: 'Voce vai bem. Continue focado.'\n");
    printf("'Animata sofre... mas cuidado. Dor pode ser perigosa.'\n");
    printf("'Damian me ensinou que se importar doi...'\n");
    printf("'Mas o amor que se sente e superior a isso.'\n");
    printf("'Boa sorte, aventureiro.'\n\n");
    
    pausar();
    printf("\n[ASTUCIA TOTAL: %d pontos]\n", pontosAstúcia);
    pausar();
}

// ---------- EVENTO 3: COBRA DO PANTANO ----------

void eventoCobraPantano() {
    limparTela();
    printf("\n=== EVENTO 3: A COBRA GUARDIA ===\n\n");
    
    printf("Ao chegar perto da saida do pantano...\n");
    printf("A agua se agita violentamente!\n");
    printf("Uma COBRA GIGANTE emerge!\n");
    printf("Seus olhos brilham com inteligencia antiga.\n\n");
    pausar();
    
    printf("Cobra: 'Sssss... voce atravesssou meu pantano...'\n");
    printf("'Vi ssssuas escolhasss...'\n");
    printf("'Agora... julgo ssssua assstucia.'\n\n");
    pausar();
    
    // JULGAMENTO BASEADO NOS PONTOS
    printf("\n--- JULGAMENTO DO PANTANO ---\n\n");
    
    if (pontosAstúcia >= 10) {
        // ALTA ASTUCIA
        printf("Cobra: 'Voce nao e pressssa... e cacador como eu.'\n");
        printf("'Pensssa antesss de agir.'\n");
        printf("'Usssa a mente, nao apenasss musculosss.'\n");
        printf("'Aceito voce como IGUAL!'\n\n");
        printf("A cobra te da uma ESCAMA VENENOSA.\n");
        printf("Cobra: 'Ussse contra a bruxa... pode ajudar.'\n");
        printf("[ITEM OBTIDO: Veneno Antigo - util contra Animata]\n");
        pontosAstúcia += 5;  // Bonus de 5
        
    } else if (pontosAstúcia >= 5) {
        // MEDIA ASTUCIA
        printf("Cobra: 'Voce ssobrevive... por inssstinto ou ssorte?'\n");
        printf("'Tanto faz. Passsou.'\n\n");
        printf("A cobra te da ESCAMAS PROTETORAS.\n");
        printf("[ITEM: Escamas - defesa aumentada]\n");
        pontosAstúcia += 2;  // Bonus de 2
        
    } else {
        // BAIXA ASTUCIA
        printf("Cobra: 'Voce tropeca em galhos propriosss...'\n");
        printf("'Nao pensa... apenasss age.'\n");
        printf("'Cuidado... ou ssera devorado.'\n\n");
        printf("A cobra te morde de leve - um AVISO.\n");
        printf("[MALDICAO: Reflexos lentos]\n");
        pontosAstúcia += 0;
    }
    
    pausar();
    printf("\n--- PANTANO COMPLETO ---");
    printf("\nPONTOS DE ASTUCIA FINAIS: %d\n", pontosAstúcia);
    pausar();
}

// ========================================
//          ROTA 3: CAVERNA
// ========================================

void rotaCaverna() {
    limparTela();
    printf("\n=== CAVERNA ===\n\n");
    printf("Voce entra na caverna escura.\n");
    printf("Tochas antigas iluminam as paredes de pedra.\n");
    printf("Aqui, a verdade sera revelada.\n\n");
    pausar();
    
    // Tres eventos da caverna
    eventoDragaoFilhote();
    eventoAnaoEgnar();
    eventoDrakeAnciao();
    
    // Apos completar a caverna, vai para o castelo
    castelo();
}

// ---------- EVENTO 1: DRAGAO FILHOTE ----------

void eventoDragaoFilhote() {
    int escolha1, escolha2;
    
    limparTela();
    printf("\n=== EVENTO 1: DRAGAO FAMINTO ===\n\n");
    
    printf("Voce ouve GRITOS ecoando na caverna!\n");
    printf("Voce corre em direcao ao som...\n\n");
    printf("Um DRAGAO FILHOTE esta perseguindo um COMERCIANTE ANAO!\n");
    printf("Comerciante: 'SOCORRO! ME AJUDA!'\n");
    printf("O dragao rosna... mas voce nota:\n");
    printf("Ele esta MUITO magro. Costelas aparecendo.\n");
    printf("O estomago do dragao RONCA alto.\n\n");
    pausar();
    
    printf("O que voce faz?\n");
    printf("1 - Atacar o dragao (proteger humano)\n");
    printf("2 - Pegar pedra e distrair (neutralidade)\n");
    printf("3 - Interagir/Acalmar (sabedoria)\n");
    printf("Escolha: ");
    scanf("%d", &escolha1);
    
    // ===== ESCOLHA 1: ATACAR =====
    if (escolha1 == 1) {
        limparTela();
        printf("\nVoce desembanha sua espada e corre em direcao ao dragao filhote!\n");
        printf("Espantado, o dragao filhote solta fogo, mas nao e muito forte.\n");
        printf("O fogo te empurra, mas nao o suficiente para voce desistir.\n");
        printf("Voce se queima um pouco, porem continua na sua investida.\n");
        printf("Voce pula, atacando e dando um golpe certeiro!\n");
        printf("O dragao cai derrotado...\n\n");
        pausar();
        
        dragaoFilhoteMorto = 1;  // Marca que matou o dragao
        
        printf("O que voce faz?\n");
        printf("1 - Verificar o dragao (reflexao)\n");
        printf("2 - Consolar o comerciante\n");
        printf("3 - Pegar escama do dragao\n");
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            printf("\nVoce se aproxima do corpo...\n");
            printf("Era apenas um FILHOTE. Com fome.\n");
            printf("Voce sente um peso na consciencia.\n");
            pontosSabedoria += 1;  // +1 por reflexao
            
        } else if (escolha2 == 2) {
            printf("\nComercian: 'Obrigado! Voce me salvou!'\n");
            printf("Ele te da um MINERIO DE MITHRIL BRUTO.\n");
            printf("'Pegue, e valioso!'\n");
            temMithril = 1;  // Ganha o mithril
            pontosSabedoria += 0;  // 0 - nao refletiu
            
        } else {
            printf("\nVoce friamente coleta uma escama do dragao.\n");
            printf("Comerciante te olha com desaprovacao.\n");
            pontosSabedoria += 0;  // 0 - frieza
        }
        
    // // ===== ESCOLHA 2: DISTRAIR =====
    // } else if (escolha1 == 2) {
    //     limparTela();
    //     printf("\nVoce pega uma pedra e arremessa longe!\n");
    //     printf("O dragao vai atras da pedra, distraido.\n");
    //     printf("O comerciante foge rapidamente.\n\n");
    //     printf("Voce se aproxima do dragao...\n");
    //     printf("Ele esta MUITO magro. Tremendo de fome.\n\n");
    //     pausar();
        
    //     printf("O que voce faz?\n");
    //     printf("1 - Dar comida da mochila\n");
    //     printf("2 - Procurar a mae dele\n");
    //     printf("3 - Sair e deixar ele\n");
    //     printf("Escolha: ");
    //     scanf("%d", &escolha2);
        
    //     if (escolha2 == 1) {
    //         printf("\nVoce joga carne seca da mochila.\n");
    //         printf("O dragao devora e ronrona como um gatinho!\n");
    //         printf("Ele lambe sua mao, agradecido.\n");
    //         printf("Ele te segue um pouco, depois volta para a caverna.\n");
    //         dragaoFilhoteSalvo = 1;  // Marca que salvou
    //         pontosSabedoria += 3;  // +3 empatia
    //         printf("\nO comerciante aparece: 'Voce... tem um bom coracao.'\n");
    //         printf("Ele te da MINERIO DE MITHRIL.\n");
    //         temMithril = 1;
            
    //     } else if (escolha2 == 2) {
    //         printf("\nVoce procura pegadas... e acha algo terrivel.\n");
    //         printf("Um esqueleto GIGANTE de dragao!\n");
    //         printf("Era a mae dele... morta ha tempos.\n");
    //         printf("O filhote chora ao ver.\n");
    //         printf("Voce pode:\n");
    //         printf("  - Deixa-lo la (duro)\n");
    //         printf("  - Enterrar a mae com ele (empatia)\n");
    //         printf("Voce escolhe enterrar.\n");
    //         printf("O dragao te olha grato e desaparece nas sombras.\n");
    //         dragaoFilhoteSalvo = 1;
    //         pontosSabedoria += 4;  // +4 maxima empatia
            
    //     } else {
    //         printf("\nVoce vai embora.\n");
    //         printf("Ouve o dragao chorando atras de voce.\n");
    //         pontosSabedoria += 0;  // 0 - frieza
    //     }
        
    // // ===== ESCOLHA 3: ACALMAR =====
    // } else {
    //     limparTela();
    //     printf("\nVoce levanta as maos e fala calmamente.\n");
    //     printf("'Calma... calma, pequeno...'\n");
    //     printf("O dragao para, confuso.