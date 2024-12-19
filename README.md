#Jeu TicTacToe

Vous trouverez 2 dossier, un pour le jeu morpion standard (*morpion*), et l'autre pour l'ultimate (*mega_morpion*)

Concernant les difficulté que j'ai pu retrouvé lors de ce projet:

* mettre en place la fonction défonce; elle marche un fois sur 2 et je n'arrive pas à savoir pourquoi
* je ne peux pas utiliser le débogueur quand il y'a des cin (c'est peu favorable pour connaître ses erreurs)
* lors de la création du 2 ème dossier *mega_morpion*, j'avais un problème de compilation  avec le **CMakeLists**. Je me suis renseigné auprès de Max qui m'a aidé a mettre cette structure ici présente.
* Dans la suite de la création du 2 ème dossier, je voulais utilisé quelques fonctions déjà existante dans le dossier * morpion*, or je n'ai pas réussi à le faire et apparemment c'est compliqué à le mettre en oeuvre. Je serai intéressé si c'est possible d'avoir une explication. Merci d'avance.
* Les algos *mine-max* et *alpha_beta* sont compréhensible niveau logique. Par contre je ne vois pas comment c'est possible de les appliquer sur nos jeu (j'avoue que je n'ai pas cherché non p^lus longtemps)
* Un problème qui reviens souvent (une fois sur 2 quand ke jeu n'est pas terminé et que je relance): dans le terminal, il y a une boucle de la première phrase qui s'affiche en infini.