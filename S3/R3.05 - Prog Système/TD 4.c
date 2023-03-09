// 1
#include <signal.h>

#define DELAI 15
#define ATTENTE 50

void relance(int sig) { // appelée toutes les 15 secondes pendant l'attente de saisie
    printf("Alors ca vient ?\n");
}

int main() {
    char c;
    struct sigaction sig_relance, ancien;

    sig_relance.sa_handler = relance;
    sig_relance.sa_flags=SA_RESTART;
    sigemptyset(&sig_relance.sa_mask);
    sigaction(SIGALRM,&sig_relance,&ancien); // Traitement du signal et récup de l'ancien traitement
    alarm(DELAI); // signal SIGALRM dans 15 secondes si on a pas arreté d'ici la
    printf("Taper un caractere \n");
    c=getchar();
    alarm(0);
    sigaction(SIGALRM,&ancien,NULL); // Arret du traitement du signal

    printf("Debut du calcul\n");
    sleep(ATTENTE);
    printf("Fin du calcul");

    exit(EXIT_SUCCESS);
}



// 2
#define DELAI2 30

void abandon() {
    printf("bon j'abandonne !\n");
    exit(EXIT_FAILURE);
}

void relance(int sig) { // appelée toutes les 15 secondes pendant l'attente de saisie
    printf("Alors ca vient ?\n");
    sig_abandon.sa_handler=abandon;
    sig_abandon.sa_flags=SA_RESTART|SA_RESETHAND;
    sigemptyset(&sig_abandon.sa_mask);
    sigaction(SIGALRM,&sig_abandon,NULL);
    alarm(DELAI2);
}

int main() {
    char c;
    struct sigaction sig_relance, ancien;

    sig_relance.sa_handler = relance;
    sig_relance.sa_flags=SA_RESTART;
    sigemptyset(&sig_relance.sa_mask);
    sigaction(SIGALRM,&sig_relance,&ancien); // Traitement du signal et récup de l'ancien traitement
    alarm(DELAI); // signal SIGALRM dans 15 secondes si on a pas arreté d'ici la
    printf("Taper un caractere \n");
    c=getchar();
    alarm(0);
    sigaction(SIGALRM,&ancien,NULL); // Arret du traitement du signal

    printf("Debut du calcul\n");
    sleep(ATTENTE);
    printf("Fin du calcul");

    exit(EXIT_SUCCESS);
}