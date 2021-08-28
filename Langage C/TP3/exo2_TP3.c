// Fonction permettant de coder un caractère
// selon la méthode indiquée dans l'énoncé :
char code_lettre(char lettre)
{
    // Lettres A à V :
    if(lettre >= 'A' && lettre <= 'V')
        return lettre + 36;
    // Lettres W à Z :
    if(lettre >= 'W' && lettre <= 'Z')
        return lettre + 10;
    // Lettre a à v :
    if(lettre >= 'a' && lettre <= 'v')
        return lettre - 28;
    // Lettre w à z :
    if(lettre >= 'w' && lettre <= 'z')
        return lettre - 54;
    // Autres caractères :
    return lettre;
}

main()
{
    char texte[50];
    int i = 0;

    printf("Entrez une chaine de caracteres : ");
    fgets(texte, 50, stdin);

    while(texte[i] != '\0')
    {
        texte[i] = code_lettre(texte[i]); // Appel de la fonction
        i++;
    }
    printf("Message code : %s\n",texte);
}