# [Codex Naturalis] Projet LO21 A26 - UTC

## :warning: Disclaimer

La rédaction de ce README a prit du temps, prenez le temps de le lire.
(Voici un lien pour vous aidez à la mise en forme : https://markdownlivepreview.com/)

Biensûr les sections qui vont suivre ne sont pas obligatoire si vous savez ce que vous faites.

Vous pouvez utiliser l'environnement de développement de votre choix,
à condition qu'il supporte CMake et Qt 6.

Pour débuter cloner le projet !

```bash
git clone MOCK # Ou MOCK est l'url du present projet 
```

## :computer: Pré-requis

Pour les utilisateurs Linux pour vérifier si vous possedez les prérequis :

```bash
git --version
cmake --version # Requis version >= 3.10
doxygen --version
```

```bash
sudo apt update
sudo apt install git cmake doxygen
```

*(Note : si vous n'avez pas g++ installer également `build-essential`)

VS Code : https://code.visualstudio.com/
(Si vous ne savez pas installer une extension : https://code.visualstudio.com/docs/configure/extensions/extension-marketplace)
    
1. Extension C/C++
2. CMake Tools

## :computer: Build avec CMake

### 1. Renseigner le Kit

Depuis Vs Code

    1. Appuyer sur `CTRL + SHIFT + P` (pour obtenir la palette)
    2. Taper "CMake Kit"
    3. Suivez les instructions et definissez un compilateur (GXX ou Clang)

Sous Windows vous pouvez très bien utiliser Visual Studio (Code::Blocks par recommander)

### 2. Build depuis Vs Code (Recommander)

Si vous avez correctement installer Visual Studio Code et 
son Extension CMake Tools, vous remarquerez qu'une barre des
tâches est apparu. 

Vous pouvez cliquer sur **Générer** pour build le projet sur votre machine.

### 3. Build depuis le terminal

Voici les étapes (il faut le dossier build à la racine) :

```bash
cd build

# Génrer les fichiers nécessaires au build (type Makefiles)
cmake ..

# Compilez le projet
cmake --build .
```

### 4. Executer le programme

Depuis Vs code,

    Dans la barre tout en bas

        - Cliquer sur la flèche (le tooltip affiche lancer la cible...)

Depuis le terminal,

1. Dans le dossier *build*
2. `cd build`
3. `./ProjectLO21-A26`

### Qt Creator

Qt Creator peut également être utilisé.

1. Ouvrir Qt Creator
2. `File → Open File or Project`
3. Sélectionner le fichier `CMakeLists.txt`
4. Sélectionner le Kit Qt
5. Configurer puis compiler le projet