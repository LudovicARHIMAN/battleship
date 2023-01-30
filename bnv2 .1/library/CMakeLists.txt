# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.7.2)

# Crée des variables avec les fichiers à compiler
set(SRCS
bnv.c
)

set(HEADERS
bnv.h
)

add_library(mylib ${SRCS} ${HEADERS})
target_include_directories (mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
