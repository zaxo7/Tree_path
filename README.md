# Tree_path
find the path between two nodes in the tree</br>
# stage 1 : Lire l'arber depuis tree.txt et créer une liste chainée
pour tree.txt c'est l'arbre des élements codée avec ma propre technique</br>
* Exemple:
l'arbre suivant </br>
![EXEMPLE](tree.png) </br>
sera traduit comme ce ci : </br>
  >   A > B > D < B > C > E < C > I </br>

* '>': pour ajouter un element dans la prochaine generation de l'arbre  </br>
* '<': pour retourner a l'element aprée le '<' et créer une branche </br>
au même temp en remplie la liste chainée </br>
pour la manipulation des branches j'ai creé un tableaux de pointeurs </br> "next[]" qui stocke les pointeurs des élements suivants branches </br>
# stage 2 : chercher le chemin entre deux villes "entre deux élements de larbre"
### premiérement on cherche si les deux villes existe dans l'arbre (map) 
Si On trouve les deux On recule depuis l'arrivée vers le départ



