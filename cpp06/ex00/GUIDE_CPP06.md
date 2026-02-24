# Guide pas à pas — Module CPP06 (Casts & conversions)

Ce guide te permet d’apprendre les points clés du projet **sans** te donner tout le code. Tu peux t’y référer exercice par exercice et avancer par toi-même.

---

## Vue d’ensemble du module

**Objectif :** Comprendre et utiliser les **casts C++** et les **conversions de types** en C++98.

- **Ex00** : Conversion de types scalaires (chaîne → char, int, float, double).
- **Ex01** : Sérialisation de pointeurs (pointeur ↔ entier).
- **Ex02** : Identification du type réel d’un objet (polymorphisme + `dynamic_cast`).

---

## Partie 0 — Les casts en C++ (à lire avant tout)

### Pourquoi des casts C++ et pas `(type)value` ?

En C, on fait `(int)ptr` ou `(float)x`. En C++, on privilégie des opérateurs explicites pour que l’intention soit claire et que le compilateur puisse mieux vérifier.

### Les 4 casts C++98

| Cast | Rôle principal | Exemple d’usage |
|------|----------------|-----------------|
| **`static_cast<T>(x)`** | Conversions “logiques” (numériques, héritage descendant quand tu es sûr du type) | `static_cast<double>(intVar)` |
| **`dynamic_cast<T>(x)`** | Conversion **à l’exécution** pour pointeurs/références dans une hiérarchie polymorphique. Retourne `NULL` (pointeur) ou lève une exception (référence) si échec | `dynamic_cast<Derived*>(basePtr)` |
| **`const_cast<T>(x)`** | Enlever ou ajouter `const` / `volatile` (sans changer le type “logique”) | `const_cast<char*>(str.c_str())` (à utiliser avec précaution) |
| **`reinterpret_cast<T>(x)`** | Réinterpréter les bits (ex : pointeur → entier, entier → pointeur). Très bas niveau | `reinterpret_cast<uintptr_t>(ptr)` |

**À faire :**  
- Lire la doc ou un cours sur chaque cast.  
- Écrire 2–3 petits exemples par cast (dans un `main` ou un fichier de test) pour bien sentir la différence.

---

## Exercice 00 — Conversion de types scalaires (ScalarConverter)

### Ce que tu dois comprendre

- Un **literal** en C++ peut être : `'c'`, `42`, `3.14f`, `2.5`, `-inff`, `nan`, etc.
- Tu reçois une **chaîne** (ex. `"42"`, `"3.14f"`, `"nan"`) et tu dois afficher la valeur convertie en **char**, **int**, **float** et **double** (avec les règles du C++ : overflow, non affichable, etc.).

### Étapes recommandées

1. **Classe “utility”**
   - Une classe dont on n’a pas besoin d’instance : tout peut être dans une méthode `static void convert(std::string const& literal)`.
   - Constructeur par défaut, copie, opérateur `=` : mets-les en **private** (ou supprime-les en C++11+) pour interdire la création d’objets.

2. **Décider du type du literal**
   - En parcourant la chaîne, détermine si c’est :
     - un **char** (ex. `'a'`) ;
     - un **int** ;
     - un **float** (suffixe `f` ou `F`, ou forme spéciale `-inff`, `+inff`, `nanf`) ;
     - un **double** (décimal sans `f`, ou `-inf`, `+inf`, `nan`).
   - Pense aux cas : signe `+`/`-`, un seul caractère entre quotes, présence de `f`/`F`, chaînes `inf`, `nan`, etc.

3. **Parser la chaîne**
   - Utilise des fonctions du C ou du C++ pour convertir :
     - **int** : `atoi`, ou boucle manuelle, en gérant le signe et l’overflow.
     - **float** / **double** : `atof` (renvoie un `double`), ou `strtof` / `strtod` pour plus de contrôle.
   - Pour le **char** : extraire le caractère entre les quotes (attention au cas d’un seul caractère).

4. **Afficher les 4 types**
   - À partir de la valeur “source” (char, int, float ou double), affiche :
     - **char** : si non affichable (ex. 0–31, 127), affiche quelque chose comme "Non displayable", sinon le caractère.
     - **int** : si overflow ou non représentable (ex. pour un float trop grand ou nan), affiche "impossible" (ou équivalent).
     - **float** / **double** : affichage décimal ; pour les entiers, tu peux afficher `.0f` / `.0` pour garder la forme “float/double”.

5. **Cas d’erreur**
   - Si la chaîne ne correspond à aucun format reconnu, affiche un message d’erreur (ex. "Invalid literal") et ne fais pas de conversion.

**Points clés :**
- Bien délimiter les cas : char literal, int, float, double, et les pseudo-literaux (`inf`, `nan`, etc.).
- Gérer les overflows (int) et les valeurs non représentables.
- Pas de cast obligatoire pour cet exo ; l’accent est sur la **détection du type** et la **conversion manuelle/par fonctions**.

---

## Exercice 01 — Sérialisation (Serializer)

### Ce que tu dois comprendre

- “Sérialiser” un pointeur ici = le convertir en un **entier** (pour le stocker ou le transmettre).
- On utilise un type de la même taille qu’un pointeur : **`uintptr_t`** (défini dans `<cstdint>` en C++11 ; en C++98, tu peux utiliser `unsigned long` ou un type fourni par ton sujet).

### Étapes recommandées

1. **Classe `Serializer`**
   - Méthodes **static** :
     - `uintptr_t serialize(Data* ptr);`  → convertit `ptr` en entier.
     - `Data* deserialize(uintptr_t raw);` → convertit l’entier en pointeur `Data*`.

2. **Quel cast utiliser ?**
   - Pointeur ↔ entier = réinterprétation de bits, **pas** une conversion “logique”.
   - Donc : **`reinterpret_cast`**.
   - `serialize` : `return reinterpret_cast<uintptr_t>(ptr);`
   - `deserialize` : `return reinterpret_cast<Data*>(raw);`

3. **Structure `Data`**
   - Une petite struct (ex. un `int` et une `string`) pour faire des tests dans `main` :
     - Créer un `Data`, prendre son adresse, appeler `serialize`, puis `deserialize`, et vérifier que le pointeur obtenu pointe bien vers les mêmes données.

**Points clés :**
- Comprendre que `reinterpret_cast` ne change pas les bits, seulement l’“interprétation” du compilateur.
- Vérifier que après `serialize` puis `deserialize`, on retrouve le même pointeur (et les mêmes valeurs dans la struct).

---

## Exercice 02 — Identifier le type réel (Base, A, B, C)

### Ce que tu dois comprendre

- Tu as une hiérarchie : **Base** (classe de base), et **A**, **B**, **C** qui en dérivent.
- On te donne un **pointeur ou une référence** vers `Base`, mais l’objet réel peut être un `A`, un `B` ou un `C`.
- Tu dois **identifier à l’exécution** le type réel → c’est le rôle de **`dynamic_cast`**.

### Étapes recommandées

1. **Hiérarchie de classes**
   - Créer une classe **Base** (vide ou avec un destructeur virtuel pour que le polymorphisme fonctionne).
   - Créer **A**, **B**, **C** qui héritent **public** de `Base`.

2. **Fonction `generate`**
   - Retourne un pointeur `Base*` qui pointe en fait vers une instance de `A`, `B` ou `C` (choix aléatoire).
   - Ex. : `return new A();` ou `new B();` ou `new C();` selon un `rand() % 3`.

3. **Identification avec `dynamic_cast`**
   - **Pointeur** :  
     `if (dynamic_cast<A*>(p))` → c’est un `A`.  
     Idem pour `B*` et `C*`.  
     `dynamic_cast<A*>(p)` retourne `NULL` si `p` ne pointe pas vers un `A`.
   - **Référence** :  
     `dynamic_cast<A&>(ref)` lance une exception (`std::bad_cast`) si ce n’est pas un `A`.  
     Tu peux faire une fonction qui affiche "A", "B" ou "C" selon le résultat des `dynamic_cast` en pointeur, et une autre qui fait la même chose en référence (avec try/catch si tu utilises la version référence).

4. **Règles importantes pour `dynamic_cast`**
   - La classe de base doit avoir **au moins une fonction virtuelle** (souvent le destructeur `virtual ~Base();`).
   - Sans polymorphisme, `dynamic_cast` ne peut pas fonctionner.

**Points clés :**
- `dynamic_cast` nécessite des types polymorphiques (classe de base avec méthode virtuelle).
- En pointeur : échec = `NULL`. En référence : échec = exception.

---

## Récap des concepts par exercice

| Exercice | Concepts principaux |
|----------|---------------------|
| **Ex00** | Parsing de chaînes, détection de type, conversion explicite (atoi, atof, etc.), affichage conditionnel (char non affichable, int impossible) |
| **Ex01** | `reinterpret_cast`, pointeur ↔ entier, `uintptr_t` (ou équivalent C++98) |
| **Ex02** | Héritage, polymorphisme (destructeur virtuel), `dynamic_cast` pointeur et référence, identification du type à l’exécution |

---

## Contraintes 42 à respecter

- **C++98** uniquement.
- Compilation : `-Wall -Wextra -Werror -std=c++98`.
- Pas de fuites mémoire (ex02 : si tu alloues avec `new` dans `generate`, pense à qui libère et où).
- Forme canonique (constructeur par défaut, copie, opérateur `=`, destructeur) là où des instances sont utilisées.

---

## Ordre de travail suggéré

1. Lire ce guide et un rappel sur les 4 casts.
2. **Ex00** : ScalarConverter (parser + conversions + affichage).
3. **Ex01** : Serializer (reinterpret_cast + Data).
4. **Ex02** : Base / A, B, C + generate + identify avec dynamic_cast.

Bonne chance pour le faire par toi-même. Si tu bloques sur un point précis (par ex. “comment détecter un float dans la chaîne”), reviens sur cette étape dans le guide ou sur la doc des casts/conversions.
