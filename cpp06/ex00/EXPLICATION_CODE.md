# Explication complète du code — ScalarConverter (ex00)

Ce document détaille chaque partie du projet, avec des liens vers la documentation officielle (C++ Reference, etc.) pour approfondir.

---

## Sommaire

1. [ScalarConverter.hpp — Le header](#1-scalarconverterhpp--le-header)
2. [ScalarConverter.cpp — Logique métier](#2-scalarconvertercpp--logique-métier)
3. [main.cpp — Point d'entrée](#3-maincpp--point-dentrée)
4. [Makefile — Compilation](#4-makefile--compilation)
5. [Flux de données global](#5-flux-de-données-global)

---

## 1. ScalarConverter.hpp — Le header

### Include guard

```cpp
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
// ...
#endif
```

- Évite d’inclure le header plusieurs fois dans une même traduction.
- Si `SCALARCONVERTER_HPP` est déjà défini, le compilateur saute tout le contenu jusqu’à `#endif`.

**Doc :** [Header guard / Include guard](https://en.cppreference.com/w/cpp/preprocessor/include) (préprocesseur C/C++).

---

### Includes

| Include      | Rôle dans le projet |
|-------------|----------------------|
| `<string>`  | Type `std::string` pour le literal passé à `convert()`. |
| `<iostream>`| `std::cout`, `std::endl` pour l’affichage. |
| `<cstdlib>` | `std::atoi`, `std::atof` pour convertir chaîne → nombre. |
| `<climits>` | `INT_MIN`, `INT_MAX` pour vérifier le domaine des `int`. |
| `<cfloat>`  | Constantes des limites des types flottants (optionnel ici). |
| `<cmath>`   | `std::isnan`, `std::isinf` pour tester NaN et infini. |

**Doc :**
- [std::string](https://en.cppreference.com/w/cpp/string/basic_string)
- [std::atoi](https://en.cppreference.com/w/cpp/string/byte/atoi), [std::atof](https://en.cppreference.com/w/cpp/string/byte/atof)
- [INT_MIN / INT_MAX (climits)](https://en.cppreference.com/w/cpp/types/climits)
- [std::isnan, std::isinf (cmath)](https://en.cppreference.com/w/cpp/numeric/math/isnan)

---

### Macros (couleurs terminal)

```cpp
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
// ...
```

- Ce sont des **séquences ANSI escape** : le terminal interprète `\033[31m` comme “couleur rouge”.
- `RESET` remet la couleur par défaut.

**Doc :** [ANSI escape codes (Wikipedia)](https://en.wikipedia.org/wiki/ANSI_escape_code).

---

### Classe et membres

```cpp
class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void convert(std::string literal);
};
```

- **Constructeur, copie, opérateur=, destructeur** en `private` : on ne peut pas créer d’instance ni copier. La classe sert uniquement de “namespace” pour la fonction `convert`.
- **`static void convert(std::string literal)`** : méthode de classe, appelée comme `ScalarConverter::convert(argv[1]);` sans objet.

**Doc :**
- [static member functions](https://en.cppreference.com/w/cpp/language/static)
- [Access specifiers (private/public)](https://en.cppreference.com/w/cpp/language/access)

---

## 2. ScalarConverter.cpp — Logique métier

### Namespace anonyme

```cpp
namespace
{
	enum e_type { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_INVALID };
	// ... fonctions ...
}
```

- Un **namespace sans nom** donne une liaison interne : les symboles sont visibles uniquement dans ce fichier (.cpp). Évite les conflits de noms avec d’autres .cpp et garde des détails d’implémentation cachés.
- `e_type` et les fonctions dans ce namespace ne sont pas exposés dans le header.

**Doc :** [Unnamed namespaces](https://en.cppreference.com/w/cpp/language/namespace#Unnamed_namespaces).

---

### Détection du type du literal

L’ordre des tests est important : le premier qui correspond “gagne”.

#### `isCharLiteral(s)`

- **Format 1 :** chaîne de longueur 3 avec `s[0] == '\''` et `s[2] == '\''` → littéral C++ `'x'` (un caractère entre quotes).
- **Format 2 :** chaîne de longueur 1 **et** ce caractère n’est pas un chiffre → ex. `A` passé par le shell quand on tape `'A'`.
- Un seul chiffre (`0`, `5`) n’est pas considéré comme char pour qu’il soit traité comme int.

**Doc :** [std::string::length](https://en.cppreference.com/w/cpp/string/basic_string/size), [std::isdigit (cctype)](https://en.cppreference.com/w/cpp/string/byte/isdigit).

---

#### `static_cast<unsigned char>(s[0])` dans `isdigit`

- `std::isdigit(int)` attend une valeur comme si c’était un `unsigned char` (ou `EOF`). Passer un `char` négatif (sur une machine où `char` est signé) peut être undefined behavior.
- `static_cast<unsigned char>(s[i])` garantit une valeur dans [0, 255] avant d’appeler `isdigit`.

**Doc :** [std::isdigit](https://en.cppreference.com/w/cpp/string/byte/isdigit) (note sur le paramètre).

---

#### `isSpecialDouble(s)`

- Reconnaît les chaînes : `"nan"`, `"inf"`, `"+inf"`, `"-inf"` (sans `f`).
- Ces littéraux sont ensuite parsés avec `atof` qui renvoie NaN ou ±∞.

**Doc :** [Floating-point literals (inf, nan)](https://en.cppreference.com/w/cpp/language/floating_literal).

---

#### `isIntLiteral(s)`

- Optionnellement un `+` ou `-` au début.
- Le reste doit être uniquement des chiffres.
- Rejette `""`, `"+""`, `"-"` (pas de chiffre après le signe) grâce à `if (i >= s.length()) return false;`.

**Doc :** [Integer literal (grammar)](https://en.cppreference.com/w/cpp/language/integer_literal).

---

#### `isFloatLiteral(s)`

- Longueur ≥ 2 et dernier caractère `f` ou `F`.
- Couvre : `3.14f`, `42f`, `nanf`, `inff`, `-inff`, etc.

**Doc :** [Floating literal (suffix f/F)](https://en.cppreference.com/w/cpp/language/floating_literal).

---

#### `isDoubleLiteral(s)`

- Optionnellement `+` ou `-`, puis une suite de chiffres et **au plus un** `.`.
- Au moins un chiffre doit être présent (pour accepter `0`, `42`, `3.14`, `.5`, `42.`).
- Pas de `f` à la fin (sinon c’est déjà pris comme float).

**Doc :** [Floating literal](https://en.cppreference.com/w/cpp/language/floating_literal).

---

#### `detectType(literal)` — Ordre des tests

1. Chaîne vide → `TYPE_INVALID`.
2. `isCharLiteral` → `TYPE_CHAR` (format `'x'` ou un seul caractère non chiffre).
3. `isFloatLiteral` → `TYPE_FLOAT` (fini par `f`/`F`).
4. `isIntLiteral` → `TYPE_INT` (entiers purs, y compris `0`, `+1`, `-2`).
5. `isSpecialDouble` ou `isDoubleLiteral` → `TYPE_DOUBLE`.
6. Longueur 1 restante → `TYPE_CHAR` (secours pour un seul caractère).
7. Sinon → `TYPE_INVALID`.

Cet ordre assure par exemple que `"0"` est int et pas double, et que `"A"` est char.

---

### Parsing (dans `convert`)

- **TYPE_CHAR :**  
  - Si `literal.length() == 1` → caractère = `literal[0]`.  
  - Sinon (format `'x'`) → caractère = `literal[1]`.  
  - On stocke la valeur numérique avec `static_cast<unsigned char>(charVal)` pour avoir un entier 0–255 cohérent.
- **TYPE_INT :** `std::atoi(literal.c_str())` → valeur entière, puis convertie en `double` pour l’affichage commun.
- **TYPE_FLOAT / TYPE_DOUBLE :** `std::atof(literal.c_str())` → `double`. `atof` gère aussi `nan`, `inf`, `-inf`, et s’arrête au premier caractère invalide (ex. le `f` de `42f` est ignoré, résultat 42.0).

**Doc :**
- [std::atoi](https://en.cppreference.com/w/cpp/string/byte/atoi)
- [std::atof](https://en.cppreference.com/w/cpp/string/byte/atof)
- [std::string::c_str](https://en.cppreference.com/w/cpp/string/basic_string/c_str)
- [static_cast](https://en.cppreference.com/w/cpp/language/static_cast)

---

### Affichage (printChar, printInt, printFloat, printDouble)

- **`fromChar`** : indique que la valeur “source” est un caractère ; on utilise alors `c` pour l’affichage char et sa valeur numérique pour int/float/double.

#### `printChar`

- Si **fromChar** : affiche `'c'` sauf si le code est “non affichable” (codes 0–31 et 127) → `"Non displayable"`.
- Sinon (valeur numérique) : si `isnan`, `isinf`, ou hors [0, 127] → `"impossible"` ; si dans [0, 31] ou 127 → `"Non displayable"` ; sinon le caractère entre quotes.

**Doc :** [std::isnan, std::isinf](https://en.cppreference.com/w/cpp/numeric/math/isnan).

---

#### `printInt`

- Si **fromChar** : on affiche le code du caractère en int via `static_cast<int>(static_cast<unsigned char>(c))`.
- Sinon : si NaN, infini, ou valeur &lt; `INT_MIN` ou &gt; `INT_MAX` → `"impossible"`, sinon la valeur en `int`.

**Doc :** [INT_MIN, INT_MAX](https://en.cppreference.com/w/cpp/types/climits).

---

#### `printFloat` / `printDouble`

- Valeur : soit depuis le caractère (conversion en float/double), soit depuis `value`.
- Cas spéciaux : `std::isnan` → `"nanf"` / `"nan"` ; `std::isinf` → `"inff"` / `"inf"` (avec `-` si négatif).
- Pour les nombres “entiers” (ex. 42.0) dans une plage raisonnable : `std::fixed` + `std::setprecision(1)` pour afficher `.0`.
- Sinon : plus de décimales (`setprecision(7)` pour float, `setprecision(15)` pour double).

**Doc :**
- [std::fixed, std::setprecision (iomanip)](https://en.cppreference.com/w/cpp/io/manip/setprecision)
- [std::fixed](https://en.cppreference.com/w/cpp/io/manip/fixed)

---

### Forme canonique (constructeur, copie, opérateur=, destructeur)

- Tous en `private` et implémentés pour satisfaire la forme canonique 42 (éviter les appels accidentels).
- Le destructeur n’est jamais appelé “utilement” puisqu’on ne construit jamais d’objet ; les messages en vert/rouge servent au debug si quelqu’un essayait d’instancier.

---

## 3. main.cpp — Point d'entrée

```cpp
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./ScalarConverter <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
```

- **argc** : nombre d’arguments (programme inclus). On exige exactement 2 → un argument après le nom du programme.
- **argv[0]** : nom du programme ; **argv[1]** : premier argument (le literal en chaîne C).
- `argv[1]` est un `char*` ; il est implicitement converti en `std::string` pour `convert()`.

**Doc :** [main function (argc, argv)](https://en.cppreference.com/w/cpp/language/main_function).

---

## 4. Makefile — Compilation

| Élément | Rôle |
|--------|------|
| `NAME = ScalarConverter` | Nom du binaire final. |
| `CXX = g++` | Compilateur C++. |
| `CXXFLAGS = -Wall -Wextra -Werror -std=c++98` | Warnings stricts, erreurs en warning, standard C++98. |
| `SRC = main.cpp ScalarConverter.cpp` | Fichiers sources. |
| `OBJ = $(SRC:.cpp=.o)` | Liste des .o (remplace .cpp par .o). |
| `$(NAME): $(OBJ)` | Lien des .o en exécutable. |
| `%.o: %.cpp` | Règle générique : un .o dépend du .cpp correspondant. |
| `clean` / `fclean` / `re` | Suppression des .o, puis du binaire ; `re` = fclean + all. |
| `.PHONY` | Indique que ces cibles ne sont pas des fichiers. |

**Doc :** [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html), [GCC -Wall -Wextra -Werror](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html).

---

## 5. Flux de données global

```
argv[1] (char*)
    ↓
convert(std::string literal)
    ↓
detectType(literal) → TYPE_CHAR | TYPE_INT | TYPE_FLOAT | TYPE_DOUBLE | TYPE_INVALID
    ↓
Si TYPE_INVALID → message d’erreur, return
    ↓
Parsing selon le type → value (double) + éventuellement charVal (char) et fromChar (bool)
    ↓
printChar(value, fromChar, charVal)
printInt(value, fromChar, charVal)
printFloat(value, fromChar, charVal)
printDouble(value, fromChar, charVal)
```

---

## Liens utiles regroupés

| Sujet | Lien |
|-------|------|
| std::string | https://en.cppreference.com/w/cpp/string/basic_string |
| std::atoi / std::atof | https://en.cppreference.com/w/cpp/string/byte/atoi |
| INT_MIN, INT_MAX | https://en.cppreference.com/w/cpp/types/climits |
| std::isnan, std::isinf | https://en.cppreference.com/w/cpp/numeric/math/isnan |
| std::isdigit | https://en.cppreference.com/w/cpp/string/byte/isdigit |
| Littéraux (int, float, double) | https://en.cppreference.com/w/cpp/language/integer_literal, https://en.cppreference.com/w/cpp/language/floating_literal |
| static_cast | https://en.cppreference.com/w/cpp/language/static_cast |
| Méthodes static | https://en.cppreference.com/w/cpp/language/static |
| Namespace anonyme | https://en.cppreference.com/w/cpp/language/namespace#Unnamed_namespaces |
| main, argc, argv | https://en.cppreference.com/w/cpp/language/main_function |
| iomanip (setprecision, fixed) | https://en.cppreference.com/w/cpp/io/manip/setprecision |
| Make (GNU) | https://www.gnu.org/software/make/manual/make.html |

Tu peux utiliser ce document comme référence pour relire le code et cliquer sur les liens pour aller plus loin sur chaque notion.
