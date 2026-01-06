# Simple Shell

**Créé par :** Lucas Podevin et Tommy Jouhans

---

## Description

L'objectif de ce projet est de créer un simple shell UNIX capable de lire des commandes depuis l’entrée standard, et de les exécuter pour afficher le résultat sur la sortie standard.

---

## Fonctionnalités

- Exécution de commandes simples avec arguments

- Gestion du PATH pour trouver les exécutables

- Built-ins de base : exit, env

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Utilisation

- Lancer le shell en mode interactif :
```bash
./hsh
```
### Built-ins

- `exit [n]` : quitte le shell avec le code `n` (0 par défaut). L’argument doit être numérique, sinon le shell retourne 2.
- `env` : affiche toutes les variables d’environnement. Si `SHLVL` n’existe pas, affiche `SHLVL=0`.

## Codes de sortie

- 0 : succès
- 127 : commande non trouvée
- 126 : erreur d'exécution dans le processus enfant
- 2 : argument invalide pour la builtin `exit`
- Sinon : code de sortie de la commande exécutée

### Exemples de tests

```bash
./hsh
#usr$ ls -l
#usr$ env
#usr$ exit 42
echo $?
```
## Flowchart

![Flowchart du Simple Shell](assets/FlowchartSimpleShell.png)

## Auteurs

Lucas Podevin

Tommy Jouhans

