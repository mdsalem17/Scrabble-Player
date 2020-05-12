# Projet Scrabble

Lien vers le [dépôt sur Gitlab](https://forge.univ-lyon1.fr/p1714033/scrabble-etu.git)

### Réalisé par 
* ABDRABO Khaled - p1713323 
* MESSOUD Salem  - p1714033
### Encadré par 
* Christophe Crespelle

### Proposé par 
* Vincent Nivoliers

## Prise en main

Clonez ou Téléchargez et décompressez l’archive scrabble-etu.zip. La compilation de ce dépôt
se fait à l'aide de la commande `premake4`. Vous devez donc bien vérifier qu'elle est bien
installée. Pour cela, vous pouvez utiliser ```apt policy premake4``` ou bien ```dpkg -l premake4```
qui doit contenir « ii ». Sinon, des paquets Premake sont disponibles pour la plupart des
distributions linux.

Compilez le programme, puis lancez-le:
```bash
premake4 gmake
make
./bin/main
```
Vous verrez défiler tous les mouvements issus de la partie du scrabble, un mouvement correspond
à placer un meilleur coup possible parmi les mots ayant le score le plus élevé. 

Pour vous faciliter la prise en main, nous avons proposé plusieurs options qui vont permettre
de garantir une fluidité et une flexibilité.
 
### Pour ralentir le défilement de la partie
```bash
./bin/main --slow [secondes: optionnel]
```
 
### Pour utiliser un plateau sous format text
```bash
./bin/main --suzette-text [board] [hand]
```
Exemple :
```bash
./bin/main --suzette-text ................................................................................................................B.........P....A.........E....T.........R....E.........L....A.........ESBROUFA.......R........................... EELMSTT
```
 
### Pour utiliser un plateau enregistrée dans un fichier (.txt)
```bash
./bin/main --suzette-file [filename]
```
Exemple:
```bash
./bin/main --suzette-file ./data/boards/board3.txt
```

### Pour débugger (uniquement en mode Suzette)
Vous pouvez utiliser les options suivantes :
```
-case, -c [number] -> pour préciser la case de départ, avec [number] inclus entre [0, 224]

-vertical, -v      -> pour chercher uniquement, le meilleur coup, en vertical

-horizontal, -h    -> pour chercher uniquement, le meilleur coup, en horizontal
```
Exemple:
```bash
./bin/main --suzette-file ./data/boards/board3.txt -case 200 -vertical
```

### Pour consulter toutes les options proposées
```bash
./bin/main --help
```
ou
```bash
./bin/main --h
```