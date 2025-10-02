# TP2 INF 231 : MANIPULATION DES LISTES CHAINEES EN  C

**Date :** Jeudi 25 septembre 2025

## NOMS DES MEMBRES DU GROUPE



## 📋 Description
L’objectif  de ce TP est d’implémenter  au travers des differentes formes de **liste chaînée**(simplement chainee, doublement chainee,simplement chainee circulaire, doublement chainee circulaire) differentes opérations  élémentaires telles que: **l’insertion**, **la suppression** et **l’affichage**.



## 🎯 Objectifs Pédagogiques

- Maîtriser les opérations de base sur les listes chaînées.  
- Comprendre les différences entre **listes simplement** et **doublement chaînées**.  
- Implémenter des opérations sur les **listes circulaires**.  
- Gérer correctement l’allocation et la libération de mémoire.
- Gérer les effets de Bohr


##  Structures de Données Implémentées

| # | Structure | Fichier | Description |
|---|-----------|---------|------------|
| 1 | Suppression d’Occurrences | `supp_occ.c` | Lecture d’un élément et suppression de toutes ses occurrences dans une liste. |
| 2 | Liste Simplement Chaînée Triée | `prog2.c` | Insertion d’éléments dans une liste simplement chaînée maintenue triée. |
| 3 | Liste Doublement Chaînée Triée ✅ | `prog3.c` | Insertion d’éléments dans une liste doublement chaînée maintenue triée. |
| 4 | Liste Simplement Chaînée Circulaire | `prog4.c` | Insertion en tête et en queue dans une liste simplement chaînée circulaire. |
| 5 | Liste Doublement Chaînée Circulaire | `prog5.c` | Insertion en tête et en queue dans une liste doublement chaînée circulaire. |

---

## 📝 Spécifications Techniques

Pour chaque implémentation :  

- Gestion correcte de la mémoire (`malloc` / `free`).  
- Validation des pointeurs.  
- Gestion des cas particuliers (liste vide,avec au moins un element).  
- Fonctions d’affichage  
- Interface claire et documentée.

---

## 🔍 Points d’Attention

- **Gestion mémoire :** Toujours libérer la mémoire allouée.  
- **Pointeurs NULL :** Vérifier systématiquement les pointeurs.  
- **Cas limites :** Traiter les listes vides et celles avec un seul élément.  
- **Listes circulaires :** Bien gérer les liaisons circulaires pour éviter les boucles infinies.

---

## 📚 Concepts Clés

- **Liste simplement chaînée :** Un seul pointeur vers l’élément suivant.  
- **Liste doublement chaînée :** Deux pointeurs (précédent et suivant).  
- **Liste circulaire :** Le dernier élément pointe vers le premier.  
- **Liste triée :** Éléments maintenus en ordre croissant ou décroissant.

---
## 📚 Difficultés rencobtrées
- **Liste chainee circulaire ** Beaucoup d'erreur de segmentation qui etait du a la mauvaise allocation de la memoire et le manipulation des pinteurs

## 👨‍💻 Auteur

Exercice réalisé dans le cadre du cours INF 231 – Structures de Données.

---


