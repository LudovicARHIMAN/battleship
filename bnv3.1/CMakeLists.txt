# - au répertoire source du projet comme $ {HELLO_SOURCE_DIR} ;
# - au répertoire binaire racine du projet en tant que $ {HELLO_BINARY_DIR}.
#

# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.7.2)

# Notre projet est étiqueté hello
project(BNV)
# On inclut notre bibliothèque dans le processus de CMake
# Ainsi que le code du programme qui l'utilisera
add_subdirectory(library)
add_subdirectory(src)

