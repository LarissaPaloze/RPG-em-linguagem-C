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
int pontosAstucia = 0;      // Pantano (escrevi sem acento pra nao dar erro)
int pontosSabedoria = 0;    // Caverna

// Controle de itens importantes (0 = nao tem, 1 = tem)
int temMithril = 0;
int temEscamaDragao = 0;
int dragaoFilhoteSalvo = 0;
int dragaoFilhoteMorto = 0;

// Controle da rota escolhida
char rotaEscolhida[20];

// ========== FUNCOES AUXILIARES ==========

// Limpa a tela
void limparTela() {
    system("cls");
    
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
           pontosCompaixao, pontosAstucia, pontosSabedoria);
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

// // Pantano
// void rotaPantano();
// void eventoCelaBruxa();
// void eventoLagartoFulzard();
// void eventoCobraPantano();

// // Caverna
// void rotaCaverna();
// void eventoDragaoFilhote();
// void eventoAnaoEgnar();
// void eventoDrakeAnciao();

// // Castelo
// void castelo();
// void eventoGargulaCharadas();
// void eventoArmadurasDancarinas();
// void eventoMimicoDiario();
// void confrontoFinalAnimata();

// // Finais
// void calcularRanking();

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

// // ========================================
// //          ROTA 2: PANTANO
// // ========================================

// void rotaPantano() {
//     limparTela();
//     printf("\n=== PANTANO ===\n\n");
//     printf("Voce entra no pantano lodoso.\n");
//     printf("O cheiro e forte, o terreno e traicoeiro.\n");
//     printf("Voce precisa de astucia para sobreviver aqui.\n\n");
//     pausar();
    
//     // Tres eventos do pantano
//     eventoCelaBruxa();
//     eventoLagartoFulzard();
//     eventoCobraPantano();
    
//     // Apos completar o pantano, vai para o castelo
//     castelo();
// }

// // ---------- EVENTO 1: CELA E BRUXA ----------

// void eventoCelaBruxa() {
//     int escolha1, escolha2;
    
//     limparTela();
//     printf("\n=== EVENTO 1: RUINAS AMALDICOADAS ===\n\n");
    
//     printf("Voce encontra uma construcao antiga em ruinas.\n");
//     printf("Parece abandonada, mas algo parece errado...\n");
//     printf("Ao entrar, voce ve runas brilhantes no chao.\n\n");
//     pausar();
    
//     printf("O que voce faz?\n");
//     printf("1 - Investigar as runas (cuidado)\n");
//     printf("2 - Andar pelas paredes (cautela)\n");
//     printf("3 - Andar direto pelo centro (confianca)\n");
//     printf("Escolha: ");
//     scanf("%d", &escolha1);
    
//     // ===== ESCOLHA 1: INVESTIGAR =====
//     if (escolha1 == 1) {
//         limparTela();
//         printf("\nVoce se abaixa e examina as runas cuidadosamente.\n");
//         printf("Sao runas de aprisionamento!\n");
//         printf("Voce percebe que e uma ARMADILHA!\n\n");
        
//         printf("O que voce faz?\n");
//         printf("1 - Contornar as runas (astucia)\n");
//         printf("2 - Tentar desarmar (arriscado)\n");
//         printf("3 - Pisar sabendo o risco (confianca)\n");
//         printf("Escolha: ");
//         scanf("%d", &escolha2);
        
//         if (escolha2 == 1) {
//             // CONTORNAR
//             printf("\nVoce contorna as runas com cuidado!\n");
//             printf("Consegue passar sem ativar a armadilha!\n");
//             pontos