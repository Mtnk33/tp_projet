# RAPPORT PROJET SERVEUR TCP

## Auteurs
- Rafanomezantsoa Andy Nirina Anthonio
- RANDRIANAINA Fifalina Fernando
- RATSIRIMANANA Harimalala Freddy


---

## 1. Introduction

Ce projet consiste à développer un serveur TCP en langage C sous Linux (Debian).
L’objectif est de comprendre le fonctionnement des communications réseau ainsi que
la gestion des connexions entre un serveur et plusieurs clients.

---

## 2. Fonctionnement du serveur

Le serveur TCP fonctionne en plusieurs étapes :

- Création du socket avec `socket()`
- Association avec une adresse grâce à `bind()`
- Mise en écoute avec `listen()`
- Acceptation des connexions avec `accept()`

Une fois connecté, le serveur reçoit un message du client et envoie une réponse.

---

## 3. Communication client-serveur

Le client se connecte au serveur grâce à l’adresse IP et au port.
Dans ce projet, le test a été réalisé avec la commande :


Le client envoie un message, et le serveur le reçoit puis répond.

---

## 4. Tests réalisés

Plusieurs tests ont été effectués :

- Test de connexion avec netcat
- Envoi de messages depuis le client
- Vérification de la réception côté serveur
- Test avec plusieurs connexions successives

---

## 5. Difficultés rencontrées

Au cours du projet, certaines difficultés ont été rencontrées :

- Compréhension des sockets
- Gestion des erreurs
- Configuration de l’environnement Linux

Ces difficultés ont été résolues grâce à des tests et des corrections progressives.

---

## 6. Conclusion

Ce projet nous a permis de comprendre :

- La programmation réseau en C
- Le fonctionnement d’un serveur TCP
- L’échange de données entre client et serveur

Le serveur fonctionne correctement et répond aux messages envoyés.

---

## 7. Résumé du code

### Création du serveur

```c
int listenfd = socket(AF_INET, SOCK_STREAM, 0);

Configuration de l’adresse
server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr = INADDR_ANY;
server_addr.sin_port = htons(8888);

Mise en écoute
bind(listenfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
listen(listenfd, 5);

Acceptation des connexions
connfd = accept(listenfd, NULL, NULL);

Réception et réponse
read(connfd, buffer, sizeof(buffer));
write(connfd, "Reçu\n", 5);


```bash
git add rapport.md
git commit -m "Rapport amélioré complet"
git push
