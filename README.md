# crackers
cracking système (le script est fournis à des but purement éducatif)

Pour utiliser ce script, vous devez le compiler et le lier avec une bibliothèque qui implémente la fonction unlock_disk_with_password. Une fois le script compilé et lié, vous pouvez l'exécuter sur le disque que vous souhaitez déverrouiller.

Pour compiler et lier le script, vous pouvez utiliser un compilateur C standard tel que GCC. Par exemple, si vous souhaitez compiler le script à l'aide de GCC, vous pouvez le faire en exécutant la commande suivante à partir de la ligne de commande :

gcc -o unlock_disk_with_password.exe unlock_disk_with_password.c -lunlock_disk_with_password

Une fois le script compilé et lié, vous pouvez l'exécuter en spécifiant le disque que vous souhaitez déverrouiller :

./unlock_disk_with_password.exe C:\
