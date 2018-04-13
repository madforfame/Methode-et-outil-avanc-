# Puissance 4 - Groupe 7

### Installation

Compiler le projet avec la commande "make", puis l'exécuter avec la commande:
./appli <fichier de configuration>

Il est possible d'exécuter les tests du projet, pour cela compiler avec la commande "make test" et l'exécution des tests se fait automatiquement.

Pour lancer gcov puis lcov sur les dernières exécutions, utiliser la commande "make cov".

Pour lancer gprof, utiliser la commande "make gprof".

Pour  lancer Valgrind avec l'option permettant de tester les performances, utiliser la commande "make missrate".

Pour lancer klee, utiliser les commandes "source ~monniaud/env.sh" puis "make klee".

Pour lancer afl, utiliser les commandes "source ~mounlaur/installe_afl.sh" puis "make afl CFLAGS='-Wall -pg -Iinclude' ".

A chaque fois qu'une option est utilisée, elle prendra en fichier de configuration le fichier nommé "config1.xml" automatiquement.

Faire un "make clean" entre chaque utilisation de différentes options du make (excepté "make cov").

## Authors

* **Benmoussa Nadia** 
* **Drobecq Antoine** 
* **Coste Benjamin** 
