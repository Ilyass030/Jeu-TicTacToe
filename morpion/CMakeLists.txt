# # la version de cmake à utiliser
# cmake_minimum_required(VERSION 3.0)

# # La version du C++ que l'on souhaite utiliser (dans notre cas C++17)
# set(CMAKE_CXX_STANDARD 17)

# # Le nom du projet
# project(IMAC_project)

# # Réglage du compilateur pour les warnings
# if (MSVC)
#     add_compile_options(/W3)
# else()
#     add_compile_options(-Wall -Wextra -Wpedantic -pedantic-errors)
# endif()

# # On souhaite placer l'exécutable dans un sous-dossier "bin" au lieu de le mettre dans le dossier build
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# # Obtenir la liste des fichiers sources dans le dossier src
# file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")


# # Optionnel : afficher la liste des fichiers sources
# message(STATUS "Found source files:")
# foreach(SRC_FILE ${SRC_FILES})
#     message(STATUS " - ${SRC_FILE}")
# endforeach()

# # On indique que l'on souhaite faire un exécutable avec nos fichiers sources
# add_executable(helloImac ${SRC_FILES})

# # le dossier contenant les fichiers d'en-tête pour notre executable helloImac
# target_include_directories(helloImac PUBLIC "src/")

cmake_minimum_required(VERSION 3.10)

# Définir une variable pour le nom du projet
set(PROJECT_NAME "MORPION")

# Nom du projet
project(${PROJECT_NAME})

# Répertoire des fichiers sources
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Chercher récursivement tous les fichiers .cpp dans le dossier src
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)

# Ajouter les fichiers sources au projet
add_executable(${PROJECT_NAME} ${SOURCES})

# Options de compilation (par exemple : C++17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

# Inclure les répertoires d'en-têtes (si besoin)
include_directories(${SRC_DIR})
