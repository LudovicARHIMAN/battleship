

# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.7.2)

# Ici on définit le répertoire qui contiendra l'exécutable, utilisé plus bas dans nstall( ...)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/exe/)

# Créé des variables avec les fichiers à compiler



set(SRCS1
client.c

)

# Notre exécutable
add_executable(CLIENT ${SRCS1})
target_link_libraries(CLIENT LINK_PUBLIC mylib)

set(SRCS2
serveur.c

)


# Notre exécutable
add_executable(SERVEUR ${SRCS2})
target_link_libraries(SERVEUR LINK_PUBLIC mylib)




# Et pour que l'exécutable fonctionne, il faut lui indiquer la bibliothèque dont il dépend
#target_link_libraries(BNV LINK_PUBLIC mylib)

#install(TARGETS BNV RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
