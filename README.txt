Code C sur les appels systèmes ubuntu de communication entre un processus fils et son parent

on a utilisé deux lignes de communication

Une ligne permettant au fils de recevoir le message de son père
et une seconde ligne permettant au père de recevoir le message de son père.

on commence avant tout par créer les deux lignes de communication, puis on crée le processus fils qui va aussi bénéficier de ces deux lignes

On vérifie si les deux lignes et le processus fils ont été bien créé, puis on fait les appels systèmes adéquats pour la lecture, ou  pour l'écriture.

On affiche la discussion du fils et de son parent puis on affiche l'état du fils
